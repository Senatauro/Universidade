#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int ordemDaArvore = 1;
int tamanhoMaximoDeValores;
int tamanhoMinimoDeValores;
int tamanhoMaximoDeFilhos;
int tamanhoMinimoDeFilhos;
int *vetorParaDispersoes;

#define true 1
#define false 0
#define VALOR_NAO_INICIALIZADO -1000
#define PONTEIRO_NAO_INICIALIZADO NULL
#define VALOR_NAO_ENCONTRADO -1002

typedef struct ArvoreB
{
    int *valores;
    struct ArvoreB **ponteiros;
}ArvoreB;

ArvoreB* CriarNodo();
int InserirElemento(ArvoreB **ponteiro, int valor);
void MostrarValoresDaArvore(ArvoreB *nodo);
void AjustarPonteiros(ArvoreB **nodo);
//Funções de ajuda
void MostrarERRO();
void MostrarTCHAU();
void MostrarVALORENCONTRADO();
void MostrarVALORNAOENCONTRADO();
//Funções de ordenar
void QuickSort(int *vetor, int inicio, int fim);
int particionar(int *vetor, int inicio, int fim);
void sleep(int tempo);

int main()
{
    ArvoreB *arvore;
    //Ex: Arvore de ordem 5; Numero maximo de filhos é 5 e numero minimo de filhos é 5/2 arredondado para cima = 3
    //E o numero de elementos é sempre 1 a menos que o numero de filhos: Maximo = 4; Minimo = 2
    do
    {
        printf("Digite a ordem da arvore: ");
        scanf("%d", &ordemDaArvore);
    }while(ordemDaArvore < 4);
    tamanhoMaximoDeFilhos = ordemDaArvore;
    tamanhoMinimoDeFilhos = round((float)ordemDaArvore/2);
    tamanhoMaximoDeValores = tamanhoMaximoDeFilhos - 1;
    tamanhoMinimoDeValores = tamanhoMinimoDeFilhos - 1;
    vetorParaDispersoes = malloc(sizeof(int) * ordemDaArvore);
    arvore = CriarNodo();
    do{
        int opcao = 0;
        printf("Escolha  sua opção: \n1 - Inserir valor\t\t2 - Pesquisar por elemento\n3 - Mostrar valores da arvore\t4 - Sair do programa\n\nSua opcao: ");
        scanf("%d", &opcao);
        switch(opcao)
        {
            case 1:
                //A partir daqui opcao é a variavel local para pegar o elemento a ser inserido
                printf("Elemento para inserir: ");
                scanf("%d", &opcao);
                opcao = InserirElemento(&arvore, opcao);
                printf("\nRaiz da arvore: %d\n\n", arvore->valores[0]);
                break;
            case 2:
                //A partir daqui opção é a variavel local para pegar elemento de procura
                scanf("%d", &opcao);
                //opcao = PesquisarPorElemento(arvore, opcao);
                if(opcao != VALOR_NAO_ENCONTRADO)
                {
                    MostrarVALORENCONTRADO(); 
                    printf("Valor encontrado!\n");
                }
                else
                {
                    MostrarVALORNAOENCONTRADO();
                    printf("Valor nao encontrado...\n");
                }
                break;
            case 3:
                MostrarValoresDaArvore(arvore);
                break;
            case 4:
                MostrarTCHAU();
                return -1;
                break;
            case 5:
                printf("Contando ponteiros inicializados...\n");
                int aga = 0;
                for(int i = 0; i < tamanhoMaximoDeFilhos; i++)
                {
                    if(arvore->ponteiros[i] != PONTEIRO_NAO_INICIALIZADO)
                    aga++;
                }
                printf("Quantidade de ponteiros inicializados: %d\n", aga);
            default:
                break;
        }
        
    }while(true);   


    return 1;
}


int InserirElemento(ArvoreB **ponteiro, int valor)
{
    ArvoreB *nodo = *ponteiro;
    if(nodo == PONTEIRO_NAO_INICIALIZADO)
    {
        printf("entrou em criar nodo pois não foi inicializado\n");
        nodo = CriarNodo();
        nodo->valores[0] = valor;
        *ponteiro = nodo;
        return 1;
    }
    for(int i = 0; i < tamanhoMaximoDeValores; i++)
    {
        if(nodo->valores[i] == VALOR_NAO_INICIALIZADO)
        {
            printf("Inseriu valor na posicao %d\n", i);
            nodo->valores[i] = valor;
            if(i > 0)
            {
                QuickSort(nodo->valores, 0, i);
                AjustarPonteiros(&nodo);
            }
            return 1;
        }
    }
    //Caso ele passe para esse ponto, significa que o tamanho maximo de valores em um no foi estourado
    //Então é necessario criar um vetor com os valores do nodo atual mais o valor que é para ser inserido
    //Ex: valores [3, 5, 55, 121] Inserir 7; Cria vetor com 7 na ultima posiçao: [3, 5, 55, 121, 7];
    // Quicksort nele: [3, 5, 7, 55, 121]; Divide o vetor em 2 e pega o elemento do meio: [3, 5] <-[7]-> [55, 121]
    DividirNodo(&nodo, valor);
    *ponteiro = nodo;
}

void DividirNodo(ArvoreB **ponteiro, int valor)
{
    ArvoreB *nodo = *ponteiro;
    //Caso ele passe para esse ponto, significa que o tamanho maximo de valores em um no foi estourado
    //Então é necessario criar um vetor com os valores do nodo atual mais o valor que é para ser inserido
    //Ex: valores [3, 5, 55, 121] Inserir 7; Cria vetor com 7 na ultima posiçao: [3, 5, 55, 121, 7];
    // Quicksort nele: [3, 5, 7, 55, 121]; Divide o vetor em 2 e pega o elemento do meio: [3, 5] <-[7]-> [55, 121]
    for(int i = 0; i < tamanhoMaximoDeValores; i++)
    {
        vetorParaDispersoes[i] = nodo->valores[i];
    }
    //Coloca o valor para ser inserido no novo vetor
    vetorParaDispersoes[tamanhoMaximoDeValores] = valor;
    //Ordena esse vetor
    QuickSort(vetorParaDispersoes, 0, tamanhoMaximoDeValores);
    //printf("Valor do meio do vetor: %d\n", vetorParaDispersoes[tamanhoMinimoDeValores]);
    //Cria outro nodo aonde o valor do meio do vetor é elevado
    ArvoreB *nodoPai = CriarNodo(), *nodoFilho1 = CriarNodo(), *nodoFilho2 = CriarNodo();
    nodoPai->valores[0] = vetorParaDispersoes[tamanhoMinimoDeValores];
    //For para adicionar os valores antes do meio-termo ao filho1
    for(int i = 0; i < tamanhoMinimoDeValores; i++)
    {
        nodoFilho1->valores[i] = vetorParaDispersoes[i];
    }
    for(int i = tamanhoMinimoDeValores + 1, j = 0; i < ordemDaArvore; i++, j++)
    {
        nodoFilho2->valores[j] = vetorParaDispersoes[i];
    }

    //for(int i = 0; i < tamanhoMaximoDeValores; i++)
    //{
    //    if(nodoFilho1->valores[i] != VALOR_NAO_INICIALIZADO)
    //    {
    //        printf("%d\n", nodoFilho1->valores[i]);
    //    }
    //}
    //printf("Nodo pai: %d\n", nodoPai->valores[0]);
    //for(int i = 0; i < tamanhoMaximoDeValores; i++)
    //{
    //    if(nodoFilho2->valores[i] != VALOR_NAO_INICIALIZADO)
    //    {
    //        printf("%d\n", nodoFilho2->valores[i]);
    //    }
    //}
    *ponteiro = nodoPai;
    nodoPai->ponteiros[0] = nodoFilho1;
    nodoPai->ponteiros[1] = nodoFilho2;
}

void AjustarPonteiros(ArvoreB **nodo)
{
    for(int i = 0; i < tamanhoMaximoDeValores; i++)
    {
        
    }
}

void MostrarValoresDaArvore(ArvoreB *nodo)
{
    for(int i = 0; i < tamanhoMaximoDeValores; i++)
    {
        if(nodo->ponteiros[i] != PONTEIRO_NAO_INICIALIZADO)
            MostrarValoresDaArvore(nodo->ponteiros[i]);
        if(nodo->valores[i] != VALOR_NAO_INICIALIZADO)
        {
            printf("%d\n", nodo->valores[i]);
        }
    }
}


ArvoreB* CriarNodo()
{
    ArvoreB *nodo = NULL;
    nodo = malloc(sizeof(ArvoreB));
    nodo->valores = malloc(sizeof(int) * tamanhoMaximoDeValores);
    nodo->ponteiros = malloc(sizeof(ArvoreB*) * tamanhoMaximoDeFilhos);
    for(int i = 0; i < tamanhoMaximoDeValores; i++)
    {
        nodo->valores[i] = VALOR_NAO_INICIALIZADO;
    }
    for(int i = 0; i < tamanhoMaximoDeFilhos; i++)
    {
        nodo->ponteiros[i] = NULL;
    }
    //memset(nodo->valores, VALOR_NAO_INICIALIZADO, sizeof(int) * ordemDaArvore);
    //memset(*nodo->ponteiros, PONTEIRO_NAO_INICIALIZADO, sizeof(ArvoreB*) * (ordemDaArvore + 1));
    return nodo;
}


//Funções de ajuda
void MostrarERRO()
{
    printf("Não digite nada por agora, vai estragar o efeito\n");
    printf("\n\n███████╗██████╗ ██████╗  ██████╗ ");
    sleep(1);
    printf("\n██╔════╝██╔══██╗██╔══██╗██╔═══██╗");
    sleep(1);
    printf("\n█████╗  ██████╔╝██████╔╝██║   ██║");
    sleep(1);
    printf("\n██╔══╝  ██╔══██╗██╔══██╗██║   ██║");
    sleep(1);
    printf("\n███████╗██║  ██║██║  ██║╚██████╔╝");
    sleep(1);
    printf("\n╚══════╝╚═╝  ╚═╝╚═╝  ╚═╝ ╚═════╝ \n\n");
    sleep(1);
}

void MostrarVALORENCONTRADO()
{
    printf("\n██╗   ██╗ █████╗ ██╗      ██████╗ ██████╗ ");
    printf("\n██║   ██║██╔══██╗██║     ██╔═══██╗██╔══██╗");
    printf("\n██║   ██║███████║██║     ██║   ██║██████╔╝");
    printf("\n╚██╗ ██╔╝██╔══██║██║     ██║   ██║██╔══██╗");
    printf("\n ╚████╔╝ ██║  ██║███████╗╚██████╔╝██║  ██║");
    printf("\n  ╚═══╝  ╚═╝  ╚═╝╚══════╝ ╚═════╝ ╚═╝  ╚═╝");
    printf("\n\n███████╗███╗   ██╗ ██████╗ ██████╗ ███╗   ██╗████████╗██████╗  █████╗ ██████╗  ██████╗ ");
    printf("\n██╔════╝████╗  ██║██╔════╝██╔═══██╗████╗  ██║╚══██╔══╝██╔══██╗██╔══██╗██╔══██╗██╔═══██╗");
    printf("\n█████╗  ██╔██╗ ██║██║     ██║   ██║██╔██╗ ██║   ██║   ██████╔╝███████║██║  ██║██║   ██║");
    printf("\n██╔══╝  ██║╚██╗██║██║     ██║   ██║██║╚██╗██║   ██║   ██╔══██╗██╔══██║██║  ██║██║   ██║");
    printf("\n███████╗██║ ╚████║╚██████╗╚██████╔╝██║ ╚████║   ██║   ██║  ██║██║  ██║██████╔╝╚██████╔╝");
    printf("\n╚══════╝╚═╝  ╚═══╝ ╚═════╝ ╚═════╝ ╚═╝  ╚═══╝   ╚═╝   ╚═╝  ╚═╝╚═╝  ╚═╝╚═════╝  ╚═════╝ \n\n");
}

void MostrarVALORNAOENCONTRADO()
{
    printf("\n██╗   ██╗ █████╗ ██╗      ██████╗ ██████╗     ███╗   ██╗ █████╗  ██████╗");
    printf("\n██║   ██║██╔══██╗██║     ██╔═══██╗██╔══██╗    ████╗  ██║██╔══██╗██╔═══██╗");
    printf("\n██║   ██║███████║██║     ██║   ██║██████╔╝    ██╔██╗ ██║███████║██║   ██║");
    printf("\n╚██╗ ██╔╝██╔══██║██║     ██║   ██║██╔══██╗    ██║╚██╗██║██╔══██║██║   ██║");
    printf("\n ╚████╔╝ ██║  ██║███████╗╚██████╔╝██║  ██║    ██║ ╚████║██║  ██║╚██████╔╝");
    printf("\n  ╚═══╝  ╚═╝  ╚═╝╚══════╝ ╚═════╝ ╚═╝  ╚═╝    ╚═╝  ╚═══╝╚═╝  ╚═╝ ╚═════╝");
    printf("\n\n███████╗███╗   ██╗ ██████╗ ██████╗ ███╗   ██╗████████╗██████╗  █████╗ ██████╗  ██████╗ ");
    printf("\n██╔════╝████╗  ██║██╔════╝██╔═══██╗████╗  ██║╚══██╔══╝██╔══██╗██╔══██╗██╔══██╗██╔═══██╗");
    printf("\n█████╗  ██╔██╗ ██║██║     ██║   ██║██╔██╗ ██║   ██║   ██████╔╝███████║██║  ██║██║   ██║");
    printf("\n██╔══╝  ██║╚██╗██║██║     ██║   ██║██║╚██╗██║   ██║   ██╔══██╗██╔══██║██║  ██║██║   ██║");
    printf("\n███████╗██║ ╚████║╚██████╗╚██████╔╝██║ ╚████║   ██║   ██║  ██║██║  ██║██████╔╝╚██████╔╝");
    printf("\n╚══════╝╚═╝  ╚═══╝ ╚═════╝ ╚═════╝ ╚═╝  ╚═══╝   ╚═╝   ╚═╝  ╚═╝╚═╝  ╚═╝╚═════╝  ╚═════╝ \n\n");
}
void MostrarTCHAU()
{
     printf("\n\n████████╗ ██████╗██╗  ██╗ █████╗ ██╗   ██╗");
     printf("\n╚══██╔══╝██╔════╝██║  ██║██╔══██╗██║   ██║");
     printf("\n   ██║   ██║     ███████║███████║██║   ██║");
     printf("\n   ██║   ██║     ██╔══██║██╔══██║██║   ██║");
     printf("\n   ██║   ╚██████╗██║  ██║██║  ██║╚██████╔╝");
     printf("\n   ╚═╝    ╚═════╝╚═╝  ╚═╝╚═╝  ╚═╝ ╚═════╝ \n\n");
}


//Função de ordenar
void QuickSort(int *vetor, int inicio, int fim)
{
    if(inicio < fim)
    {
        int p = particionar(vetor, inicio, fim);
        QuickSort(vetor, inicio, p - 1);
        QuickSort(vetor, p + 1, fim);
    }
}


int particionar(int *vetor, int inicio, int fim)
{
    int pivo = vetor[fim];
    int aux;
    int i = inicio - 1;
    for(int j = inicio; j < fim; j++)
    {
        if(vetor[j] < pivo)
        {
            i++;
            aux = vetor[j];
            vetor[j] = vetor[i];
            vetor[i] = aux;
        }
    }
    if(vetor[fim] < vetor[i+1])
    {
        aux = vetor[fim];
        vetor[fim] = vetor[i + 1];
        vetor[i + 1] = aux;
    }
    return i+1;
}