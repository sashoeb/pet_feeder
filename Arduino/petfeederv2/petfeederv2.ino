#include<Servo.h>

Servo servo;
const int LED_PIN =  LED_BUILTIN; // The number of the LED pin
int SERVO_PIN = 9;    // The pin which the servo is attached to
int CLOSE_ANGLE = 0;  // The closing angle of the servo motor arm
int OPEN_ANGLE = 60;  // The opening angle of the servo motor arm

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(LED_PIN,OUTPUT);
  servo.attach(SERVO_PIN);
  servo.write(CLOSE_ANGLE); // Close the trapdoor when it first boots up
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available()){
    char c = Serial.read();   // Read data sent by the cloud
    switch(c){
      case 'a' : digitalWrite(LED_PIN,HIGH);  // If character received is 'a', dispense the treat
                 open_door();
                 delay(1000);
                 close_door();
                 digitalWrite(LED_PIN,LOW);
                 break;
      case 'b' : digitalWrite(LED_PIN,LOW);   // If charecter received is 'b', close the trapdoor
                 close_door();
                 break;
      case 'c' : digitalWrite(LED_PIN,HIGH);  // If charecter received is 'c', open the trapdoor
                 open_door();
                 break;  
      default : digitalWrite(LED_PIN,LOW);
                break;
    }
  }  
}

void open_door(){
  Serial.println("Opened Door");
  servo.write(OPEN_ANGLE);   // Send the command to the servo motor to open the trap door
}

void close_door(){
  Serial.println("Closed Door");
  servo.write(CLOSE_ANGLE);   // Send te command to the servo motor to close the trap door
}
