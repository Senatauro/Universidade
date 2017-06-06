%
% Uma funçao que recebe a matriz que vai sofrer a operaçao de fechamento
% Outra matriz chamada de elemento estruturante, onde 0 significa pixel que vai sofrer alteraçao, qualquer outro valor e ignorado
% O centro da matriz. Ex [2 3]  -> [x y]
%
function f = fechamento(Matriz, ElementoEstruturante, Centro)
  
  dilatada = dilatarImagem(Matriz, ElementoEstruturante, Centro);
  erodida = erodirImagem(dilatada, ElementoEstruturante, Centro);
  figure, imshow(erodida), title("Imagem Fechada");
  f = erodida;
  
endfunction

% Ps:
% Demora pra caramba em matrizes maiores que 100x100 com o elemento maior que uma matriz de 5x5, paciencia