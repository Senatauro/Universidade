function f = diferenca()
  
  Im = imread("cena1.png");
  Im2 = imread("cena2.png");
  
  f = Im - Im2;
  
endfunction