%4) (1,0) Abra o arquivo de imagem ‘lena_cor.bmp’. Crie uma imagem em tons de cinza com base na média
%dos 3 canais e exiba essa imagem

im1 = imread('lena_cor.bmp');
im1 = double(im1);
im = uint8((im1(:,:,1) + im1(:,:,2) + im1(:,:,3))/3);
imshow(im);
