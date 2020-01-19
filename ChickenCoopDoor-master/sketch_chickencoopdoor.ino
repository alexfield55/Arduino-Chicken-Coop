#ifndef chickencoopdoor_data_h
  #define chickencoopdoor_data_h
  #include "chickencoopdoor_data.h"
#endif

LightData lightState;

void setup() {
  pinMode(StepperPin1, OUTPUT); // each output pin can provide ~40mA of current to external hardware
  pinMode(StepperPin2, OUTPUT);
  lightState.lightLevel = 0; // assume dark
}

 unsigned int AnalogValue;

void loop() 
{
  unsigned int l = readLight();
  if(l != -1) {
    // dark to light
    if(lightState.lightLevel == 0 && lightState.lightLevel != l) {
      TurnCounterClockwise();
      lightState.lightLevel = l;
      delay(3000);
      StopTurn();
    }
    // light to dark
      if(lightState.lightLevel == 1 && lightState.lightLevel != l) {
      TurnClockwise();
      lightState.lightLevel = l;
      delay(3000);
      StopTurn();
    }
  }
}

void TurnClockwise() {
  digitalWrite(StepperPin1, HIGH);
  digitalWrite(StepperPin2, LOW);
}

void TurnCounterClockwise() {
  digitalWrite(StepperPin1, LOW);
  digitalWrite(StepperPin2, HIGH);  
}

void StopTurn() {
  digitalWrite(StepperPin1, LOW);
  digitalWrite(StepperPin2, LOW);  
}

int readLight() {
  int d = analogRead(DaylightPin); // 1 read takes ~100 microseconds
  if(d > LightMidpoint) {
    return 1; // light;
  } else if(d < LightMidpoint) {
    return 0; // no light
  } else { return -1; }
}

