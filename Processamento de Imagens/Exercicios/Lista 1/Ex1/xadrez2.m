function f = xadrez2(altura, largura)
  [x y] = meshgrid(1:largura, 1:altura);
  x
  y
  y = rem((x+y),2);
  f = y;
endfunction
