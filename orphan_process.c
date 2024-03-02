/* Orphan processes

When a parent dies before its child, the child is automatically adopted by the original “init”
process whose PID is 1. To, illustrate this insert a sleep statement into the child’s code. This
ensured that the parent process terminated before its child. */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main()
{
    int pid;
    printf("I'm the original process with PID: %d and PPID: %d.\n",getpid(),getppid());
    pid = fork();
    if(pid != 0)
    {
        //it must be a parent 
        printf("I.m the parent with PID: %d and PPID: %d.\n",getpid(),getppid());
        printf("My child's PID is: %d.\n",pid);
    }
    else // pid is Zero , so it must be the child 
    {
        sleep(4);//make sure the parent terminates
        printf("I'm the child with PID %d and PPID %d.\n",getpid(),getppid());
    }
    printf("PID %d terminates/+.\n",getpid());
}
