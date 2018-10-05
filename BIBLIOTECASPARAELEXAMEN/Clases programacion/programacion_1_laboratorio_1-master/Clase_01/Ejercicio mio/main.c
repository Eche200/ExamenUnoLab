#include <stdio.h>
#include <stdlib.h>

int main()
{   short int numeroUno;
    short int numeroDos;
    short int numeroTres;
    short int numeroMaximo;
    short int numeroMinimo;
    printf("Ingrese numeroUno");
    scanf("%d ",&numeroUno);
    numeroMinimo=numeroUno
    numeroMaximo=numeroUno
    printf("Ingrese numeroDos");
    scanf("%d ",&numeroDos);
    if(numeroDos<numeroMinimo)
    {
        numeroMinimo=numeroDos
    }
    else if(numeroDos>numeroMinimo)
    {
        numeroMaximo=numeroDos
    }
    printf("Ingrese numeroTres");
    scanf("%d ",&numeroTres);
    if(numeroTres<numeroMinimo)
    {
        numeroMinimo=numeroTres
    }
    else if(numeroTres>numeroMinimo)
    {
        numeroMaximo=numeroTres
    }
    printf("Minimo:%d-Maximo:%d",numeroMinimo,numeroMaximo)
    if(numeroUno>numeroMinimo&&numeroUno<numeroMaximo)
    {
        printf("El numero del medio es:%d",numeroUno)
    }
     if(numeroDos>numeroMinimo&&numeroDos<numeroMaximo)
    {
        printf("El numero del medio es:%d",numeroDos)
    }
     if(numeroTres>numeroMinimo&&numeroTres<numeroMaximo)
    {
        printf("El numero del medio es:%d",numeroTres)
    }

    return

}



