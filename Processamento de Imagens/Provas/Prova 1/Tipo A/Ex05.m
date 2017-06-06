%1,0) Implemente uma função .m que calcule a distância entre dois objetos, utilizando a função:
% Euclidiana: De(p,q) = [(x-s)² + ( y-t)²]1/2

function distancia = distanciaEuclediana(x, y, s, t)
  distancia = [(x - s) .^2 + (y - t) .^ 2]^(1/2);