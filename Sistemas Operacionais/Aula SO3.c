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

void BASHLimpar();
void BASHListar(char *arg);
void BASHMKDir(char *arg);
void BASHRede();
void BASHSorte();

void main()
{
    char entrada[100], argumentos[100];
    pid_t pid_filho;

    while(true)
    {
        printf("%sComandos:\n\t%slistar\t%slimpar\n\t%srede\t%ssair\n\t%smkdir\t%ss%so%sr%st%se\nDigite o comando: %s",KGRN, KRED, KBLU, KYEL, KMAG, KCYN, KCYN, KBLU, KRED, KWHT, KGRN, KWHT);
        scanf("%s", entrada);
        char ch = getchar();
        memset(argumentos, '\0', 100);
        if(ch != '\n')
        {
            for(int i = 0; ; i++)
            {
                argumentos[i] = getchar();
                printf("%c\n", argumentos[i]);
                if(argumentos[i] == '\n')
                {
                    argumentos[i] = '\0';
                    break;
                }
            }
            printf("Lista de argumentos: %s\n", argumentos);
        }
        pid_filho = fork();
        if(!pid_filho)
        {
            if(!strcmp("listar", entrada))
            {
                BASHListar(argumentos);
            }
            else if(!strcmp("mkdir", entrada))
            {
                BASHMKDir(argumentos);
            }
            else if(!strcmp("limpar", entrada))
            {
                BASHLimpar();
            }
            else if(!strcmp("rede", entrada))
            {
                printf("Encontrou rede\n");
                BASHRede();
            }
            else if(!strcmp("sorte", entrada))
            {
                BASHSorte();
            }
            return;
        }
        if(!strcmp("sair", entrada))
            return;
        while(true)
        {
            int status;
            pid_t resultado = waitpid(pid_filho, &status, WNOHANG);
            wait(NULL);
            if(resultado == 0); //processo filho ainda executando
            else if(resultado == -1)    //processo filho deu erro
            {
                printf("Deu ruim, fechando programa");
                //break;
                return ;
            }
            else    //processo filho terminou
            {
                break;
            }
            break;
        }
        //sleep(3);
    }
}


void BASHListar(char *argumentos)
{
    printf("entrou na funcao %s   %d\n", argumentos, strlen(argumentos));
    if(strlen(argumentos) > 0)
        execlp("/bin/ls", "ls", argumentos, NULL);
    else
        execlp("/bin/ls", "ls", NULL);
    //execlp("/usr/bin", "clear", (char*) NULL);
}

void BASHMKDir(char *argumentos)
{
    if(strlen(argumentos) > 0)
        execlp("/bin/mkdir", "mkdir", argumentos, NULL);
}

void BASHLimpar()
{
    execlp("clear",NULL);
    printf("Executou limpar\n");
}

void BASHRede()
{
    printf("entrou em rede");
    execlp("/sbin/ifconfig","ifconfig",NULL);
}

void BASHSorte()
{
    printf("%s", KBLU);
    printf("\n\n");
    system("fortune -a | cowsay");
    printf("\n\n");
}


void RemoverSubstring(char *s,const char *paraRemove)
{
  while( s=strstr(s, paraRemove) )
    memmove(s,s+strlen(paraRemove),1+strlen(s+strlen(paraRemove)));
}