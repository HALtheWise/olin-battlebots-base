
const byte inputPins[] = {51, 52, 53};
const int mins[] =  {1024, 0, 0};
const int maxes[] = {1960, 1, 1};

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
  Serial.begin(9600);
}


void loop() {
  // put your main code here, to run repeatedly:
  delay(100);
  printRadioData();
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

