%�� ������ ����
f1=imread('lena.jpg');
f2=imread('mask.jpg');
f3=f1+f2;
imshow(f3); title('<���� ���� ���>');

f4=f1+f1;
imshow(f4);

%mask.jpg ������ ����ȭ �� ���� ������ ����
f5=imcomplement(f2);
f6=f1+f5;
imshow(f6);




%�� ������ ����
f7=f1-f2;
imshow(f7); title('<���� ���� ���>');

%mask.jpg ������ ����ȭ �� ���� ������ ����
f8=f1-f5;
imshow(f8);

f9=f1-f1; %f9�� ���� ��� 0�� ������ ��. ��� ������ ��µǴ� ���� Ȯ���� �� �־���.
imshow(f9);