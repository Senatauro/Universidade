function lerImagem2()
  Im = imread("lenna.jpg");
  Verm = Im(:,:,1);
  Verd = Im(:,:,2);
  Azul = Im(:,:,3);
  figure, imshow(Verm), title("Lenna na banda vermelha")
  figure, imshow(Verd), title("Lenna na banda verde")
  figure, imshow(Azul), title("Lenna na banda azul")
  imwrite(Verm, "red.jpg");
  imwrite(Verd, "green.jpg");
  imwrite(Azul, "blue.jpg");
endfunction