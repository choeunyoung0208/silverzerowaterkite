f=imread('lena.jpg');
g=imcomplement(f); %영상 f의 보수를 계산해 영상의 색을 반전시킨 후 변수 g에 할당
imshow(g); %보수를 사용해 색을 반전시킨 영상 출력
f1=im2double(f); %원본 영상 데이터 클래스를 double형으로 변환한 값을 변수 f1에 할당
f2=im2double(g);%변수 g의 데이터 클래스를 double형으로 변환한 값을 변수 f2에 할당

%보수를 계산하는 과정이 어떻게 되는지 모르겠어서 한 번 찾아보려고 합니다.
