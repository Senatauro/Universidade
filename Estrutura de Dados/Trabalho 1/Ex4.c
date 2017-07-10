#include <stdio.h>
#include <stdlib.h>

#define byte char
#define ERRO_CHEGOU_LIMITE -1

typedef struct Lista_Int
{
    int numero;
    struct Lista_Int *proximo;
}Lista_Int;

Lista_Int *CriarLista();
void DeletarLista(Lista_Int **nod);
int InserirNodo(Lista_Int **nod, int pos);
int RemoverNodo(Lista_Int **nod, int pos);
int AcessarElemento(Lista_Int **nod, int pos);
int AlterarElemento(Lista_Int **nod, int pos);

/*
    Criação de uma lista - OK
    Remoção de uma lista - OK
    Inserção de um elemento da lista
    Remoção de um elemento da lista
    Acesso de um elemento da lista - OK
    Alteração de um elemento da lista - OK
*/

void main()
{
    Lista_Int *listaPorPonteiro;
    listaPorPonteiro = NULL;
    byte menu[3], aux;
    int pos, num;
    do
    {
        printf("1 - Criar lista\n2 - Deletar lista\n3 - Inserir elemento\n4 - Remover elemento\n5 - Acessar elemento\n6 - Alterar elemento\n");
        scanf("%s", menu);
        if(menu[1] != '\0')
            menu[0] = -1;
        system("clear");
        switch(menu[0])
        {
            //Criar uma nova lista
            case '1':
                if(listaPorPonteiro != NULL)
                {
                    printf("Lista ja criada\n\n");
                    break;
                }
                listaPorPonteiro = CriarLista();
                if(listaPorPonteiro != NULL)
                    printf("Lista criada com suceso\n");
                else
                    printf("Erro ao criar a lista\n");
            break;

            //Deletar toda a lista
            case '2':
                if(listaPorPonteiro != NULL)
                {
                    DeletarLista(&listaPorPonteiro);
                    if(listaPorPonteiro == NULL)
                        printf("Lista deletada com sucesso\n");
                    else
                        printf("A lista nao foi deletada\n");
                }
                else
                    printf("Lista ja vazia\n");
            break;

            //Inserir novo nodo
            case '3':
                if(listaPorPonteiro != NULL)
                {
                    printf("0 - Insere no inicio\n-1 - Insere no final\nOutro - Insere na posicao N\nPosicao para inserir o novo elemento: ");
                    scanf("%d", &pos);
                    num = InserirNodo(&listaPorPonteiro, pos);
                    num != ERRO_CHEGOU_LIMITE ? printf("Insercao com sucesso na posicao %d\n", pos) : printf("ERRO: Chegou no fim da lista e nao encontrou tal posicao\n");
                }
                else
                    printf("Lista nao existe\n");
            break;
            case '4':
                if(listaPorPonteiro != NULL)
                {
                    printf("0 - Remove no inicio\n-1 - Remove no final\nOutro - Remove na posicao N\nPosicao para remover o elemento: ");
                    scanf("%d", &pos);
                    num = RemoverNodo(&listaPorPonteiro, pos);
                    num != ERRO_CHEGOU_LIMITE ? printf("Remocao com sucesso na posicao %d\n", pos) : printf("ERRO: Chegou no fim da lista e não encontrou tal posicao\n");
                }
                else
                    printf("Lista nao existe\n");
            break;
            //Acessar Valor
            case '5':
                if(listaPorPonteiro != NULL)
                {
                    printf("Posicao para acessar o valor: ");
                    scanf("%d", &pos);
                    num = AcessarElemento(&listaPorPonteiro, pos);
                    num != ERRO_CHEGOU_LIMITE ? printf("Valor do elemento na posicao %d  -  %d\n", pos, num) : printf("ERRO: Chegou no fim da lista e nao encontrou tal posicao\n");
                }
                else
                    printf("Lista nao existe\n");
            break;

            //Alterar Valor
            case '6':
                if(listaPorPonteiro != NULL)
                {
                    printf("Posicao para acessar o valor: ");
                    scanf("%d", &pos);
                    num = AlterarElemento(&listaPorPonteiro, pos);
                    num != ERRO_CHEGOU_LIMITE ? printf("Valor alterado com sucesso\n") : printf("ERRO: Chegou no fim da lista e nao encontrou tal posicao\n ");
                }
                else
                    printf("Lista nao existe\n");
            break;
            default:
                printf("Opcao invalida\n");
                break;
        }
    }while(menu != 0);
}

    /*--- Operações da lista ---*/
//Criar
Lista_Int *CriarLista()
{
    Lista_Int *nod = malloc(sizeof(Lista_Int));
    nod->numero = NULL;
    nod->proximo = NULL;
    return nod;
}

void DeletarLista(Lista_Int **nod)
{
    Lista_Int *atual = *nod;
    Lista_Int *proximo;
    while (atual != NULL)
    {
        proximo = atual->proximo;
        free(atual);
        atual = proximo;
    }
    *nod = NULL;
}

int InserirNodo(Lista_Int **nod, int pos)
{
    Lista_Int *aux = *nod;
    Lista_Int *aux2;
    if(pos == 0)    //Aloca no inicio
    {
        aux = malloc(sizeof(Lista_Int));    //aloca nova estrutura
        aux->proximo = *nod;     //coloca o proximo como a cabeça atual
        aux->numero = 0;
        *nod = aux;      //muda a referencia da cabeça atual para a recem alocada
        return 1;
    }
    else if(pos == -1)  //Aloca no fim
    {
        while(aux->proximo != NULL)
            aux = aux->proximo;
        aux->proximo = malloc(sizeof(Lista_Int));
        aux->proximo->proximo = NULL;
        aux->proximo->numero = 0;
        return 1;
    }
    else
    {
        aux2 = aux;
        for(int i = 0; i < pos; i++)
        {
            if(aux->proximo == NULL)
                return ERRO_CHEGOU_LIMITE;
            
            aux2 = aux;
            aux = aux->proximo;
        }
        aux2->proximo = malloc(sizeof(Lista_Int));
        aux2->proximo->proximo = aux;
        aux2->proximo->numero = 0;
    }
}

int RemoverNodo(Lista_Int **nod, int pos)
{
    Lista_Int *aux = *nod;
    Lista_Int *aux2;
    if(pos == 0)    //Remove no inicio
    {
        if(aux->proximo == NULL)
        {
            free(aux);
            *nod = NULL;
        }
        else
        {
            *nod = aux->proximo;
            free(aux);
        }
        return 1;
    }
    else if(pos == -1)  //Remove no fim
    {
        while(aux->proximo != NULL)
        {
            aux2 = aux;
            aux = aux->proximo;
        }
        aux2->proximo = NULL;
        free(aux);
        return 1;
    }
    else
    {
        aux2 = aux;
        for(int i = 0; i < pos; i++)
        {
            if(aux->proximo == NULL)
                return ERRO_CHEGOU_LIMITE;
            
            aux2 = aux;
            aux = aux->proximo;
        }
        aux2->proximo = aux->proximo;
        free(aux);
        return 1;

    }
}

int AcessarElemento(Lista_Int **nod, int pos)
{
    Lista_Int *aux = *nod;
    for(int i = 0; i < pos; i++)
    {
        if(aux->proximo == NULL)
            return ERRO_CHEGOU_LIMITE;
        aux = aux->proximo;
    }
    return aux->numero;
}

int AlterarElemento(Lista_Int **nod, int pos)
{
    Lista_Int *aux = *nod;
    //int numeroParaColocar;
    for(int i = 0; i < pos; i++)
    {
        if(aux->proximo == NULL)
            return ERRO_CHEGOU_LIMITE;
        aux = aux->proximo;
    }
    printf("Posicao %d encontrada, posui o valor de: %d\nDeseja colocar que valor no seu lugar? ", pos, aux->numero);
    scanf("%d", &aux->numero);
    return 1;
}