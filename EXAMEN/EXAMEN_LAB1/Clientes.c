#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Clientes.h"
#include "AfichesVendidos.h"
#include "ClientesAfiches.h"
#include "FuncionesParaTodo.h"
/** \brief esta funcion recibe por parametro un array y un limite
 *el array es donde se  haran las operaciones , y la cantidad maxima de  empleados que puedo almacenar
 *inicializo todos  empleados del array poniendo el atributo .isEmpty en 1 para indicar  que esta vacio tambien ponemos el ID en -1 , para que luego al dar de alta a un empleado
 * podamos evaluar , no solo  si esta de baja sino que  jamas se cargara un dato en el , ya que no debemos borrar nunca a nadie , solo dar de baja.
 * \param Empleado arrayDeEmpleados[] es el  array que le paso como parametro
 * \param limiteDeArrayDeEmpleados cantidad maxima del array
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */

int UTN_initClientes(Clientes arrayDeClientes[],int indice, int limiteDeArrayDeClientes)
{
    int retorno =-1;
    int i;

    if(arrayDeClientes!= NULL && limiteDeArrayDeClientes > 0)
    {
        for(i = indice; i < limiteDeArrayDeClientes ; i++)
        {
            arrayDeClientes[i].isEmpty=1;
            arrayDeClientes[i].idCliente = -1;
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


int UTN_addClientes(Clientes arrayDeClientes[],int indice ,int limiteDeArrayDeClientes,int idCliente, char* name,char*
lastName,char* cuit)
{
    int retorno = -1;
    int i;

    if(arrayDeClientes != NULL && limiteDeArrayDeClientes > 0)
    {
        for( i = indice; i < limiteDeArrayDeClientes ; i++)
        {
            if(arrayDeClientes[i].isEmpty == 1 && arrayDeClientes[i].idCliente == -1)
            {
                __fpurge(stdin);
                printf("\ningrese nombre del cliente\n");
                if(utn_getString(name , 51) == 0 && utn_isValidNombre(name , 51) == 1 )
                {
                    __fpurge(stdin);
                    printf("\ningrese apellido del cliente\n");
                    if(utn_getString(lastName , 51) == 0 && utn_isValidNombre(lastName , 51) == 1)
                    {
                        __fpurge(stdin);
                        printf("\ningrese el cuit del cliente\n");
                        if(utn_getString(cuit,8) == 0 && utn_isValidInt(cuit , 8) == 1)
                        {

                                __fpurge(stdin);
                                arrayDeClientes[i].idCliente = idCliente;
                                arrayDeClientes[i].isEmpty = 0;
                                strncpy(arrayDeClientes[i].nombre , name ,51);
                                strncpy(arrayDeClientes[i].apellido , lastName,51);
                                arrayDeClientes[i].cuit = atoi(cuit);
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






int UTN_modificarClientes(Clientes arrayDeClientes[],int indice , int limiteDeArrayDeClientes, int idDeClientesAModificar)
{
    int retorno = -1;
    int i;

    char nombre[51];
    char apellido[51];
    char cuit[8];

    if(arrayDeClientes != NULL && limiteDeArrayDeClientes > 0 && idDeClientesAModificar > 0)
    {
        for( i = indice; i < limiteDeArrayDeClientes ; i++)
        {
            if(arrayDeClientes[i].idCliente == idDeClientesAModificar && arrayDeClientes[i].isEmpty == 0)
            {

                __fpurge(stdin);
                printf("\ningrese Apellido DEL Cliente \n");
                if(utn_getString(nombre , 51) == 0 && utn_isValidNombre(nombre , 51) == 1 )
                {
                    __fpurge(stdin);
                    printf("\ningrese El nombre del Cliente\n");
                    if(utn_getString(apellido , 51) == 0 && utn_isValidNombre(apellido , 51) == 1)
                    {
                        __fpurge(stdin);
                        printf("\ningrese el cuit \n");
                        if(utn_getString(cuit,20) == 0 && utn_isValidNombre(cuit , 20) == 1)
                        {

                                __fpurge(stdin);

                                strncpy(arrayDeClientes[i].nombre , nombre ,51);
                                arrayDeClientes[i].cuit = atoi(cuit);
                                strncpy(arrayDeClientes[i].apellido , apellido ,51);
                                retorno = 0;

                        }
                    }
                }




            }
        }
    }
    return retorno;
}





int UTN_removeCliente(Clientes arrayDeClientes[], int indice , int limiteDeArrayDeClientes, int idDeClientesABorrar)
{
    int retorno = -1;
    int i;
    if(arrayDeClientes != NULL && limiteDeArrayDeClientes > 0 && idDeClientesABorrar)
    {
        for( i = indice; i < limiteDeArrayDeClientes ; i++)
        {
            if(arrayDeClientes[i].idCliente == idDeClientesABorrar && arrayDeClientes[i].isEmpty == 0)
            {
                arrayDeClientes[i].isEmpty = 1;
                retorno = 0;
                break;
            }
        }
        if( retorno != 0 )
        {
            printf("el id ingresado no correspondo a un usuario en alta");
        }
    }
    return retorno;
}






int  UTN_obtenerSiguienteIdDeClientes()
{
    static int idDeClientes=0;
    idDeClientes++;
    return idDeClientes;
}

