  m = zeros(10,10);
  [l,c] = size(m);
  for linha = 1: l
    for coluna = 1 : c
        if (rem(linha+coluna,2) == 0)
          m(linha,coluna) = 0;
         else
          m(linha,coluna) = 1;
        end
    end
  end

  imshow(m);