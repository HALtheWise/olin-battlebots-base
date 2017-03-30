/* 
 *  
 *  This file is full of ugly copy-pasted code. I am sorry. Improvements to come.
 *  
 */


#define MIN_MICROS 0
#define MAX_MICROS 35000

void input1Interrupt() {
  const byte id = 0;
  static long lastRiseTime = 0;
  numMsg++;
  bool state = digitalRead(inputPins[id]);
  long now = micros();
  if (state == HIGH){
    lastRiseTime = now;
  } else {
    long dt = now - lastRiseTime;
    if (dt < MIN_MICROS || dt > MAX_MICROS || lastRiseTime == 0){
      // The data is probably corrupt
      return;
    }
    lastRiseTime = 0;
    
    input1 = float(dt - mins[id])/(maxes[id]-mins[id]);
  }
}

void input2Interrupt() {
  const byte id = 1;
  static long lastRiseTime = 0;
  numMsg++;
  bool state = digitalRead(inputPins[id]);
  long now = micros();
  if (state == HIGH){
    lastRiseTime = now;
  } else {
    long dt = now - lastRiseTime;
    if (dt < MIN_MICROS || dt > MAX_MICROS || lastRiseTime == 0){
      // The data is probably corrupt
      return;
    }
    lastRiseTime = 0;
    
    input2 = float(dt - mins[id])/(maxes[id]-mins[id]);
  }
}

void input3Interrupt() {
  const byte id = 2;
  static long lastRiseTime = 0;
  numMsg++;
  bool state = digitalRead(inputPins[id]);
  long now = micros();
  if (state == HIGH){
    lastRiseTime = now;
  } else {
    long dt = now - lastRiseTime;
    if (dt < MIN_MICROS || dt > MAX_MICROS || lastRiseTime == 0){
      // The data is probably corrupt
      return;
    }
    lastRiseTime = 0;
    
    input3 = float(dt - mins[id])/(maxes[id]-mins[id]);
  }
}
