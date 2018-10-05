#include <stdio.h>
#include <stdlib.h>
#include "utn.h"

int main()
{
    int numero;

    if (utn_getNumero(&numero, "Numero?\n","Fuera de rango",10,100,2)==0)
    {
        printf("\nEl numero es %d",numero);
    }
    return 0;
}
