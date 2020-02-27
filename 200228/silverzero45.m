%�÷� ���� ���� ó��

%���Ǵ� �Լ�
%rgb2hsv :  RGB �̹����� ������, ���, �Ķ��� ���� HSV(HSI) �̹����� ����, ä��, �� ������ ��ȯ����.
%hsv2rgb :  HSV(HSI) �̹����� ����, ä��, �� ���� RGB �̹����� ������, ���, �Ķ��� ������ ��ȯ����.

%RGB �÷� ���� ���� ���� ó�� ���
%1) RGB �÷� ���� �״�� ����ϴ� ���
%������ ���а������� ������ ����, �ʷϻ� ���а������� ������ ����, �Ķ��� ���а������� ������ �������� �и��� ����
%�� ���п� ���� ȸ�� ����ũ�� ���������� �����ϰ� �� �� ��ģ ����� ����ϸ� ��.

%3*3 ũ���� ��� ����ũ ����
RGB=imread('test.jpg');
RGB_R=RGB(:, :, 1);
RGB_G=RGB(:, :, 2);
RGB_B=RGB(:, :, 3);
mask=fspecial('average');
imshow(RGB_R), figure, imshow(RGB_G), figure, imshow(RGB_B);

result_R2=filter2(mask, RGB_R);
result_R2=uint8(result_R2);
result_G2=filter2(mask, RGB_G);
result_G2=uint8(result_G2);
result_B2=filter2(mask, RGB_B);
result_B2=uint8(result_B2);
imshow(result_R2), figure, imshow(result_G2), figure, imshow(result_B2);

result_RGB2(:, :, 1)=result_R2;
result_RGB2(:, :, 2)=result_G2;
result_RGB2(:, :, 3)=result_B2;
imshow(RGB), figure, imshow(result_RGB2);
%a1=imfilter(RGB, mask)�� ���� ���


%11*11 ũ���� ��� ����ũ ����
mask11=fspecial('average', 11);

result_R2=filter2(mask11, RGB_R);
result_R2=uint8(result_R2);
result_G2=filter2(mask11, RGB_G);
result_G2=uint8(result_G2);
result_B2=filter2(mask11, RGB_B);
result_B2=uint8(result_B2);

result_RGB2(:, :, 1)=result_R2;
result_RGB2(:, :, 2)=result_G2;
result_RGB2(:, :, 3)=result_B2;
imshow(RGB), figure, imshow(result_RGB2);
%a2=imfilter(RGB, mask11)�� ���� ���


%2) HSI �÷� �𵨷� ��ȯ�Ͽ� ó���ϴ� ���
%H : ����(Hue)
%S : ä��(Saturation)
%I : ���(Intensity)
%RGB �÷��� HSI �÷��� ��ȯ�� ����, ��� I�� ���� ȸ���� ������ ��⸦ ��ȯ�� ������ RGB �÷� �������� ��ȯ�ϸ� ��. 
%(����(H)�� ä��(S)�� ���ؼ��� �ƹ��� �۾��� �������� ����.)

RGB=imread('test.jpg');
HSI=rgb2hsv(RGB);
mask=fspecial('average');
mask11=fspecial('average', 11);
HSI_I=HSI(:, :, 3);

result_I=filter2(mask, HSI_I);
result_I2=filter2(mask11, HSI_I);

HSI1=HSI;
HSI2=HSI;

HSI1(:, :, 3)=result_I;
RGB1=hsv2rgb(HSI1);
HSI2(:, :, 3)=result_I2;
RGB2=hsv2rgb(HSI2);

b1=imfilter(RGB, mask);
b2=imfilter(RGB, mask11);
imshow(b1), figure, imshow(RGB1), figure, imshow(b2), figure, imshow(RGB2);