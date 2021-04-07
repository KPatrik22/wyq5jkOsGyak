#include <unistd.h>
#include <signal.h>
#include <stdio.h>

void do_nothing();

int main(void)
{
    signal(SIGALRM, do_nothing);
    printf(" varok, de meddig?\n");
    pause();
    printf("Vegre itt az alarm\n");
    return 0;
}

void do_nothing() {}


