import turtle #그래픽을 가져옴

colors = ["red", "purple", "blue", "green", "yellow", "orange"] #선의 색 리스트 생성
t = turtle.Turtle() #거북이 생성

turtle.bgcolor("black") #그래픽 배경색 설정
t.speed(0) #선이 그려지는 속도 설정
t.width(3) #선의 굵기 설정
length = 10 #선의 한변의 길이 설정

while length < 500: #선의 한변의 길이가 500미만인 경우 실행
    t.forward(length) #길이만큼 앞으로 전진
    t.pencolor(colors[length%6]) #길이를 6으로 나눈 나머지로 색 리스트에서 선의 색을 결정
    t.right (89) #선의 회전방향과 회전각도 설정
    length += 5 #길이를 5씩 더해줌

#학번:21812009
#이름:조은영

ㅎㅎㅎㅎ
