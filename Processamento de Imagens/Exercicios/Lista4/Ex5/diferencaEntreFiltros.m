function diferencaEntreFiltros()
  pkg load image
  filtroP = filtroPrewitt(false);
  
  filtroS = filtroSobel(false);
  
  diferenca = filtroP .- filtroS;
  figure, imshow(diferenca * 2), title("Filtro Prewitt - filtro Sobel multiplicado por 128");
  figure, imshow([imcomplement(filtroP) ones(size(filtroP)(1), 40) imcomplement(filtroS)]), title("Filtro Prewitt e Sobel");
  
endfunction