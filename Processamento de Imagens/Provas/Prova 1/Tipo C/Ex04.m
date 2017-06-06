
im = imread('lena_gray.bmp');
%im = imread('image1.png');

% Item A
C = 2;
B = 30;

imN = uint8(C * double(im) + B);

subplot(1,2,1); imshow(im);
subplot(1,2,2); imshow(imN);

% Item B
C = 20;
imN = uint8(C * log2(double(im) + 1));

figure;
subplot(1,2,1); imshow(im);
subplot(1,2,2); imshow(imN);

% Item C
C = 30;
imN = uint8(C * exp(double(im)/255 + 1));

figure;
subplot(1,2,1); imshow(im);
subplot(1,2,2); imshow(imN);