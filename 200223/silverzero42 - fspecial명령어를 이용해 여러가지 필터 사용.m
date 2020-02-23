%fspecial() ��ɾ �̿��� �������� ���� ����ũ ������ ����� �����غ���(�� ���� �Ẹ�� ���� �� ���Ƽ� �غý��ϴ�!)

%h=fspecial('type', parameters)
%fspecial : ���� ����ũ ������ ����� �Լ�
%h : fspecial��ɾ� ��� ��� ����� ���� ���� ����ũ

%parameters : default���� 3*3 ũ��. parameters�� [��, ��] �Ǵ� ����� �Է� ����.
%[��, ��] : ����ũ ����� ũ�⸦ ������.
%��� : �������(���簢���)�� �ǹ���.

%type : �������� ����. 'average', 'disk', 'gaussian', laplacian', 'log',
%'motion', 'prewitt', 'sobel', 'unsharp'
%average : ��� ����
%disk : ���� ��� ����
%gaussian : ����þ� ������� ����
%laplacian : ���ö�þ� ����
%log : ���ö�þ��� ����þ� ����
%motion : ī�޶��� ���� ��� �ٻ�ȭ ����
%prewitt : Prewitt ���� �𼭸� ���� ����
%sobel : Sobel ���� �𼭸� ���� ����
%unsharp : unsharp ����

%��� ����
 f=imread('lena.jpg');
h_average=fspecial('average');
result_average=filter2(h_average, f);
result_average=uint8(result_average);
imshow(result_average);

%���� ��� ����
h_disk=fspecial('disk');
result_isk=filter2(h_disk, f);
result_disk=uint8(result_disk);
imshow(result_disk);

%����þ� ������� ����
h_gaussian=fspecial('gaussian');
result_gaussian=filter2(h_gaussian, f);
result_gaussian=uint8(result_gaussian);
imshow(result_gaussian);

%���ö�þ� ����
h_laplacian=fspecial('laplacian');
result_laplacian=filter2(h_laplacian, f);
result_laplacian=uint8(result_laplacian);
imshow(result_laplacian);

%���ö�þ��� ����þ� ����
h_log=fspecial('log');
result_log=filter2(h_log, f);
result_log=uint8(result_log);
imshow(result_log);

%ī�޶��� ���� ��� �ٻ�ȭ ����
h_motion=fspecial('motion');
result_motion=filter2(h_motion, f);
result_motion=uint8(result_motion);
imshow(result_motion);

%Prewitt ���� �𼭸� ���� ����
h_prewitt=fspecial('prewitt');
result_prewitt=filter2(h_prewitt, f);
result_prewitt=uint8(result_prewitt);
imshow(result_prewitt);

%Sobel ���� �𼭸� ���� ����
h_sobel=fspecial('sobel');
result_sobel=filter2(h_sobel, f);
result_sobel=uint8(result_sobel);
imshow(result_sobel);

%unsharp ����
h_unsharp=fspecial('unsharp');
result_unsharp=filter2(h_unsharp, f);
result_unsharp=uint8(result_unsharp);
imshow(result_unsharp);