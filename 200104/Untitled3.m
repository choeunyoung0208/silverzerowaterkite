%matlab �����Լ� histeq�� ���� ������ �ϴ� �Լ� ����

%�� ������ �;�����....�� ������ ����...�ϴ��� ���������...

%[counts,binLocations] = imhist(f) ��ɾ ����� ���� f�� �� �׷��� ������ �ش�Ǵ� �󵵼�(�ȼ���) Ȯ��
%counts : ������׷� ����
%binLocations : Bin ��ġ(���� f�� �׷��� ���� ����Ʈ��)
%f : ��Ȱȭ�� ����
[counts, binLocations]=imhist(f); %���� ������ �� �׷��� ������ �ش�Ǵ� �ȼ��� Ȯ��

function ans = make_histeq(image, num, counts)
%image : ��Ȱȭ�� ����

%num : �ִ� �׷��� ������
%ex) 0~255�� ��� 
%num=255

%count : num�� �� ��ҿ� �ش�Ǵ� �󵵼�
%ex) count=[0 1 0 0 1...]�� ��� 
%num(1), num(3), num(4)�� �ش��ϴ� �ȼ��� ������ 0�� 
%num(2), num(5)�� �ش��ϴ� �ȼ��� ������ 1��

gray_level=0:1:num;
gray_level2=zeros(1, num+1);
total_pixel_number=sum(counts(:));
accumulated_sum=zeros(1, num+1);
eq=zeros(1, num+1);

%������ ���
accumulated_sum(1)=counts(1);
for i=2:num+1
    accumulated_sum(i)=accumulated_sum(i-1)+counts(i);
end

%��Ȱȭ�� �׷��� ���� ���
for i=1:num+1
    gray_level2(i)=round(((num+1)/total_pixel_number)*(accumulated_sum(i)), 0); 
end

for i=1:num+1
    eq(gray_level2(i)+1)=eq(gray_level2(i)+1)+counts(i);
end

end