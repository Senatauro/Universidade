function correlacaoEConvolucao(Imagem, Mascara, Divisor)
  ImagemAumentada = zeros(size(Imagem)(1) + 4, size(Imagem)(2) + 4);
  for linha = 1:size(Imagem)(1)
    for coluna = 1:size(Imagem)(2)
      ImagemAumentada(linha+2, coluna + 2) = Imagem(linha, coluna);
    end
  end
  ImagemAumentada;
  MascaraRotacionada = rot90(rot90(Mascara))
  linha = 2;
  coluna = 2;
  %Pega de pedaco em pedaco a imagem
  for linha= 2 : size(ImagemAumentada)(1) -1
    for coluna = 2 : size(ImagemAumentada)(2) -1
      ImagemFinalCorrelacao(linha, coluna) = sum(sum(ImagemAumentada(linha - 1 : linha + 1, coluna - 1 : coluna + 1) .* Mascara)) / Divisor;
      ImagemFinalConvolucao(linha, coluna) = sum(sum(ImagemAumentada(linha - 1 : linha + 1, coluna - 1 : coluna + 1) .* MascaraRotacionada)) / Divisor;
    end
  end
  
  ImagemSomada = Imagem + ImagemFinalCorrelacao;
  
  %figure, imshow(uint8(ImagemFinalCorrelacao)), title("Correlacao");
  %figure, imshow(uint8(ImagemFinalConvolucao)), title("Convolucao");
  figure, imshow(uint8(ImagemSomada)), title("Soma da imagem original com a correlacao");
endfunction