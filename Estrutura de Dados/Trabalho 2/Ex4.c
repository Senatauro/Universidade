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

// Dada duas pilhas de elementos inteiros codificar um algoritmo que crie a pilha P3 intercalando os elementos da pilha P1 e P2.
void main()
{
    int_Pilha *pilhaA, *pilhaB, *pilhaC, *ajudador;
    int cont = 0;
    pilhaA = InicializaPilha();
    pilhaB = InicializaPilha();
    pilhaC = InicializaPilha();
    //P1: [1, 2, 3, 4]
    push(&pilhaA, 1);
    push(&pilhaA, 2);
    push(&pilhaA, 3);
    push(&pilhaA, 4);
    //P2: [5, 6, 7, 8]
    push(&pilhaB, 5);
    push(&pilhaB, 6);
    push(&pilhaB, 7);
    push(&pilhaB, 8);

    for(cont = 0; cont < 4; cont++)
    {
        ajudador = pop(&pilhaA);
        push(&pilhaC, ajudador->aga);
        ajudador = pop(&pilhaB);
        push(&pilhaC, ajudador->aga);
    }
    printf("Pilhas entrelaçadas:\n");
    for(cont = 0; cont < 10; cont++)
    {
        int retorno = ConsultaPilhaPorNivel(&pilhaC, cont);
        if(retorno == ERRO_PILHA_POSICAO_NAO_EXISTE || retorno == ERRO_PILHA_VAZIA || retorno == PILHA_POSICAO_INICIAL)
            break;
        printf("%d ", retorno);
    }
}