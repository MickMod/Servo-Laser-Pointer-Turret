// Servo controlled laser pointer turret.
#include <Servo.h>

Servo Xservo;
Servo Yservo;

String Data;

void setup() {
  Xservo.attach(10);
  Yservo.attach(11);
  Serial.begin(9600);
  Serial.setTimeout(10);
}

void loop() {
  // Not used.
}

void Event(){
  Data = Serial.readString();

  Serial.print("X: ");
  Serial.println(parseX(Data));
  Serial.print("Y: ");
  Serial.println(parseY(Data));
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
