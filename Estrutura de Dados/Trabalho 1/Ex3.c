#include <stdio.h>
#include <stdlib.h>

typedef struct Lista_Int
{
    int numero;
    struct Lista_Int *proximo;
}Lista_Int;

void main()
{
    //por vetor
    Lista_Int listaPorVetor[10];
    for(int i = 0; i < 10; i++)
    {
        listaPorVetor[i].numero = i;
        if(i<9)
            listaPorVetor[i].proximo = &listaPorVetor[i+1];
    }
    printf("Mostrando os valores da lista por vetor\n");
    for(int i = 0; i < 10; i++)
        printf("%d ", listaPorVetor[i].numero);

    //por ponteiro
    Lista_Int *listaPorPonteiros, *aux;
    listaPorPonteiros = malloc(sizeof(Lista_Int));
    aux = listaPorPonteiros;
    for(int i = 0; i < 10; i++)
    {
        aux->numero = i;
        if(i<9)
        {
            aux->proximo = malloc(sizeof(Lista_Int));
            aux = aux->proximo;
        }
    }
    aux = listaPorPonteiros;
    printf("\n\nMostrando os valores da lista por ponteiro\n");
    for(int i = 0; i < 10; i++)
    {
        printf("%d ", aux->numero);
        aux = aux->proximo;
    }
    printf("\n\n");
}