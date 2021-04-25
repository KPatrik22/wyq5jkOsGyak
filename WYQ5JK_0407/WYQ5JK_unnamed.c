#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

#define MSIZE 128

int main(){

char inBuffer[MSIZE];
int p[2], nbytes, pid;

if (pipe(p) < 0)
{
	perror("Pipe hiba");
	exit(1);
}

pid = fork();
if (pid < 0)
	exit(2);

if (pid == 0)
{
	printf("Child: most fog beirni a pipe-ba!\n");
	write(p[1], "KP WYQ5JK", MSIZE);
	printf("Child: irt a pipe-ba, lehet olvasni!!\n");
}
else if (pid > 0 )
{
	wait(NULL);
	printf("Parent: kiolvas a pipe-bol!\n");
	read(p[0], inBuffer, MSIZE);
	printf("Parent ezt olvasta ki: %s\n", inBuffer);
	printf("Parent: kesz\n");
}

return 0;
}