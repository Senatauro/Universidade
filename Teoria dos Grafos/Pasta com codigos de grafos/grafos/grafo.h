#ifndef GRAFO_H_INCLUDED
#define GRAFO_H_INCLUDED

#include <stdlib.h>

typedef struct grafo {
   char *nome;
   int n;       // N�mero de v�rtices
   int m;       // N�mero de arestas
   int **adj;   // Ponteiro para a matriz de adjac�ncias
} Grafo;

int **gerarMatriz(int n) {

   int i, j;

   // Aloca um vetor de n ponteiros (do tipo int) na mem�ria
   int **m = malloc( n * sizeof (int *));

   // Para cada ponteiro, aloca n elementos (do tipo int) na mem�ria
   for (i = 0; i < n; i++)
      m[i] = malloc( n * sizeof (int));

   // Preenche cada c�lula da matriz com valor 0
   for (i = 0; i < n; i++)
      for (j = 0; j < n; j++)
         m[i][j] = 0;

   return m;
}

void inicializar(Grafo *g, char *nome, int n) {

    // Inicializa os par�metros da estrutura Grafo
    g->nome = nome;
    g->n = n;
    g->m = 0;
    g->adj = gerarMatriz(n);

}

void inserirAresta(Grafo *g, int v, int w) {

    // Garantindo que os argumentos est�o entre
    // 0 e n-1 (fechado)
    if( (v >= 0) && (v < g->n) ){
        if( (w >= 0) && (w < g->n) ){

            if (g->adj[v][w] == 0) { // Verifica se a aresta n�o existe
              // � necess�rio preencher as duas c�lulas com 1
              g->adj[v][w] = 1;
              g->adj[w][v] = 1;
              g->m++;
            }
        }
    }

}

void removerAresta(Grafo *g, int v, int w) {

    // Garantindo que os argumentos est�o entre
    // 0 e n-1 (fechado)
    if( (v >= 0) && (v < g->n) ){
        if( (w >= 0) && (w < g->n) ){

            if (g->adj[v][w] == 1) { // Verifica se a aresta existe
              // � necess�rio preencher as duas c�lulas com 0
              g->adj[v][w] = 0;
              g->adj[w][v] = 0;
              g->m--;
            }
        }
    }

}

void exibir(Grafo *g) {

   int v, w;


    printf("\n=================");
    printf("\n%s", g->nome);
    printf("\n=================");

    // Imprime o conjunto de v�rtices
    printf("\nV = {");

    for(v = 0; v < g->n; v++ )
        printf("%d, ", v);

    if(g->n > 0)
        printf("\b\b");
    printf("}");


    // Imprime o conjunto de arestas
    printf("\nA = {");
    for (v = 0; v < g->n; v++)
        for (w = 0; w < g->n; w++)
            if (g->adj[v][w] == 1)                  // Se os v�rtices s�o vizinhos
                if (v < w)                          // Considera apenas a regi�o superior � diagonal principal
                    printf("(%d, %d); ", v, w);   // Imprime

    if(g->m > 0)
        printf("\b\b");
    printf("}");

    printf("\n=================\n");
}

int grau(Grafo *g, int v){

    int soma;

    // Garantindo que os argumentos est�o entre
    // 0 e n-1 (fechado)
    if( (v >= 0) && (v < g->n) ){

        soma = 0;
        for(int i=0; i<g->n; i++)
            soma += g->adj[v][i];

    }

    return soma;

}

int grauMinimo(Grafo *g){

    int minimo = g->n;

    for(int i=0; i < g->n; i++){

        int grauI = grau(g, i);

        if( grauI < minimo )
            minimo = grauI;
    }

    return minimo;
}

int grauMaximo(Grafo *g){

    int maximo = -1;

    for(int i=0; i < g->n; i++){

        int grauI = grau(g, i);

        if( grauI > maximo )
            maximo = grauI;
    }

    return maximo;
}

int ehRegular(Grafo *g){

    if(g->n != 1){
        int valorGrau = grau(g, 0);

        for(int i=1; i<g->n; i++)
            if( grau(g,i) != valorGrau )
                return 0;
    }

    return 1;
}

int eh3Regular(Grafo *g){

    if(g->n != 1){
        int valorGrau = grau(g, 0);

        if(valorGrau != 3)
            return 0;

        for(int i=1; i<g->n; i++)
            if( grau(g,i) != valorGrau )
                return 0;

        return 1;
    }

    return 0;

}

Grafo *gMenosV(Grafo *g, int v){

    Grafo *h = malloc(sizeof (Grafo));
    inicializar(h, "G - v", g->n - 1);

    for(int i=0; i<g->n; i++){

        int l = i;

        if(i == v) continue;
        else
            if(i > v)
                l = i - 1;

        for(int j=0; j<g->n; j++){

            int c = j;

            if(j == v) continue;
            else
                if(j > v)
                    c = j - 1;

            h->adj[l][c] = g->adj[i][j];
        }
    }

    return h;
}

int ehCaminho(Grafo *g){

    if( g->n == 1)
        return 1;
    else{
        //Encontrar um v�rtice de grau 1 e
        //contar a qtd de v�rtices de grau 1.
        int vGrau1 = -1;
        int qtdGrau1 = 0;
        for(int v=0; v<g->n; v++){
            if( grau(g,v) == 1){
                vGrau1 = v;
                qtdGrau1++;
            }
        }

        //Se n�o houver v�rtice de grau 1 ou
        //se n�o houver dois v�rtices de grau 1, n�o � caminho
        if( vGrau1 == -1 || qtdGrau1 != 2)
            return 0;

        //Criar H = G - v (v�rtice de grau 1)
        Grafo *h = gMenosV(g, vGrau1);

        //Chamada recursiva para H
        return ehCaminho(h);
    }
}

int ehCircuito(Grafo *g)
{
    if(g->n<3)
        return 0;
    else
    {
        if(grauMinimo(g) != grauMaximo(g))
            return 0;
        else
        {
            for(int i = 0; i < g->n; i++)
            {

            }
        }
    }
}

#endif // GRAFO_H_INCLUDED
