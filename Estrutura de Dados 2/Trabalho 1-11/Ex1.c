#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ERRO_FILA_VAZIA 100
#define ERRO_FILA_POSICAO_NAO_EXISTE 101
#define FILA_POSICAO_INICIAL -1000
#define true 1
#define false 0

typedef struct Fila
{
    int codigo;
    char nome[100];
    float preco;
    struct Fila *proximo, *anterior;
}Fila;

Fila *InicializaFila()
{
    Fila *fila;
    fila = malloc(sizeof(Fila));
    fila->proximo = NULL;                               //Proximo (se cabeça da fila, o 2 elemento)
    fila->anterior = NULL;                              //Anterior (se cabeça da fila, ultimo)
    fila->codigo = FILA_POSICAO_INICIAL;
    fila->preco = FILA_POSICAO_INICIAL;
    return fila;
}


/*
    Cabeça   proximo    nodo    proximo   nodo
       o        ->        o        ->       o
        ->          ->          ->      ->  Î
       anterior
*/

void push(Fila **cabeca, int cod, int prec)
{
    Fila *top = *cabeca;
    if(top->anterior != NULL)      //Caso já tenha posição na fila
    {
        top->anterior->proximo = malloc(sizeof(Fila));   //Pega o ultimo elemento e aloca uma posição depois dele
        top->anterior->proximo->proximo = NULL;                         //Indica fim de fila
        top->anterior->proximo->anterior = top->anterior;               //Coloca o elemento anterior do recem alocado como a ex ultima posicao
        top->anterior = top->anterior->proximo;                         //Coloca o novo ultimo elemento como a nova ultima posicao
    }
    else                            //Caso não tenha nenhuma posição na fila
    {
        top->proximo = malloc(sizeof(Fila));
        top->anterior = top->proximo;
        top->proximo->proximo = NULL;
        top->proximo->anterior = top;
    }
    top->anterior->codigo = cod;
    top->anterior->preco = prec;
    memset(top->anterior->nome, '\0', 100);
}

Fila* pop(Fila **cabeca)
{
    if(FilaVazia(cabeca))
        return NULL;
    Fila *cab = *cabeca;     //os 2 apontam para a cabeça da fila
    Fila *nod;
    if(cab->proximo->proximo != NULL)       //se passou pra ca, significa que a fila tem pelo menos 1 posicao
    {
        nod = cab->proximo;
        cab->proximo = cab->proximo->proximo;
    }                                       //verificar se existe proximo do proximo da cabeça, se existir, ele e a nova primeira posicao
    else
    {
        nod = cab->proximo;
        cab->proximo = NULL;
    }                                        //se não, nova primeira posicao e NULL
    return nod;
}

int FilaVazia(Fila **fila)
{
    Fila *fi = *fila;
    if(fi->proximo == NULL)
        return 1;
    else
        return 0;
}

//---- Funções uteis ----\\

void LimparTela()
{
    #ifdef _WIN32
    system("cls");
    #endif
    #ifdef linux
    system("clear");
    #endif
}

//---- Funções uteis ----\\

void main()
{
    Fila *fila;
    int filaOrdenada = false;
    int op;
    fila = InicializaFila();
    do
    {
        printf("1 - inserir valor\n2 - Ordenar Vetor\n3 - Busca Sequencial\n4 - Busca Binaria");
        switch(op)
        {
            case 1:
            {
                int codigo;
                char nome[100];
                float preco;
                printf("Digite o codigo de acesso: ");
                scanf("%d", &codigo);
                printf("Digite o preco: ");
                scanf("%f", &preco);
                push(&fila, codigo, preco);
                printf("Digite o nome do produto: ");
                scanf("%s", nome);
                strcpy(fila->anterior->nome, nome);
            }
            break;  
            case 2:
            break;
            case 3:
            break;
        }
    }while(op != 0);
}