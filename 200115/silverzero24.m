%0~1�� ���� �������� mapping

f=imread('lena.jpg'); %������ �о� f�� �Ҵ�
f1=im2double(f); %f�� ����� ������ double������ ��ȯ�ؼ� f1�� �Ҵ�
minimum=min(min(f1)); %f1�� �ּڰ�. f1�� ������ 2�����̹Ƿ� min()��ɾ �ι� �����
maximum=max(max(f1)); %f1�� �ִ�. f1�� ������ 2�����̹Ƿ� min()��ɾ �ι� �����
[m, n]=size(f); %f�� ��� ���� ���� m, n�� �Ҵ�
g=zeros(m, n); %m, n�� �̿��Ͽ� f�� ���� ũ�⸦ ������ ��� ����
g=(f1-minimum)/(maximum-minimum); %���� ������ �ȼ�����, �ּڰ�, �ִ��� �̿��� ���� ������ ��Ȱȭ
imshow(g), figure, imshow(f), figure, imhist(g), figure, imhist(f); %���� ����� ��Ȱȭ�� ������ ����ϰ�, ������׷��� ���� ���
