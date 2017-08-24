#include <stdio.h>
#include <stdlib.h>

#define ERRO_LISTA_VAZIA 200
#define ERRO_LISTA_POSICAO_NAO_EXISTE 201
#define LISTA_POSICAO_INICIAL -2000

typedef struct int_Fila
{
    int aga;
    struct int_Fila *proximo, *anterior;
}int_Fila;

int_Fila *InicializaFila()
{
    int_Fila *fila;
    fila = malloc(sizeof(int_Fila));
    fila->proximo = NULL;
    fila->anterior = NULL;
    fila->aga = LISTA_POSICAO_INICIAL;
    return fila;
}

//feito para lista duplamente encadeada
void push(int_Fila **inicio, int te)
{
    int_Fila *ini = *inicio;
    //Caso não exista nada depois dessa fila
    //Cria o proximo elemento, coloca ele como o proximo e anterior
    //da cabeça da fila, e coloca o valor daquele elemento como te
    if(ini->proximo == NULL)
    {
        ini->proximo = malloc(sizeof(int_Fila));
        ini->anterior = ini->proximo;
        ini->proximo->anterior = ini;
        ini->proximo->proximo = ini;
        ini->proximo->aga = te;
    }
    //Se existir algo, pega a ultima posição da lista(o anterior a cabeça)
    //Cria algo na ultima posição(anterior a cabeça)
    //Coloca o anterior dessa ultima posição como o antigo anterior
    //E proximo como a cabeça
    else
    {
        int_Fila *ultimaPosicao = ini->anterior;
        ini->anterior = malloc(sizeof(int_Fila));
        ini->anterior->proximo = ini;
        ini->anterior->anterior = ultimaPosicao;
        ini->anterior->aga = te;
    }
}

int_Fila* pop(int_Fila **inicio)
{
    if(FilaVazia(inicio))
        return NULL;
    int_Fila *ini = *inicio;
    int_Fila *novoIni = ini;
    ini = ini->proximo;
    ini->anterior = NULL;
    inicio
}

void main()
{

}