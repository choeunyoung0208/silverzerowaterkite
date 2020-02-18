#클래스


#클래스 생성하기
#class 클래스명 :
#    #이 부분에 관련 코드 구현

#클래스 안에서 선언된 변수는 필드(Field)라고 함
#클래스 안에서 구현된 함수는 함수라고 하지 않고 메서드(Method)라고 함





#1. 자동차 클래스 만들기
class Car : #Car라는 이름의 클래스를 생성
    #자동차의 필드
    color="" #자동차의 색상을 결정해주는 필드 생성
    speed=0 #자동차의 현재 속도를 결정해주는 필드 생성

    #자동차의 메서드
    def upSpeed(self, value) : #자동차의 속도를 증가시키는 메서드 생성
        #27행의 self.speed를 사용하기 위해서 메서드 upSpeed의 매개변수로 self를 받아야 함. (매개변수 self는 실제로 전달받지는 않고 value값만 전달받음)
        #메서드 upSpeed의 매개변수 중 하나인 self는 클래스 자신을 가리킴.
        #27행의 self.speed는 19행의 speed를 의미함(자신의 클래스에 있는 speed 변수라고 생각하면 됨)

        self.speed += value

    def downSpeed(self, value) : #자동차의 속도를 감소시키는 메서드 생성
        self.speed -= value

#★결과
#아무것도 나오지 않음 => 왜냐하면 클래스를 만든것일뿐 사용한 것은 아니기 때문!

#+추가
#메서드의 첫 번째 매개변수로 self를 사용하는 이유 : 메서드 안에서 필드(위에서 보면 color, speed변수)에 접근하기 위해서!
#따라서 메서드 안에서 필드에 접근할 일이 없다면 self는 생략이 가능함





#2. 인스턴스 생성하기
#위에서 자동차 클래스를 생성한 것은 자동차 설계도를 그린 것과 비슷함 => 실제로 작동하는 자동차를 만든 것은 아님
#실제로 작동하는 자동차를 만드는 것을 인스턴스를 생성한 것이라고 생각하면 된다!
#인스턴스를 객체라고도 함

#위의 설계도(위에서 만든 클래스)를 바탕으로 자동차(인스턴스)를 생성
myCar1=Car()
myCar2=Car()
myCar3=Car() #세 대의 자동차(인스턴스)를 생성
#만들어진 인스턴스 각각에는 color, speed 필드를 별도로 가지고 있음





#3. 필드에 값 대입하기
#위에서 생성한 각 인스턴스에는 별도의 필드가 존재하며, 각각 별도의 값을 대입할 수 있음

#'인스턴스명.필드명 = 값' 형식으로 값 대입 가능

myCar1.color="빨강"
myCar1.speed=0
myCar2.color="초록"
myCar2.speed=30
myCar3.color="파랑"
myCar3.speed=60





#4. 메서드 호출하기
#메서드 또한 각 인스턴스마다 별도로 존재함

#'인스턴스명.메서드명()' 형식으로 메서드 호출 가능

myCar1.upSpeed(30) #속도를 30만큼 증가
myCar2.downSpeed(60) #속도를 60만큼 감소





#5. 위에서 부분적으로 작성한 코드들을 바탕으로 클래스의 완전한 작동 구현하기

#클래스 생성
class Car1 : #Car1 클래스 생성
    color="" #자동차의 색상 필드 생성
    speed=0 #자동차의 현재 속도 필드 생성

    def upSpeed(self, value) : #매개변수로 추가 속도(value)를 받아 현재 속도를 value값 만큼 증가시킴
        self.speed +=value

    def downSpeed(self, value) : #매개변수로 추가 속도(value)를 받아 현재 속도를 value값 만큼 감소시킴
        self.speed -=value

#메인 코드
myCar_1=Car1() #Car1클래스를 이용해 myCar_1 인스턴스를 생성
myCar_1.color="빨강" #myCar_1 인스턴스의 color 필드에 값 대입
myCar_1.speed=0 #myCar_1 인스턴스의 speed 필드에 값 대입

myCar_2=Car1() #myCar_2 인스턴스를 생성
myCar_2.color="초록"
myCar_2.speed=0

myCar_3=Car1() #myCar_3 인스턴스를 생성
myCar_3.color="파랑"
myCar_3.speed=0

myCar_1.upSpeed(30) #myCar_1의 speed 필드를 30만큼 증가시킴
print("자동차1의 색상은 %s색이며, 현재 속도는 %d입니다." % (myCar_1.color, myCar_1.speed))

myCar_2.upSpeed(60) #myCar_2의 speed 필드를 60만큼 증가시킴
print("자동차2의 색상은 %s색이며, 현재 속도는 %d입니다." % (myCar_2.color, myCar_2.speed))

myCar_3.downSpeed(0) #myCar_3의 speed 필드를 0만큼 감소시킴
print("자동차3의 색상은 %s색이며, 현재 속도는 %d입니다." % (myCar_3.color, myCar_3.speed))
#★결과
#자동차1의 색상은 빨강색이며, 현재 속도는 30입니다.
#자동차2의 색상은 초록색이며, 현재 속도는 60입니다.
#자동차3의 색상은 파랑색이며, 현재 속도는 0입니다.

#+추가
#클래스를 사용하는 순서
#클래스 생성 -> 인스턴스 생성 -> 필드나 메서드에 값을 대입해 사용





#6. 생성자
#생성자는 인스턴스를 생성하면 무조건 호출되는 메서드임

#인스턴스를 생성하면서 값을 초기화시키는 함수를 생성자 라고 함
#ex) 100행에서 인스턴스를 생성하면서 동시에 '빨강'과 '0'을 필드값에 할당해주는 함수를 생성자!

#생성자는 __init__()라는 이름을 가짐
#init : initialize의 약자로, 초기화 한다는 의미

#생성자의 기본 형태
#class 클래스명 :
#  def __init__(self) :
#     #이 부분에 초기화할 코드 입력

#위에서 생성한 Car1클래스를 이용해 생성자 만들기
class Car1 :
    color = ""
    speed=0

    def __init__(self) : #생성자 만들기
        self.color="빨강"
        self.speed=0

myCar1=Car1() #인스턴스를 생성하면 자동으로 생성자를 호출함
print("자동차1의 색상은 %s색이며, 현재 속도는 %d입니다." % (myCar1.color, myCar1.speed))
#★결과
#자동차1의 색상은 빨강색이며, 현재 속도는 0입니다.





#7. 생성자의 종류
#생성자의 종류로는 기본 생성자, 매개변수가 있는 생성자가 있음
#기본 생성자 : __init__()의 매개변수가 self만 있는 생성자를 기본 생성자라고 함
#매개변수가 있는 생성자 : 생성자도 메서드처럼 매개변수를 사용할 수 있음. self라는 매개변수를 제외한 매개변수가 있는 생성자를 말함.
#                        그리고, 인스턴스를 만들 때 초기값을 매개변수로 넘기는 것도 가능함

#매개변수가 있는 생성자 만들기

#클래스 생성
class Car :
    color=""
    speed=0

    def __init__(self, value1, value2) :
        self.color=value1
        self.speed=value2

    def upSpeed(self, value) :
        self.speed += value

    def downSpeed(self, value) :
        self.speed -= value

#메인 코드
myCar1=Car("빨강", 30)
myCar2=Car("초록", 60)

print("자동차1의 색상은 %s색이며, 현재 속도는 %d입니다." % (myCar1.color, myCar1.speed))
print("자동차2의 색상은 %s색이며, 현재 속도는 %d입니다." % (myCar2.color, myCar2.speed))
#★결과
#자동차1의 색상은 빨강색이며, 현재 속도는 30입니다.
#자동차2의 색상은 초록색이며, 현재 속도는 60입니다.
