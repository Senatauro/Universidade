#5. Crie uma nova matriz a partir da multiplicacão entre as matrizes obtidas nos itens 2 e 4;
# matriz1 %*% matriz2
#%*% = multiplicação de matrizes
a = seq(1,90,2)
b = matrix(a, nrow = 15, ncol = 3)
c = rnorm(135, 6, 2)
d = matrix(c, nrow = 3, ncol = 15)
e = b %*% d
e