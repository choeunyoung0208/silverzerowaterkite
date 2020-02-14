"""if-else문"""
print("Tell me your age?")  # 지시문 출력
myage = int(input())  # 입력받은 값을 정수형으로 변환한 후 myage에 할당
if myage<30:  # myage가 30 미만일 경우
    print("Welcome to the Club.")  # 해당 메세지 출력
else:  # 그 이외의 경우 (myage가 30 이상일 경우)
    print("Oh! No. You are not accepted.")  # 해당 메세지 출력
'''
파이썬 if문의 큰 장점 중 하나는 수행 명령의 구분 부분이다.
C언어의 경우 if문은 수행 명령어가 두개 이상일 경우 중괄호를 작성해야하지만 파이썬은 들여쓰기만 제대로 해준다면 중괄호가 필요없다.
여기서 들여쓰기는 space키나 tab키로 코드를 일정 간격을 안쪽으로 넣어주기만하면 정상적으로 작동한다.
'''

"""True와 False의 치환"""
print((3 > 5) < 10)  # True
'''
3은 5보다 작으니 3 > 5 는 False이다. False는 0으로 치환된다.
따라서 이것을 다시 치환하면 (0) < 10 은 True이기 때문에 True가 출력이 된다.
'''

"""논리 연산자"""
a = 8  # a에 8을 할당
b = 5  # b에 5를 할당
print(a == 8 and b == 4)  # False
# a값은 8과 동일하기에 True이지만 b값은 4가 아니기 때문에 False라서 and 연산에 의해 False 출력
print(a > 7 or b > 7)  # True : a값은 7보다 크기 때문에 True, b값은 7보다 작아서 False이지만 or 연산에 의해 True 출력
print(not (a > 7))  # False : a값은 7보다 커서 True이지만 not 연산에 의해 그의 반대인 False 출력

'''
and 연산은 두개의 조건문이 모두 True일 경우 True이고 그렇지 않으면 False이다.
or 연산은 두개의 조건문 중 하나라도 Ture일 경우 True이고 둘 다 False일 경우만 False이다.
not 연산은 True이면 False로 나오고 False이면 True로 나오는 연산결과의 반대값을 도출한다.
'''

"""if-elif-else문"""
score = int(input("Enter your score: "))  # 지시문과 함께 입력을 받고 입력값을 정수형으로 변환한 후 score 변수에 할당

if score >= 90:  # score가 90이상일 경우
    grade = 'A'  # grade 변수에 A 할당
elif score >= 80:  # 앞선 조건문 이외의 경우 중 score가 80이상일 경우 (90미만 80이상일 경우)
    grade = 'B'  # grade 변수에 B 할당
elif score >= 70:  # 앞선 조건문 이외의 경우 중 score가 70이상일 경우 (80미만 70이상일 경우)
    grade = 'C'  # grade 변수에 C 할당
elif score >= 60:  # 앞선 조건문 이외의 경우 중 score가 60이상일 경우 (70미만 60이상일 경우)
    grade = 'D'  # grade 변수에 D 할당
else:  # 앞선 조건문 이외의 모든 경우
    grade = 'F'  # grade 변수에 F 할당

print(grade)  # grade 출력

"""
실습02 : 어떤 종류의 학생인지 맞히기

나이는 (2020 - 태어난 연도 + 1) 로 계산
26세 이하 20세 이상이면 '대학생'
20세 미만 17세 이상이면 '고등학생'
17세 미만 14세 이상이면 '중학생'
14세 미만 8세 이상이면 '초등학생'
그 외의 경우는 '학생이 아닙니다.' 출력
---
당신이 태어난 연도를 입력하세요. <- 입력 대기
1982 <- 자신이 태어난 연도 입력
학생이 아닙니다. <- 어떤 종류의 학생인지 출력
"""

year = int(input("당신이 태어난 연도를 입력하세요.(4자리 수 입력)\n"))
# 연도를 입력받고 해당 입력을 정수형으로 변환 후 year 변수에 할당
age = 2020 - year + 1  # year 값을 사용하여 나이 계산 후 age 변수에 할당

if age < 1 or year < 1:  # age가 1미만이거나 year이 1 미만일 경우
    print("잘못된 입력입니다.")  # 해당 메세지 출력
elif age <= 26 and age >= 20:  # 앞선 조건문 이외의 경우 중 age가 26이하 20이상일 경우
    print("대학생")  # 해당 메세지 출력
elif age < 20 and age >= 17:  # 앞선 조건문 이외의 경우 중 age가 20미만 17이상일 경우
    print("고등학생")  # 해당 메세지 출력
elif age < 17 and age >= 14:  # 앞선 조건문 이외의 경우 중 age가 17미만 14이상일 경우
    print("중학생")  # 해당 메세지 출력
elif age < 14 and age >= 8:  # 앞선 조건문 이외의 경우 중 age가 14미만 8이상일 경우
    print("초등학생")  # 해당 메세지 출력
else:  # 앞선 조건문 이외의 모든 경우
    print("학생이 아닙니다.")  # 해당 메세지 출력

'''
기존의 문제에 작성되어 있는 입력문의 지시문에 조건을 더 추가해서 작성하였습니다.
아직 태어나지 않은 경우나 기원전 기준으로 작성할 시엔 잘못된 입력이라는 출력을 내도록 설정하였습니다.
또한 입력하는 사람을 배려하여 몇 글자를 입력할 지 작성해 두었습니다.
그 이외의 경우는 모두 실습문제에 적힌대로 작성하였습니다.
'''