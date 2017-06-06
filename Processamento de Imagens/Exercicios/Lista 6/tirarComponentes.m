function tirarComponentes()
  
  Imagem = imread("lenna.jpg");
  imVerd = Imagem(:,:,2);
  imVerm = Imagem(:,:,1);
  imAzul = Imagem(:,:,3);
  
  imagemVerd = zeros(size(Imagem));
  imagemAzul = zeros(size(Imagem));
  imagemVerm = zeros(size(Imagem));
  imagemVerd(:,:,2) = imVerd;
  imagemVerm(:,:,1) = imVerm;
  imagemAzul(:,:,3) = imAzul;
  
  figure, imshow(imVerm), title("Banda vermelha");
  figure, imshow(imVerd), title("Banda verde");
  figure, imshow(imAzul), title("Banda azul");
  
  figure, imshow(uint8(imagemVerd)), title("Imagem verde");
  figure, imshow(uint8(imagemVerm)), title("Imagem vermelha");
  figure, imshow(uint8(imagemAzul)), title("Imagem azul");
  
endfunction