/*programe um minishell que execute, em processos filhos(usando a função fork()),alguns comandos do sistema
a)listar(ls)
b)limpar
c)rede(ifconfig)
d)sair
*/

//execlp("comando", "comando", (char*)null);

#define true 1

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#define KNRM  "\x1B[0m"
#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define KYEL  "\x1B[33m"
#define KBLU  "\x1B[34m"
#define KMAG  "\x1B[35m"
#define KCYN  "\x1B[36m"
#define KWHT  "\x1B[37m"
#define BBLK  "\x1B[40m"
#define BRED  "\x1B[41m"
#define BGRN  "\x1B[42m"
#define BYEL  "\x1B[43m"
#define BBLU  "\x1B[44m"
#define BMAG  "\x1B[45m"
#define BCYN  "\x1B[46m"
#define BWHT  "\x1B[47m"

void BASHApagar();
void BASHListar(char *arg);
void BASHMKDir(char *arg);
void BASHRede();
void BASHSorte();
void BASHAjuda(char *argumentos);
void BASHCalendario();

void main()
{
    char entrada[100], argumentos[100];
    pid_t pid_filho;
    printf("- Mini Shell desenvolvido por %sCarlos Gabriel Silva Stedile%s\n- Versao %s1.0%s\n- Para obter %sajuda%s, digite: %sajuda%s\n", KYEL, KNRM, KGRN, KNRM, KRED, KNRM, KRED, KNRM);
    while(true)
    {
        printf("%s>> ", KNRM);
        //printf("%sComandos:\n\t%slistar\t%slimpar\n\t%srede\t%ssair\n\t%smkdir\t%ss%so%sr%st%se\nDigite o comando: %s",KGRN, KRED, KBLU, KYEL, KMAG, KCYN, KCYN, KBLU, KRED, KWHT, KGRN, KWHT);
        scanf("%s", entrada);
        char ch = getchar();
        memset(argumentos, '\0', 100);
        if(ch != '\n')
        {
            for(int i = 0; ; i++)
            {
                argumentos[i] = getchar();
                if(argumentos[i] == '\n')
                {
                    argumentos[i] = '\0';
                    break;
                }
            }
        }
        pid_filho = fork();
        if(!pid_filho)
        {
            if(!strcmp("listar", entrada))
                BASHListar(argumentos);
            else if(!strcmp("criar", entrada))
                BASHMKDir(argumentos);
            else if(!strcmp("apagar", entrada))
                BASHApagar();
            else if(!strcmp("rede", entrada))
                BASHRede();
            else if(!strcmp("sorte", entrada))
                BASHSorte();
            else if(!strcmp("ajuda", entrada))
                BASHAjuda(argumentos);
            else if(!strcmp("calendario", entrada))
                BASHCalendario(argumentos);
            else
                printf("Comando nao existente\n");
            return;
        }
        if(!strcmp("sair", entrada))
            return;
        wait(NULL);
    }
}


void BASHListar(char *argumentos)
{
    if(strlen(argumentos) > 0)
        execlp("/bin/ls", "ls", argumentos, NULL);
    else
        execlp("/bin/ls", "ls", NULL);
}

void BASHMKDir(char *argumentos)
{
    if(strlen(argumentos) > 0)
        execlp("/bin/mkdir", "mkdir", argumentos, NULL);
    else
        printf("Falta argumento para a criacao da pasta\n");
}

void BASHApagar()
{
    execlp("clear", "clear", NULL);
}

void BASHRede()
{
    execlp("/sbin/ifconfig","ifconfig",NULL);
}

void BASHSorte()
{
    printf("%s", KBLU);
    printf("\n\n");
    execlp("fortune", "fortune", "-a", NULL);
    printf("\n\n");
}

void BASHCalendario()
{
    execlp("cal", "cal", NULL);
}

void BASHAjuda(char *argumentos)
{
    if(strlen(argumentos) == 0)
        printf("%sComandos Existentes:\n\t%slistar\t%sapagar\n\t%srede\t%ssair\n\t%scriar\t%s%scalendario%s\n\t%ss%so%sr%st%se\n\n%s", KGRN, KRED, KBLU, KYEL, KMAG, KCYN, KNRM, BBLU, KNRM, KCYN, KBLU, KRED, KWHT, KGRN, KNRM);
    else if(!strcmp(argumentos, "listar"))
        printf("\t\t\t%sListar%s\nLista as informacoes sobre os arquivos no diretorio de trabalho atual\n\nComo deve ser utilizado: %slistar%s  OU  %slistar%s %s-argumento%s\n\nArgumentos: \n\t   -a\n\tNao ignora arquivos comecando com .\n\t   -l\n\tUsa o formato de lista completa\n\t   -s\n\tOrdena por tamanho, colocando o maior primeiro\n\nExemplos:\n\t>> listar\n\t>> listar -a\n\t>> listar -ls\n\t>> listar -las\n\n",KRED, KNRM, KRED, KNRM, KRED, KNRM, BMAG, KNRM);
    else if(!strcmp(argumentos, "apagar"))
        printf("\t\t\t%sApagar%s\nLimpa a tela se possivel\n\nComo deve ser utilizado: %sapagar%s\n\nNao possui argumentos\n\nExemplo: \n\t>> apagar\n\n", KBLU, KNRM, KBLU, KNRM);
    else if(!strcmp(argumentos, "rede"))
        printf("\t\t\t%sRede%s\nMostra as informacoes sobre as redes conectadas\n\nComo deve ser utilizado: %srede%s\n\nNao possui argumentos\n\nExemplo:\n\t>> rede\n\n", KYEL, KNRM, KYEL, KNRM);
    else if(!strcmp(argumentos, "sair"))
        printf("\t\t\t%sSair%s\nFecha o mini shell\n\nComo deve ser utilizado: %ssair%s\n\nNao possui argumentos\n\nExemplo:\n\t>> sair\n\n", KMAG, KNRM, KMAG, KNRM);
    else if(!strcmp(argumentos, "criar"))
        printf("\t\t\t%sCriar%s\nCria o diretorio se ele nao existir\n\nComo deve ser utilizado: %scriar%s %sDiretorioASerCriado%s\n\nArgumentos:\n\t   Recebe como argumento o nome da pasta a ser criada\n\nExemplo:\n\t>> criar pasta\n\n", KCYN, KNRM, KCYN, KNRM, BMAG, KNRM);
    else if(!strcmp(argumentos, "calendario"))
        printf("\t\t\t%sCalendario%s\nMostra o calendario no formato tradicional\n\nComo deve ser utilizado: %scalendario%s\nNao possui argumentos\n\nExemplo:\n\t>> calendario\n\n",BBLU, KNRM, BBLU, KNRM);
}