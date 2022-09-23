

const express = require('express');
const app = express();
const http = require('http');
const server = http.createServer(app);
const { Server } = require("socket.io");
const io = new Server(server);

const fs = require('fs');
const es = require('event-stream');

const { exec } = require("child_process");

const file_path = "../data/test.csv";

var total_lines_read = 0;

setInterval(()=>{

  exec("wc -l " + file_path + " | cut -d \" \" -f1", (error, stdout, stderr)=>{
    if(error){
      console.log("Error while checking data length", error);
      return;
    }
    if(stderr){
      console.log("Stderr while checking data length", stderr);
      return;
    }
    //console.log(stdout);
    if(Number(stdout) > total_lines_read){
      ReadFile(Number());
    }
  })
}, 500);


function ReadFile(){
  let current_lines_read = 0;
  try{
  var s = fs.createReadStream(file_path)
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
