%
% Função EXTREMAMENTE LENTA
% Faz o que tem que fazer, mas demora DEMAIS
% Para utilizar, passar a matriz em forma binaria, 0 ou 1, sendo 1 o pixel que possui valor
% O elementro estruturante em forma de matriz. O elemento 0 sera considerado o pixel com valor; Ex[0 0 0; 0 0 0; 1 0 1];
% O centro da matriz. Ex [2 3]  -> [x y]
%

function f = erodirImagem(Matriz, ElementoEstruturante, Centro)
  centroX = Centro(1);
  centroY = Centro(2);
  tic
  ImagemAjustada = zeros(size(Matriz)(1) + (2 * size(ElementoEstruturante)(1)), size(Matriz)(2) + (2* size(ElementoEstruturante)(2)));
  ImagemAjustada(1 + size(ElementoEstruturante)(1) : size(Matriz)(1) + size(ElementoEstruturante)(1),1 + size(ElementoEstruturante)(2) : size(Matriz)(2) + size(ElementoEstruturante)(2)) = Matriz;
  size(ImagemAjustada)
  NIm = zeros(size(Matriz)(1) + (2 * size(ElementoEstruturante)(1)), size(Matriz)(2) + (2* size(ElementoEstruturante)(2)));
  
  for linha = 1:size(ImagemAjustada)(1)
    for coluna = 1:size(ImagemAjustada)(2)
      if(ImagemAjustada(linha, coluna) == 1)
        for linhaE = 1:size(ElementoEstruturante)(1)
          for colunaE = 1:size(ElementoEstruturante)(2)
            if(ElementoEstruturante(linhaE, colunaE) == 0)
              if(NIm(linha, coluna) != 2) 
                  if(ImagemAjustada(linha + (linhaE - centroX), coluna + (colunaE - centroY), 1) == 1)
                    NIm(linha, coluna) = 1;
                    continue
                  else
                    NIm(linha, coluna) = 2;
                  endif
              else
                break
              endif
            endif
          endfor
          if(NIm(linha, coluna) == 2)
            NIm(linha, coluna) = 0;
            break
          elseif(NIm(linha, coluna) == 3)
            break
          endif
        endfor
      endif
    endfor
  endfor
  
  figure, imshow(NIm), title("Imagem Erodida");
  f = NIm(1 + size(ElementoEstruturante)(1) : size(Matriz)(1) + size(ElementoEstruturante)(1),1 + size(ElementoEstruturante)(2) : size(Matriz)(2) + size(ElementoEstruturante)(2));
  toc
  
endfunction

% Ps:
% Demora pra CARAMBA em matrizes maiores que 100x100 com o elemento maior que uma matriz de 5x5, paciencia