%1,0) Implemente uma fun��o .m que calcule a dist�ncia entre dois objetos, utilizando a fun��o:
% Euclidiana: De(p,q) = [(x-s)� + ( y-t)�]1/2

function distancia = distanciaEuclediana(x, y, s, t)
  distancia = [(x - s) .^2 + (y - t) .^ 2]^(1/2);