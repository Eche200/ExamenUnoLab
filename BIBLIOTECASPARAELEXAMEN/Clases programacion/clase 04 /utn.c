#include <stdio_ext.h>
#include <stdlib.h>
#include "utn.h"

/**
*\brief Socilito un numero al usuario, valida y devuelve un resultado
*\param pResultado Puntero a la variable resultado
*\param mensaje Es el mensaje a ser mostrado
*\param mensajeError Es el mensaje a ser mostrado en casp de error
*\param minimo Es el numero minimo aceptado
*\param maximo Es el numero maximo aceptado
*\param reintentos Es la cantidad de reintentos que tiene el usuario
*\return En caso de exito retorna 0 y en caso de error -1
*
*/

static void myFpurge()
{
    __fpurge(stdin);
    //fflush(stdin)
}
static  int getInt(int*numeroIngresado)
{
    myFpurge();
    return scanf("%d",numeroIngresado);
}
static  int getFloat(float*numeroIngresado)
{
    myFpurge();
    return scanf("%f",numeroIngresado);
}
static  int getChar(char*caracterIngresado)
{
    myFpurge();
    return scanf("%c",caracterIngresado);
}
static  int getString(int*textoIngresado)
{
    myFpurge();
    return scanf("%s",textoIngresado);
}






int utn_getNumero(  int* pResultado,
                char mensaje[],
                char mensajeError[],
                int minimo,
                int maximo,
                int reintentos)
{
    int numeroIngresado;

    while(reintentos>0)
    {
        printf("%s",mensaje);

        if(int getInt(int*numeroIngresado)==1)
        {
            if(numeroIngresado<=maximo&&numeroIngresado>=minimo)
            {
                *pResultado=numeroIngresado;
                return 0;
            }
            else
            {
                printf("%s",mensajeError);
                reintentos--;
            }
        }
    }

    return -1;
}

int utn_getTelefono(int* pResultado,
                    char mensaje[],
                    char mensajeError[],
                    int reintentos)
{
    int numeroIngresado;

    while(reintentos>0)
    {
        printf("%s",mensaje);

        if(scanf("%d",&numeroIngresado)==1)
        {
            if(numeroIngresado<=maximo&&numeroIngresado>=minimo)
            {
                *pResultado=numeroIngresado;
                return 0;
            }
            else
            {
                printf("%s",mensajeError);
                reintentos--;
            }
        }
    }

    return -1;
}

int utn_getNumeroConSigno(  int* pResultado,
                            char mensaje[],
                            char mensajeError[],
                            int numeroPositivo,
                            int numeroNegativo,
                            int reintentos)
{
    int numeroIngresado;

    while(reintentos>0)
    {
        printf("%s",mensaje);

        if(int getInt(int*numeroIngresado)==1)
        {
            if(numeroIngresado<0)
            {    numeroPositivo=numeroIngresado
                *pResultado=numeroPositivo;
                return 0;
            }
            else if(numeroIngresado>0)
            {   numeroNegativo=numeroIngresado;
                ;
                return 0;
            }
                *pResultado=numeroNegativo;
             else
            {
                printf("%s",mensajeError);
                reintentos--;
            }
            }
        }
    }

    return -1;
}


