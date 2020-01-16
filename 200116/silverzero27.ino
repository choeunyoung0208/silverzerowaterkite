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
}

void loop() {}

void CHA_A () {
  bool p1 = digitalRead(2), p2 = digitalRead(3);
  if (p1 == p2) {
    //Serial.println("1+"); 
    a=a-1; //p1과 p2가 같으면 상이 같다는 뜻이므로 정방향
  }
  else {
    //Serial.println("1-"); 
    a=a+1;
  }
}

void CHA_B () {
  bool p1 = digitalRead(2), p2 = digitalRead(3);
  if (p1 == p2) {
    //Serial.println("1-"); 
    a=a+1;
  }
  else {
    //Serial.println("1+"); 
    a=a-1;
  }
}

void CHB_A () {
  bool p1 = digitalRead(18), p2 = digitalRead(19);
  if (p1 == p2) {
    //Serial.println("2+"); 
    b=b-1;
  }
  else {
    //Serial.println("2-"); 
    b=b+1;
  }
}

void CHB_B () {
  bool p1 = digitalRead(18), p2 = digitalRead(19);
  if (p1 == p2) {
    //Serial.println("2-"); 
    b=b+1;
  }
  else {
    //Serial.println("2+"); 
    b=b-1;
  }
}

void tim() { ccc=1; 
Serial.print(a); Serial.print("  ");
Serial.println(b);
a=0;
b=0;
}
