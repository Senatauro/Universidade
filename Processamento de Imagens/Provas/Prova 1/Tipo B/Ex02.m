%1,0) Dada a matriz A = [11 21 31 41; 51 61 71 81; 91 100 111 121; 131 141 151 161], crie uma fun��o .m que:
%a)	Crie a matriz B como uma c�pia de A, adicione mais uma linha e coluna em B com valores zeros.
%b)	Crie uma fun��o que: multiplique 2 em todos os elementos impares de A (fun��o para pegar o resto da divis�o: rem)
%c)	Remova a �ltima coluna de B


A = [11 21 31 41; 51 61 71 81; 91 100 111 121; 131 141 151 161];
[l,c] = size(A);
B = zeros(l+1,c+1);
B(1: end-1,1: end-1) = A;


%---------------B------------------
function C = Ex02(A)
  [l,c] = size(A);
  C = zeros(l,c);
  for linha = 1: l
    for coluna = 1 : c
        if (rem(A(linha,coluna),2) != 0)
          C(linha,coluna) = A(linha,coluna) * 2;
         else
          C(linha,coluna) = A(linha,coluna);
        end
    end
  end
end

%--------------C------------------
C = B(:,1:end-1)