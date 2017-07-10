#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define byte char
#define true 1
#define false 0

typedef struct ListaDeCompras
{
 int quantidade;
 char *produto;
 float valor;
 struct ListaDeCompras *proximo;
}ListaDeCompras;

void AdicionarCompra(ListaDeCompras **nod);
ListaDeCompras *AlocarEstrutura();

void main()
{
    byte menu[3];
    ListaDeCompras *cabeca = NULL;

    do
    {
        printf("1 - Adicionar Produto\n2 - Remover Produto\n3 - Listar Produtos\nSua escolha: ");
        scanf("%s", menu);
        if(menu[1] != '\0')
            menu[0] = -1;
        //system("clear");
        switch(menu[0])
        {
            case '1':
                AdicionarCompra(cabeca);
            break;
            case '2':
                RemoverCompra();
            break;
            case '3':
                ListarCompras();
            break;
            default:
            break;
        }
    }while(true);
}

void AdicionarCompra(ListaDeCompras **nod)
{
    ListaDeCompras *aux;
    if(*&nod != NULL)
    {
        aux = *nod;
        while (aux->proximo != NULL)
        {
            aux = aux->proximo;
        }
        aux->proximo = AlocarEstrutura();

    }
    else
    {
        printf("123");
        aux = AlocarEstrutura();
    }
    
    /*if (aux != NULL)
    {
        while (aux->proximo != NULL)
        {
            aux = aux->proximo;
        }
        aux->proximo = malloc(sizeof(ListaDeCompras));
        char nomeDoProduto[100];
        int quantidade;
        float preco;
        printf("Digite o nome do produto");
        //getline(nomeDoProduto, 100, stdin);
        printf("\n%s\n", nomeDoProduto);
        //printf()
    }
    else
    {
        *nod = malloc(sizeof(ListaDeCompras));
    }*/
}

void RemoverCompra()
{

}

void ListarCompras()
{

}

ListaDeCompras *AlocarEstrutura()
{
    getchar();
    ListaDeCompras *estrutura = malloc(sizeof(ListaDeCompras));
    printf("123");
    char nomeDoProduto[100];
    int tamanho;
    int quantidade;
    float preco;
    
    printf("Digite o nome do produto");
    scanf("%s", nomeDoProduto);
    estrutura->produto = malloc(sizeof(strlen(nomeDoProduto)));

    /*
    estrutura->produto = malloc(tamanho);
    estrutura->produto = nomeDoProduto;
    printf("\n%s\n", estrutura->produto);
    */
}