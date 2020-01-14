#include <TimerThree.h>
int LED=0;

void setup() {
pinMode(4,OUTPUT);
Timer3.initialize(10000);
Timer3.attachInterrupt(tim);
}

void loop() {}

void tim(){
LED++;
if (LED>19)
{LED=0; digitalWrite(4,!digitalRead(4));}
}


/*voidsetup() {
pinMode(4,OUTPUT);}

void loop(){
digitalWrite(4,HIGH); delay(500);
digitalWrite(4,LOW); delay(500);

delay와 Timer의 차이
delay는 delay가 되는 그 시간동안 아무 것도 행동하지 못한다.
Timer는 하는 일을 하다 특정 주기가 이르는 시간에 Timer에 해당해놓은 함수를 실행한다.
*/
