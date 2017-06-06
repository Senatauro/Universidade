function Ex3()
  
  Imagem = imread("lena_cor.bmp");
  %a)
  figure, imshow(Imagem), title("Lena Normal");
  
  %b)
  figure, imshow(Imagem(:,:,2)), title("Lena no canal 2(Verde)");
  %imwrite(Imagem(:,:,2), "lena verde.bmp");
  
  %c)
  size(Imagem)
  
  %d)
  figure, imshow(Imagem(:, 1: size(Imagem) - 50)), title("Lena com menos 50 pixels no lado direito");
  %imwrite(Imagem(:, 1: size(Imagem) - 50, :), "lena sem 50.bmp");
  
endfunction