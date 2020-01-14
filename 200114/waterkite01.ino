#include <TimerThree.h>
int time1, time2=0;

void setup() {
Serial.begin(250000);
Timer3.initialize(10000);
Timer3.attachInterrupt(tim);
}

void loop() {}

void tim(){
time1=micros();
Serial.println(time1-time2);
time2=time1;
}
