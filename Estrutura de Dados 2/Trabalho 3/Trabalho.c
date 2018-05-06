#include<stdio.h>
#include<stdlib.h>

void main()
{
    
}

void BubbleSort(int vet, int tamanhoDoVetor)
{
    int aux;
    for(int i = tamanhoDoVetor - 1; i>0; i--)
    {
        for(int j = 0; j < i; j++)
        {
            if(vet[j] > vet[j+1])
            {
                aux = vet[j+1];
                vet[j+1] = vet[j];
                vet[j] = aux;
            }
        }
    }
}

void SelectionSort(int *vetor, int tamanhoVetor)
{
    int i, j, menorValorAtualPos;
    for(i = 0; i < tamanhoVetor; i++)
    {
        menorValorAtualPos = i;
        for(j = i; j < tamanhoVetor; j++)
        {
            if(vetor[j] < vetor[menorValorAtualPos])
                menorValorAtualPos = j;
        }
        if(menorValorAtualPos != i)
        {
            int aux = vetor[i];
            vetor[i] = vetor[menorValorAtualPos];
            vetor[menorValorAtualPos] = aux;
        }
    }
}

void InsertionSort(int *vetor, int tamanhoVetor)    //Insertion sort vai rodando até encontrar um valor menor que o elemento selecionado
{                                                   //É quase um bubble sort, só que não roda n vezes pra todos os elementos
    int i, j;
    for(i = 0; i < tamanhoVetor; i++)
    {
        for(j = i; j > 0 && vetor[j] < vetor[j-1]; j--)
        {
            int aux = vetor[j];
            vetor[j] = vetor[j-1];
            vetor[j-1] = aux;
        }
    }
}