#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "AfichesVendidos.h"
#include "Clientes.h"
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

int UTN_initAfichesVendidos(AfichesVendidos arrayDeAfichesVendidos[],int indice, int limiteDeArrayDeAfichesVendidos)
{
    int retorno =-1;
    int i;

    if(arrayDeAfichesVendidos != NULL && limiteDeArrayDeAfichesVendidos > 0)
    {
        for(i = indice; i < limiteDeArrayDeAfichesVendidos ; i++)
        {
            arrayDeAfichesVendidos[i].isEmpty=1;
            arrayDeAfichesVendidos[i].idAficheVendido = -1;
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

int UTN_addAfichesVendidos(AfichesVendidos arrayDeAfichesVendidos[],int indice ,int limiteDeArrayDeAfichesVendidos,int idAfichesVendidos, char* nombreDelArchivos,char*
lastName,char* cantidadDeAfiches,char* zona , void* arrayDeClientesVoid)
{
    Clientes* arrayDeClientes = arrayDeClientesVoid;
    int retorno = -1;
    int i;
    char idDelClienteParaVenta[1000];

    if(arrayDeAfichesVendidos != NULL && limiteDeArrayDeAfichesVendidos > 0)
    {
        for( i = indice; i < limiteDeArrayDeAfichesVendidos ; i++)
        {
            if(arrayDeAfichesVendidos[i].isEmpty == 1 && arrayDeAfichesVendidos[i].idAficheVendido == -1)
            {

                __fpurge(stdin);
                printf("Ingrese el ID del cliente");
                if(utn_getString(idDelClienteParaVenta , 1000) == 0 && utn_isValidInt(idDelClienteParaVenta , 1000) == 1)
                {
                    for(int j = 0 ; j< 100 ; j++)
                    {
                        if(arrayDeClientes[i].idCliente == atoi(idDelClienteParaVenta))
                        {
                            __fpurge(stdin);
                            printf("\ningrese Cantidad de afiches a comprar \n");
                            if(utn_getString(cantidadDeAfiches , 6) == 0 && utn_isValidInt(cantidadDeAfiches , 6) == 1 )
                            {
                                __fpurge(stdin);
                                printf("\ningrese El nombre del archivo\n");
                                if(utn_getString(nombreDelArchivos , 51) == 0 && utn_isValidNombre(nombreDelArchivos , 51) == 1)
                                {
                                    __fpurge(stdin);
                                    printf("\ningrese La zona donde se pondra el afiche\n");
                                    if(utn_getString(zona,20) == 0 && utn_isValidNombre(zona , 20) == 1)
                                    {

                                        __fpurge(stdin);
                                        arrayDeAfichesVendidos[i].idAficheVendido = idAfichesVendidos;
                                        arrayDeAfichesVendidos[i].isEmpty = 0;
                                        strncpy(arrayDeAfichesVendidos[i].nombreDelArchivo , nombreDelArchivos ,51);
                                        arrayDeAfichesVendidos[i].cantidadDeAfichesAVender = atof(cantidadDeAfiches);
                                        strncpy(arrayDeAfichesVendidos[i].zona , zona ,20);
                                        retorno = 0;

                                    }
                                }
                            }
                            break;
                        }
                    }
                }
            }
            break;
        }
    }
    return retorno;
}




/** \brief esta funcion recibe por parametro un array , un limiteDeArrayDeAfichesVendidos y un identificador unico
 *el array es donde se  haran las operaciones , y la cantidad maxima de  empleados que puedo almacenar
 *con esos datos  mas el ID que nos pase , podemos  saber si existe en el array y si existe lo podremos modificar.
 * \param Empleado arrayDeAfichesVendidos[] es el  array que le paso como parametro
 * \param limiteDeArrayDeAfichesVendidos cantidad maxima del array
 *\param idDePersonaAModificar obtiene un  id y buscamos en el array
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 */



int UTN_modificarAfichesVendidos(AfichesVendidos arrayDeAfichesVendidos[],int indice , int limiteDeArrayDeAfichesVendidos, int idDeAfichesVendidosAModificar )
{
    int retorno = -1;
    int i;
    char cantidadDeAfiches[6];
    char zona[20];
    char idDeLaVenta[1000];
    if(arrayDeAfichesVendidos != NULL && limiteDeArrayDeAfichesVendidos > 0 && idDeAfichesVendidosAModificar > 0)
    {
        for( i = indice; i < limiteDeArrayDeAfichesVendidos ; i++)
        {
            printf("Ingrese el ID de Venta");
            if(utn_getString(idDeLaVenta , 1000) == 0 && utn_isValidInt(idDeLaVenta , 1000) == 1)
            {
                if(atoi(idDeLaVenta) == arrayDeAfichesVendidos[i].idAficheVendido && arrayDeAfichesVendidos[i].isEmpty == 0)
                {
                    __fpurge(stdin);
                    printf("\ningrese Cantidad de afiches a comprar \n");
                    if(utn_getString(cantidadDeAfiches , 6) == 0 && utn_isValidInt(cantidadDeAfiches , 6) == 1 )
                    {

                        __fpurge(stdin);
                        printf("\ningrese La zona donde se pondra el afiche\n");
                        if(utn_getString(zona,20) == 0 && utn_isValidNombre(zona , 20) == 1)
                        {
                                __fpurge(stdin);
                                arrayDeAfichesVendidos[i].cantidadDeAfichesAVender = atof(cantidadDeAfiches);
                                strncpy(arrayDeAfichesVendidos[i].zona , zona ,20);
                                retorno = 0;
                        }
                    }
                }
            }
        }
    }
    return retorno;
}






int UTN_removeAfichesVendidos(AfichesVendidos arrayDeAfichesVendidos[], int indice , int limiteDeArrayDeAfichesVendidos, int idDeAfichesVendidosABorrar)
{
    int retorno = -1;
    int i;
    char idDeVentaBuffer[1000];
    if(arrayDeAfichesVendidos != NULL && limiteDeArrayDeAfichesVendidos > 0 && idDeAfichesVendidosABorrar)
    {
        __fpurge(stdin);
        printf("\ningrese el ID de la venta  \n");
        if(utn_getString(idDeVentaBuffer , 1000) == 0 && utn_isValidInt(idDeVentaBuffer , 1000) == 1 )
        {
            for( i = indice; i < limiteDeArrayDeAfichesVendidos ; i++)
            {
                if(atoi(idDeVentaBuffer) == arrayDeAfichesVendidos[i].idAficheVendido)
                {
                    arrayDeAfichesVendidos[i].isEmpty = 1;
                    retorno = 0;
                    break;
                }
            }
        }
        if( retorno != 0 )
        {
            printf("el id ingresado no correspondo a un usuario en alta");
        }
    }
    return retorno;
}





void listarClientes()
{



}






/** \brief no recibe parametros , lo que haces es crear  una variable permanente que se autoincrementa cada vez que la llamamos y nos devuelve el proximo ID
 * \return devuelve el siguiente ID
 *
 */


int  UTN_obtenerSiguienteIdDeAfichesVendidos()
{
    static int idDeAfichesVendidos=0;
    idDeAfichesVendidos++;
    return idDeAfichesVendidos;
}
