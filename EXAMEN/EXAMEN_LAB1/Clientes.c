#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Clientes.h"
#include "AfichesVendidos.h"

#include "FuncionesParaTodo.h"
/** \brief esta funcion recibe por parametro un array,un inicio y un limite
 *el array es donde se  haran las operaciones , el indice es donde empezara  a ejecutarse el FOR y la cantidad maxima de  lugares que puedo inicializar
 *inicializo todos  Afiches vendidos del array poniendo el atributo .isEmpty en 1 para indicar  que esta vacio tambien ponemos el ID en -1 , para que luego al dar de alta a un afiche vendido
 * podamos evaluar , no solo  si esta de baja sino que  jamas se cargara un dato en el , ya que no debemos borrar nunca a nadie , solo dar de baja.
 * \param Clientes arrayDeClientes[] es el  array de clientes que le paso como parametro
 *\param indice es donde empezara a  contar  la iteracion
 * \param limiteDeArrayDeClientes cantidad maxima del array
 * \return int Return (-1) si hubo algun error- (0) if Ok
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


/** \brief esta funcion recibe por parametro un array , un indice , un limite , idCliente, name, lastName,cuit.
 *el array es donde se  haran las operaciones para dar de alta  una venta ,el indice es donde empezara la iteracion, el limite es la cantidad maxima de  afiches vendidos que puedo vender,
 *le pasaremos  nombre nombre multimedia, el IDdelAficheVendido , cantidad De Afiches que venderemos en esa venta, zona donde se colocara  y
 *y el array de empleados para ver si el cliente existe , si no existe , no haremos la venta.
 *
 *buscaremos que en el array haya un lugar donde el isEmpty este en 1 (osea vacio) pero tambien el id sea -1 , ya que puede estar dado de baja , pero no hay que borrarlo
 * sino que solo darlo de baja , por eso buscamos tambien el ID -1
 *
 * \param AfichesVendidos arrayDeAfichesVendidos[]
 * \param indice cantidad
 * \param limiteDeArrayDeEmpleados
 * \param idAfichesVendidos
 * \param nombreDelArchivos
 * \param cantidadDeAfiches
 * \param zona
 * \param arrayDeClientesVoid[]
 * \return int Return (-1) si hubo error- (0) if Ok
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

