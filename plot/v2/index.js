const fs = require('fs');
const es = require('event-stream');


setTimeout(()=>{
    
var s = fs.createReadStream('../../test.csv')
  .pipe(es.split())
  .pipe(es.mapSync((line)=>{
      s.pause();
      
      console.log(line);
      io.emit('chat message', line);

      s.resume(); 
    })
    .on('error', (err)=>{
      console.log("Error while reading file", err);
    })
    .on('end', ()=>{
      console.log("Read entire file");
    })
  );
    }, 5000);


const express = require('express');
const app = express();
const http = require('http');
const server = http.createServer(app);
const { Server } = require("socket.io");
const io = new Server(server);

app.get('/', (req, res) => {
  res.sendFile(__dirname + '/index.html');
});

io.on('connection', (socket) => {
  console.log("connect");
  socket.on('chat message', (msg) => {
    io.emit('chat message', msg);
  });

  socket.on('disconnect', ()=>{
    console.log("disconnect"); 
  });
});


server.listen(3000, () => {
  console.log('listening on port 3000');
});
