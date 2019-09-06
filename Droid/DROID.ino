#include <IRremote.h>
#include <IRremoteInt.h>
#include <boarddefs.h>
#include <ir_Lego_PF_BitStreamEncoder.h>

#include <Servo.h> //servo motor library

int mot1=5;
int mot2=6; 
int mot3=9;
int mot4=10;

const int RED_PIN = 8;
const int GREEN_PIN = 7;
const int BLUE_PIN = 4;

int servoPin = 3;
Servo Servo1;

const int RECV_PIN = 2;
IRrecv irrecv(RECV_PIN);
decode_results results;

void setup()
{
  pinMode(mot1,OUTPUT);
  pinMode(mot2,OUTPUT);
  pinMode(mot3,OUTPUT);
  pinMode(mot4,OUTPUT);
  pinMode(RED_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(BLUE_PIN, OUTPUT);
  Servo1.attach(servoPin);
  Serial.begin(9600);
  irrecv.enableIRIn();
}

// Execute command after receiving IR Input

void loop()
{
  if (irrecv.decode(&results))
    {
     Serial.println(results.value, HEX);
     irrecv.resume(); // Receive the next value
     
   //bot moves front
    if(results.value == 0x40BD48B7)
    {
      digitalWrite(RED_PIN, HIGH);
      digitalWrite(GREEN_PIN, LOW);
      digitalWrite(BLUE_PIN, LOW);
      digitalWrite(mot1,HIGH);
      digitalWrite(mot2,LOW);
      digitalWrite(mot3,HIGH);
      digitalWrite(mot4,LOW);
      delay(1000);
    }
    //bot moves back
    else if(results.value == 0x40BDC837)
    {
      digitalWrite(RED_PIN, LOW);
      digitalWrite(GREEN_PIN, LOW);
      digitalWrite(BLUE_PIN, HIGH);
      digitalWrite(mot1,LOW);
      digitalWrite(mot2,HIGH);
      digitalWrite(mot3,LOW);
      digitalWrite(mot4,HIGH);
      delay(1000);
    }
    //bot moves left
    else if(results.value == 0x40BD8877)
    {
      digitalWrite(RED_PIN, HIGH);
      digitalWrite(GREEN_PIN, HIGH);
      digitalWrite(BLUE_PIN, LOW);
      digitalWrite(mot1,HIGH);
      digitalWrite(mot2,LOW);
      digitalWrite(mot3,LOW);
      digitalWrite(mot4,LOW);
      delay(160);
    }
    //bot moves right
    else if(results.value == 0x40BD08F7)
    {
      digitalWrite(RED_PIN, LOW);
      digitalWrite(GREEN_PIN, HIGH);
      digitalWrite(BLUE_PIN, HIGH);
      digitalWrite(mot1,LOW);
      digitalWrite(mot2,LOW);
      digitalWrite(mot3,HIGH);
      digitalWrite(mot4,LOW);
      delay(160);
    }
    //bot stops
    else if(results.value == 0x40BD50AF)
    {
      digitalWrite(RED_PIN, HIGH);
      digitalWrite(GREEN_PIN, LOW);
      digitalWrite(BLUE_PIN, HIGH);
      digitalWrite(mot1,LOW);
      digitalWrite(mot2,LOW);
      digitalWrite(mot3,LOW);
      digitalWrite(mot4,LOW);
    }
    else if(results.value == 0x40BD00FF)
    {
      digitalWrite(RED_PIN, HIGH);
      digitalWrite(GREEN_PIN, HIGH);
      digitalWrite(BLUE_PIN, HIGH);
      Servo1.write(0);
      delay(1000);
    }
    else if(results.value == 0x40BD807F)
    {
      
      digitalWrite(RED_PIN, HIGH);
      digitalWrite(GREEN_PIN, HIGH);
      digitalWrite(BLUE_PIN, HIGH);
      Servo1.write(45);
      delay(1000);
    }
    else if(results.value == 0x40BD40BF)
    {
      digitalWrite(RED_PIN, HIGH);
      digitalWrite(GREEN_PIN, HIGH);
      digitalWrite(BLUE_PIN, HIGH);
      Servo1.write(90);
      delay(1000);
    }
    else if(results.value == 0x40BDC03F)
    {
      digitalWrite(RED_PIN, HIGH);
      digitalWrite(GREEN_PIN, HIGH);
      digitalWrite(BLUE_PIN, HIGH);
      Servo1.write(135);
      delay(1000);
    }
    else if(results.value == 0x40BD20DF)
    {
      
      digitalWrite(RED_PIN, HIGH);
      digitalWrite(GREEN_PIN, HIGH);
      digitalWrite(BLUE_PIN, HIGH);
      Servo1.write(180);
      delay(1000);
    }
    else if(results.value == 0x40BDA05F)
    {
      digitalWrite(RED_PIN, HIGH);
      digitalWrite(GREEN_PIN, HIGH);
      digitalWrite(BLUE_PIN, HIGH);
      Servo1.write(225);
      delay(1000);
    }
    else if(results.value == 0x40BD609F)
    {
      digitalWrite(RED_PIN, HIGH);
      digitalWrite(GREEN_PIN, HIGH);
      digitalWrite(BLUE_PIN, HIGH);
      Servo1.write(270);
      delay(1000);
    }
    }
}
