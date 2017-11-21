#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void main()
{
    int tamanhoVetor, argc;
    clock_t start_t, end_t;
    double total_t;
    time_t tempo;
    int i;
    
    srand((unsigned) time(&tempo));
    scanf("%d %d", &tamanhoVetor, &argc);
    int *vetor = (int*) malloc(sizeof(int) * tamanhoVetor);
    if(argc != 2)
        for(i = 0; i < tamanhoVetor; i++)
        {
            if(argc == 1)    //para binario
            {
                vetor[i] = rand() % 2;
            }
            else
            {
                int jota = rand() % argc + 1;
                vetor[i] = jota;
            }
        }
    start_t = clock();        
    printf("Iniciando a organização, start_t = %ld\n", start_t);
    //SelectionSort(vetor, tamanhoVetor);
    InsertionSort(vetor, tamanhoVetor);
    printf("Terminou a organização, start_t = %ld\n", start_t);
    
    end_t = clock();
    
    total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC;
    printf("Tempo total levado pela cpu: %f\n", total_t);
    for(int i = 0; i < tamanhoVetor; i++)
    {
        printf("Pos %d: %d\n", i + 1, vetor[i]);
    }
}

void InsertionSort(int *vetor, int tamanhoVetor)    //Insertion sort vai rodando até encontrar um valor menor que o elemento selecionado
{                                                   //É quase um bubble sort, só que não roda n vezes pra todos os elementos
    int i, j;
    for(i = 0; i < tamanhoVetor; i++)
    {
        for(j = i; vetor[j] < vetor[j-1]; j--)
        {
            int aux = vetor[j];
            vetor[j] = vetor[j-1];
            vetor[j-1] = aux;
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
            {
                menorValorAtualPos = j;
            }
        }
        if(menorValorAtualPos != i)
        {
            int aux = vetor[i];
            vetor[i] = vetor[menorValorAtualPos];
            vetor[menorValorAtualPos] = aux;
        }
    }
}