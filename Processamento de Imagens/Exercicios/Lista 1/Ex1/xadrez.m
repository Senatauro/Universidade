function f = xadrez(altura, largura)
  for row = 1:altura
    for col = 1:largura
      y(row, col)= rem((row + col),2);
    end
  end
  f = y;
endfunction