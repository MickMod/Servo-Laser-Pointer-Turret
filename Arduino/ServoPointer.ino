// Servo controlled laser pointer turret.
#include <Servo.h>

Servo Xservo;
Servo Yservo;

String Data;

void setup() {
  pinMode(9, OUTPUT); //5V for second servo, remove if your Arduino has two 5V outputs.
  Xservo.attach(10); //Y-rotation
  Yservo.attach(11); //X-rotation
  Serial.begin(9600);
  Serial.setTimeout(10);
}

void loop() {
  digitalWrite(9, HIGH); //5V for second servo, remove if your Arduino has two 5V outputs.
}

void Event(){
  Data = Serial.readString();
  Xservo.write(parseX(Data));
  Yservo.write(parseY(Data));
}

int parseX(String data){
  data.remove(data.indexOf("Y"));
  data.remove(data.indexOf("X"), 1);
  return data.toInt();
}

int parseY(String data){
  data.remove(0, data.indexOf("Y") + 1);
  return data.toInt();
}
