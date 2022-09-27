const express = require('express');
const app = express();
const http = require('http');
const server = http.createServer(app);
const { Server } = require("socket.io");
const io = new Server(server);

app.use(express.static('public'));

const fs = require('fs');
const es = require('event-stream');

const { exec } = require("child_process");

const folder_path = "../data/";

var total_lines_read = 0;

setInterval(()=>{

  GetLastFile();

}, 500);

function GetLastFile(){
  var file_name = "";
  exec("ls ../data/ | tail -n 1", (error, stdout, stderr)=>{
     if(error){
      console.log("Error while checking last lap csv", error);
      return;
     } 
     if(stderr){
      console.log("Stderr while checking last lap csv", stderr);
      return;
     }
     file_name = stdout.replace("\n", "");
     console.log(file_name);
     //file_name = stdout;
     CheckFileLenght(file_name)
  });
}

function CheckFileLenght(file_name){
  exec("wc -l " + folder_path + file_name + " | cut -d \" \" -f1", (error, stdout, stderr)=>{
    if(error){
      console.log("Error while checking data length", error);
      return;
    }
    if(stderr){
      console.log("Stderr while checking data length", stderr);
      return;
    }
    console.log(stdout);
    if(Number(stdout) > total_lines_read){
      ReadFile(folder_path + file_name);
    }
  })
}

function ReadFile(file){
  let current_lines_read = 0;
  try{
  var s = fs.createReadStream(file)
    .pipe(es.split())
    .pipe(es.mapSync((line)=>{
        if(current_lines_read > total_lines_read){
          
          s.pause();
      
          console.log(line);
          setTimeout(()=>{
            
            io.emit('chat message', line);
            
            total_lines_read++; 
            s.resume(); 
          }, 50);
        }
        current_lines_read++;

      })
      .on('error', (err)=>{
        console.log("Error while reading file", err);
      })
      .on('end', ()=>{
        console.log("Read entire file");
    })
  );
  }catch(e){
    console.log("Something went wrong");
  }
}

app.get('/', (req, res) => {
  res.sendFile(__dirname + '/index.html');
});

io.on('connection', async(socket) => {
  console.log("connect");

  //ReadFile();
  //console.log("Other line--------");
  /*
  socket.on('chat message', (msg) => {
    io.emit('chat message', msg);
  });
  */

  socket.on('disconnect', ()=>{
    console.log("disconnect"); 
  });
});


server.listen(3000, () => {
  console.log('listening on port 3000');
});
