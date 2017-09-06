#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ERRO_PILHA_VAZIA 100
#define ERRO_PILHA_POSICAO_NAO_EXISTE 101
#define PILHA_POSICAO_INICIAL -1000
#define true 1

typedef struct Estacionamento_Pilha
{
    int numVezesManobrado;
    char placa[9];
    struct Estacionamento_Pilha *proximo, *anterior;
}Estacionamento_Pilha;

char tamanhoPilha = 0;

Estacionamento_Pilha *InicializaPilha()
{
    Estacionamento_Pilha *pilha;
    pilha = malloc(sizeof(Estacionamento_Pilha));
    pilha->proximo = NULL;
    pilha->anterior = NULL;
    pilha->numVezesManobrado = PILHA_POSICAO_INICIAL;
    return pilha;
}

void push(Estacionamento_Pilha **topo, int te)
{
    Estacionamento_Pilha *top = *topo;
    top->proximo = malloc(sizeof(Estacionamento_Pilha));
    top->proximo->anterior = top;
    top->proximo->proximo = NULL;
    top = top->proximo;
    top->numVezesManobrado = te;
    int i = 0;
    memset(top->placa, '\0', 9);
    *topo = top;
}

Estacionamento_Pilha* pop(Estacionamento_Pilha **topo)
{
    if(PilhaVazia(topo))
        return NULL;
    Estacionamento_Pilha *top = *topo;
    Estacionamento_Pilha *nod = top;
    top = top->anterior;
    top->proximo = NULL;
    *topo = top;
    return nod;
}

Estacionamento_Pilha* popEspecifico(Estacionamento_Pilha **topo, int posicao)       //Função propria pra retirar carros
{
    Estacionamento_Pilha *nod = *topo;
    for(int i = tamanhoPilha; i > posicao; i--)
    {
        if(nod->anterior != NULL)
        {
            nod->numVezesManobrado++;
            nod = nod->anterior;
        }
        else
        {
            printf("\n\nretornou nulo\n\n");
            break;
        }
    }
    //proximo do anterior = anterior desse
    //creio eu que seja isso
    if(nod->proximo != NULL)
    {
        nod->anterior->proximo = nod->proximo;
        nod->proximo->anterior = nod->anterior;
    }
    else
    {
        nod->anterior->proximo = NULL;
        *topo = nod->anterior;
    }
    return nod;
    //printf("Retorno é: %d\n\n", nod->numVezesManobrado);
    //return nod->numVezesManobrado;
}

int PilhaVazia(Estacionamento_Pilha **pilha)
{
    Estacionamento_Pilha *pi = *pilha;
    if(pi->anterior == NULL)
        return 1;
    else
        return 0;
}

int ConsultaPilha(Estacionamento_Pilha **topo)
{
    Estacionamento_Pilha *top = *topo;
    return top->numVezesManobrado;
}

int ConsultaPilhaPorNivel(Estacionamento_Pilha **topo, int nivel)
{
    Estacionamento_Pilha *nod = *topo;
    for(int i = 0; i < nivel; i++)
        if(nod->anterior != NULL)
            nod = nod->anterior;
        else
            return ERRO_PILHA_POSICAO_NAO_EXISTE;
    //printf("Retorno é: %d\n\n", nod->numVezesManobrado);
    return nod->numVezesManobrado;
}

int ConsultarPorPlaca(Estacionamento_Pilha **topo, char* placa)
{
    Estacionamento_Pilha *nod = *topo;
    for(int i = tamanhoPilha; nod != NULL; i--)
    {
        if(strcmp(nod->placa, placa))
        {
            //printf("entrou aqui");
            nod = nod->anterior;
        }
        else
            return i;
    }
    return ERRO_PILHA_POSICAO_NAO_EXISTE;
}

void FinalizarPilha(Estacionamento_Pilha **topo)
{
    Estacionamento_Pilha *nod, *pilha = *topo;
    while(pilha->anterior != NULL)
    {
        nod = pilha->anterior;
        free(pilha);
        pilha = nod;
    }
    free(pilha);
    *topo = NULL;
}

void CopiarPilha(Estacionamento_Pilha **pilhaOriginal, Estacionamento_Pilha **pilhaCopia)
{
    Estacionamento_Pilha *pilhaOr = *pilhaOriginal;
    Estacionamento_Pilha *pilhaCop = NULL;
    while(pilhaOr->anterior != NULL)
    {
        pilhaOr = pilhaOr->anterior;
    }

    pilhaCop = malloc(sizeof(Estacionamento_Pilha));
    pilhaCop->anterior = NULL;
    pilhaCop->proximo = NULL;
    pilhaCop->numVezesManobrado = pilhaOr->numVezesManobrado;
    pilhaOr = pilhaOr->proximo;
    
    while(pilhaOr != NULL)
    {
        pilhaCop->proximo = malloc(sizeof(Estacionamento_Pilha));
        //pilhaCop->anterior = pilhaCop;
        //pilhaCop->proximo = NULL;
        //pilhaCop->numVezesManobrado = pilhaOr->numVezesManobrado;
        //pilhaOr = pilhaOr->proximo;
        if(pilhaOr->proximo != NULL)
            pilhaCop = pilhaCop->proximo;
    }
    *pilhaCopia = pilhaCop;
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

//Criar uma pilha com 10 posições
void main()
{
    Estacionamento_Pilha *pilha;    //Cria a variavel da pilha
    int opcao = 0;
    pilha = InicializaPilha();      //Inicializa a variavel da pilha
    //printf("%s\n", pilha->placa); //Testar se ta tudo certo
    do
    {
        printf("Estacionamento Empilhomaniaco:\nNumero de carros: %d", tamanhoPilha);
        printf("\n1 - Estacionar\n2 - Tirar\n\t");
        scanf("%d", &opcao);
        LimparTela();
        switch(opcao)
        {
            case 1:
            {
                char placa[9];
                if(tamanhoPilha >= 10)
                {
                    printf("Quantidade maxima de carros no estacionamento...\n");
                    break;
                }
                printf("Digite a placa do carro: ");
digitarPlaca:   scanf("%s", placa);
                if(strlen(placa) != 8)
                {
                    printf("Placa não digitada corretamente, digite denovo.\nEx: ABC-1234\n");
                    goto digitarPlaca;
                }
                else
                    placa[8] = '\0';            //identifica que ali é o fim da string para leituras futuras
                push(&pilha, 0);                //Cria novo carro no topo da pilha
                strcpy(pilha->placa, placa);    //Copia a placa recem digitada
                tamanhoPilha++;
                break;
            }
            case 2:
            {
                char placa[9];
                printf("Digite a placa do carro para ser retirado: ");
digitarPlaca1:  scanf("%s", placa);
                if(strlen(placa) != 8)
                {
                    printf("Placa não digitada corretamente, digite denovo.\nEx: ABC-1234\n");
                    goto digitarPlaca1;
                }
                else
                    placa[8] = '\0';
                int resposta = ConsultarPorPlaca(&pilha, placa);
                if(resposta == ERRO_PILHA_POSICAO_NAO_EXISTE)
                {
                    printf("Carro com placa %s nao encontrado, voltado ao menu...\n\n", placa);
                    break;
                }
                else
                {
                    printf("Carro com placa %s encontado na vaga %d\n", placa, resposta);
                    Estacionamento_Pilha *carro = popEspecifico(&pilha, resposta);
                    printf("Carro com placa %s foi manobrado %d vezes antes de sair\n\n", carro->placa, carro->numVezesManobrado);
                }
                tamanhoPilha--;
            }
            case 3:
            {
                
                printf("\nFechando programa...");
                return;
            }
            default:
            {
                printf("\nOpcao invalida, voltado ao menu...");
                break;
            }
        }
    }while(true);
}