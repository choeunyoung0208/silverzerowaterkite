%두 영상의 덧셈
f1=imread('lena.jpg');
f2=imread('mask.jpg');
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