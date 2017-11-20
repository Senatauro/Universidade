#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

#define true 1
#define false 0
void InsertionSort(int *vetor, int tamanhoVetor, int analizar, int checar);      //Insertion sort vai rodando até encontrar um valor menor que o elemento selecionado


void main()
{
    int vetor[998], argc = 100;
    time_t tempo;    
    srand((unsigned) time(&tempo));    
    for(int i = 0; i < 998; i++)
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
    InsertionSort(vetor, 998, 0, 1);
    for(int i = 0; i < 998; i++)
    {
        printf("Vetor[%d]: %d\n", i, vetor[i]);
    }
}


//Modificado para funcionar com busca binaria
void InsertionSort(int *vetor, int tamanhoVetor, int analizar, int checar)      //Insertion sort vai rodando até encontrar um valor menor que o elemento selecionado
{                                                                   //É quase um bubble sort, só que não roda n vezes pra todos os elementos
    int i, j, valorBin, valorDiv, flagParaAnalize = analizar, flagParaChecagem = checar, aux, numDivs = 0;
    //Caso a primeira posicao seja maior que a segunda
    //Faca a troca para as 2 primeiras posicoes estarem "ordenadas"
    if(vetor[0] > vetor[1])
    {
        aux = vetor[1];
        vetor[1] = vetor[0];
        vetor[0] = aux;
    }
    //Agora que se tem 2 posicoes "ordenadas" é possivel
    //começar a busca binaria apartir da 3 posicao
    //para a inserção de elementos
    for(i = 2; i < tamanhoVetor; i++)
    {
        //para saber se existe meio exato
        if(i % 2 == 0)
            valorBin = i/2;
        else
            valorBin = (int)ceil((float)i/(float)2) - 1;
        valorDiv = valorBin;
        //Checar caso tenha algum numero maior que outro
         if(flagParaChecagem == 1)
         {
            numDivs = 0;
            int temErro = 0;
            for(int i2 = 0; i2 < i-1; i2++)
            {
                for(int i3 = i2+1; i3 < i-1; i3++)
                {
                    if(vetor[i2] > vetor[i3])
                    {
                        temErro = 1;
                        for(int eme = 0; eme < i; eme++)
                        {
                            printf("Vetor[%d] = %d\n", eme, vetor[eme]);
                        }
                        printf("Elemento na posicao %d com valor %d maior que elemento na posicao %d com valor %d\n\n\n", i2, vetor[i2], i3, vetor[i3]);
                        flagParaAnalize = 1;
                        break;
                    }
                }
                if(temErro == 1)
                    break;
            }
        }
        if(flagParaAnalize == 1)
            for(int eme = 0; eme < i; eme++)    printf("Vetor[%d] = %d\n", eme, vetor[eme]);
        
        for(; true; numDivs++)
        {
            if(flagParaAnalize == 1) printf("Posicao sendo analizada: %d\tvalorBin: %d\nValor posicao i:%d\tValor posicao valorBin: %d\tValor div: %d\n\n", i, valorBin, vetor[i], vetor[valorBin], valorDiv);
            //Caso o valorBin chegue/passe o valor de i
            //Significa que o elemento atual é maior que o maior ordenado
            if(valorBin >= i)
            {
                if(flagParaAnalize == 1) printf("Numero atual é maior que maior elemento do vetor\n");
                valorBin = i+1;
                break;
            }
            //Caso o valorBin chegue/passe o valor de 0
            //Significa que o elemento atual é o menor elemento ordenado
            else if(valorBin <= 0)
            {
                if(flagParaAnalize == 1) printf("Numero atual é menor que menor elemento do vetor\n");
                valorBin = 0;
                break;
            }
            //Caso o vetor na posiçao valorBin seja o meio termo entre o menor e o maior para o numero selecionado
            //Significa que aquela é a posição correta do elemento
            else if(vetor[valorBin - 1] <= vetor[i] && vetor[valorBin] > vetor[i])
            {
                if(flagParaAnalize == 1) printf("Adicionando elemento com valor %d entre vetor[%d] = %d e vetor[%d]= %d\n\n", vetor[i], valorBin - 1, vetor[valorBin-1], valorBin, vetor[valorBin]);
                break;
            }
            
            //Caso a posição sendo analizada seja menor que o valor em i
            //Significa que a posição correta do elemento esta mais a frente
            else if(vetor[valorBin] <= vetor[i])
            {
                if(flagParaAnalize == 1) printf("Vetor[%d] = %d < vetor[i] = %d\n\n\tValorDiv: %d\tAumentando valorDiv\n\n", valorBin, vetor[valorBin], vetor[i], valorDiv);

                if(valorDiv % 2 == 0)
                    valorDiv /= 2;
                else
                    valorDiv = (int)round((float)valorDiv/(float)2) - 1;
                if(flagParaAnalize == 1) printf("ValorDiv atual = %d\n", valorDiv);
                valorBin += valorDiv;
                if(flagParaAnalize == 1) printf("ValorBin atual = %d\n\n", valorBin);                
            }
            //Caso a posicao atual sendo analizada seja maior que o valor em i
            //Significa que a posicao correta do elemento esta mais atras
            else if(vetor[valorBin] > vetor[i])
            {
                if(flagParaAnalize == 1) printf("Vetor[%d] = %d > vetor[i] = %d\n\n\tValorDiv: %d\n\n", valorBin, vetor[valorBin], vetor[i], valorDiv);
                if(valorDiv % 2 == 0)
                    valorDiv /= 2;
                else
                    valorDiv = (int)round((float)valorDiv/(float)2) - 1;
                if(flagParaAnalize == 1) printf("ValorDiv atual = %d\n", valorDiv);                    
                valorBin -= valorDiv;
                if(flagParaAnalize == 1) printf("ValorBin atual = %d\n\n", valorBin);                                
            }
            //Para evitar um livelock do valor div, quando ele chegar a 0, Colocar valor como 2
            //assim ele vai andar casa a casa na procura do elemento
            if(valorDiv == 0)
                valorDiv = 2;
            if(flagParaAnalize == 1) getchar();
            if(numDivs > 50)
            {
                printf("numero de divisoes passou de 50\n\n");
                for(int eme = 0; eme < i; eme++)
                {
                    printf("Vetor[%d] = %d\n", eme, vetor[eme]);
                }
                flagParaAnalize = 1;
            }
        }
        if(flagParaAnalize == 1) getchar();        
        for(j = i; j > valorBin; j--)
        {
            aux = vetor[j];
            vetor[j] = vetor[j-1];
            vetor[j-1] = aux;
        }
        numDivs = 0;
        // flagParaAnalize = 0;
    }
}
/*
void MandarElementosParaFrente(int vetor*, int posicao, int pontoParaParar)
{
    int aux = vetor[i+1];
    for(int i = posicao; i < pontoParaParar; i++)
    {
        vetor[i+1] = aux;
        vetor[i + 1] = vetor[i];
    }
}
*/