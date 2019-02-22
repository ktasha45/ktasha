#include <SoftwareSerial.h>
#include <Servo.h>
#include <String.h>

SoftwareSerial mySerial(0, 1);
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

void Exceleration() {
  digitalWrite(4, LOW);
  digitalWrite(5, HIGH);
  digitalWrite(6, LOW);
  digitalWrite(7, LOW);
}

void Break() {
  digitalWrite(4, HIGH);
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);
  digitalWrite(7, LOW);
}

void F_L(){
  digitalWrite(4, LOW);
  digitalWrite(5, HIGH);
  digitalWrite(6, HIGH);
  digitalWrite(7, LOW);
}

void F_R(){
  digitalWrite(4, LOW);
  digitalWrite(5, HIGH);
  digitalWrite(6, LOW);
  digitalWrite(7, HIGH);
}

void B_R(){
  digitalWrite(4, HIGH);
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);
  digitalWrite(7, HIGH);
}

void B_L(){
  digitalWrite(4, HIGH);
  digitalWrite(5, LOW);
  digitalWrite(6, HIGH);
  digitalWrite(7, LOW);
}

void Left() {
  digitalWrite(6, HIGH);
  digitalWrite(7, LOW);
}

void Right() {
  digitalWrite(6, LOW);
  digitalWrite(7, HIGH);
}

void Stop() {
  digitalWrite(5, LOW);
  digitalWrite(4, LOW);
}

void loop() {
  if(mySerial.available() > 0){
    char a1 = char(mySerial.read());
    if(a1 !='\n'){
     Serial.print(a1);
    }
    else{
      a1 = '\0';
    }
      
    switch(a1){
      case 'F':
       Exceleration();
        break;
     case 'G':
       Break();
       break;
     case 'L':
       Left();
        break;
     case 'R':
       Right();
        break;
     case 'S':
       Stop();
       break; 
     case 'Q':
       F_L();
       break;
     case 'E':
       F_R();
       break;
     case 'Z':
       B_L();
       break;
     case 'C':
       B_R();
       break;
     default:
       break;
  }
  }
}


// i love inging
