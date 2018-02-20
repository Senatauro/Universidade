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
    struct ArvoreB *nodoPai;
}ArvoreB;

ArvoreB* CriarNodo();
int InserirElemento(ArvoreB **ponteiro, int valor);
int InserirNodo(ArvoreB **nodoAondeVaiSerInserido, ArvoreB **nodoParaSerInserido);
void MostrarValoresDaArvore(ArvoreB *nodo);
ArvoreB* DividirNodo(ArvoreB **ponteiro, int valor);
int InserirElementoNoVetor(int *vetor, int valor);
void InserirPonteirosNoNodo(ArvoreB **nodoAReceberPonteiro, ArvoreB **ponteiro);
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
    arvore = CriarNodo(NULL);
    /* COMANDOS PARA DEBUG's */
    //InserirElementoNoVetor(arvore->valores, 71);
    //InserirElementoNoVetor(arvore->valores, 122);
    //ArvoreB *teste1 = CriarNodo(NULL);
    //ArvoreB *teste2 = CriarNodo(NULL);
    //
    //InserirElementoNoVetor(teste1->valores, 61);
    //InserirElementoNoVetor(teste1->valores, 28);
    //InserirPonteirosNoNodo(&arvore, &teste1);
    //InserirElementoNoVetor(arvore->ponteiros[1]->valores, 37);

    //InserirElementoNoVetor(arvore->valores, 71);
    //InserirElementoNoVetor(arvore->valores, 122);
    
    /* COMANDOS PARA DEBUG's */

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
                printf("\nRetorno: %d\n\n", opcao);
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

    //Primeiro começa vendo se existe ponteiros para subarvores, caso não exista, adicionar elemento nessa arvre
    //Caso contrario, adicionar em subarvore referente ao valor
    for(int i = 0; i < tamanhoMaximoDeFilhos; i++)
    {
        if(nodo->valores[i] > valor)
        {
            if(nodo->ponteiros[i] != PONTEIRO_NAO_INICIALIZADO)
            {
                return InserirElemento(&nodo->ponteiros[i], valor);
            }
        }
    }

    //Caso tenha sido possivel inserir elemento no vetor ele retorna 1(Sucesso);
    if(InserirElementoNoVetor(nodo->valores, valor) == 1)
        return 1;
    //Caso não tenha sido possivel inserir elemento no vetor, é necessario dividir o nodo
    ArvoreB *nodoPai = DividirNodo(&nodo, valor);
    if(nodo->nodoPai == NULL)
    {
        *ponteiro = nodoPai;
        return 1;
    }
    //Caso o nodo já possua um pai, é necessario inserir os valores desse nodo no nodoPai
    return InserirNodo(&nodo->nodoPai, &nodoPai);


    //*ponteiro = nodoPai;
}

//Função chamada quando um nodo é dividido e é necessario pegar o nodo recem dividio e adicionar ele em outro nodo;
int InserirNodo(ArvoreB **nodoAondeVaiSerInserido, ArvoreB **nodoParaSerInserido)
{
    ArvoreB *nodo = *nodoAondeVaiSerInserido, *nodoASerInserido = *nodoParaSerInserido;
    //Caso seja possivel inserir o elemento existente no nodo pai, ajusta os ponteiros que vieram com o nodo sendo inserido
    if(InserirElementoNoVetor(nodo->valores, nodoASerInserido->valores[0]) == 1)
    {
        for(int i = 0; i < tamanhoMinimoDeFilhos; i++)
        {
            if(nodoASerInserido->ponteiros[i] != PONTEIRO_NAO_INICIALIZADO)
                InserirPonteirosNoNodo(&nodo, &nodoASerInserido->ponteiros[i]);
        }
        return 1;
    }
    //Caso não tenha sido possivel inserir elemento dividir o nodo atual com o elemento a mais
    //CASO NAO EXISTA, definir o nodo dividido como o nodo principal
    ArvoreB *nodoPai = DividirNodo(&nodo, nodoASerInserido->valores[0]);
    if(nodo->nodoPai == NULL)
    {
        *nodoAondeVaiSerInserido = nodoPai;
        return 1;
    }
    //E fazer a inserção do nodo dividido no nodo pai CASO EXISTA acima
    //if()


    //if(InserirElementoNoVetor(nodo->valores, valor) == 1)
    //    return 1;
    ////Caso não tenha sido possivel inserir elemento no vetor, é necessario dividir o nodo
    //ArvoreB *nodoPai = DividirNodo(&nodo, valor);
    //if(nodo->nodoPai != NULL)
    //{
    //    
    //}
    //*ponteiro = nodoPai;
}

void InserirPonteirosNoNodo(ArvoreB **nodoAReceberPonteiro, ArvoreB **ponteiro)
{
    ArvoreB *nodo = *nodoAReceberPonteiro, *pont = *ponteiro;
    for(int i = 0; i < tamanhoMaximoDeFilhos; i++)
    {
        if(nodo->valores[i] > pont->valores[0])
        {
            nodo->ponteiros[i] = pont;
            pont->nodoPai = nodo;
            //MostrarValoresDaArvore(nodo);
            return;
        }
    }
    nodo->ponteiros[ordemDaArvore - 1] = pont;
    pont->nodoPai = nodo;
    //MostrarValoresDaArvore(nodo);
    
}

//Caso tenha sido possivel inserir elemento no vetor ele retorna 1(Sucesso);
//Caso não tenha, retorna 2(Fracasso);
int InserirElementoNoVetor(int *vetor, int valor)
{
    for(int i = 0; i < tamanhoMaximoDeValores; i++)
    {
        if(vetor[i] == VALOR_NAO_INICIALIZADO)
        {
            vetor[i] = valor;
            QuickSort(vetor, 0, i);
            return 1;
        }
    }
    return 2;
}

//Função chamada quando é necessario dividir o nodo em 2 partes e retornar o nodo pai
ArvoreB* DividirNodo(ArvoreB **ponteiro, int valor)
{
    ArvoreB *nodoPai = CriarNodo(NULL), *nodoFilho1 = CriarNodo(nodoPai), *nodoFilho2 = CriarNodo(nodoPai);
    ArvoreB *nodo = *ponteiro;

    //Um for para colocar todos os valores do nodo principal dentro de um vetor
    for(int i = 0; i < tamanhoMaximoDeValores; i++)
    {
        vetorParaDispersoes[i] = nodo->valores[i];
    }
    vetorParaDispersoes[tamanhoMaximoDeValores] = valor;
    QuickSort(vetorParaDispersoes,0, tamanhoMaximoDeValores);

    //Começa a separar os valores nos nós
    nodoPai->valores[0] = vetorParaDispersoes[tamanhoMinimoDeValores];
    for(int i = 0; i < tamanhoMinimoDeValores; i++)
    {
        nodoFilho1->valores[i] = vetorParaDispersoes[i];
    }
    for(int i = tamanhoMinimoDeValores + 1, j = 0; i < ordemDaArvore; i++, j++)
    {
        nodoFilho2->valores[j] = vetorParaDispersoes[i];
    }
    nodoPai->ponteiros[0] = nodoFilho1;
    nodoPai->ponteiros[1] = nodoFilho2;
    return nodoPai;
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


ArvoreB* CriarNodo(ArvoreB *nodoP)
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
    if(nodo != NULL)
        nodo->nodoPai = nodoP;
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