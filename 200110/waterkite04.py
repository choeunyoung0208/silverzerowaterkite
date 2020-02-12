# 리스트 추가 및 삭제
# append() 함수
color = ['red', 'blue', 'green']  # 리스트 선언
color.append('write')  # color 리스트에 'white' 추가 (리스트 맨 마지막 인덱스에 새로 값을 추가)
print(color)  # ['red', 'blue', 'green', 'write'] : 리스트 color 출력

# extend() 함수
color = ['red', 'blue', 'green']  # 리스트 선언
color.extend(['black', 'purple'])  # color 리스트에 ['black', 'purple'] 리스트를 추가 (리스트의 덧셈연산과 유사)
print(color)  # 'red', 'blue', 'green', 'black', 'purple'] : 리스트 color 출력

# insert() 함수
color = ['red', 'blue', 'green']  # 리스트 선언
color.insert(0, 'orange')  # color 리스트 0번째 자리에 'orange' 추가
print(color)  # ['orange', 'red', 'blue', 'green'] : 리스트 color 출력

# remove() 함수
print(color)  # ['orange', 'red', 'blue', 'green'] : 리스트 color 출력
color.remove('red')  # 리스트에 'red'에 해당하는 값 삭제
print(color)  # ['orange', 'blue', 'green'] : 리스트 color 출력