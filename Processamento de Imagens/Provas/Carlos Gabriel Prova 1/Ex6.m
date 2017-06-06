function xa = Ex6(tamanho)
  
  for linha = 1 : tamanho
    for coluna = 1 : tamanho
      if(rem(linha + coluna, 2) == 0)
        Xadres(linha, coluna) = 0;
      else
        Xadres(linha, coluna) = 1;
      endif
    endfor
  endfor
  xa = Xadres;
endfunction