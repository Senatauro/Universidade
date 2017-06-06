function aga = rotular8Conectados(matrizOriginal)
  MatrizAumentada = zeros(size(matrizOriginal)(1) + 2,size(matrizOriginal)(2) + 2);
  MatrizAumentada(2:size(MatrizAumentada)(1)-1, 2:size(MatrizAumentada)(2)-1) = matrizOriginal;
  MatrizRotulada = zeros(size(matrizOriginal)(1) + 2,size(matrizOriginal)(2) + 2);
  linha = 1;
  coluna = 1;
  NumRotulo = 1;
  while linha < size(MatrizAumentada)(1)
    while coluna < size(MatrizAumentada)(2)
      if(MatrizAumentada(linha, coluna) == 1 && MatrizRotulada(linha, coluna) == 0)
        
        if(MatrizRotulada(linha - 1, coluna - 1) != 0)
          MatrizRotulada(linha, coluna) = MatrizRotulada(linha - 1, coluna - 1);
          
        elseif(MatrizRotulada(linha - 1, coluna) != 0)
          MatrizRotulada(linha, coluna) = MatrizRotulada(linha - 1, coluna);
          
        elseif(MatrizRotulada(linha - 1, coluna + 1) != 0)
          MatrizRotulada(linha, coluna) = MatrizRotulada(linha - 1, coluna + 1);
          
        elseif(MatrizRotulada(linha, coluna - 1) != 0)
          MatrizRotulada(linha, coluna) = MatrizRotulada(linha, coluna - 1);
        else
          MatrizRotulada(linha, coluna) = NumRotulo;
          NumRotulo = NumRotulo + 1;
        endif
        
      endif
      coluna = coluna + 1;
    end
    coluna = 1;
    linha = linha + 1;
  end
  aga = MatrizRotulada;
endfunction