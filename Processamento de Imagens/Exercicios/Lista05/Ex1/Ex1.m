%
% Recebe 2 matrizes e faz as operaçoes de uniao, interseccao e diferenca entre elas e mostra o resultado em janelas diferentes
%
function Ex1(MatrizA, MatrizB)
  
  figure, imshow(Uniao(MatrizA, MatrizB)), title("Uniao");
  
  figure, imshow(Interseccao(MatrizA, MatrizB)), title("Interseccao");
  
  figure, imshow(Diferenca(MatrizA, MatrizB)), title("Diferenca");
  
endfunction