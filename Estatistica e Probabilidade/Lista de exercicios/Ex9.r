<<<<<<< HEAD
#9. calcule as principais medidas estatisticas básicas para cada coluna da matriz obtida no
#item anterior;

a = seq(1,90,2)
b = matrix(a, nrow = 15, ncol = 3)
c = rnorm(135, 6, 2)
d = matrix(a, nrow = 3, ncol = 15)
e = b %*% d
f = matrix(e[,3], e[,11], nrow = 15, ncol = 2)
cat("Media da coluna 1:", mean(f[,1]))
=======
#9. calcule as principais medidas estatisticas básicas para cada coluna da matriz obtida no
#item anterior;

a = seq(1,90,2)
b = matrix(a, nrow = 15, ncol = 3)
c = rnorm(135, 6, 2)
d = matrix(a, nrow = 3, ncol = 15)
e = b %*% d
f = matrix(e[,3], e[,11], nrow = 15, ncol = 2)
cat("Media da coluna 1:", mean(f[,1]))
>>>>>>> 4d687118a90e6f1ef766281ce9447fa83af69c76
#???