#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "AfichesVendidos.h"
#include "Clientes.h"
#include "ClientesAfiches.h"
#include "FuncionesParaTodo.h"

int UTN_initClientesAfiches(ClientesAfiches arrayDeClientesAfiches[],int indice, int limiteDeArrayDeClientesAfiches)
{
    int retorno =-1;
    int i;

    if(arrayDeClientesAfiches != NULL && limiteDeArrayDeClientesAfiches > 0)
    {
        for(i = indice; i < limiteDeArrayDeClientesAfiches ; i++)
        {
            arrayDeClientesAfiches[i].isEmpty=1;
            arrayDeClientesAfiches[i].idClientesAfiches= -1;
        }
        retorno=0;
    }
    return retorno;
}


/** \brief esta funcion recibe por parametro un array y un limite
 *el array es donde se  haran las operaciones , y el limite la cantidad maxima de  empleados que puedo almacenar
 *le pasaremos un nombre, apellido , saldo , sector ,  y daremos de alta un empleado y le pondremos un ID UNICO y pondremos que isEmpty es 0 porque esta lleno
 *buscaremos que en el array haya un lugar donde el isEmpty este en 1 (osea vacio) pero tambien el ide sea -1 , ya que puede estar dado de baja , pero no hay que borrarlo
 * sino que solo darlo de baja , por eso buscamos tambien el ID -1
 * \param Empleado arrayDeEmpleados[] es el  array que le paso como parametro
 * \param limiteDeArrayDeEmpleados cantidad maxima del array
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */

int UTN_addClientesAfiches(ClientesAfiches arrayDeClientesAfiches[],int indice ,int limiteDeArrayDeClientesAfiches,int idClientesAfiches, char* idDelCliente,char*
idDeAfichesVendidos)
{
    int retorno = -1;
    int i;
    char idAfichesVendidos[1000];
    char idClientes[1000];



    if(arrayDeClientesAfiches != NULL && limiteDeArrayDeClientesAfiches > 0)
    {
        for( i = indice; i < limiteDeArrayDeClientesAfiches ; i++)
        {
            if(arrayDeClientesAfiches[i].isEmpty == 1 && arrayDeClientesAfiches[i].idClientesAfiches == -1)
            {


                __fpurge(stdin);
                printf("\ningrese el ID del Cliente\n");
                if(utn_getString(idClientes , 51) == 0 && utn_isValidInt(idClientes , 51) == 1 )
                {
                    __fpurge(stdin);
                    printf("\ningrese ID del Afiche vendido \n");
                    if(utn_getString(idAfichesVendidos , 51) == 0 && utn_isValidInt(idAfichesVendidos , 51) == 1)
                    {
                        if(idClientes == idDelCliente && idAfichesVendidos == idDeAfichesVendidos){
                            __fpurge(stdin);
                            arrayDeClientesAfiches[i].idClientesAfiches = idClientesAfiches;
                            arrayDeClientesAfiches[i].isEmpty = 0;
                            arrayDeClientesAfiches[i].idCliente = atoi(idClientes);
                            arrayDeClientesAfiches[i].idAficheVendido = atoi(idAfichesVendidos);
                            retorno = 0;
                        }
                    }
                }
            }
            break;
        }
    }
    return retorno;
}









int UTN_modificarClientesAfiches(ClientesAfiches arrayDeClientesAfiches[],int indice , int limiteDeArrayDeClientesAfiches, int idDeClientesAfiches)
{/*
    int retorno = -1;
    int i;

    char idClientes[1000];
    char idAfichesVendidos[1000];


    if(arrayDeClientesAfiches != NULL && limiteDeArrayDeClientesAfiches > 0 && idDeClientesAfiches > 0)
    {
        for( i = indice; i < limiteDeArrayDeClientes ; i++)
        {
            if(arrayDeClientesAfiches[i].idClientesAfiches == idDeClientesAfiches && arrayDeClientesAfiches[i].isEmpty == 0)
            {
                    __fpurge(stdin);
                    printf("\ningrese El ID  del Afiche Vendido\n");
                    if(utn_getString(idAfichesVendidos , 1000) == 0 && utn_isValidInt(idAfichesVendidos , 1000) == 1)
                    {

// VER ESTO CON URGENCIA!!!!!!!!
                                __fpurge(stdin);

                                strncpy(arrayDeClientes[i].nombre , nombre ,51);
                                arrayDeClientes[i].cuit = atoi(cuit);
                                strncpy(arrayDeClientes[i].apellido , apellido ,51);
                                retorno = 0;


                    }
            }
        }
    }*/
    return 0; //aca va retorno
}







int  UTN_obtenerSiguienteIdDeClientesAfiches()
{
    static int idDeClientesAfiches=0;
    idDeClientesAfiches++;
    return idDeClientesAfiches;
}
