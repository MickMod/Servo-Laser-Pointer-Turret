// Servo controlled laser pointer turret.
#include<Servo.h>

Servo serX;
Servo serY;

String serialData;

void setup() {
  pinMode(9, OUTPUT); //5V for second servo
  serX.attach(10); //Pan servo
  serY.attach(11); //Tilt servo
  Serial.begin(9600);
  Serial.setTimeout(10);
}

void loop() {
  digitalWrite(9, HIGH); //5V for second servo
}

void serialEvent() {
  serialData = Serial.readString();
  serX.write(parseDataX(serialData));
  serY.write(parseDataY(serialData));
  
  Serial.print("X: ");
  Serial.println(parseDataX(serialData));
  Serial.print("Y: ");
  Serial.println(parseDataY(serialData));
}

int parseDataX(String data){
  data.remove(data.indexOf("Y"));
  data.remove(data.indexOf("X"), 1);
  return data.toInt();
}

int parseDataY(String data){
  data.remove(0,data.indexOf("Y") + 1);
  return data.toInt();
}