function f = calcularDistancia(x1, y1, x2, y2)
  f(1) = sqrt((x1 - x2)^2 + (y1 - y2)^2)
  a = x1 - x2
  b = y1 - y2
  if(a < 0)
    a = a * -1
  endif
  if(b < 0)
    b = b * -1
  endif
  f(2) = a + b
  f(3) = max(a, b)
endfunction