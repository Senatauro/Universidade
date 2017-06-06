function f = RGB2HSI()
  imagem1 = imread("lena_cor.bmp");
  imagem = double(imagem1) / 255;
  radianos = acos(((imagem(:,:,1) - imagem(:,:,2) + imagem(:,:,1) - imagem(:,:,3)) / 2) ./ sqrt(pow2(imagem(:,:,1) - imagem(:,:,2)) + (imagem(:,:,1) - imagem(:,:,3)) .* (imagem(:,:,2) - imagem(:,:,3))));
  graus = (radianos * 180) / 3.1416;
  
  ESSE = zeros(size(graus));
  AGA = zeros(size(graus));
  I = zeros(size(graus));
  for linha = 1 : size(graus)(1)
    for coluna = 1 : size(graus)(2)
    %Calculo de I
    I(linha, coluna) = (imagem(linha, coluna, 1) + imagem(linha, coluna, 2) + imagem(linha, coluna, 3))/3;
    
    %Calculo de ESSE
    ESSE(linha, coluna) = 1 - (3/(imagem(linha, coluna, 1) + imagem(linha, coluna, 2) + imagem(linha, coluna, 3)) * min(min(imagem(linha, coluna, 1)), imagem(linha, coluna, 2)));
    
    %Calculo de AGA
      if(imagem(linha, coluna, 3) <= imagem(linha, coluna, 2))
        AGA(linha, coluna) = graus(linha, coluna);
      else
        AGA(linha, coluna) = 360 - graus(linha, coluna);
      endif
      
      %setores
      if(AGA < 120)
        ImagemHSI(linha, coluna,1) = I(linha, coluna) * (1 + (ESSE(linha, coluna) * cos(AGA(linha, coluna))) / cos(60 - AGA(linha, coluna)));
        ImagemHSI(linha, coluna,2) = I(linha, coluna) * (1 - ESSE(linha, coluna));
        ImagemHSI(linha, coluna,3) = 1 - (imagem(linha, coluna,1) - imagem(linha, coluna,3));
      elseif(AGA < 240)
        aga = AGA(linha, coluna) - 120;
        
        ImagemHSI(linha, coluna, 2) = I(linha, coluna) * (1 + (ESSE(linha, coluna) * cos(AGA(linha, coluna))) / cos(60 - AGA(linha, coluna)));
        ImagemHSI(linha, coluna, 1) = I(linha, coluna) * (1 - ESSE(linha, coluna));
        ImagemHSI(linha, coluna, 3) = 1 - (imagem(linha, coluna,1) - imagem(linha, coluna,2));
      else
        aga = AGA(linha, coluna) - 240;
        
        ImagemHSI(linha, coluna, 3) = I(linha, coluna) * (1 + (ESSE(linha, coluna) * cos(AGA(linha, coluna))) / cos(60 - AGA(linha, coluna)));
        ImagemHSI(linha, coluna, 2) = I(linha, coluna) * (1 - ESSE(linha, coluna));
        ImagemHSI(linha, coluna, 1) = 1 - (imagem(linha, coluna,2) - imagem(linha, coluna,3));
      endif
    endfor
  endfor
  imshow(ImagemHSI);
  f = ImagemHSI;
endfunction