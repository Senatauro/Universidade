#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>


#define MAXSENHAS 430000
#define true 1
#define false 0

struct senha{
	char *palavra;
	int tamanho;
	int frequencia;
};
typedef struct senha Senha;

void LerSenhas(Senha **senhas, char *filepath)
{
    FILE *fp;
    int n = 0, tam, freq;
    char pass[200];
    fp = fopen(filepath, "r");
	while (fscanf(fp, "%d %d %[^\n]", &tam, &freq, pass) == 3)
	{
        senhas[n] = (Senha*)malloc(sizeof(Senha));
        senhas[n]->tamanho = tam;
        senhas[n]->frequencia = freq;
        senhas[n]->palavra = (char*)malloc((tam+1) * sizeof(char));
        pass[tam] = '\0';
        strcpy(senhas[n]->palavra, pass);
        n++;
	}

	fclose(fp);
}

void BubbleSort(Senha **vet, int tamanhoDoVetor);
void SelectionSort(Senha **vetor);
void InsertionSort(Senha **vetor, int tamanhoDoVetor);
void QuickSort(Senha **vetor, int inicio, int fim);

int main()
{
    clock_t start_t, end_t;
    double total_t;
    FILE *arq;
    int n;
	Senha** senhas;
	senhas = (Senha**)malloc(MAXSENHAS * sizeof(Senha*));
    LerSenhas(senhas, "senhas.txt");

    start_t = clock();        
    printf("Iniciando a organização, start_t = %ld\n", start_t);

    //BubbleSort(senhas, 1000);             //Vai demorar pra sempre(Travou meu computador 3 vezes no numero total de senhas, reduzindo para mil)
    //SelectionSort(senhas);                //Pra sempre²
    //InsertionSort(senhas,MAXSENHAS);      //Pra sempre³
    QuickSort(senhas, 0, MAXSENHAS - 1);    //Rapidinho, nem deu 1 segundo e já estava ordenado

    printf("Terminou a organização, start_t = %ld\n", start_t);
    end_t = clock();
    total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC;
    printf("Tempo total levado pela cpu: %f\n", total_t);

    arq = fopen("senhasOrdenadasQuickSort.txt", "w");
    for(int i = 0; i < MAXSENHAS; i++)
    {
        fprintf (arq, "%s %d %d\n", senhas[i]->palavra, senhas[i]->tamanho, senhas[i]->frequencia);
    }
    /*
	for (n = 0; n < MAXSENHAS; n++)
		printf("%s - %d %d\n", senhas[n]->palavra, senhas[n]->tamanho, senhas[n]->frequencia);


	for (n = 0; n < MAXSENHAS ; n++)
		free(senhas[n]);
	free(senhas);
    */
    fclose(arq);
	return 0;
}

void BubbleSort(Senha **vet, int tamanhoDoVetor)
{
    Senha *aux;
    for(int i = tamanhoDoVetor - 1; i>0; i--)
    {
        for(int j = 0; j < i; j++)
        {
            if(strcmp(vet[j]->palavra, vet[j+1]->palavra) > 0)
            {
                aux = vet[j+1];
                vet[j+1] = vet[j];
                vet[j] = aux;
            }
        }
    }
}

void SelectionSort(Senha **vetor)
{
    int i, j, menorValorAtualPos;
    for(i = 0; i < MAXSENHAS; i++)
    {
        printf("Analizando o numero %d\n", i);
        menorValorAtualPos = i;
        for(j = i; j < MAXSENHAS; j++)
        {
            //Verifica se a palavra atual tem valor menor que a outra palavra
            if(strcmp(vetor[j]->palavra, vetor[menorValorAtualPos]->palavra) < 0)
                menorValorAtualPos = j;
        }
        if(menorValorAtualPos != i)
        {
            Senha *aux = vetor[i];
            vetor[i] = vetor[menorValorAtualPos];
            vetor[menorValorAtualPos] = aux;
        }
    }
}

void InsertionSort(Senha **vetor, int tamanhoDoVetor)                   //Insertion sort vai rodando até encontrar um valor menor que o elemento selecionado
{                                                                       //É quase um bubble sort, só que não roda n vezes pra todos os elementos
    int i, j;
    for(i = 0; i < tamanhoDoVetor; i++)
    {
        printf("Analizando elemento %d\n", i);
        for(j = i; j > 0 && strcmp(vetor[j-1]->palavra, vetor[j]->palavra) > 0; j--)
        {
            Senha *aux = vetor[j];
            vetor[j] = vetor[j-1];
            vetor[j-1] = aux;
        }
    }
}

void QuickSort(Senha **vetor, int inicio, int fim)
{
    if(inicio < fim)
    {
        int p = particionar(vetor, inicio, fim);
        QuickSort(vetor, inicio, p - 1);
        QuickSort(vetor, p + 1, fim);
    }
}

int particionar(Senha **vetor, int inicio, int fim)
{
    Senha *pivo = vetor[fim];
    Senha *aux;
    int i = inicio - 1;
    for(int j = inicio; j < fim; j++)
    {
        if(strcmp(vetor[j]->palavra, pivo->palavra) < 0)
        {
            i++;
            aux = vetor[j];
            vetor[j] = vetor[i];
            vetor[i] = aux;
        }
    }
    if(strcmp(vetor[fim]->palavra, vetor[i+1]->palavra) < 0)
    {
        aux = vetor[fim];
        vetor[fim] = vetor[i + 1];
        vetor[i + 1] = aux;
    }
    return i+1;
}