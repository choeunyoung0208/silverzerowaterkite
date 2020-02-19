%silverzero34.m �߰�

%���� ��� ó��
%���� ��� ó���� �Է� �ȼ��� �� ���� �ȼ����� ����Ͽ� ��� �ȼ��� ���� ������
%���� ��� ó���� ������ �帮�� �Ǵ� �����ϰ� �ϰų�, ������ ��輱�� �����ϰų�, ������ �����ϴ� ������ ȿ�������� ������ ��
%����


%������ �帮�� �ϰų�, ������ �����ϰ� �ϰų�, ������ ��輱�� �����ϰų�, ������ �����ϴ� ���� ��� ó������ ȸ�� ����� ����
%�ϴ� ����� ��� �����ϰ� ���� ����ũ�� ���� ���� �ٸ�!


%ȸ��(convolution)
%�Է� ������ �� �ȼ��� ���� ��� �ȼ� ���� ���ϱ� ����, �Է� �ȼ��� �� ���� �ȼ��� ���� ȸ�� ����ũ�� ���� ���� ���� �̵��� ��
%�� ����
%������ �Է� �ȼ��� ���� ���� �ȼ��� ����� ��, �� �������� ��Ī�ǵ��� �ؾ� �ϹǷ� ȸ�� ����ũ�� ���ο� ���� ũ��� Ȧ������ ��


%��� �� ��ɾ��

%1. double Ŭ�������� uint8 Ŭ������ ��ȯ�ϴ� ��ɾ� (2����) 
%1) Y=uint8(X) : X�� ���� uint8������ ��ȯ. ���� [0,255] �ۿ� �ִ� ���� ���� ����� ������ ���ε�.
%2) J=im2uint8(I) : ȸ����, RGB �Ǵ� ���� ���� I�� uint8������ ��ȯ�ϰ� �ʿ信 ���� �����͸� �ٽ� �����ϸ��ϰų� ��������
%�Է� ������ logical�� Ŭ�����̸� im2uint8�� true ���� ���� ��Ҹ� 255�� ������



%2. filter2()
%filter�� �� ���� ���� �̵��ϸ鼭 ó��

%Y=filter2(filter, image, shape)

%Y : �������� ����ó�� ���
%filter : ����ũ ����
%image : �� ����

%shape : 'same', 'valid', 'full'�� �� ������ ����. 'same'�� default.
%same : default. ��� ������ ������� ������ ũ���� ��Ʈ����. ���� ó���� pad with zeros
%valid : ����ũ�� ���� ������ ������ ��ø�Ǵ� ȭ�ҿ��� ó��. ���� ó���� ignore edges. 
%        'same'���� ó���� ����� �������� �ܺο� �̸� 0���� ä�� �� 'valid'�� ó���ϸ� ���� �� ����
%full : ����� �����󺸴� �� ū ũ��. ������ ȭ�Ұ��� ���� ��� '0'���� ä��. 
%       ����ũ�� ���� ����� ���� ��ġ�� �κ��� ������ ����� ������ ��� ������ ���͸� �����Ͽ� ��� ��Ʈ������ ����(?)

%filter2() �� ����� double data type





%���� �帮�� �ϱ�
%���⼭ ���Ǵ� ȸ�� ����ũ�� �� �Է� �ȼ����� ���� �ȼ�������� '��հ����� ��ȯ'��

%3*3 ũ���� ȸ�� ����ũ�� ����Ͽ� ���� �帮�� �ϱ�
f=imread('lena.jpg');
mask33=[1/9, 1/9, 1/9; 1/9, 1/9, 1/9; 1/9, 1/9, 1/9];
result33=filter2(mask33, f);
result33=uint8(result33); %��result33=im2uint8(result33);�� ���� ��� ���� 255�� ��. �� �׷��� �����غ���!
imshow(f), figure, imshow(result33);

%5*5 ũ���� ȸ�� ����ũ�� ����Ͽ� ���� �帮�� �ϱ�
mask55=ones(5);
mask55=1/25*mask55;
result55=filter2(mask55, f);
reulst55=uint8(result55);
imshow(f), figure, imswho(result55);

%11*11 ũ���� ȸ�� ����ũ�� ����Ͽ� ���� �帮�� �ϱ�
mask1111=ones(11);
mask1111=1/121*mask1111;
result1111=filter2(mask1111, f);
result1111=uint8(result1111);
imshow(f), figure, imshow(result1111);

%����ũ�� ũ�Ⱑ Ŀ������ ������� ������ �� Ŀ���� ���� Ȯ���� �� �־����ϴ�

%+�߰�
%3*3 ũ���� ȸ�� ����ũ�� ����Ͽ� ���� �帮�� �ϱ�(valid)
result33_valid=filter2(mask33, f, 'valid');
result33_valid=uint8(result33_valid);
imshow(result33_valid2);


%3*3 ũ���� ȸ�� ����ũ�� ����Ͽ� ���� �帮�� �ϱ�(full)
result33_full=filter2(mask33, f, 'full');
result33_full=uint8(result33_full);
imshow(result33_full);




%���� �����ϰ� �ϱ�
%������ �����ϰ� ���ִ� ����ũ (2����)
%1) [0 -1 0; -1 5 -1; 0 -1 0]
%2) [-1 -1 -1; -1 9 -1; -1 -1 -1]
%���� ����ũ���� �����ϸ� ������� 0���� �۰ų� 255���� Ŀ�� �� �����Ƿ�, �׷� ��쿡�� 0�� 255�� ���� ������ �����ؾ� ��

%������ �帮�� ���ִ� ȸ�� ����ũ�� ������ �����ϰ� ���ִ� ����ũ��(���� 2��)�� ����ũ ���� ������ ��� ���ϸ� 1�� �ȴٴ� ����
%Ȯ���� �� ����!
%����ũ ���� ���� ���ϸ� 1�� �ǵ��� �����ν� ȸ�� ����ũ�� �����ϱ� ���� ������ ���� ���󿡼� ��ü���� ������ ��Ⱑ ����ϰ�
%�����ȴٴ� Ư���� ����

%����ũ 1 ����
mask1=[0 -1 0; -1 5 -1; 0 -1 0];
result_mask1=filter2(mask1, f);
result_mask1=uint8(result_mask1);
imshow(f), figure, imshow(result_mask1);

%����ũ 2 ����
mask2=[-1 -1 -1; -1 9 -1; -1 -1 -1];
result_mask2=filter2(mask2, f);
result_mask2=uint8(result_mask2);
imshow(f), figure, imshow(result_mask1), figure, imshow(result_mask2);

%����ũ 1 �� �� ����
result_mask1=filter2(mask1, f);
result_mask1=uint8(result_mask1);
result_mask11=filter2(mask1, result_mask1);
result_mask11=uint8(result_mask11);
imshow(result_mask11);

%����ũ 2 �� �� ����
result_mask2=filter2(mask2, f);
result_mask2=uint8(result_mask2);
result_mask22=filter2(mask2, result_mask2);
result_mask22=uint8(result_mask22);
imshow(result_mask22);





%��輱 ����
%��������� �ٸ� ��ϵ��� ���� �� ���� ���� ��踦 ������
%�̺� ������ �̿��� ��輱�� �����ϴ� ����� �θ� ���ǰ� ����

%�̺��� �̿��� ��輱 ����� ȸ�� ����ũ (3����)
%�� ���� ȸ�� ����ũ�� �̿��Ͽ� ȸ���� ������. �� ȸ�� ����ũ�� ���� ������ ��輱�� ���ϰ�, �ٸ� ȸ�� ����ũ�� ���� ������
%������ ���ϱ� ���� ����
%1) Prewitt ����ũ
%���� ��輱 : [-1 -1 -1; 0 0 0; 1 1 1]
%���� ���� : [1 0 -1; 1 0 -1; 1 0 -1]
%2) Roberts ����ũ
%���� ��輱 : [-1 0; 0 1]
%���� ��輱 : [0 -1; 1 0]
%3) Sobel ����ũ
%���� ��輱 : [-1 -2 -1; 0 0 0; 1 2 1]
%���� ��輱 : [1 0 -1; 2 0 -2; 1 0 -1]

%Prewitt ����ũ�� �밢 ������ ��輱���ٴ� ����, ���� ��輱�� �� �ΰ���
%Roberts ����ũ�� �ٸ� ����ũ���� ũ�Ⱑ �۾Ƽ� ������ ȿ���������� ������ �ΰ���
%Sobel ����ũ�� ����, ���� ������ ��輱���ٴ� �밢�� ������ ��輱�� �� �ΰ���

%Prewitt ����ũ�� ��쿡�� ����ũ �߽ɿ����� �Ÿ��� ������� +1�Ǵ� -1�� ���� ������ ����
%�ݸ鿡 Sobel ����ũ������ ����ũ�� �߽ɿ� ����� �ȼ��� +2 �Ǵ� -2�� ���� ������, �� �ȼ��� +1 �Ǵ� -1�� ���� ��������
%�Ǿ� �־� ���� ��Ȯ�� ��輱�� ������ �� ����

%Prewitt ����ũ�� �̿��� ��輱 ����
mask_prewitt_h=[-1 -1 -1; 0 0 0; 1 1 1]; %���� ��輱�� �����ϴ� Prewitt ����ũ
mask_prewitt_v=[1 0 -1; 1 0 -1; 1 0 -1]; %���� ��輱�� �����ϴ� Prewitt ����ũ

result_prewitt_h=filter2(mask_prewitt_h, f);
result_prewitt_h=uint8(result_prewitt_h);

result_prewitt_v=filter2(mask_prewitt_v, f);
result_prewitt_v=uint8(result_prewitt_v);

result_prewitt=result_prewitt_h + result_prewitt_v;

imshow(result_prewitt_h), figure, imshow(result_prewitt_v), figure, imshow(result_prewitt);


%Roberts ����ũ�� �̿��� ��輱 ����
mask_roberts_h=[-1 0; 0 1]; %���� ��輱�� �����ϴ� Roberts ����ũ
mask_roberts_v=[0 -1; 1 0]; %���� ��輱�� �����ϴ� Roberts ����ũ

result_roberts_h=filter2(mask_roberts_h, f);
result_roberts_h=uint8(result_roberts_h);

result_roberts_v=filter2(mask_roberts_v, f);
result_roberts_v=uint8(result_roberts_v);

result_roberts=result_roberts_h + result_roberts_v;

imshow(result_roberts_h), figure, imshow(result_roberts_v), figure, imshow(result_roberts);


%Sobel ����ũ�� �̿��� ��輱 ����
mask_sobel_h=[-1 -2 -1; 0 0 0; 1 2 1]; %���� ��輱�� �����ϴ� Sobel ����ũ
mask_sobel_v=[1 0 -1; 2 0 -2; 1 0 -1]; %���� ��輱�� �����ϴ� Sobel ����ũ

result_sobel_h=filter2(mask_sobel_h, f);
result_sobel_h=uint8(result_sobel_h);

result_sobel_v=filter2(mask_sobel_v, f);
result_sobel_v=uint8(result_sobel_v);

result_sobel=result_sobel_h + result_sobel_v;

imshow(result_sobel_h), figure, imshow(result_sobel_v), figure, imshow(result_sobel);