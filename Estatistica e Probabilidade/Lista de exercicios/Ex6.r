#Calcule a inversa da matriz do item anterior
a = seq(1,90,2)
b = matrix(a, nrow = 15, ncol = 3)
c = rnorm(135, 6, 2)
d = matrix(c, nrow = 3, ncol = 15)
e = b %*% d
f = solve(M)
f
#Caso com solve não de certo:
#----------------------------------------------
#
#          Invertendo matriz no R
#
#----------------------------------------------
#obs<-c(1,3,2,4,0,3,3,8,5)
#Gerando Matriz Quadrada
#matriz_original<-matrix(obs,ncol=sqrt(length(obs)))
# Encontrando a Matriz dos Cofatores
#matriz_cof<-matrix(rep(0,length(matriz_original)),ncol=sqrt(length(obs)))
#for(i in 1:length(matriz_original[1,])){
#	for(j in 1:length(matriz_original[,1])){
#	matriz_cof[i,j]<-((-1)**(i+j))*det(matriz_original[-i,-j])
#	}
#}
# A matriz inversa é dada pela formula da razão de 1/determinante
#multiplicado pela matriz transposta da inversa
#matriz_inversa<-(1/det(matriz_original)) * t(matriz_cof)
#matriz_inversa