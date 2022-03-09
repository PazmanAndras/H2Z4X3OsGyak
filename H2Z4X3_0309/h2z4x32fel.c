#include <stdio.h>
#include <stdlib.h>

int main()
{
    char cmd[255];


    do{
    printf("Adj meg egy parancsot:");
    scanf("%s", cmd);

    if(*cmd == 'q')
    {

            return 0;
    }

    system(cmd);



    }while(1);
    return 0;
}
