function jota = rotularImagem(matrix)
  Im = matrix;
  NIm = zeros(size(matrix)(1),size(matrix)(2));
  rotulo = 1;
%  for linha = 1:size(matrix)(2)
%    for coluna = 1:size(matrix)(1)
%      if(Im(linha,coluna) == 0 && NIm(linha, coluna) == 0)
        
        
  for linha = 1:size(matrix)(1)
    for coluna = 1:size(matrix)(2)
      if(Im(linha, coluna) == 1)
        if(Im(linha - 1, coluna) == 0 && NIm(linha, coluna - 1) == 0)
          NIm(linha, coluna) = rotulo;
          rotulo = rotulo + 1
        elseif(NIm(linha - 1, coluna) != 0 && NIm(linha, coluna - 1) == 0)
          NIm(linha, coluna) = NIm(linha - 1, coluna);
        elseif(NIm(linha, coluna - 1) != 0 && NIm(linha - 1, coluna) == 0)
          NIm(linha, coluna) = NIm(linha, coluna - 1);
        elseif(NIm(linha -  1, coluna) == NIm(linha, coluna -1))
          NIm(linha, coluna) = NIm(linha -  1, coluna);
        elseif(NIm(linha - 1, coluna) != NIm(linha, coluna - 1) == 1)
          NIm(linha, coluna) = NIm(linha - 1, coluna);
        endif
        
      endif
    end
  end
  jota = NIm;
  imshow(NIm);
  
endfunction