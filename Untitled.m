f=imread('lena.jpg');
sampled=f(1:2:end,1:2:end);
imshow(sampled);
sampled2(1:2:256,1:2:256)=sampled;
sampled2(2:2:256,2:2:256)=sampled;
imshow(sampled2);