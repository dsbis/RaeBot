import React, { Component } from 'react';
import openSocket from 'socket.io-client';
import './App.css';
const socket = openSocket("http://10.27.167.83:4001");



class App extends Component {
  constructor() {
    super();

    this.moveForward = this.moveForward.bind(this);
    this.rotateLeft = this.rotateLeft.bind(this);
    this.rotateRight = this.rotateRight.bind(this);
    this.moveBackward = this.moveBackward.bind(this);
  }

  moveForward(e){
    console.log("moveForward");
    socket.emit('action', "FORWARD");
  }

  rotateLeft(e){
    console.log("rotateLeft");
    socket.emit('action', "LEFT");
  }

  rotateRight(e){
    console.log("rotateRight");
    socket.emit('action', "RIGHT");
  }

  moveBackward(e){
    console.log("moveBackward");
    socket.emit('action', "BACKWARD");
  }

  // adding the function
  setColor = (color) => {
    this.setState({ color })
  }

  render() {
    return (
      <div className="App">
        <h1>RaeBot</h1>
        <div>
          <button className="Button" style={{backgroundColor: 'red'}} onClick={this.moveForward}>Forward</button><br/>
          <button className="Button" style={{backgroundColor: '#1E90FF'}} onClick={this.rotateLeft}>Left</button>
          <button className="Button" style={{backgroundColor: 'yellow'}} onClick={this.rotateRight}>Right</button><br/>
          <button className="Button" style={{backgroundColor: '#32CD32'}} onClick={this.moveBackward}>Backward</button>
        </div>
        <footer className="Footer">
          HackISU :: Spring 2018 :: David Bis
        </footer>
      </div>
    );
  }
}
export default App;
