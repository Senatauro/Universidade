#include<stdio.h>
#include<stdlib.h>

#define true 1
#define false 0
#define bool char

typedef struct Arvore_Int
{
    int valor;
    struct Arvore_Int *esquerda, *direita;
}Arvore_Int;

Arvore_Int* BuscarElemento(Arvore_Int **arvore, int elemento);

void main()
{
    Arvore_Int *arvore = NULL;
    AdicionarElemento(&arvore, 40);
    AdicionarElemento(&arvore, 25);
    AdicionarElemento(&arvore, 77);
    AdicionarElemento(&arvore, 15);
    AdicionarElemento(&arvore, 8);
    AdicionarElemento(&arvore, 33);
    AdicionarElemento(&arvore, 56);
    AdicionarElemento(&arvore, 90);
    AdicionarElemento(&arvore, 48);

    if(BuscarElemento(&arvore, 91) != NULL)
        printf("Encontrou o elemento 90\n");
    else
        printf("Elemento nao encontrado\n");
}


int ArvoreInicializada(Arvore_Int *arvre)
{
    return arvre == NULL ? false : true;
}

void AdicionarElemento(Arvore_Int **arvore, int elemento)
{
    Arvore_Int *arvre = *arvore;
    if(arvre == NULL)
    {
        arvre = (Arvore_Int*) malloc(sizeof(Arvore_Int));
        arvre->valor = elemento;
        arvre->esquerda = NULL;
        arvre->direita = NULL;
        *arvore = arvre;
    }
    else if(arvre->valor > elemento)
    {
        AdicionarElemento(&arvre->esquerda, elemento);
    }
    else if(arvre->valor < elemento)
    {
        AdicionarElemento(&arvre->direita, elemento);
    }
}

//nos esquerdos, raiz, nos direitos
void MostrarArvoreEmOrdem(Arvore_Int **arvore)
{
    Arvore_Int *arvre = *arvore;
    if(arvre->esquerda != NULL)
        MostrarArvoreEmOrdem(&arvre->esquerda);
    printf(" %d ", arvre->valor);
    if(arvre->direita != NULL)
        MostrarArvoreEmOrdem(&arvre->direita);
}

//Raiz, nos esquerdos, nos direitos
void MostrarArvorePreOrdem(Arvore_Int **arvore)
{
    Arvore_Int *arvre = *arvore;
    printf(" %d ", arvre->valor);
    if(arvre->esquerda != NULL)
        MostrarArvorePreOrdem(&arvre->esquerda);
    if(arvre->direita != NULL)
        MostrarArvorePreOrdem(&arvre->direita);
}

//Nos esquerdos, nos direitos, raiz
void MostrarArvorePosOrdem(Arvore_Int **arvore)
{
    Arvore_Int *arvre = *arvore;
    if(arvre->esquerda != NULL)
        MostrarArvorePosOrdem(&arvre->esquerda);
    if(arvre->direita != NULL)
        MostrarArvorePosOrdem(&arvre->direita);
    printf(" %d ", arvre->valor);
}

int CalcularProfundidade(Arvore_Int **arvore)
{
    Arvore_Int *arvre = *arvore;
    int profEsquerda = 0, profDireita = 0;
    if(arvre == NULL)
        return 0;
    profEsquerda = CalcularProfundidade(&arvre->esquerda) + 1;
    profDireita = CalcularProfundidade(&arvre->direita) + 1;

    if(profEsquerda > profDireita)
        return profEsquerda;
    else
        return profDireita;
}

Arvore_Int* BuscarElemento(Arvore_Int **arvore, int elemento)
{
    Arvore_Int *arvre = *arvore;
    if(arvre == NULL)
        return (Arvore_Int*)NULL;
    else if(arvre->valor == elemento)
        return arvre;
    else if(arvre->valor > elemento)
        return BuscarElemento(&arvre->esquerda, elemento);
    else
        return BuscarElemento(&arvre->direita, elemento);
}