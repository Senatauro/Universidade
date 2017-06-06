function operadoresLogicos()
  
  Im = imread("forma1.png");
  Im2 = imread("forma2.png");
  
  E = Im + Im2;
  Ou = or(Im, Im2);
  Xor = xor(Im, Im2);
  Nao = not(Im) + not(Im2);
  figure, imshow(E);
  figure, imshow(Ou);
  figure, imshow(Xor);
  figure, imshow(Nao);
  
endfunction