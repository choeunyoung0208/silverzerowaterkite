#함수
#함수는 파이썬 자체에서 제공하는 함수와 사용자가 직접 만들어서 사용하는 함수가 있음

#파이썬에서 제공하는 함수는 '함수명()' 의 형식으로 사용함
#ex) print() => print("a")

#사용자가 함수를 직접 만들어서 사용할 때는 아래와 같이 정의하여 사용함
#def 함수이름(매개변수) :
#    명령어
#ex) def func_test(num):
#      print("test")





#1. 커피 자판기 프로그램

#전역 변수 선언
coffee=0

#함수 정의
def coffee_machine(button) :
    if button==1 :
        print("아메리카노 나왔습니다.")
    elif button==2 :
        print("카페라떼 나왔습니다.")
    elif button==3 :
        print("에스프레소 나왔습니다.")
    elif button==4 :
        print("취소 되었습니다.")
    else :
        print("잘못 누르셨습니다. 다시 선택해주세요.")

#메인 코드
while (1) : #while True : 도 사용 가능(이게 일반적)
    button=int(input("어떤 커피 드릴까요? (1: 아메리카노, 2: 카페라떼, 3: 에스프레소, 4: 취소)"))
    if button==4 :
        coffee_machine(button)
        break
    else :
        coffee_machine(button)

#★결과
#어떤 커피 드릴까요? (1: 아메리카노, 2: 카페라떼, 3: 에스프레소, 4: 취소)1
#아메리카노 나왔습니다.
#어떤 커피 드릴까요? (1: 아메리카노, 2: 카페라떼, 3: 에스프레소, 4: 취소)2
#카페라떼 나왔습니다.
#어떤 커피 드릴까요? (1: 아메리카노, 2: 카페라떼, 3: 에스프레소, 4: 취소)5
#잘못 누르셨습니다. 다시 선택해주세요.
#어떤 커피 드릴까요? (1: 아메리카노, 2: 카페라떼, 3: 에스프레소, 4: 취소)4
#취소 되었습니다.





#2. 숫자 두개를 덧셈, 뺄셈, 곱셈, 나눗셈 해주는 계산기

#함수 정의
def option(op) :
    if op=='+' :
        print("덧셈 연산.")
    elif op=='-' :
        print("뺄셈 연산.")
    elif op=='*' :
        print("곱셈 연산.")
    elif op=='/' :
        print("나눗셈 연산.")
    else :
        print("다시 입력해주세요.")
        op = input("연산 종류를 입력하세요.(+, -, *, /) : ")

def cal(a1, a2, op) :
    result=0
    while True :
        if op=='+' :
            result=a1+a2
            print("결과는 %s 입니다." % result)
            return result
        elif op=='-' :
            result=a1-a2
            print("결과는 %s 입니다." % result)
            return result
        elif op=='*' :
            result=a1*a2
            print("결과는 %s 입니다." % result)
            return result
        elif op=='/' :
            if a2==0 :
                print("0으로는 나눌 수 없습니다.")
                break
            else :
                result=a1/a2
                print("결과는 %s 입니다." % result)
                return result
        else :
            print("연산 입력이 잘못되었습니다. 다시 시도해주세요.")
            break


#전역 변수 선언
ans=0

#메인 코드
while True :
    start=input("계산기를 실행하시겠습니까? [y/n] : ")
    if start=='y':
        option = input("연산 종류를 입력하세요.(+, -, *, /) : ")
        input1=int(input("첫 번째 수를 입력하세요. : "))
        input2=int(input("두 번째 수를 입력하세요. : "))
        ans=cal(input1, input2, option)
    elif start=='n' :
        print("실행이 취소되었습니다.")
        break
    else :
        print("다시 입력해주세요.")

#★결과
#계산기를 실행하시겠습니까? [y/n] : ㅛ
#다시 입력해주세요.
#계산기를 실행하시겠습니까? [y/n] : y
#연산 종류를 입력하세요.(+, -, *, /) : +
#첫 번째 수를 입력하세요. : 1
#두 번째 수를 입력하세요. : 2
#결과는 3 입니다.
#계산기를 실행하시겠습니까? [y/n] : y
#연산 종류를 입력하세요.(+, -, *, /) : /
#첫 번째 수를 입력하세요. : 5
#두 번째 수를 입력하세요. : 4
#결과는 1.25 입니다.
#계산기를 실행하시겠습니까? [y/n] : y
#연산 종류를 입력하세요.(+, -, *, /) : /
#첫 번째 수를 입력하세요. : 2
#두 번째 수를 입력하세요. : 0
#0으로는 나눌 수 없습니다.
#계산기를 실행하시겠습니까? [y/n] : y
#연산 종류를 입력하세요.(+, -, *, /) : p
#첫 번째 수를 입력하세요. : 1
#두 번째 수를 입력하세요. : 2
#연산 입력이 잘못되었습니다. 다시 시도해주세요.
#계산기를 실행하시겠습니까? [y/n] : n
#실행이 취소되었습니다.





#지역 변수와 전역 변수
#지역 변수 : 함수 안에서만 사용하는 변수
#전역 변수 : 함수 밖에서도 사용할 수 있는 변수.

#한 프로그램내에서 지역 변수와 전역 변수의 이름이 같을 경우
#1. 함수 안에 변수가 선언되어 있으면 그 함수 안의 변수는 지역 변수
#2. 함수 안에 변수가 선언되어 있지 않으면 그 함수 안의 변수는 전역 변수
#밑에서 자세히..





#3. 지역 변수, 전역 변수 판단

#함수 정의
def func1() :
    a=10 #지역 변수 선언
    print("func1()에서 a 값 : %d " % a)

def func2() :
    print("func2()에서 a 값 : %d " % a)

#전역 변수 선언
a=20

#메인 코드
func1() #func1() 함수 안에는 a라는 변수를 선언해주므로 지역 변수 a의 값이 출력됨
func2() #func2() 함수 안에는 a라는 변수를 선언해주지 않고 그냥 출력만 하고 있으므로 전역 변수 a의 값이 출력됨

#★결과
#func1()에서 a 값 : 10
#func2()에서 a 값 : 20

#+추가
#173행의 전역 변수가 없다면, func2()함수가 오류가 남을 확인할 수 있었습니당




#4. global 예약어
#함수 안에서 사용되는 변수를 지역 변수 대신 전역 변수로 사용하고 싶을 때 사용함
#함수 안에서 global이라는 예약어로 전역 변수임을 알려주면 된다!

#함수 정의
def func1() :
    global a #func1() 함수 안에서 변수 a는 전역변수
    a=10
    print("func1()에서 a값 : %d " % a)

def func2() :
    print("func2()에서 a값 %d " % a)

#전역 변수 선언
a=20

#메인 코드
func1()
func2()

#196행에서 전역 변수 a를 10으로 변경해주므로, 메인 코드 부분의 func1()과 func2()에서 a의 값이 10으로 출력됨
#★결과
#func1()에서 a값 : 10
#func2()에서 a값 10






#5. 함수의 반환값
#함수는 크게 반환값이 있는 함수와 반환값이 없는 함수로 나눌 수 있음

#반환값이 있는 함수
#값을 반환할 때 'return 반환값'형식으로 표현함

#반환값이 없는 함수
#return 문을 생략하거나 반환값 없이 'return'만 입력함


#5-1) 반환값이 없거나 하나만 있을때

#함수 정의
def func1() :
    result=100
    return result

def func2() :
    print("반환값이 없는 함수 실행1")

def func3() :
    print("반환값이 없는 함수 실행2")
    return

#전역 변수 선언
a=0

#메인 코드
a=func1() #func1() 함수를 실행한 후, 반환값을 a에 할당
print("func1()에서 돌려준 값 : %d " % a)

func2()
func3()
#★결과
#func1()에서 돌려준 값 : 100
#반환값이 없는 함수 실행1
#반환값이 없는 함수 실행2


#5-2) 반환값이 여러 개 있을때
#리스트에 반환할 값을 넣은 후 리스트를 반환하면 된다! (리스트에 아무리 많은 데이터를 넣더라도 결국 리스트 1개를 반환하는 것이므로)

#함수 정의
def multi(v1, v2) :
    returnList=[] #반환할 리스트
    res1=v1+v2
    res2=v1-v2
    returnList.append(res1)
    returnList.append(res2)
    return returnList

#전역 변수 선언
List=[]
List1, List2=0, 0

#메인 코드
List=multi(10, 20)
List1=List[0]
List2=List[1]
print("multi()함수에서 돌려준 값 : %d, %d " % (List1, List2))

#★결과
#multi()함수에서 돌려준 값 : 30, -10

#+추가
#파이썬은 여러 개의 값을 반환하는 문법을 허용함.
#=> 266~268행을 return res1, res2로 변경할 수 있음 (이때 내부적으로는 튜플로 구성되어 반환됨)
#★결과
#multi()함수에서 돌려준 값 : 30, -10





#6. pass 예약어
#함수를 구현할 때 이름만 만들어 놓고 내용은 pass 예약어를 사용해 비울 수 있음

#6-1) 함수에서 pass 예약어 사용
def myFunc():
    pass

#함수뿐만 아니라 if문이나 반복문에서도 내용을 비워두고 싶을때 pass예약어를 사용할 수 있음

#6-2) if문에서 pass 예약어 사용
if True :
    pass #True일때 내용을 빈 줄로 두면 문법의 오류가 생김
else :
    print("거짓.")





#7. 함수의 매개변수 전달
#함수의 매개변수를 전달하는 방법(3가지) : 매개변수 개수를 정확히 지정해서 전달하는 방법, 매개변수에 기본값을 설정해 놓고 전달하는 방법,
# 매개변수 개수를 지정하지 않고 전달하는 방법

#7-1) 매개변수의 개수를 지정해둔 뒤 전달하는 방법
#=> 매개변수의 개수를 지정해 놓으면 정확히 매개변수의 개수에 맞추어 호출해야 함

#함수 정의
def para2_func(v1, v2) :
    result=0
    result=v1+v2
    return result

def para3_func(v1, v2, v3) :
    result=0
    result=v1+v2+v3
    return result

#전역 변수 선언
sum=0

#메인 코드
sum=para2_func(10, 20)
print("매개변수가 2개인 함수를 호출한 결과(10+20) : %d " % sum)
sum=para3_func(10, 20, 30)
print("매개변수가 3개인 함수를 호출한 결과(10+20+30) : %d " % sum)
#★결과
#매개변수가 2개인 함수를 호출한 결과(10+20) : 30
#매개변수가 3개인 함수를 호출한 결과(10+20+30) : 60

#7-2) 매개변수에 기본값을 설정해 놓고 전달하는 방법
#=> 위에서 매개변수를 2개 또는 3개 처리할 때는, 매개변수를 가장 많이 사용하는 개수만큼 준비한 후 각 매개변수에 기본값을 설정함

#함수 정의
def para_func(v1, v2, v3=0) : #v3=0 : 세 번째 매개변수(v3)가 없으면 0값을 기본으로 사용하라는 의미
    result=0
    result=v1+v2+v3
    return result

#전역 변수 선언
sum=0

#메인 코드
sum=para_func(10, 20)
print("매개변수가 2개인 함수를 호출한 결과(10+20) : %d " % sum)
sum=para_func(10, 20, 30)
print("매개변수가 3개인 함수를 호출한 결과(10+20+30) : %d " % sum)
#★결과
#매개변수가 2개인 함수를 호출한 결과(10+20) : 30
#매개변수가 3개인 함수를 호출한 결과(10+20+30) : 60

#7-3) 매개변수의 개수를 지정해두지 않고 전달하는 방법
#=> 가변 매개변수(Arbitrary Argument List) 사용
#가변 매개변수 사용 : 함수의 매개변수명 앞에 *를 붙이면 됨. *를 붙이면 매개변수가 튜플 형식으로 넘어와 튜플을 처리하는 방식으로 함수 안에서 사용할 수 있음

#함수 정의
def para_func(*para) :
    result=0
    for num in para : #넘겨받은 매개변수를 for 문으로 하나씩 추출해 365행에서 result에 누적함
        result = result + num

    return result

#전역 변수 선언
sum=0

#메인 코드
sum=para_func(10, 20) #여기서 호출한 매개변수는 (10, 20) 형식의 튜플로 para_func()함수에 전달됨
print("매개변수가 2개인 함수를 호출한 결과(10+20) : %d " % sum)
sum=para_func(10, 20, 30, 40, 50, 60, 70)
print("매개변수가 7개인 함수를 호출한 결과(10+20+30+40+50+60+70) : %d " % sum)
#★결과
#매개변수가 2개인 함수를 호출한 결과(10+20) : 30
#매개변수가 7개인 함수를 호출한 결과(10+20+30+40+50+60+70) : 280

#+추가
#함수의 매개변수 앞에 **를 붙이면 튜플이 아닌 딕셔너리 형식으로 전달받음. 이때는 함수를 호출할 때 딕셔너리 형식의 매개변수를 키=값 형식으로 사용해야 함

def dic_func(**para) :
    for k in para.keys() :
        print("%d = %s " % (k, para[k]))

dic_func(1=one, 2=two, 3=three) #오류
#★결과
#    dic_func(1=one, 2=two, 3=three)
#            ^
#SyntaxError: keyword can't be an expression