function Ex2B()
  
  A = [1 2 3 4; 5 6 7 8; 9 10 11 12; 13 14 15 16]; 
  for linha = 1 : size(A)(1)
    for coluna = 1 : size(A)(2)
      if(rem(A(linha, coluna), 2) == 0)
        A(linha, coluna)++
      endif
    endfor
  endfor
  
endfunction