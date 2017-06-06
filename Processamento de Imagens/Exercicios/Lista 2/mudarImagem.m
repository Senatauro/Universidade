function f = mudarImagem()
  %pegar a imagem original, pegar a intensidade de cada pixel e atribuir o valor de 255 - o valor do pixel
  %*Transformalo em negativo
  %e depois disso pegar o max da junçao de cada imagem
  Im = imread("esqueleto.png");
  %NIm = zeros(size(Im));
  for linha = 1:size(Im,1)
    for coluna = 1:size(Im,2)
      NIm(linha, coluna) = 255 - Im(linha, coluna);
      if(NIm(linha, coluna) > Im(linha, coluna))
        NNIm(linha,coluna) = max(NIm(linha, coluna), Im(linha,coluna));
      elseif(NIm(linha, coluna) < Im(linha,coluna))
        NNIm(linha,coluna) = max(Im(linha,coluna), NIm(linha, coluna));
      endif
      %NNNIm(linha, coluna) = ma
    end
  end
  %NNIm = max(NIm, Im);
  %for linha = 1 : size(
  %NNIm = max(NIm, Im);
  imshow(NNIm);
endfunction