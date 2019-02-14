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

void Exceleration(){
  digitalWrite(4, LOW);
  digitalWrite(5, HIGH);
}

void Break(){
  digitalWrite(4, HIGH);
  digitalWrite(5, LOW);
}

void Left(){
  digitalWrite(6, HIGH);
  digitalWrite(7, LOW);
}

void Right(){
  digitalWrite(7, HIGH);
  digitalWrite(6, LOW);
}

void Stop(){
  digitalWrite(5, LOW);
  digitalWrite(4, LOW);
}

void TStop(){
  digitalWrite(6, LOW);
  digitalWrite(7, LOW);
}

void loop() {
  if (mySerial.available()) {
    a1 = char(mySerial.read());
    
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
    case 'P':
      TStop();
    default:
      break;
  }
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
