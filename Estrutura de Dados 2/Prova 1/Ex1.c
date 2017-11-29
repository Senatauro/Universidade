/*

Um manobrista de um estacionamento precisa arrumar todos os carros por ordem de tamanho,
de tal forma que os carros maiores sejam guardados primeiros e os menores por ultimo.
Ha espaço o suficiente para todos os carros. A pessoa chega ao estacionamento e coloca o carro em qualquer ordem,
no fim do dia o manobrista precisa rearranjar todos respeitando a ordem dos maiores primeiro.
Implemente um metodo de ordenação que simule o funcionamento do estacionamento

a)os carros chegam ao estacionamento e são guardados em qualquer ordem
b)as vagas do estacionamento são enumeradas
c)os carros possuem um tamanho
d)o manobrista precisa arrumar os carros por ordem decrescente

*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define true 1
#define false 0
#define VAGA_VAZIA -1

typedef struct Carro
{
    int tamanho;
}Carro;

void main()
{
    Carro estacionamento[1000];
    memset(estacionamento, -1, 1000 * sizeof(Carro));
    int op;
    do
    {
        printf("1 - Estacionar carro\n2 - Finalizar dia\n");
        scanf("%d", &op);
        if(op == 1)
        {
            printf("Posição que o carro parou: ");
            int pos;
VAGA_OCUPADA:scanf("%d", &pos);
            if(estacionamento[pos].tamanho != -1)
            {
                printf("Vaga já ocupada, selecione outra posicao: ");
                goto VAGA_OCUPADA;
            }
            printf("Tamanho do carro: ");
            scanf("%d", &estacionamento[pos].tamanho);
        }
        else if(op == 2)
            break;
        else
            printf("\nOpção invalida\n\n");
    }while(true);
    SelectionSort(estacionamento, 1000);
    for(int i = 0; i < 1000; i++)
        if(estacionamento[i].tamanho != -1)
            printf("Vaga %d - Carro com tamanho %d\n", i, estacionamento[i].tamanho);
        else
            break;
}

void SelectionSort(Carro *vetor, int tamanhoVetor)
{
    int i, j, menorValorAtualPos;
    for(i = 0; i < tamanhoVetor; i++)
    {
        menorValorAtualPos = i;
        for(j = i; j < tamanhoVetor; j++)
        {
            if(vetor[j].tamanho > vetor[menorValorAtualPos].tamanho)
                menorValorAtualPos = j;
        }
        if(menorValorAtualPos != i)
        {
            Carro aux = vetor[i];
            vetor[i] = vetor[menorValorAtualPos];
            vetor[menorValorAtualPos] = aux;
        }
    }
}