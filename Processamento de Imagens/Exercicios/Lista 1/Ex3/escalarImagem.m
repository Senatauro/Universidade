%A) Faça um script OCTAVE para ler a imagem “lenna.jpg” (240x256 pixels) do diretório local, usar a
%função imresize para gerar imagens com 64x64 pixels, 16x16 pixels, 512 x 512 pixels, 300 x 200 pixels,
%100 x 30 pixels a partir da imagem original, e depois apresentar os resultados usando a função
%imshow.
function escalarImagem()
  pkg load image
  Im = imread("flor.png");
  figure, imshow(Im);
  Im64 = imresize(Im, [64 64]);
  figure, imshow(Im64);
  Im16 = imresize(Im, [16 16]);
  figure, imshow(Im16);
  Im512 = imresize(Im, [512 512]);
  Im300 = imresize(Im, [300 200]);
  Im100 = imresize(Im, [100 30]);
  
  endfunction