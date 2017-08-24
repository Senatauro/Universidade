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
        if(pilhaOr->proximo != NULL)
            pilhaCop = pilhaCop->proximo;
    }
    
    *pilhaCopia = pilhaCop;
}

//2) Seja S uma cadeia formada exclusivamente por caracteres “+” e “-“, seja N o número
//máximo de elementos que uma pilha pode conter. Codificar um programa que quando o
//caracter da cadeia for “+” empilhe (Push) e se for “-“ desempilhe. Indicar se ocorreu
//“Estouro de Pilha” ou “Pilha Vazia”.
void main()
{
    int_Pilha *pilha;
    int maxPilha, cont, tamanhoPilha = 0;;
    char ordens[100];
    pilha = InicializaPilha();
    printf("Digite o numero maximo da pilha:");
    scanf("%d", &maxPilha);
    printf("Digite os comandos(não separados por espaco):\n");
    scanf("%s", ordens);
    for(cont = 0; ordens[cont] != '\0'; cont++)
    {
        if(ordens[cont] == '+')
        {
            if(tamanhoPilha < maxPilha)
            {
                push(&pilha, 0);
                tamanhoPilha++;
            }
            else
            {
                printf("Estouro de Pilha\n");
            }
        }
        else if(ordens[cont] == '-')
        {
            if(tamanhoPilha > 0)
            {
                pop(&pilha);
                tamanhoPilha--;
            }
            else
            {
                printf("Pilha Vazia");
            }
        }
    }
}