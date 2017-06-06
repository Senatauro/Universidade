function conv2CMY()
  imagem = imread("circ.jpeg");
  imVerm = imagem(:,:,1);  
  imVerd = imagem(:,:,2);
  imAzul = imagem(:,:,3);
  
  %Vermelho é equivalente a ciano
  imC = 256 - imVerm;
  %Verde e equivalente a magenta
  imM = 256 - imVerd;
  %Azul e equivalente a amarelo
  imY = 256 - imAzul;
  
  imagemCMY = uint8(zeros(size(imagem)));
  imagemCMY(:,:,1) = imC;
  imagemCMY(:,:,2) = imM;
  imagemCMY(:,:,3) = imY;
  
  imshow(imagemCMY);
    
endfunction