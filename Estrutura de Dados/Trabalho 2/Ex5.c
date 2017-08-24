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

//Elabore um programa que transforme um número decimal em binário. Usando a estrutura de pilha
void main()
{
    int_Pilha *pilha;
    int numero, i, h;
    pilha = InicializaPilha();
    scanf("%d", &numero);

    for(i = 0; numero != 0; i++)
    {
        //operações de bits, too much rasquer!
        if(numero & 1 == 1)         //Checa se o ultimo bit de numero e 1 são iguais
            push(&pilha, 1);        //Caso sejam, empilha 1!
        else
            push(&pilha, 0);        //Caso contrario, 0¡ 
        //printf("%d - bit em 2^%d\n", numero & 1, i);  //Comentarios dos comentarios
        //for(h = 0; h < 50000000; h++)   //For para deixar bonitinho a amostra(da um certo delay)
        //{
        //}
        numero = numero >> 1;        
    }
    for(; i > 0; i--)
    {
        printf("%d - bit na posicao 2^%d\n", pop(&pilha)->aga, i-1);
    }

    //numero & 1 ? printf("1\n") : printf("0\n");
    //numero = numero >> 1;                           
    //printf("Numero : %d\n", numero);
    //numero & 1 ? printf("1\n") : printf("0\n");
    //numero = numero >> 1;
    //printf("Numero : %d\n", numero);
}