function Ex2A()
  
  A = [1 2 3 4; 5 6 7 8; 9 10 11 12; 13 14 15 16]; 
  %a)
  B = A(1:3, 1:3)
  
  %b)
  for linha = 1 : size(A)(1)
    for coluna = 1 : size(A)(2)
      if(rem(A(linha, coluna), 2) == 0)
        A(linha, coluna)++;
      endif
    endfor
  endfor
  A
  
  %c)
  A = A(1:4, 2:4);
  A
  
endfunction