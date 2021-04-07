#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void do_nothing();
void do_int();

int main()
{
    unsigned sec = 1;
    signal(SIGINT, do_int);

    for (int i = 1; i < 8 ;i++)
    {
        alarm(sec);
        signal(SIGALRM, do_nothing);
        printf("%d varok, de meddig?\n", i);
        pause();
    }
    return 0;
}

void do_nothing() { }

void do_int()
{
    printf("int jott -> megszakitas");
    signal(SIGINT, SIG_IGN);
}