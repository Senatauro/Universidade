#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define true 1
#define false 0
#define VALOR_NAO_INICIALIZADO -1000
#define PONTEIRO_NAO_INICIALIZADO NULL
#define VALOR_NAO_ENCONTRADO -1002

int tamanhoMaximoDeCadaNo = 1;

typedef struct ABM
{
    int *valores;
    struct ABM **ponteiros;
}ABM;

ABM* CriarNodo();
int InserirElemento(ABM **ponteiro, int valor);
int PesquisarPorElemento(ABM *nodo, int valor);
void MostrarValoresDaArvore();

//Funções de ajuda
void MostrarERRO();
void MostrarTCHAU();
void MostrarVALORENCONTRADO();
void MostrarVALORNAOENCONTRADO();

int main()
{
    ABM *arvore = NULL;
    printf("Digite o tamanho maximo de valores em cada no: ");
    scanf("%d", &tamanhoMaximoDeCadaNo);
    //arvore = CriarNodo();
    if(!arvore)
    {
        MostrarERRO();
        printf("Nao foi possivel criar a arvore, por favor, tente mais tarde...\n\n");
        return -1;
    }
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
                break;
            case 2:
                //A partir daqui opção é a variavel local para pegar elemento de procura
                scanf("%d", &opcao);
                opcao = PesquisarPorElemento(arvore, opcao);
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
            default:
                break;
        }
        
    }while(true);
}

int InserirElemento(ABM **ponteiro, int valor)
{
    ABM *nodo = *ponteiro;
    if(nodo == PONTEIRO_NAO_INICIALIZADO)
    {
        nodo = CriarNodo();
        nodo->valores[0] = valor;
        *ponteiro = nodo;
        return 1;
    }
    for(int i = 0; i < tamanhoMaximoDeCadaNo; i++)
    {
        //Caso seja detectado que o valor para ser inserido é maior que todos os valores desse nó
        if(nodo->valores[i] == VALOR_NAO_INICIALIZADO)
        {
            nodo->valores[i] = valor;
            return 1;
        }
        //Caso seja detectado que o valor para ser inserido seja menor que algum já existente
        else if(nodo->valores[i] > valor)
        {
            //Caso o valor sendo analizado seja menor que um existente e já exista uma subarvore
            if(nodo->ponteiros[i] != PONTEIRO_NAO_INICIALIZADO)
            {
                //printf("Para inserir em elemento abaixo da posicao(no ponteiro) %d\n", i);
                //return -1;
                return InserirElemento(&nodo->ponteiros[i], valor);
            }
            //Caso o calor sendo analizado seja menor que um existente e não exista uma subarvore
            else
            {
                //printf("Criando ponteiro na posicao %d\n", i);
                //return 1;
                nodo->ponteiros[i] = CriarNodo();
                nodo->ponteiros[i]->valores[0] = valor;
                //1 - Inserção feita com sucesso
                return 1;
            }
        }
    }
    //Caso não retorne nesse for, significa que o valor para inserir é maior que todos os elementos desse nó
    InserirElemento(&nodo->ponteiros[tamanhoMaximoDeCadaNo], valor);
}

int PesquisarPorElemento(ABM *nodo, int valor)
{
    for(int i = 0; i <= tamanhoMaximoDeCadaNo; i++)
    {
        //Caso o valor seja encontrado
        if(nodo->valores[i] == valor)
            return valor;
        //Caso o valor não seja encontrado e possui um valor maior que o procurado
        else if(nodo->valores[i] > valor)
        {
            //Caso o ponteiro na posicao do valor maior não seja inicializado retorna VALOR_NAO_ENCONTRADO, caso contrario, pesquisa dentro dele
            return nodo->ponteiros[i] != PONTEIRO_NAO_INICIALIZADO ? PesquisarPorElemento(nodo->ponteiros[i], valor) : VALOR_NAO_ENCONTRADO;
        }
    }
    //mesma coisa que ali em cima
    return nodo->ponteiros[tamanhoMaximoDeCadaNo] != PONTEIRO_NAO_INICIALIZADO ? PesquisarPorElemento(nodo->ponteiros[tamanhoMaximoDeCadaNo], valor) : VALOR_NAO_ENCONTRADO;
}

void MostrarValoresDaArvore(ABM *nodo)
{
    for(int i = 0; i < tamanhoMaximoDeCadaNo; i++)
    {
        if(nodo->ponteiros[i] != PONTEIRO_NAO_INICIALIZADO)
            MostrarValoresDaArvore(nodo->ponteiros[i]);
        if(nodo->valores[i] != VALOR_NAO_INICIALIZADO)
            printf("%d\n", nodo->valores[i]);
    }
    if(nodo->ponteiros[tamanhoMaximoDeCadaNo] != PONTEIRO_NAO_INICIALIZADO)
        MostrarValoresDaArvore(nodo->ponteiros[tamanhoMaximoDeCadaNo]);
}

ABM* CriarNodo()
{
    ABM *nodo = NULL;
    nodo = malloc(sizeof(ABM));
    nodo->valores = malloc(sizeof(int) * tamanhoMaximoDeCadaNo);
    nodo->ponteiros = malloc(sizeof(ABM*) * (tamanhoMaximoDeCadaNo + 1));
    for(int i = 0; i < tamanhoMaximoDeCadaNo; i++)
    {
        nodo->valores[i] = VALOR_NAO_INICIALIZADO;
    }
    for(int i = 0; i <= tamanhoMaximoDeCadaNo; i++)
    {
        nodo->ponteiros[i] = NULL;
    }
    //memset(nodo->valores, VALOR_NAO_INICIALIZADO, sizeof(int) * tamanhoMaximoDeCadaNo);
    //memset(*nodo->ponteiros, PONTEIRO_NAO_INICIALIZADO, sizeof(ABM*) * (tamanhoMaximoDeCadaNo + 1));
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