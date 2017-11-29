/*
O programa tem que salvar os cadastros em um arquivo texto
E tem que mostrar todos os cadastros
*/

#include<stdio.h>
#include<stdlib.h>

#define true 1
#define false 0

typedef struct Paciente
{
    int identificador;
    char nome[100];
    char telefone[20];
}Paciente;

void main()
{
    int op = 0;
    do
    {
        printf("1 - Cadastrar paciente\n2 - Ver pacientes cadastrados\n3 - Fechar programa\n");
        scanf("%d", &op);
        if(op == 1)
            CadastrarPaciente();
        else if(op == 2)
            MostrarPacientesCadastrados();
        else if(op == 3)
            break;
    }while(true);
}

void CadastrarPaciente()
{
    FILE *arq;
    arq = fopen("pacientes.txt", "a");
    if(arq == NULL)
    {
        printf("Deu problema ao abrir o arquivo de pacientes, fechando programa");
        exit(1);
    }
    Paciente pac;
    printf("Digite o identificador do paciente: ");
    scanf("%d", &pac.identificador);
    printf("Digite o nome do paciente: ");
    getchar();
    gets(pac.nome);
    printf("O telefone do paciente: ");
    gets(pac.telefone);
    fprintf(arq, "%d %s %s\n", pac.identificador, pac.nome, pac.telefone);
    fclose(arq);
}

void MostrarPacientesCadastrados()
{
    FILE *arq;
    arq = fopen("pacientes.txt", "r");
    if(arq == NULL)
    {
        printf("Deu problema ao abrir o arquivo de pacientes, fechando programa");
        exit(1);
    }
    int identificador;
    char nome[100];
    char telefone[20];
    while (fscanf(arq, "%d %s %[^\n]", &identificador, &nome, &telefone) == 3)
	{
        printf("Identificador: %d\nNome: %s\tTelefone: %s\n\n", identificador, nome, telefone);
	}
    fclose(arq);
}