function Ex4()
  Imagem = imread("lena_cor.bmp");
  
  for linha = 1:size(Imagem)(1)
    for coluna = 1:size(Imagem)(2)
      NImagem(linha, coluna) = (Imagem(linha, coluna, 1) + Imagem(linha, coluna, 2) + Imagem(linha, coluna, 3)) / 3;
    endfor
  endfor
  
  imwrite(NImagem, "l.bmp");
endfunction