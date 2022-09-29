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
var file_name = "";
var benchmark_file_name = "lap1.csv";

setInterval(()=>{

  GetLastFile();

}, 10000);

function GetLastFile(){
  exec("ls -p ../data/ | grep -v / | tail -n 1", (error, stdout, stderr)=>{
    if(error){
      console.log("Error while checking last lap csv", error);
      return;
    } 
    if(stderr){
      console.log("Stderr while checking last lap csv", stderr);
      return;
    }
    if(file_name != stdout.replace("\n", "")){
      file_name = stdout.replace("\n", "");
      total_lines_read = 0;
     
      console.log("CLEAR");
      io.emit('new_data', "new_lap", false, true);
    
    }
    CheckFileLenght();
  });
}

function CheckFileLenght(){
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
      ReadFile(folder_path + file_name, false);
    }
  })
}

function ReadFile(file, benchmark){
  let current_lines_read = 0;
  try{
  var s = fs.createReadStream(file)
    .pipe(es.split())
    .pipe(es.mapSync((line)=>{
        if(current_lines_read > total_lines_read || benchmark){
          
          s.pause();
      
          console.log(line);
            
          io.emit('new_data', "plot_data", benchmark, line);
            
          total_lines_read++; 
          s.resume(); 
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

  ReadFile(folder_path + benchmark_file_name, true);
  socket.on('disconnect', ()=>{
    console.log("disconnect"); 
  });
});


server.listen(3000, () => {
  console.log('listening on port 3000');
});
