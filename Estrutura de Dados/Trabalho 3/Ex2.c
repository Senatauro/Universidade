#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ERRO_FILA_VAZIA 100
#define ERRO_FILA_POSICAO_NAO_EXISTE 101
#define FILA_POSICAO_INICIAL -1000
#define true 1

typedef struct Estacionamento_Fila
{
    int numVezesManobrado;
    char placa[9];
    struct Estacionamento_Fila *proximo, *anterior;
}Estacionamento_Fila;

char tamanhoFila1 = 0;                                  //tamanho da fila no estacionamento
char tamanhoFila2 = 0;                                  //tamanho da fila de espera

Estacionamento_Fila *InicializaFila()
{
    Estacionamento_Fila *Fila;
    Fila = malloc(sizeof(Estacionamento_Fila));
    Fila->proximo = NULL;                               //Proximo (se cabeça da fila, o 2 elemento)
    Fila->anterior = NULL;                              //Anterior (se cabeça da fila, ultimo)
    Fila->numVezesManobrado = FILA_POSICAO_INICIAL;
    return Fila;
}


/*
    Cabeça   proximo    nodo    proximo   nodo
       o        ->        o        ->       o
        ->          ->          ->      ->  Î
       anterior
*/

void push(Estacionamento_Fila **cabeca, int te)
{
    Estacionamento_Fila *top = *cabeca;
    if(top->anterior != NULL)      //Caso já tenha posição na fila
    {
        top->anterior->proximo = malloc(sizeof(Estacionamento_Fila));   //Pega o ultimo elemento e aloca uma posição depois dele
        top->anterior->proximo->proximo = NULL;                         //Indica fim de fila
        top->anterior->proximo->anterior = top->anterior;               //Coloca o elemento anterior do recem alocado como a ex ultima posicao
        top->anterior = top->anterior->proximo;                         //Coloca o novo ultimo elemento como a nova ultima posicao
    }
    else                            //Caso não tenha nenhuma posição na fila
    {
        top->proximo = malloc(sizeof(Estacionamento_Fila));
        top->anterior = top->proximo;
        top->proximo->proximo = NULL;
        top->proximo->anterior = top;
    }
    top->anterior->numVezesManobrado = te;
    memset(top->anterior->placa, '\0', 9);
}

Estacionamento_Fila* pop(Estacionamento_Fila **cabeca)
{
    if(FilaVazia(cabeca))
        return NULL;
    Estacionamento_Fila *cab = *cabeca;     //os 2 apontam para a cabeça da fila
    Estacionamento_Fila *nod;
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

int ConsultaFila(Estacionamento_Fila **cabeca)
{
    if(FilaVazia(cabeca))
        return FILA_POSICAO_INICIAL;
    Estacionamento_Fila *top = *cabeca;
    return top->proximo->numVezesManobrado;
}

int FilaVazia(Estacionamento_Fila **fila)
{
    Estacionamento_Fila *fi = *fila;
    if(fi->proximo == NULL)
        return 1;
    else
        return 0;
}

//---- Funções especificas ----\\

int ConsultarPorPlaca(Estacionamento_Fila **cabeca, char* placa)
{
    Estacionamento_Fila *nod = *cabeca;
    for(int i = 0; nod != NULL; i++)
    {
        if(strcmp(nod->placa, placa))
        {
            //printf("entrou aqui");
            nod = nod->proximo;
        }
        else
            return i;
    }
    return ERRO_FILA_POSICAO_NAO_EXISTE;
}

Estacionamento_Fila* popEspecifico(Estacionamento_Fila **cabeca, int posicao)       //Função propria pra retirar carros
{
    Estacionamento_Fila *nod = *cabeca;
    for(int i = 0; i < posicao; i++)
    {
        if(nod->proximo != NULL)
        {
            nod->numVezesManobrado++;
            nod = nod->proximo;
        }
        else
        {
            printf("\n\nretornou nulo\n\n");
            //break;
            return NULL;
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
        //*cabeca = nod->anterior;
    }
    return nod;
    //printf("Retorno é: %d\n\n", nod->numVezesManobrado);
    //return nod->numVezesManobrado;
}

//---- Funções especificas ----\\

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
    Estacionamento_Fila *estacionamento, *filaDeEspera;
    int opcao = 0;
    estacionamento = InicializaFila();
    filaDeEspera = InicializaFila();
    LimparTela();    
    do
    {
        printf("Sistema de gerenciamentos do **Estacionamento Filastatico**\nNumero de carros no estacionamento: %d\nNumero de carros na fila de espera: %d", tamanhoFila1, tamanhoFila2);
        printf("\n1 - Estacionar\n2 - Tirar\n3 - Sair\n");
        scanf("%d", &opcao);
        LimparTela();
        switch(opcao)
        {
            case 1://Adicionar carro
            {
                char placa[9];
                char colocarNaFilaDeEspera = 0;
                if(tamanhoFila1 >= 10)
                {
                    printf("Quantidade maxima de carros no estacionamento...\nColocando na fila de espera...\n");
                    colocarNaFilaDeEspera = 1;
                    //break;
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
                if(colocarNaFilaDeEspera)
                {
                    push(&filaDeEspera, 0);
                    strcpy(filaDeEspera->anterior->placa, placa);
                    tamanhoFila2++;
                }
                else
                {
                    push(&estacionamento, 0);                           //Cria novo carro no fim da fila
                    strcpy(estacionamento->anterior->placa, placa);     //Copia a placa recem digitada
                    tamanhoFila1++;
                }
                break;
            }
            case 2://Retirar carro
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
                int resposta = ConsultarPorPlaca(&estacionamento, placa);
                if(resposta == ERRO_FILA_POSICAO_NAO_EXISTE)
                {
                    printf("Carro com placa %s nao encontrado, voltado ao menu...\n\n", placa);
                    break;
                }
                else
                {
                    printf("Carro com placa %s encontado na vaga %d\n", placa, resposta);
                    Estacionamento_Fila *carro = popEspecifico(&estacionamento, resposta);
                    printf("Carro com placa %s foi manobrado %d vezes antes de sair\n\n", carro->placa, carro->numVezesManobrado + 1);
                    tamanhoFila1--;
                    if(tamanhoFila2 != 0)
                    {
                        carro = pop(&filaDeEspera);
                        printf("Abriu espaco, colocando carro de placa %s no estacionamento\n", carro->placa);
                        push(&estacionamento, 0);
                        strcpy(estacionamento->anterior->placa, carro->placa);
                        tamanhoFila2--;
                    }
                    //Estacionamento_Pilha *carro = popEspecifico(&pilha, resposta);
                    //printf("Carro com placa %s foi manobrado %d vezes antes de sair\n\n", carro->placa, carro->numVezesManobrado);
                }
                //tamanhoPilha--;
                break;
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