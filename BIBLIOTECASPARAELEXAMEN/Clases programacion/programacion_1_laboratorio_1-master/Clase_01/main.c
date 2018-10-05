#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numeroUno;
    int numeroDos;
    int numeroTres;
    int numeroMin;
    int numeroMax;
    int i;
    for(i=0;i<10;i++)
    {
        printf("\nNumero 1?");
        scanf("%d",&numeroUno);
        numeroMin = numeroUno;
        numeroMax = numeroUno;

        printf("Numero 2?");
        scanf("%d",&numeroDos);
        if(numeroDos < numeroMin)
        {
            numeroMin = numeroDos;
        }
        else if(numeroDos > numeroMax)
        {
            numeroMax = numeroDos;
        }

        printf("Numero 3?");
        scanf("%d",&numeroTres);
        if(numeroTres < numeroMin)
        {
            numeroMin = numeroTres;
        }
        else if(numeroTres > numeroMax)
        {
            numeroMax = numeroTres;
        }

        printf("MIN: %d - MAX: %d",numeroMin,numeroMax);

        if(numeroUno > numeroMin && numeroUno < numeroMax)
        {
            printf("El numero del medio es: %d",numeroUno);
        }
        else if(numeroDos > numeroMin && numeroDos < numeroMax)
        {
            printf("El numero del medio es: %d",numeroDos);
        }
        else if(numeroTres > numeroMin && numeroTres < numeroMax)
        {
            printf("El numero del medio es: %d",numeroTres);
        }


    }
    return 0;
}
