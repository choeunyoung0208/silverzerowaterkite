# 연습문제 9 : 코드 실행 결과 설명
# a = "3.5"  # a에 문자열 3.5 할당
# b = "1.5"  # b에 문자열 1.5 할당
# print(a + b)  # 3.51.5 : 문자형 간 덧셈 후 출력 (문자형간의 합은 문자를 이어 붙인다)

# 연습문제 10 : 코드 실행 결과 설명
# a = '3'  # a에 문자형 3 할당
# b = float(a)  # b = 3.0 : b에 문자형 a를 실수형으로 변환한 후 할당
# print(b ** int(a))  # 27.0 : 문자형 a를 정수형으로 변환 -> int(a) = 3 -> b의 int(a)승 -> 3.0의 3승 = 27.0

# 연습문제 12 : 코드 실행 결과 설명
# a = '20'  # a에 문자형 20 할당
# b = '4'  # b에 문자형 4 할당
# #print(type(float(a / b)))  # 출력 과정에서 오류 발생 -> TypeError : 문자형 간의 나눗셈은 이뤄지지 않음

# 연습문제 13 : 코드 실행 결과 설명
"""
a = "Gyungsan"
b = "YU"
c = 200
[            ]
print(a, b, c)

실행 결과 : Gyungsan YU 50
위와 같은 실행결과가 나오도록 빈칸에 코드 추가
"""
# a = "Gyungsan"  # a에 문자열 Gyungsan을 할당
# b = "YU"  # b에 문자열 YU 할당
# c = 200  # c에 200 할당
# c = int(c / 4)  # c = 50
"""
c / 4 = 200 / 4 = 50.0 : c를 4로 나눗셈
-> 실수형인 50.0을 50으로 바꾸기 위해 정수형으로 변환
-> c에 50을 할당
"""
# print(a, b, c)  # Gyungsan YU 50 : a, b, c 출력

# 연습문제 14 : 동적 타이핑
"""
다른 언어들과 달리 파이썬은 자료형을 인터프리터가 스스로 동적으로 판단한다
변수를 선언할 때 저장되는 값의 형태에 따라 자료형을 결정하고, 할당받는 메모리 공간도 그 크기에 따라 다르게 할당받을 수 있다.
"""
# a = 12  # a에 12를 할당 -> 정수형으로 할당
# b = 12.0  # b에 12.0을 할당 -> 실수형으로 할당
# c = "12"  # c에 "12"를 할당 -> 문자형으로 할당
# print(type(a), type(b), type(c)) # <class 'int'> <class 'float'> <class 'str'>
# 자료형이 실제로 위와 같이 유동적으로 할당됐음을 확인할 수 있다

# 연습문제 15 : 코드 실행 결과 설명
# (가)
# print("1.0" * 5)  # 1.01.01.01.01.0 : 문자열에 숫자형을 곱셈 (문자열을 숫자형 값만큼 이어서 나열)
# (나)
# print("1.0" + 2)  # 오류 발생 : 문자형과 숫자형 간의 덧셈 불가능
# (다)
# print("Hanbit" + "Python")  # HanbitPython : 문자형 간의 덧셈 (문자열을 이어붙임)
# (라)
# print("3.5" + "0.5")  # 3.50.5 : 문자형 간의 덧셈 (문자열을 이어붙임)

# 연습문제 17 : 반올림 오차가 나타나는 이유
"""
파이썬은 실수를 표현할 때 부동소수점 방식으로 표현한다.
그러나 이 부동소수점은 실수를 정확히 표현하지 못하는 문제가 있다.
따라서 일부 실수간의 연산 결과가 실제 결과값의 근사값으로 반올림 오차가 발생한다.
"""
# print(0.1 + 0.2)  # 0.30000000000000004 : 실제 계산 값 0.3의 근사값을 출력