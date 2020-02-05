f=imread('image1.jpg');
f1=rgb2gray(f); %�Է¹��� ���� f�� grayscale�� ��ȯ
f2=(f1>150); %grayscale�� ��ȯ�� ���� f1�� ����ȭ. 150���� ū ���� 255��, �������� 0���� ��ȯ.

%ħ�Ŀ���
%imerode(image, kernel) ��ɾ ����Ͽ� ħ�Ŀ��� ����
%image : ħ�Ŀ����� ������ ����
%kernel : ���� ������. ���� ������ �� ��Ҵ� 0�Ǵ� 1�� ���� ���� �� �ִ�. ����� ũ�Ⱑ Ŭ���� ������ ȿ���� �� Ŀ��. 
k=ones(3, 3); %��� ��Ұ� 1�� 3*3�� ���� ������ ����
k1=ones(5, 5);
k2=ones(7, 7);
erode1=imerode(f2, k); %kernel k�� �̿��Ͽ� �̹��� f2�� ħ�Ŀ���
erode2=imerode(f2, k1); %kernel k1�� �̿��Ͽ� �̹��� f2�� ħ�Ŀ���
erode3=imerode(f2, k2); %kernel k2�� �̿��Ͽ� �̹��� f2�� ħ�Ŀ���
imshow(f2), figure, imshow(erode1), figure, imshow(erode2), figure, imshow(erode3); 
%f2, erode1, erode2, erode3 ������ ��� ����Ͽ� ��� ��



%��â����
%imdilate(image, kernel) ��ɾ ����Ͽ� ��â���� ����
%���� ħ�Ŀ���� ������ �Ȱ���.
%������ ������ ���� �����츦 �Ȱ��� ���.
dilate1=imdilate(f2, k);  %kernel k�� �̿��Ͽ� �̹��� f2�� ��â����
dilate2=imdilate(f2, k1); %kernel k1�� �̿��Ͽ� �̹��� f2�� ��â����
dilate3=imdilate(f2, k2); %kernel k2�� �̿��Ͽ� �̹��� f2�� ��â����
imshow(f2), figure, imshow(dilate1), figure, imshow(dilate2), figure, imshow(dilate3);
%f2, dilate1, dilate2, dilate3 ������ ��� ����Ͽ� ��� ��


%��������
%���������� ħ�Ŀ����� ������ ������ ��â������ �����ϴ� ����.
%imopen(image, kernel) ��ɾ ����Ͽ� �������� ����
open1=imopen(f2, k);
open2=imopen(f2, k1);
open3=imopen(f2, k2);
imshow(f2), figure, imshow(open1), figure, imshow(open2), figure, imshow(open3);

%���������� ���ǰ� ħ�Ŀ����� ������ ������ ��â������ �����ϴ� �����̹Ƿ�,
%ħ�Ŀ���, ��â���� ��ɾ ����ؼ��� ���������� �����غ��ҽ��ϴ�.
open4=imdilate(erode1, k);
open5=imdilate(erode2, k1);
open6=imdilate(erode3, k2);
imshow(open1), figure, imshow(open2), figure, imshow(open3), figure, imshow(open4), figure, imshow(open5), figure, imshow(open6);
%���� �� ��� ���� ������ ��µ��� Ȯ���� �� �־����ϴ�.



%��������
%���������� ��â������ ������ ������ ħ�Ŀ����� �����ϴ� ����.
%imclose(image, kernel) ��ɾ ����Ͽ� �������� ����
close1=imclose(f2, k);
close2=imclose(f2, k1);
close3=imclose(f2, k2);
imshow(f2), figure, imshow(close1), figure, imshow(close2), figure, imshow(close3);

%���������� ���ǰ� ��â������ ������ ������ ħ�Ŀ����� �����ϴ� �����̹Ƿ�,
%��â����, ħ�Ŀ��� ��ɾ ����ؼ��� ���������� �����غ��ҽ��ϴ�.
close4=imerode(dilate1, k);
close5=imerode(dilate2, k1);
close6=imerode(dilate3, k2);
imshow(close1), figure, imshow(close2), figure, imshow(close3), figure, imshow(close4), figure, imshow(close5), figure, imshow(close6);
%���� �� ��� ���� ������ ��µ��� Ȯ���� �� �־����ϴ�.



%+ �߰��� �� �� �͵�..!
%��� ��Ұ� 1�� 12*12�� ũ�⸦ ������ kernel�� �����ؼ� ħ�Ŀ��� ����
k3=ones(12, 12);
erode4=imerode(f2, k3);
imshow(erode3), figure, imshow(erode4);

%f, f1, f2 ���� ���� k3 kernel�� �̿��� ħ�Ŀ��� ����
%f : rgb���� ������ ����, 
%f1 : grayscale�� ���� ������ ����, 
%f2 : ����ȭ�� ����
erodee1=imerode(f, k3);
erodee2=imerode(f1, k3);
erodee3=imerode(f2, k3);
imshow(erodee1), figure, imshow(erodee2), figure, imshow(erodee3);