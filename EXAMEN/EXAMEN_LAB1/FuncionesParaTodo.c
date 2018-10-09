#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "AfichesVendidos.h"
#include "Clientes.h"

#include "FuncionesParaTodo.h"


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

// toma un auxiliar y evalua si es  solo palabras
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
