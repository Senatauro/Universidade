function a = quantizarAImagem(numBits, salvar, nomeParaSalvar)
  Im = imread("cameraman.png");
  if (numBits > 7)
    escala = 256
  elseif (numBits == 7)
    escala = 128
  elseif (numBits == 6)
    escala = 64
  elseif (numBits == 5)
    escala = 32
  elseif (numBits == 4)
    escala = 16
  elseif (numBits == 3)
    escala = 8
  elseif (numBits == 2)
    escala = 4
  elseif (numBits == 1)
    escala = 2
   elseif numBits < 1
    escala = 2
   endif
  for linha = 1:size(Im)(1)
    
    for coluna = 1:size(Im)(2)
      Ima(linha, coluna) =  (((  round((double(Im(linha, coluna)) * (escala))/256)   )*256)/(escala-1) );
      %fix((double(Im(linha, coluna)) * escala)/256)
      end
      
    end
    if (salvar)
      imwrite(uint8(Ima), nomeParaSalvar);
    endif
    figure, imshow(uint8(Ima));
    a = uint8(Ima);
  endfunction