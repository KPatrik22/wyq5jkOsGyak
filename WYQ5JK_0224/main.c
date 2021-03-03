#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE * fp;
    fp = fopen ("kolozsvari.txt","w");

    fprintf (fp, "Nev: Kolozsvari Patrik\nSzak: Programtervezo informatikus\nNeptun: WYQ5JK");

    fclose (fp);
    return 0;
}
