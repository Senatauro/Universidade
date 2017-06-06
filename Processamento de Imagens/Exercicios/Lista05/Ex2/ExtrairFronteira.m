%
% Funçao feita para extrair e retornar a fronteira de uma imagem
% Para utilizar, passar a matriz em forma binaria, 0 ou 1, sendo 1 o pixel que possui valor
% O elementro estruturante em forma de matriz. O elemento 0 sera considerado o pixel com valor; Ex[0 0 0; 0 0 0; 1 0 1];
% O centro da matriz. Ex [2 3]  -> [x y]
% E o tipo de extracao de fronteira, Externa = 1, interna = 0
%
function Fronteira = ExtrairFronteira(Matriz, ElementoEstruturante, Centro, Tipo)
  if(Tipo == 1)
    Dil = dilatarImagem(Matriz, ElementoEstruturante, Centro);
    Fronteira = Matriz - Dil;
  else if(Tipo == 2)
    Ero = erodirImagem(Matriz, ElementoEstruturante, Centro);
    Fronteira = Matriz - Ero;
  endif
endfunction