function lerImagem()
  Im = imread("lenna.jpg");
  Verm = Im(:,:,1);
  Verd = Im(:,:,2);
  Azul = Im(:,:,3);
  figure, imshow(Im), title("Lenna colorida")
  figure, imshow([Verm Verd Azul]), title("Lenna em R G B")
  imwrite(Verm, "red.jpg");
  imwrite(Verd, "green.jpg");
  imwrite(Azul, "blue.jpg");
endfunction