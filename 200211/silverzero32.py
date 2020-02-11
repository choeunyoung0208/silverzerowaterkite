#2차원 리스트
#1차원 리스트를 여러 개 연결한 것으로 첨자를 2개 사용함


#1. 2차원 리스트 생성
aa = [[1, 2, 3, 4], [5, 6, 7, 8], [9, 10, 11, 12]] #3행 4열 리스트 생성
print("%s" % aa)
#★결과
#[[1, 2, 3, 4], [5, 6, 7, 8], [9, 10, 11, 12]]





#2. for문을 이용해 위와 같은 2차원 리스트를 생성한 뒤, 리스트의 각 요소에 접근
list=[]
value=1

for i in range(0, 3) :
    for j in range(0, 4) :
        list.append(value)
        value+=1

for i in range(0, 3, 1) :
    for j in range(0, 4, 1) :
       print("%d" % list[i][j], end = "")  #한 행에 대해서는 줄바꿈이 일어나지 않게 하기 위해서  뒤에 end = " "를 넣음
#★결과
#Traceback (most recent call last):
#  File "C:/Users/IT/PycharmProjects/untitled1/silverzero32.py", line 26, in <module>
#    print("%d" % list[i][j], end = "")  #한 행에 대해서는 줄바꿈이 일어나지 않게 하기 위해서  뒤에 end = " "를 넣음
#TypeError: 'int' object is not subscriptable





#3. 불규칙한 크기의 2차원 리스트 생성
#리스트는 행마다 열의 크기가 다르게도 생성할 수 있다!
bb = [[1, 2, 3, 4], [5, 6], [7], [8, 9, 10]]
print("%s" % bb)
#★결과
#[[1, 2, 3, 4], [5, 6], [7], [8, 9, 10]]