#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE * fpointer = fopen("h2z4x3.txt","w");

    fprintf(fpointer,"Pazman Andras mernokinformatikus  H2Z4X3 ");


    fclose(fpointer);

    char line[255];
    FILE * fpointer2 = fopen("h2z4x3.txt","r");

    fgets(line, 255, fpointer);
    fgets(line, 255, fpointer);
    printf("%s",line);

    fclose(fpointer2);

    return 0;
}
