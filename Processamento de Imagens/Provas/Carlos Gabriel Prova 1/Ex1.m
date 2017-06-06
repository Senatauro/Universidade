function Ex1()
  A = [1 2; 3 4]
  B = [5 6; 7 8]
  %a)
  E = [1 2; 3 4; 5 6; 7 8] 
  %Cria uma matriz E 4x2 com os valores determinados e mostrar o resultado
  
  %b)
  A + 5 
  %Vai somar o valor de todas as posicoes da matriz A com 5 e mostrar o resultado
  
  %c)
  A / 2
  %Vai dividir o valor de todas as posicoes A por 2 e mostrar o resultado
 
  %d)
  A + B
  %Vai somar a matriz A com a matriz B, ponto a ponto e mostrar o resultado
  
  %e)
  C = A + B
  %Vai armazenar a matriz resultante da soma da matriz A com B e mostrar o resultado
  
  %f)
  [m,n] = size(B)
  %Vai armazenar a quantidade de linhas e colunas que a matriz B possui, sendo m o numero de linhas, e n o numero de colunas e mostrar o resultado
  
  %g)
  A * B
  %Vai multiplicar a matriz A pela matriz B, resultando em uma nova matriz que é o arranjo matricial de A com B, e não multiplicar ponto a ponto os valores e mostrar o resultado
  
  %h)
  A .* B
  %Vai multiplicar ponto a ponto os valores da matriz A com os da matriz B e mostrar o resultado
  
  %i)
  y = 2^3
  %Vai armazenar o valor de 2 elevado a 3(2 ao cubo) em uma nova variavel chamada y e mostrar o resultado
  
  %j)
  A / B
  %Vai dividir a matriz A pela matriz B, resultando em uma nova matriz que é o arranjo matricial de A com B, e não dividindo ponto a ponto e mostrar o resultado
  
  %k)
  A ./ B
  %Vai dividir ponto a ponto os valores da matriz A pelo os da matriz B e mostrar o resultado
  
  %l)
  C = [A B; B A]
  %Vai criar uma nova matriz 4x4 que as 2 primeiras linhas são a concatenação da matriz A com a B e a 3° e 4° linhas a concatenação da matriz B com a A e mostrar o resultado
  
  %m)
  C(2,2) = 0
  %Vai atribuir o valor na posição 2x2 da matriz C como 0
  
endfunction