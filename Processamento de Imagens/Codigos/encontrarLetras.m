%Funcao para procurar letras em uma matriz e devolver outra matriz 
%A mascara e a matriz que vai passar na matriz original verificando se a tal letras


%O peso ja vai ser declarado na mascara (---O peso serve para ajudar a calcular se tal pixel, na posicao atual da verificaçao, possui a cor correta---)
function f = encontrarLetras(Matriz, Mascara, Limite)
  
  MatrizAjustada = zeros(size(Matriz)(1) + (2 * size(Mascara)(1)), size(Matriz)(2) + (2 * size(Mascara)(2)));
  size(MatrizAjustada);
  size(Matriz);
  size(Mascara)(1);
  size(Matriz)(1) + size(Mascara)(1);
  size(Matriz)(1);
  size(Mascara)(2);
  size(Matriz)(2) + size(Mascara)(2);
  size(Matriz)(1);
  MatrizAjustada(1 + size(Mascara)(1) : size(Matriz)(1) + size(Mascara)(1), 1 + size(Mascara)(2) : size(Matriz)(2) + size(Mascara)(2)) = Matriz;
  
  MatrizFinal = zeros(size(Matriz)(1) + (2 * size(Mascara)(1)), size(Matriz)(2) + (2 * size(Mascara)(2)));
  soma = 0;
  %sum(sum(ImagemAumentada(linha - 1 : linha + 1, coluna - 1 : coluna + 1) .* Mascara)) / Divisor;
  
  for linha = round(size(Mascara)(1)/2) : size(MatrizAjustada)(1) - round(size(Mascara)(1)/2)
    for coluna = round(size(Mascara)(2)/2) : size(MatrizAjustada)(2) - round(size(Mascara)(2)/2)
      for linhaM = 1 : size(Mascara)(1)
        for colunaM = 1:size(Mascara)(2)
          soma = soma + (double(MatrizAjustada(linha + linhaM - (round(size(Mascara)(1)/2)), coluna + colunaM  - (round(size(Mascara)(1)/2)))) * Mascara(linhaM, colunaM));
          %soma = soma + (MatrizAjustada(linha + linhaM - size(Mascara)(1), coluna + colunaM  - size(Mascara)(2)) * Peso(linhaM, colunaM));
        endfor
      endfor
    if(soma > Limite)
    MatrizFinal(linha, coluna) = soma;
    else
      MatrizFinal(linha, coluna) = 0;
    endif
    %if(soma != 0)
    %  soma
    %  endif
    soma = 0;
    %MatrizFinal(linha, coluna) = MatrizAjustada(linha, coluna);
    endfor
  endfor
  
  figure, imshow(MatrizFinal), title("Matriz Final");
  f = MatrizFinal;
endfunction