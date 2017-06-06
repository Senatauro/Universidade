function Barns()
  imagem = imread("Barns_grand_tetons.jpg");
  imCMY = conv2CMY(imagem);
  
  %imagem em ciano
  imC = ones(size(imCMY));
  imC(:,:,1) = imCMY(:,:,1);
  %size(imC)
  %imagem em magenta
  imM = ones(size(imCMY));
  imM(:,:,2) = imCMY(:,:,2);
  %size(imM)
  %imagem em amarelo
  imY = ones(size(imC));
  imY(:,:,3) = imCMY(:,:,3);
  %size(imY)

  
  figure, imshow(imC), title("Imagem em ciano");
  figure, imshow(imM), title("Imagem em magenta");
  figure, imshow(imY), title("Imagem em amarelo");
  
  figure, imshow((double(imC(:,:,1)) + double(imC(:,:,2)) + double(imC(:,:,3)))/3), title("imagem em ciano em tons de cinza");
  figure, imshow((double(imM(:,:,1)) + double(imM(:,:,2)) + double(imM(:,:,3)))/3), title("imagem em magenta em tons de cinza");
  figure, imshow((double(imY(:,:,1)) + double(imY(:,:,2)) + double(imY(:,:,3)))/3), title("imagem em amarelo em tons de cinza");
  
endfunction