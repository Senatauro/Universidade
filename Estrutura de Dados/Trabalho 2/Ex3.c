#include <stdio.h>
#include <stdlib.h>

#define ERRO_PILHA_VAZIA 100
#define ERRO_PILHA_POSICAO_NAO_EXISTE 101
#define PILHA_POSICAO_INICIAL -1000

typedef struct int_Pilha
{
    int aga;
    struct int_Pilha *proximo, *anterior;
}int_Pilha;

int_Pilha *InicializaPilha()
{
    int_Pilha *pilha;
    pilha = malloc(sizeof(int_Pilha));
    pilha->proximo = NULL;
    pilha->anterior = NULL;
    pilha->aga = PILHA_POSICAO_INICIAL;
    return pilha;
}

void push(int_Pilha **topo, int te)
{
    int_Pilha *top = *topo;
    top->proximo = malloc(sizeof(int_Pilha));
    top->proximo->anterior = top;
    top->proximo->proximo = NULL;
    top = top->proximo;
    top->aga = te;
    *topo = top;
}

int_Pilha* pop(int_Pilha **topo)
{
    if(PilhaVazia(topo))
        return NULL;
    int_Pilha *top = *topo;
    int_Pilha *nod = top;
    top = top->anterior;
    top->proximo = NULL;
    *topo = top;
    return nod;
}

int PilhaVazia(int_Pilha **pilha)
{
    int_Pilha *pi = *pilha;
    if(pi->anterior == NULL)
        return 1;
    else
        return 0;
}

int ConsultaPilha(int_Pilha **topo)
{
    int_Pilha *top = *topo;
    return top->aga;
}

int ConsultaPilhaPorNivel(int_Pilha **topo, int nivel)
{
    int_Pilha *nod = *topo;
    for(int i = 0; i < nivel; i++)
        if(nod->anterior != NULL)
            nod = nod->anterior;
        else
            return ERRO_PILHA_POSICAO_NAO_EXISTE;
    //printf("Retorno é: %d\n\n", nod->aga);
    return nod->aga;
}

void FinalizarPilha(int_Pilha **topo)
{
    int_Pilha *nod, *pilha = *topo;
    while(pilha->anterior != NULL)
    {
        nod = pilha->anterior;
        free(pilha);
        pilha = nod;
    }
    free(pilha);
    *topo = NULL;
}

void CopiarPilha(int_Pilha **pilhaOriginal, int_Pilha **pilhaCopia)
{
    int_Pilha *pilhaOr = *pilhaOriginal;
    int_Pilha *pilhaCop = NULL;
    while(pilhaOr->anterior != NULL)
    {
        pilhaOr = pilhaOr->anterior;
    }

    pilhaCop = malloc(sizeof(int_Pilha));
    pilhaCop->anterior = NULL;
    pilhaCop->proximo = NULL;
    pilhaCop->aga = pilhaOr->aga;
    pilhaOr = pilhaOr->proximo;
    
    while(pilhaOr != NULL)
    {
        pilhaCop->proximo = malloc(sizeof(int_Pilha));
        //pilhaCop->anterior = pilhaCop;
        //pilhaCop->proximo = NULL;
        //pilhaCop->aga = pilhaOr->aga;
        //pilhaOr = pilhaOr->proximo;
        if(pilhaOr->proximo != NULL)
            pilhaCop = pilhaCop->proximo;
    }
    
    *pilhaCopia = pilhaCop;
}

//Seja A uma seqüência formada por 20 números inteiros. Codifique um programa que coloque pares na pilha A e impares na pilha B

void main()
{
    int_Pilha *pilhaA, *pilhaB;
    int valorA, contadorB;
    pilhaA = InicializaPilha();
    pilhaB = InicializaPilha();

    //printf("%x     %x", pilhaA, pilhaB);
    for(contadorB = 0; contadorB < 20; contadorB++)
    {
        scanf("%d", &valorA);
        if(valorA % 2 == 0)
        {
            push(&pilhaA, valorA);
            int resposta = ConsultaPilha(&pilhaA);
            //printf("é numero par   %d\n\n", resposta);
        }
        else
        {
            push(&pilhaB, valorA);
            int resposta = ConsultaPilha(&pilhaB);
            //printf("é numero impar   %d\n\n", resposta);
        }
    }
    printf("numeros pares:\n\t");
    for(contadorB = 0; contadorB < 20; contadorB++)
    {
        int retorno = ConsultaPilhaPorNivel(&pilhaA, contadorB);
        if(retorno == ERRO_PILHA_POSICAO_NAO_EXISTE)
            break;
        else if(retorno != PILHA_POSICAO_INICIAL)
            printf("%d ", retorno);
    }
    printf("\n\nnumeros impares:\n\t");
    for(contadorB = 0; contadorB < 20; contadorB++)
    {
        int retorno = ConsultaPilhaPorNivel(&pilhaB, contadorB);
        if(retorno == ERRO_PILHA_POSICAO_NAO_EXISTE)
            break;
        else if(retorno != PILHA_POSICAO_INICIAL)
            printf("%d ", retorno);
    }
}
