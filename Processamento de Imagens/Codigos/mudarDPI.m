function f = mudarDPI(x, y, matriz)
  
  escX = round(size(matriz)(1) / x)
  escy = round(size(matriz)(2) / y)
  a = 1;
  b = 1;
  c = 1;
  d = 1;
  while(a < size(matriz,1))
    while(b < size(matriz,2))
      Im(c,d) = matriz(a,b);
      d = d + 1;
      b = b + escy;
    endwhile
    c = c + 1;
    a = a + escX;
    b = 1;
    d = 1;
  endwhile
  
  f = Im;
endfunction