f=imread('lena.jpg'); %lena.jpg ������ �о� ���� f�� ��� ���·� ����
g=imread('lena_g.jpg'); %lena_g.jpg ������ �о� ���� g�� ��� ���·� ����
imshow(f) %lena.jpg �� ȭ�鿡 ���
figure, imshow(g) %lena.jpg �� ȭ�鿡 ����� ���¿��� lena_g.jpg �� ���
%������ lena.jpg�� lena_g.jpg ������ ���ƺ������� matlab���� ����غ� ��� ���� ������ �ƴ��� Ȯ���� �� �־���
%matlab�� ���� �������� lena.jpg�� lena_g.jpg�� ����Ŭ�� �Ͽ� ���� �� ��� lena_g.jpg�� colormap�̶�� ���� �������� Ȯ��.
%colormap�� 3���� ǥ�õǸ�, ù��° ���� R, �ι�° ���� G, ����° ���� B�� ��Ÿ��. ������ 0<=colormap<=1 ����.
[X,map]=imread('lena_g.jpg');
figure, imshow(X,map)
%imshow(X,map)�� [A,map] = imread(___)�� �̿��Ͽ� map�� colormap�� �Ҵ��ϰ�, �ٽ� lena_g.jpg�� ����غ� ��� lena.jpg�� ���� ������ ��µ�.
%colormap�� �����Ǵ� ������ ���� ã�ƺ����� �ϰڽ��ϴ�
