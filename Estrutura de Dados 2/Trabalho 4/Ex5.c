#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define true 1
#define false 0
#define bool char

typedef struct Arvore_String
{
    char valor[100];
    struct Arvore_String *esquerda, *direita;
}Arvore_String;

void main()
{
    Arvore_String *arvore = NULL;
    AdicionarElemento(&arvore, "abc");
    AdicionarElemento(&arvore, "bcd");
    AdicionarElemento(&arvore, "cde");
    AdicionarElemento(&arvore, "def");
    AdicionarElemento(&arvore, "efg");
    AdicionarElemento(&arvore, "fgi");
    AdicionarElemento(&arvore, "gih");
    AdicionarElemento(&arvore, "ihj");
    AdicionarElemento(&arvore, "hjk");

    MostrarArvoreEmOrdem(&arvore);
}

int ArvoreInicializada(Arvore_String *arvre)
{
    return arvre == NULL ? false : true;
}

void AdicionarElemento(Arvore_String **arvore, char *elemento)
{
    Arvore_String *arvre = *arvore;
    if(arvre == NULL)
    {
        arvre = (Arvore_String*) malloc(sizeof(Arvore_String));
        strcpy(arvre->valor, elemento);
        //arvre->valor = elemento;
        arvre->esquerda = NULL;
        arvre->direita = NULL;
        *arvore = arvre;
    }
    
    else if(strcmp(arvre->valor,elemento) > 0)
    {
        AdicionarElemento(&arvre->esquerda, elemento);
    }
    else if(strcmp(arvre->valor,elemento) < 0)
    {
        AdicionarElemento(&arvre->direita, elemento);
    }
}

//nos esquerdos, raiz, nos direitos
void MostrarArvoreEmOrdem(Arvore_String **arvore)
{
    Arvore_String *arvre = *arvore;
    if(arvre->esquerda != NULL)
        MostrarArvoreEmOrdem(&arvre->esquerda);
    printf(" %s ", arvre->valor);
    if(arvre->direita != NULL)
        MostrarArvoreEmOrdem(&arvre->direita);
}

//Raiz, nos esquerdos, nos direitos
void MostrarArvorePreOrdem(Arvore_String **arvore)
{
    Arvore_String *arvre = *arvore;
    printf(" %s ", arvre->valor);
    if(arvre->esquerda != NULL)
        MostrarArvorePreOrdem(&arvre->esquerda);
    if(arvre->direita != NULL)
        MostrarArvorePreOrdem(&arvre->direita);
}

//Nos esquerdos, nos direitos, raiz
void MostrarArvorePosOrdem(Arvore_String **arvore)
{
    Arvore_String *arvre = *arvore;
    if(arvre->esquerda != NULL)
        MostrarArvorePosOrdem(&arvre->esquerda);
    if(arvre->direita != NULL)
        MostrarArvorePosOrdem(&arvre->direita);
    printf(" %s ", arvre->valor);
}

int CalcularProfundidade(Arvore_String **arvore)
{
    Arvore_String *arvre = *arvore;
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
