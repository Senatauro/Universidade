clear all;
clc;
close all;

im1 = imread('forma1.png');
im2 = imread('forma2.png');

figure;
imshow(im1)
figure;
imshow(im2)

im1 = double(im1)/255;
im2 = double(im2)/255;

%A
im3 = im1 & im2;
figure;
imshow(im3)

%B
im3 = im1 | im2;
figure;
imshow(im3)

%C
im3 = xor(im1,im2);
figure;
imshow(im3)

%D
im4 = ~im1;
figure;
imshow(im4)