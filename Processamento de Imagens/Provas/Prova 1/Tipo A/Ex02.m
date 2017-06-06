%a) Crie a matriz B como uma cópia de A, sem a última linha e coluna
%b) Crie uma função que: some +1 em todos os elementos pares de A (função para pegar o resto da
%divisão: rem)
%c) Remova a primeira coluna de A

%---------------A------------------
A = [1 2 3 4; 5 6 7 8; 9 10 11 12; 13 14 15 16];
B = A(1:3,1:3);

%---------------B------------------
function C = Ex02(A)
  [l,c] = size(A);
  C = zeros(l,c);
  for linha = 1: l
    for coluna = 1 : c
        if (rem(A(linha,coluna),2) == 0)
          C(linha,coluna) = A(linha,coluna) + 1;
         else
          C(linha,coluna) = A(linha,coluna);
        end
    end
  end
end

%---------------C------------------
D = (A(:,2:end))