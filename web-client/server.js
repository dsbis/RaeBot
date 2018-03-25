const express = require('express')
const http = require('http')
const socketIO = require('socket.io')

// our localhost port
const port = 4001

const app = express()

// our server instance
const server = http.createServer(app)

// This creates our socket using the instance of the server
const io = socketIO(server)

var SerialPort = require('serialport');
var sPort = new SerialPort('COM4', {
  baudRate: 9600,
  autoOpen: false
});

sPort.open(function (err){
  if(err){
    return console.log("Error opening port: ", err.message);
  }
});

// This is what the socket.io syntax is like, we will work this later
io.on('connection', socket => {
  console.log('User connected')

  socket.on('disconnect', () => {
    console.log('user disconnected')
  })

  socket.on('action', function(data){
    console.log(data);
    sPort.write(data, function(err){
      if(err){
        return console.log('Error on write: ', err.message)
      } else {
        console.log('Successful write');
      }
    })
  });
})

server.listen(port, () => console.log(`Listening on port ${port}`))
