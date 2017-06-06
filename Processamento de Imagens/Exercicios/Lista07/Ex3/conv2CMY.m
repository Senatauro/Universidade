function f = conv2CMY(Matriz)
  %imagem = imread("circ.jpeg");
  imVerm = Matriz(:,:,1);  
  imVerd = Matriz(:,:,2);
  imAzul = Matriz(:,:,3);
  
  %Vermelho é equivalente a ciano
  imC = ones(size(Matriz));
  imC(:,:,1) = 1 - (double(imVerm)/255); 
  %imC(:,:,2) = 1;
  %imC(:,:,3) = 1;
  %Verde e equivalente a magenta
  imM = ones(size(Matriz));
  imM(:,:,2) = 1 - (double(imVerd)/255);
  %imM(:,:,1) = 1;
  %imM(:,:,3) = 1;
  %Azul e equivalente a amarelo
  imY = ones(size(Matriz));
  imY(:,:,3) = 1 - (double(imAzul)/255);
  %imY(:,:,1) = 1;
  %imY(:,:,2) = 1;
  
  imCMY(:,:,1) = imC(:,:,1);
  imCMY(:,:,2) = imM(:,:,2);
  imCMY(:,:,3) = imY(:,:,3);
    
  %figure, imshow(imC), title("imagem em ciano");
  %figure, imshow(imM), title("imagem em magenta");
  %figure, imshow(imY), title("imagem em amarelo");
  
  %figure, imshow((double(imC(:,:,1)) + double(imC(:,:,2)) + double(imC(:,:,3)))/3), title("imagem em tons de cinza inverso");
  
  %imshow(imagemCMY);
  f = imCMY;
    
endfunction