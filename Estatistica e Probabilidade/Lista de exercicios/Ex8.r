#8. Extraia da matriz obtida no item 6 as colunas 3 e 11 e crie uma nova matriz com
#duas colunas. Caso o item 6 nao tenha sido resolvido, pelo fato da matriz nao aceitar
#inversa, pegar as colunas da matriz do item 5;

a = seq(1,90,2)
b = matrix(a, nrow = 15, ncol = 3)
c = rnorm(135, 6, 2)
d = matrix(a, nrow = 3, ncol = 15)
e = b %*% d
f = matrix(e[,3], e[,11], nrow = 15, ncol = 2)
f