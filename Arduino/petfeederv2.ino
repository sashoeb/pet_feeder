#include<Servo.h>

Servo servo;
const int LED_PIN =  LED_BUILTIN;// the number of the LED pin
int SERVO_PIN = 9;
int CLOSE_ANGLE = 0;
int OPEN_ANGLE = 180;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(LED_PIN,OUTPUT);
  servo.attach(SERVO_PIN);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available()){
    char c = Serial.read();
    switch(c){
      case 'a' : digitalWrite(LED_PIN,HIGH);
                 dispense_treat();
                 break;
      case 'b' : digitalWrite(LED_PIN,LOW);
                 delay(1000);
                 break;  
      default : digitalWrite(LED_PIN,LOW);
                break;
    }
  }  
}

void dispense_treat(){
    open_door();
    delay(1000);
    close_door();
}

void open_door(){
  Serial.println("Opened Door");
  servo.write(OPEN_ANGLE);
}

void close_door(){
  Serial.println("Closed Door");
  servo.write(CLOSE_ANGLE);  
}
