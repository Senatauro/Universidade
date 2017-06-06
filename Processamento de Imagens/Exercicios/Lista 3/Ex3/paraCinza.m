function paraCinza()
  Im = imread("lena_cor.bmp");
  for linha = 1:size(Im)(1)
    for coluna = 1:size(Im)(2)
      Cinza(linha, coluna) = (double(Im(linha, coluna, 1)) + double(Im(linha, coluna, 2)) + double(Im(linha, coluna, 3))) / 3;
    end
  end
  Cinza = uint8(Cinza);
  imshow(Cinza);
  
  NIm = Cinza - imread("lena_gray.bmp");
  figure, imshow(NIm);
  
endfunction