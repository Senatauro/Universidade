%
% Uma funçao que recebe a matriz que vai sofrer a operaçao de abertura
% Outra matriz chamada de elemento estruturante, onde 0 significa pixel que vai sofrer alteraçao, qualquer outro valor e ignorado
% O centro da matriz. Ex [2 3]  -> [x y]
%
function f = abertura(Matriz, ElementoEstruturante, Centro)
  
  erodida = erodirImagem(Matriz, ElementoEstruturante, Centro);
  dilatada = dilatarImagem(erodida, ElementoEstruturante, Centro);
  figure, imshow(dilatada), title("Imagem Aberta");
  f = dilatada;
  
endfunction

% Ps:
% Demora pra caramba em matrizes maiores que 100x100 com o elemento maior que uma matriz de 5x5, paciencia