#define LEFT_DIRECT 11
#define RIGHT_DIRECT 10
#define LEFT_POWER 5
#define RIGHT_POWER 6

void setup() {
  Serial.begin(9600);
}

void loop() {     
//  moveForward(1000);
//  delay(1000);             
//  moveBackward(500);
//  delay(1000);
//  rotateLeft(500);
//  rotateRight(500);
//  delay(1000);
  if (Serial.available() > 0) {
    // read the incoming byte:
    String data = Serial.readString();
    if(data.equals("FORWARD")){
      moveForward(500);
    } else if(data.equals("LEFT")){
      rotateLeft(250);
    } else if(data.equals("RIGHT")){
      rotateRight(250);
    } else if(data.equals("BACKWARD")){
      moveBackward(500);
    }
  }
}

void leftWheelPower(bool onOff){
  if(onOff == true){
    pinMode(LEFT_POWER, OUTPUT);
  } else {
    pinMode(LEFT_POWER, INPUT);
  }
}

void rightWheelPower(bool onOff){
  if(onOff == true){
    pinMode(RIGHT_POWER, OUTPUT);
  } else {
    pinMode(RIGHT_POWER, INPUT);
  }
}

void leftWheelDirection(String forwardBackward){
  if(forwardBackward.equals("forward")){
    analogWrite(LEFT_DIRECT, 255);
  }  else if(forwardBackward.equals("backward")){
    analogWrite(LEFT_DIRECT, 0);  
  }
}

void rightWheelDirection(String forwardBackward){
  if(forwardBackward.equals("forward")){
    analogWrite(RIGHT_DIRECT, 255);
  } else if(forwardBackward.equals("backward")){
    analogWrite(RIGHT_DIRECT, 0);  
  }
}

void moveForward(int mTime){
  leftWheelPower(true);
  rightWheelPower(true);
  leftWheelDirection("forward");
  rightWheelDirection("forward");
  delay(mTime);
  leftWheelPower(false);
  rightWheelPower(false);
}

void moveBackward(int mTime){
  leftWheelPower(true);
  rightWheelPower(true);
  leftWheelDirection("backward");
  rightWheelDirection("backward");
  delay(mTime);
  leftWheelPower(false);
  rightWheelPower(false);
}

void rotateLeft(int mTime){
  leftWheelPower(true);
  rightWheelPower(true);
  leftWheelDirection("backward");
  rightWheelDirection("forward");
  delay(mTime);
  leftWheelPower(false);
  rightWheelPower(false);
}

void rotateRight(int mTime){
  leftWheelPower(true);
  rightWheelPower(true);
  leftWheelDirection("forward");
  rightWheelDirection("backward");
  delay(mTime);
  leftWheelPower(false);
  rightWheelPower(false);
}



