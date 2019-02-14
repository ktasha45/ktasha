#include <SoftwareSerial.h>
#include <Servo.h>
#include <String.h>

SoftwareSerial mySerial(8, 9);
char a1;

void setup() {
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);

  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);

  pinMode(10, OUTPUT); //ena
  pinMode(11, OUTPUT); //enb
  Serial.begin(9600);
  mySerial.begin(9600);
}

int Speed = 0;
int RotationCoefficient = 128;
void Exceleration(){
  Speed++;
  digitalWrite(6, LOW);
  digitalWrite(7, HIGH);
  analogWrite(10, Speed);
}

void Break(){
  Speed--; 
  digitalWrite(6, LOW);
  digitalWrite(7, HIGH);
  analogWrite(10, Speed);
}

void Left(){
  RotationCoefficient++;
  digitalWrite(4, HIGH);
  digitalWrite(5, LOW);
  analogWrite(11. RotationCoefficient);
}

void Right(){
  RotationCoefficient--;
  digitalWrite(4, HIGH);
  digitalWrite(5, LOW);
  analogWrite(11, RotationCoefficient);
}

void Stop(){
  Speed = 0;
}

void loop() {
  if (mySerial.available()) {
    a1 = char(mySerial.read());
    Serial.write(a1);
  }

  switch(a1){
    case F:
      Exceleration();
      break;
    case G:
      Break();
      break;
    case L:
      Left();
      break;
    case R:
      Right();
      break;
    case S:
    
    default:
      break;
  }


  
 /* else if (a1 == 'S') {
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
  }
  else {
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
  }*/

}
