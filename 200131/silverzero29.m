%두 영상의 덧셈(크기가 같아야 가능함)
f1=imread('lena.jpg'); %f1의 크기 : 256*256
f2=imread('mask.jpg'); %f2의 크기 : 256*256
f3=f1+f2;
imshow(f3); title('<영상 덧셈 결과>');

f4=f1+f1;
imshow(f4);

%mask.jpg 영상을 보수화 한 다음 영상을 덧셈
f5=imcomplement(f2);
f6=f1+f5;
imshow(f6);




%두 영상의 뺄셈
f7=f1-f2;
imshow(f7); title('<영상 뺄셈 결과>');

%mask.jpg 영상을 보수화 한 다음 영상을 뺄셈
f8=f1-f5;
imshow(f8);

f9=f1-f1; %f9의 값은 모두 0을 가지게 됨. 흑백 영상이 출력되는 것을 확인할 수 있었음.
imshow(f9);


%교수님..혹시 3차원(256*256*3)인 행렬을 2차원(256*256)으로 바꾸는 방법은... 없을까요? 혹시 있다면 용어가 뭔지 궁금합니다.. 
%제가 책을 찾아보고있긴 한데.. 서브샘플링으로 만들 수 있나? 하는 생각이..듭니다... 한번... 도전해보고 오겠다..
