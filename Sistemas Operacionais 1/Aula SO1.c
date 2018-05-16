#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

int main()
{
    pid_t pid_filho[10];
    int contador = 0;
    //pid_filho = fork();//cria outro processo
    for(contador = 0; contador < 10; contador++)
    {
        pid_filho[contador] = fork();
    }
    if(pid_filho[0] == 0)
    {
        while(getppid() == 1);
        printf("(FILHO)Executando processo filho com PID %d\nProcesso pai com PID %d\n", getpid(), getppid());
        getchar();
        getchar();
        getchar();
    }
    else
    {
        wait(NULL);
        printf("(PAI)Executando processo pai com PID %d\nProcesso pai do pai com PID %d\n", getpid(), getppid());
    }
}