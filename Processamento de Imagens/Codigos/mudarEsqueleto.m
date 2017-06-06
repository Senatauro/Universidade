function f = mudarEsqueleto()
  
  Imagem = imread("esqueleto.png");
  IntensidadeMedia = 0;
  for linha = 1:size(Imagem)(1)
    for coluna = 1:size(Imagem)(2)
      IntensidadeMedia = IntensidadeMedia + double(Imagem(linha, coluna));
    end
  end
  
  IntensidadeMediaFinal = (round(IntensidadeMedia / (size(Imagem)(1) * size(Imagem)(2))) * 2) - 31
  for linha = 1:size(Imagem)(1)
    for coluna = 1:size(Imagem)(2)
      if (Imagem(linha, coluna) < IntensidadeMediaFinal)
        MatrizFinal(linha, coluna) = IntensidadeMediaFinal;
      else
        MatrizFinal(linha, coluna) = Imagem(linha, coluna);
      endif
    end
  end
  f = MatrizFinal;
  
  imshow(uint8(MatrizFinal));
  
endfunction