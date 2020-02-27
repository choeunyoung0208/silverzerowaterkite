%���� ��� ó�� - ����(noise) ����

%������ ���޽�(impulse) ������ ����þ�(Gaussian) �������� ������ �� ����.
%���޽� ���� : 0�Ǵ� 255�� ���� ������ �ȼ������� �ѷ��ϰ� �ٸ� �ȼ����� ���� ������ ����.
%����þ� ���� : ������ �ȼ������κ��� �ұ�Ģ������ ������� �ѷ��ϰ� ������� ���� �ȼ����� ���� ������ ����. (å�� �̷���
%�����ִµ� ���� �Ҹ����� ���ذ� �� ���� �ٽ� ã�ƺ��ҽ��ϴ�..����)
%���Ժ����� ������ ����. ���� ���� �Ϲ����� ����(���޽� ����ó�� ���ڱ� Ƣ�� ������ �ƴ�, ��� ���� ������ ������ �ƴ�)�̸� ��� ���� �����ϸ鼭
%�ڿ��迡�� ���� �� �� �ִ� ������ ����.





%���Ǵ� �Լ�
%1) imnoise : ���� ���� �߰�

%imnoise(I,'gaussian')
%ex) imnoise(I,'gaussian') : �л� 0.01�� ��� 0�� ���콺 ��� ������ ȸ���� ���� I�� �߰�.

%imnoise(I,'salt & pepper',d) : �������� �߰���. ���⼭ d�� ���� �е�(default : 0.05). 
%ex) imnoise(I,'salt & pepper',0.02) : ���� �е��� 0.02�� ������(Salt and Pepper
%Noise)�� ���� �߰�.


%2) randi : ������ ���� ����
%ex) randi([10 50],1,5) : 10���� 50 ���̿� �����ϰ� ������ 5���� ������ ������ ����





%������ �����ϴ� ���
%1) ��� ����ũ�� �̿��� ȸ�� ���
%����þ� ������ �帰 ���� ������ ���� ��� ����ũ�� �̿��� ȸ�� ����� ����Ͽ� ȿ�������� ������ �� ����.
%����þ� ������ ������ �ȼ������� ũ�� ����� �ʱ� ������ ������ ������ �ƴ� �ȼ������ ����� ���ϸ� ������ ������鼭 ������
%������ ����.

f=imread('lena.jpg');
gaussian=imnoise(f, 'gaussian'); %���� f�� gaussian noise�� �߰�
impulse=imnoise(f, 'salt & pepper'); %���� f�� impulse noise�� �߰�

%3*3 ũ���� ��� ����ũ
average33=fspecial('average');
average33_gaussian=filter2(average33, gaussian);
average33_gaussian=uint8(average33_gaussian);

average33_impulse=filter2(average33, impulse);
average33_impulse=uint8(average33_impulse);


%5*5 ũ���� ��� ����ũ
average55=fspecial('average', 5);
average55_gaussian=filter2(average55, gaussian);
average55_gaussian=uint8(average55_gaussian);
imshow(average33_gaussian), figure, imshow(average55_gaussian);

average55_impulse=filter2(average55, impulse);
average55_impulse=uint8(average55_impulse);
imshow(average33_impulse), figure, imshow(average55_impulse);





%2) �߰��� ���͸� �̿�
%���޽� ������ ȿ�������� ������ �� �մ� ���.
%�Է� �ȼ��� ���� �ȼ����� �� �߿��� �߰����� ã�Ƽ� �̸� ��� �ȼ������� ����ϴ� ���.
%�߰��� ���ʹ� ��輱�� �� ������. (��� ����ũ�� �̿��ϸ� ������ ����� ��輱�� ��ȣ������ �ݸ�, �߰��� ���ʹ� ������ �帮��
%���� ����.)

%���޽� ������ ��� ����ũ�� �̿��� ȸ�� ��� ���ٴ� �߰��� ���͸� �̿��ϴ� ���� ������ �ξ� �� �� �������� �� �� ����.

%3*3 ũ���� �߰��� ����
k1=ordfilt2(gaussian, 5, ones(3, 3));
k2=ordfilt2(impulse, 5, ones(3, 3));

%5*5 ũ���� �߰��� ����
k3=ordfilt2(gaussian, 13, ones(5, 5));
k4=ordfilt2(impulse, 13, ones(5, 5));
imshow(k1), figure, imshow(k3), figure, imshow(k2), figure, imshow(k4);