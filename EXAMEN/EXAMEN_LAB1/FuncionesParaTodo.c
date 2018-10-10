#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "AfichesVendidos.h"
#include "Clientes.h"
#include "Informar.h"
#include "FuncionesParaTodo.h"



/**
*\brief Esta funcion lo que hace  es tomar un puntero de tipo CHAR (cadena de caracteres) , y le indicamos el limite de letras
*toma una palabra , y  la pasa correctamente sacandole los contra barra n que pueden aparecer para copiarlo correctamente
*en la cadena de caracteres que le pase.
*
*\param  char* pBuffer
*\param int limite
*\return 0 si esta bien , 1 si esta mal
*/
int utn_getString(char* pBuffer, int limite)
{
    int retorno=-1;
    char bufferStr[4900];
    int tamanoDelBuffer;
    if(pBuffer != NULL && limite > 0){
        __fpurge(stdin);
        fgets(bufferStr,limite,stdin);
        tamanoDelBuffer=strlen(bufferStr);
        if(tamanoDelBuffer != limite - 1 || bufferStr[limite - 2] == '\n'){
            bufferStr[tamanoDelBuffer-1]= '\0';
        }
        strncpy(pBuffer,bufferStr,limite);
        retorno=0;

    }
    return retorno;
}





/**
*toma un puntero de char   y tambien le pasamos el limite
*esta funcion evalua si  en la cadena de caracteres  son solo letras
*
*\param char* pBuffer
*\param int limite
*\return 0 si esta bien , 1  si esta mal
*
*/


int utn_isValidNombre(char* pBuffer , int limite)
{
    int retorno=0;
    int i;
    if(pBuffer != NULL && limite > 0){
        retorno=1;
        for(i=0;i<limite && pBuffer[i]!= '\0';i++){
            if(tolower(pBuffer[i])<'a' || tolower(pBuffer[i])>'z'){
                retorno=0;
                break;
            }
        }
    }
    return retorno;
}


/**
*toma un puntero de char   y tambien le pasamos el limite
*esta funcion evalua si  en la cadena de caracteres  son solo numeros
*
*\param char* pBuffer
*\param int limite
*\return 0 si esta bien , 1  si esta mal
*
*/
int utn_isValidInt(char* pBuffer , int limite)
{
    int retorno=0;
    int i;
    if(pBuffer != NULL && limite > 0){
        retorno=1;
        for( i = 0 ; i < limite && pBuffer[i] != '\0'; i++){
            if(pBuffer[i] >= 'a' && pBuffer[i] <= 'z'){
                retorno=0;
                break;
            }
        }
    }
    return retorno;
}


/**
*toma un puntero de char   y tambien le pasamos el limite
*esta funcion evalua si  en la cadena de caracteres  son solo numeros y tiene un punto para la coma flotante
*
*\param char* pBuffer
*\param int limite
*\return 0 si esta bien , 1  si esta mal
*
*/

int utn_isValidFloat(char* pBuffer , int limite)
{
    int retorno = 0;
    int i;
    int contadorDeComas = 0;
    if(pBuffer != NULL && limite > 0)
    {
        retorno=1;
        for( i = 0 ; i < limite && pBuffer[i] != '\0'; i++)
        {
            if( pBuffer[i] == '.')
            {
                contadorDeComas++;
                if(contadorDeComas > 1 )
                {
                    retorno = 0;
                    break;
                }
            }
            else if(pBuffer[i] >='a' && pBuffer[i] <= 'z')
            {
                retorno = 0;
                break;
            }


        }
        if(contadorDeComas < 1)
        {
            retorno = 0;
        }
    }
    return retorno;
}





void showMenu()
{
    Clientes arrayDeClientes[100];
    AfichesVendidos arrayDeAfichesVendidos[1000];
    char numeroDeOpcion[2];
    int continuar= 0;
    char charDeContinuar[2];
    char bufferParaNombre[4000];
    char bufferParaApellido[4000];
    char bufferParaCantidadDeAfiches[4000];
    char bufferParaIdDeCliente[4000];
    char bufferParaIdDeAfichesVendidos[4000];
    char bufferParaZona[4000];
    do
    {
        printf("\n\n Ingrese una opcion.1-dar de alta a un usuario\n2-Modificar un usuario\n3-Dar de baja un usuario\n"
        "4-dar de alta una venta\n5-Modificar una venta\n6-Cobrar una venta\n7-Cliente con mas ventas a cobrar\n "
        "8- cliente con mas ventas cobradas\n9-cantidad de afiches vendidos por cada una de las 3 zonas\n"
        "10- Listar ventas ordenadas por zona.\n\n");

        if(utn_getString(numeroDeOpcion, 2) == 0 && utn_isValidInt(numeroDeOpcion , 2)== 1)
        {
            switch(atoi(numeroDeOpcion))
            {

                case 1:

                    break;
            }
        }
        printf("desea seguir haciendo operaciones? < 0 para si , 1 para no");
        if(utn_getString(charDeContinuar, 2) == 0 && utn_isValidInt(charDeContinuar , 2)== 1)
        {
            continuar = atoi(charDeContinuar);
        }



    }while(continuar == 0);


}


