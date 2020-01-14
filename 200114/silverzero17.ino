//초기 주기를 0.1s로 고정하면서 주기를 0.2s로 바꾸기(1)

#include <TimerThree.h>
int LED=0;

void setup() {
  Serial.begin(250000); 
  pinMode(4, OUTPUT);
  Timer3.initialize(100000);
  Timer3.attachInterrupt(tim);
}

void loop() {
}

void tim() { 
  LED++; // LED=LED+1과 같음
  if (LED<20) {digitalWrite(4, HIGH);}
  else {digitalWrite(4, LOW); if(LED>39) {LED=0;} }
}
