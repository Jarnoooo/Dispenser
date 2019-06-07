#include <Servo.h>

Servo Servo1; // 10
Servo Servo2; // 50
Servo Servo3; // 100

boolean connection = false;
String java;
int withdr;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Servo1.attach(10);
  Servo2.attach(11);
  Servo3.attach(12);
}

void loop() {
  while(true){
    java = connection_java();
    if(connection == false){
      return;
    }
   st_int(java);
   withdraw(withdr);
  }
}

void st_int (String x){
  withdr = x.toInt();
//  return withdr;
}

String connection_java(){
  if(Serial.available()>0){
    connection = true;
    byte b = Serial.read();  
  }else{
    connection = false;
  }
}

int withdraw(int x){
  int y = x;
  if(y/10 == 1){
    dispenser(1);
    Serial.println(" geld van 1");
  }
  else if(y/50 == 1){
    dispenser(2);
    Serial.println(" geld van 2");
  }
  else if(y/100 == 1){
    dispenser(3);
    Serial.println(" geld van 3");
  }
}

void dispenser(int x){
    switch(x){
      case 1:
        Servo1.write(180);
        delay(1150);
      break;
        
      case 2:
        Servo3.write(180);
        delay(1150);
      break;

      case 3:
        Servo2.write(180);
        delay(1150);
      break;
      return;
  }
}
