#include <Servo.h>

int posS1 = 90;         // variable to store the bottom servo position
int posS2 = 0;         // variable to store the top servo position
int posS1i = 90;        // servo 1 initial position for bottom
int posS2i = 0;      // servo 2 initial position for top
int incomingByte = 0;  // for incoming serial data
int structure = 0;  // for incoming serial data to select character
int currentPosS1;      //current position servo bottom
int currentPosS2;      //current position servo top
char Input;

Servo servo_bottom;  // create servo object to control a servo. A maximum of eight servo objects can be created 
Servo servo_top;

void setup()
{
  Serial.begin(9600);
  Serial.println("Program booting up...");

  //Setup the Servo motors at respective pins
  servo_bottom.attach(9);
  servo_top.attach(10);

  //Reset the servo motors to default position
  servo_bottom.write(posS1i);
  servo_top.write(posS2i);

  //Setup the LEDs at respective pins
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);

  //Select what you want to work with
  Serial.println("Please select 1-Structure or 2-Character");
  while(Serial.available() <= 0) {}
  structure = Serial.read();
  digitalWrite(2, HIGH);
  Serial.println("Setup Complete!");
}

/* ascii codes for the keys to de used:
   a = 97
   s= 115
   d = 100
   w = 119
   x = 120
   1 = 49
   2 = 50
*/

void loop()
{

  if(structure == 49)
  {
    
//    Serial.println("You Selected the Structure");
    //read the incoming byte
    if(Serial.available() > 0)
    {
      incomingByte = Serial.read();
  
      //make the servo motors move
      switch(incomingByte){
        case 97:
          Input = 'a';
          if(posS1 >= 180)
            posS1 = 170;
          posS1 +=10;
          servo_bottom.write(posS1);
          currentPosS1 = servo_bottom.read();
          Serial.println("I received: " + (String)Input);
          Serial.println("Servo bottom position: " + (String)currentPosS1);
          break;
        case 100:
          Input = 'd';
          if(posS1 <= 0)
            posS1 = 10;
          posS1 -=10;
          servo_bottom.write(posS1);
          currentPosS1 = servo_bottom.read();
          Serial.println("I received: " + (String)Input);
          Serial.println("Servo bottom position: " + (String)currentPosS1);
          break;
        case 115:
          Input = 's';
          if(posS2 <= 0)
            posS2 = 15;
          posS2 -=15;
          servo_top.write(posS2);
          currentPosS2 = servo_top.read();
          Serial.println("I received: " + (String)Input);
          Serial.println("Servo top position set: " + (String)posS2);
          Serial.println("Servo top position: " + (String)currentPosS2);
          break;
        case 119:
          Input = 'w';
          if(posS2 >= 45)
            posS2 = 30;
          posS2 +=15;
          servo_top.write(posS2);
          currentPosS2 = servo_top.read();
          Serial.println("I received: " + (String)Input);
          Serial.println("Servo top position set: " + (String)posS2);
          Serial.println("Servo top position: " + (String)currentPosS2);
          break;
        case 120:
          Input = 'x';
          Serial.println("I received: " + (String)Input);
          Serial.println("Reset servo to default position");
          servo_bottom.write(posS1i);
          servo_top.write(posS2i);
          posS1 = 90;
          posS2 = 0;
          currentPosS1 = servo_bottom.read();
          currentPosS2 = servo_top.read();
          break;
        default:
          incomingByte = 0;
      }
      
      //Control the LEDs
      if(currentPosS2 == 0)
      {
        digitalWrite(3, LOW);
        digitalWrite(4, LOW);
        digitalWrite(5, LOW);
      }
      if(currentPosS2 == 15)
      {
        digitalWrite(3, LOW);
        digitalWrite(4, LOW);
        digitalWrite(5, HIGH);
      }
      else if(currentPosS2 == 30)
      {
        digitalWrite(3, LOW);
        digitalWrite(4, HIGH);
        digitalWrite(5, LOW);
      }
      else if(currentPosS2 == 45)
      {
        digitalWrite(3, HIGH);
        digitalWrite(4, LOW);
        digitalWrite(5, LOW);
      }
    }
  }
  else if(structure == 50)
  {
    if(Serial.available() > 0)
    {
      incomingByte = Serial.read();
  
      //make the servo motors move
      switch(incomingByte){
        case 97:
          Input = 'a';
          if(posS1 >= 180)
            posS1 = 170;
          posS1 +=10;
          servo_bottom.write(posS1);
          currentPosS1 = servo_bottom.read();
          Serial.println("I received: " + (String)Input);
          Serial.println("Servo bottom position: " + (String)currentPosS1);
          break;
        case 100:
          Input = 'd';
          if(posS1 <= 0)
            posS1 = 10;
          posS1 -=10;
          servo_bottom.write(posS1);
          currentPosS1 = servo_bottom.read();
          Serial.println("I received: " + (String)Input);
          Serial.println("Servo bottom position: " + (String)currentPosS1);
          break;
        case 115:
          Input = 's';
          if(posS2 <= 0)
            posS2 = 15;
          posS2 -=15;
          servo_top.write(posS2);
          currentPosS2 = servo_top.read();
          Serial.println("I received: " + (String)Input);
          Serial.println("Servo top position set: " + (String)posS2);
          Serial.println("Servo top position: " + (String)currentPosS2);
          break;
        case 119:
          Input = 'w';
          if(posS2 >= 45)
            posS2 = 30;
          posS2 +=15;
          servo_top.write(posS2);
          currentPosS2 = servo_top.read();
          Serial.println("I received: " + (String)Input);
          Serial.println("Servo top position set: " + (String)posS2);
          Serial.println("Servo top position: " + (String)currentPosS2);
          break;
        case 120:
          Input = 'x';
          Serial.println("I received: " + (String)Input);
          Serial.println("Reset servo to default position");
          servo_bottom.write(posS1i);
          servo_top.write(posS2i);
          posS1 = 90;
          posS2 = 0;
          currentPosS1 = servo_bottom.read();
          currentPosS2 = servo_top.read();
          break;
        default:
          incomingByte = 0;
      }
  
      //Control the LEDs
      if(currentPosS2 < 45)
      {
        digitalWrite(3, LOW);
        digitalWrite(4, LOW);
//        digitalWrite(5, LOW);
      }
      else if(currentPosS2 >= 45)
      {
        digitalWrite(3, HIGH);
        digitalWrite(4, HIGH);
//        digitalWrite(5, LOW);
      }
    }
  }
  else
    Serial.println("Only 1 & 2 numbers are allowed. \n PLEASE REUPLOAD THE PROJECT.");
}

