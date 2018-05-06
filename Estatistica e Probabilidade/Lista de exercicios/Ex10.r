#10. faca um grafico de dispersao entre as colunas da matriz do item 8. Tente colocar o
#maximo de informacoes no grafico, por exemplo: titulo, nome dos eixos, cor diferente
#da default;

a = seq(1,90,2)
b = matrix(a, nrow = 15, ncol = 3)
c = rnorm(135, 6, 2)
d = matrix(a, nrow = 3, ncol = 15)
e = b %*% d
f = matrix(e[,3], e[,11], nrow = 15, ncol = 2)
