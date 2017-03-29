#include <Servo.h>

Servo weaponServo;

const byte inputPins[] = {8, 9, 10};
const int mins[] =  {1024, 1024, 1024};
const int maxes[] = {1960, 1960, 1960};

volatile float input1 = 0;
volatile float input2 = 0;
volatile float input3 = 0;

volatile long numMsg = 0;

#include "PinChangeInt.h"

#include "battlebot_interrupts.h"

void setup() {
  // put your setup code here, to run once:
  pinMode(inputPins[0], INPUT_PULLUP);
  attachPinChangeInterrupt(inputPins[0], input1Interrupt, CHANGE);
  pinMode(inputPins[1], INPUT_PULLUP);
  attachPinChangeInterrupt(inputPins[1], input2Interrupt, CHANGE);
  pinMode(inputPins[2], INPUT_PULLUP);
  attachPinChangeInterrupt(inputPins[2], input3Interrupt, CHANGE);

  pinMoode(9, OUTPUT);
  pinMoode(10, OUTPUT);
  pinMoode(11, OUTPUT);
  pinMoode(12, OUTPUT);
  pinMoode(13, OUTPUT);
  
  weaponServo.attach(14);
  
  Serial.begin(9600);
}


void loop() {
  // put your main code here, to run repeatedly:
  static int i = 0;
  i++;
  delay(10);

  float forward = input1;
  float turn = input2;
  float weapon = input3;

  float left = forward + turn;
  float right = forward - turn;

  driveMotors(left, right);

  weaponServo.write(180*weapon);

  if (i%20 == 0)
    printRadioData();
}

void driveMotors(float leftPow, float rightPow){
  // Inputs constrained to be in range -1...1
  leftPow = constrain(leftPow, -1.0, 1.0);
  rightPow = constrain(rightPow, -1.0, 1.0);
  bool leftDir = leftPow > 0;
  bool rightDir = rightPow > 0;

  digitalWrite(8, leftDir);
  digitalWrite(9, !leftDir);
  
  digitalWrite(10, rightDir);
  digitalWrite(11, !rightDir);

  analogWrite(12, abs(255 * leftPow));
  analogWrite(13, abs(255 * rightPow));
}

void printRadioData() {
  Serial.print("Number of messages recieved: ");
  Serial.println(numMsg);
  Serial.print("inputs: ");
  Serial.print(input1);
  Serial.print("\t\t"); Serial.print(input2);
  Serial.print("\t\t"); Serial.print(input3);
  Serial.println();
}

