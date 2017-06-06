%2) (1,0) Dada a matriz A = [5 6 7 9; 18 5 4 20; 13 2 4 9; 20 3 1 6], crie uma função .m que:
%a)	Crie a matriz B como uma cópia de A, adicione mais uma linha e coluna a esquerda de B com valores zeros.
%b)	Crie uma função que: dívida por 2 todos os elementos pares de A (função para pegar o resto da divisão: rem)
%c)	Remova a primeira coluna de B

%---------------A------------------
A = [5 6 7 9; 18 5 4 20; 13 2 4 9; 20 3 1 6]
[l,c] = size(A);
B = zeros(l+1,c+1);
B(1:end-1,2:end) = A

%---------------B------------------
function C = Ex02(A)
  [l,c] = size(A);
  C = zeros(l,c);
  for linha = 1: l
    for coluna = 1 : c
        if (rem(A(linha,coluna),2) == 0)
          C(linha,coluna) = A(linha,coluna) / 2;
         else
          C(linha,coluna) = A(linha,coluna);
        end
    end
  end
end

%---------------C------------------
D = (B(:,2:end))