#include<stdio.h>
#include <stdlib.h>

typedef struct Produto
{
    int codigo;
    float preco;
    char nome[100];
}Produto;

typedef struct Par
{
    Produto prod;
    int posicao;
}Par;

Produto BuscaSequencial(Produto* vetor, int tamanhoDoVetor, int codigoParaProcurar);
Produto BuscaBinaria(Produto* vetor, int posicaoAtual, int valorX, int codigoParaProcurar);

int main()
{
    int tamanhoDoVetor = 0;
    int tamanhoMaximoDoVetor = 100;
    int opcao = 0;
    Produto *vetor;
    vetor = (Produto*) realloc (vetor, tamanhoMaximoDoVetor * sizeof(Produto));
    do
    {
        printf("1 - Adicionar produto\n2 - Organizar vetor\n3 - Busca sequencial\n4 - Busca binaria\n5 - Mostrar Vetor\n\n");
        scanf("%d", &opcao);
        switch(opcao)
        {
            case 1:
            {
                Produto novoProduto;
                if(tamanhoDoVetor + 1 >= tamanhoMaximoDoVetor)
                {
                    tamanhoMaximoDoVetor += 100;
                    vetor = (Produto*) realloc (vetor, tamanhoMaximoDoVetor * sizeof(Produto));
                }
                printf("Digite o codigo do produto: ");
                scanf("%d", &novoProduto.codigo);
                printf("Digite o preco do produto: ");
                scanf("%f", &novoProduto.preco);
                printf("Digite o nome do produto: ");
                scanf("%s", novoProduto.nome);
                vetor[tamanhoDoVetor] = novoProduto;
                tamanhoDoVetor++;
                break;                
            }
            case 2:
            {
                SelectionSort(vetor, tamanhoDoVetor);
                break;
            }
            case 3:
            {
                int codigoParaProcurar;
                printf("Digite o codigo do produto que quer procurar: ");
                scanf("%d", &codigoParaProcurar);
                Produto p = BuscaSequencial(vetor, tamanhoDoVetor, codigoParaProcurar);
                if(p.codigo == -1)
                    printf("Não encontrou produto com esse codigo no vetor\n\n");
                else
                {
                    printf("Produto: %s\nPreco: %f\nCodigo: %d\n\n", p.nome, p.preco, p.codigo);
                }
                break;
            }
            case 4:
            {
                int codigoParaProcurar;
                printf("Digite o codigo do produto que quer procurar: ");
                scanf("%d", &codigoParaProcurar);
                Produto p = BuscaBinaria(vetor, tamanhoDoVetor/2, tamanhoDoVetor/2, codigoParaProcurar);
                if(p.codigo == -1)
                    printf("Não encontrou produto com esse codigo no vetor\n\n");
                else
                {
                    printf("Produto: %s\nPreco: %f\nCodigo: %d\n\n", p.nome, p.preco, p.codigo);
                }
                break;
            }
            case 5:
            {
                for(int i = 0; i < tamanhoDoVetor; i++)
                {
                    printf("Produto: %s\nPreco: %f\nCodigo: %d\nPosicao: %d\n\n", vetor[i].nome, vetor[i].preco, vetor[i].codigo, i);                    
                }
                break;
            }

        }
    }while(opcao != 0);
}

Produto BuscaSequencial(Produto* vetor, int tamanhoDoVetor, int codigoParaProcurar)
{
    Produto p;
    p.codigo = -1;
    for(int i = 0; i < tamanhoDoVetor; i++)
    {
        if(vetor[i].codigo == codigoParaProcurar)
        {
            return vetor[i];
        }
    }
    return p;
}

Produto BuscaBinaria(Produto* vetor, int posicaoAtual, int valorX, int codigoParaProcurar)
{
    Produto p;
    if(vetor[posicaoAtual].codigo > codigoParaProcurar)
    {
        return BuscaBinaria(vetor, posicaoAtual + valorX, valorX/2, codigoParaProcurar);
    }
    else if(vetor[posicaoAtual].codigo < codigoParaProcurar)
    {
        return BuscaBinaria(vetor, posicaoAtual - valorX, valorX/2, codigoParaProcurar);
    }
    else
    {
        return vetor[posicaoAtual];
    }
}

void SelectionSort(Produto* vetor, int tamanhoDoVetor)
{
    int i,j;
    int n = tamanhoDoVetor;
    for (j = 0; j < n-1; j++) 
    {
        int iMin = j;
        for (i = j+1; i < n; i++) 
        {
            if (vetor[i].codigo < vetor[iMin].codigo) 
            {
                iMin = i;
            }
        }
        if (iMin != j) 
        {
            Produto aux = vetor[j];
            vetor[j] = vetor[iMin];
            vetor[iMin] = aux;
        }
    }
}
