//Interrupt를 이용해 바퀴의 회전방향을 측정 

#include <Balance.h>
Balance BR;
int a=0;
int b=0;
bool ccc=0;

void setup() {
  Serial.begin(500000); BR.Motor_Init(); BR.Gyro_Init();
  Timer3.initialize(10000); Timer3.attachInterrupt(tim);

  attachInterrupt(digitalPinToInterrupt(2), CHA_A, CHANGE); //2번핀과 3번핀이 한 개의 모터에 대한 것이고 18번핀과 19번핀이 또다른 모터에 대한 것인데, 위상들을 보고 정방향인지 역방향인지 판단할 수 있다!
  attachInterrupt(digitalPinToInterrupt(3), CHA_B, CHANGE);
  attachInterrupt(digitalPinToInterrupt(18), CHB_B, CHANGE);
  attachInterrupt(digitalPinToInterrupt(19), CHB_A, CHANGE);
  
  BR.Motor(-255, -255);
}

void loop() {
if(ccc==1) {ccc=0;
  int vl=a, vr=b; a=0; b=0; //vl과 vr에 a와 b값을 저장하자마자 a와 b값을 리셋할 수 있음
  Serial.print(vl); Serial.print(" "); Serial.println(vr);
  //위의 int vl=a, vr=b; a=0; b=0; 명령어 대신 여기에 a=0; b=0;을 해도 a와 b값을 리셋할 수 있긴 하지만 이것보다 위에 했던것이 더 좋은 명령어!
  }
}

void CHA_A () {
  bool p1 = digitalRead(2), p2 = digitalRead(3);
  if (p1 == p2) {
    a++; //p1과 p2가 같으면 상이 같다는 뜻이므로 정방향
  }
  else {
    a--;
  }
}

void CHA_B () {
  bool p1 = digitalRead(2), p2 = digitalRead(3);
  if (p1 == p2) {
    a--;
  }
  else {
    a++;
  }
}

void CHB_A () {
  bool p1 = digitalRead(18), p2 = digitalRead(19);
  if (p1 == p2) { 
    b--;
  }
  else {
    b++;
  }
}

void CHB_B () {
  bool p1 = digitalRead(18), p2 = digitalRead(19);
  if (p1 == p2) {
    b++;
  }
  else {
    //Serial.println("2+"); 
    b--;
  }
}

void tim() { ccc=1; 
}
