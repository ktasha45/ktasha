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
  Serial.begin(9600);
  mySerial.begin(9600);
}

void loop() {
  if (mySerial.available()) {
    a1 = char(mySerial.read());
    Serial.write(a1);
    if(a1 == 'L'){
      digitalWrite(4, HIGH);
      digitalWrite(5, LOW);
      delay(10);
    }
    else if(a1 == 'F'){
      digitalWrite(6, LOW);
      digitalWrite(7, HIGH);
      delay(!0);
    }
    else if(a1 == 'S'){
      digitalWrite(6, LOW);
      digitalWrite(7, LOW);
      delay(10);
    }
    else if(a1 == 'G'){
      digitalWrite(6, HIGH);
      digitalWrite(7, LOW);
      analogWrite(10, 255);
      delay(10);
    }
    else{
      digitalWrite(6, LOW);
      digitalWrite(7, LOW);
      digitalWrite(4, LOW);
      digitalWrite(5, LOW);
    }
    a1 = "";
  }
}
