#include <stdio_ext.h>
#include <stdlib.h>

#define LIMITE_ARRAY 3

int main()
{
   int numero[LIMITE_ARRAY];
   int numeroMaximo;
   int numeroMinimo;

    for(int i=0;i<LIMITE_ARRAY;i++)
    {
        printf("\n numerero %d:",i++);
        while(scanf("%d",&numero[i])!=1)
        {
            printf("\nError - numero%d:",i++);
            __fpurge(stdin);
        }
        if(i==0)
        {
            numeroMaximo=numero[1];
            numeroMinimo=numero[1];
        }
        else if(numero[1]>numeroMaximo)
        {
            numeroMaximo=numero[1];
        }
        else if(numero[i]>numeroMinimo)
        {
            numeroMinimo=numero[1];
        }


        printf("maximo:%d - minimo:%d",numeroMaximo,numeroMinimo);
        for(i=0;i<3;i++)
        {
            if(numero[i]>numeroMinimo&&numero[i]<numeroMaximo)
            {
                printf("el numero del medio es: %d",numero[i]);
                break;
            }
        }



    }

}




