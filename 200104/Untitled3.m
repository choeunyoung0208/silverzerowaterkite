%matlab 내장함수 histeq와 같은 역할을 하는 함수 생성

%다 끝내고 싶었지만....다 끝내지 못해...일단은 여기까지만...

%[counts,binLocations] = imhist(f) 명령어를 사용해 영상 f의 각 그레이 레벨에 해당되는 빈도수(픽셀수) 확인
%counts : 히스토그램 도수
%binLocations : Bin 위치(영상 f의 그레이 레벨 스펙트럼)
%f : 평활화될 영상
[counts, binLocations]=imhist(f); %원본 영상의 각 그레이 레벨에 해당되는 픽셀수 확인

function ans = make_histeq(image, num, counts)
%image : 평활화될 영상

%num : 최대 그레이 레벨수
%ex) 0~255인 경우 
%num=255

%count : num의 각 요소에 해당되는 빈도수
%ex) count=[0 1 0 0 1...]인 경우 
%num(1), num(3), num(4)에 해당하는 픽셀의 개수가 0개 
%num(2), num(5)에 해당하는 픽셀의 개수가 1개

gray_level=0:1:num;
gray_level2=zeros(1, num+1);
total_pixel_number=sum(counts(:));
accumulated_sum=zeros(1, num+1);
eq=zeros(1, num+1);

%누적합 계산
accumulated_sum(1)=counts(1);
for i=2:num+1
    accumulated_sum(i)=accumulated_sum(i-1)+counts(i);
end

%평활화된 그레이 레벨 계산
for i=1:num+1
    gray_level2(i)=round(((num+1)/total_pixel_number)*(accumulated_sum(i)), 0); 
end

for i=1:num+1
    eq(gray_level2(i)+1)=eq(gray_level2(i)+1)+counts(i);
end

end