#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ERRO_FILA_VAZIA 100
#define ERRO_FILA_POSICAO_NAO_EXISTE 101
#define FILA_POSICAO_INICIAL -1000
#define true 1

typedef struct Estacionamento_Fila
{
    int numVezesManobrado;
    char placa[9];
    struct Estacionamento_Fila *proximo, *anterior;
}Estacionamento_Fila