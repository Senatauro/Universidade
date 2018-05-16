#include<stdio.h>
#include <stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

void Funcao()
{
    printf("(FILHO) Processo filho com o PID %d\n", getpid());
    printf("(FILHO) Processo pai com PID %d\n", getpid());
    execl("bin/bash","bash", "cowsay teste", NULL);
    getchar();
}

void main()
{
    pid_t pid_filho = fork();
    if(!pid_filho)
    {
        Funcao();
        va_start();
    }
    else
    {
        //wait(NULL);
        for(int i = 0; i < 3; i++)
        {
                //printf("(PAI) Processo pai com PID %d ainda executando\n", getpid());
                int numPID = getpid();
                system("cowsay -f dragon-and-cow processo pai executando com o PID");
                printf("%d\n", numPID);
                getchar();
        }
    }
}