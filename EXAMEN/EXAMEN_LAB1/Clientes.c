#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Clientes.h"
#include "AfichesVendidos.h"
#include "Informar.h"
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

int Clientes_initClientes(Clientes arrayDeClientes[],int indice, int limiteDeArrayDeClientes)
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
 *el array es donde se  haran las operaciones para dar de alta  una venta ,el indice es donde empezara la iteracion, el limite es la cantidad maxima de  Clientes ,
 *le pasaremos  nombre nombre del clientes , su id , su apellido y cuit
 *buscaremos que en el array haya un lugar donde el isEmpty este en 1 (osea vacio) pero tambien el id sea -1 , ya que puede estar dado de baja , pero no hay que borrarlo
 * sino que solo darlo de baja , por eso buscamos tambien el ID -1
 * \param Clientes arrayDeClientes[]
 * \param indice
 * \param limiteDeArrayDeClientes
 * \param idCliente
 * \param name
 * \param lastName
 * \param cuit
 * \return int Return (-1) si hubo error- (0) if Ok
 */


int Clientes_addClientes(Clientes arrayDeClientes[],int indice ,int limiteDeArrayDeClientes,int idCliente, char* name,char*
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
                        if(utn_getString(cuit,8) == 0 && utn_isValidInt(cuit , 8) == 1 && strlen(cuit) == 8)
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

/** \brief esta funcion recibe por parametro un array ,un indice ,un limiteDeArrayDeClientes y un identificador unico
 *el array es donde se  haran las operaciones , la cantidad maxima de  Clientes  , el id del cliente y
 *un indice para empezar a iterar desde ahi
 *con esos datos  mas el ID que nos pase , podemos  saber si existe en el array y si existe lo podremos modificar.
 * \param Clientes arrayDeClientes[] es el  array que le paso como parametro
 * \param limiteDeArrayDeClientes cantidad maxima del array
 *\param idDeClientesAModificar
 *\param indice
 * \return int Return (-1)si hubo un error - (0) if Ok
 */
int Clientes_modificarClientes(Clientes arrayDeClientes[],int indice , int limiteDeArrayDeClientes, int idDeClientesAModificar)
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
                        if(utn_getString(cuit,8) == 0 && utn_isValidNombre(cuit , 8) == 1)
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


/** \brief esta funcion recibe por parametro un array ,un indice ,un limiteDeArrayDeClientes y un identificador unico
 *el array es donde se  haran las operaciones , la cantidad maxima de  clientes ,
 *el id del cliente a dar de baja .
 *con esos datos  mas el ID que nos pase , podemos  saber si existe en el array y si existe lo podremos dar de baja.
 * \param Clientes arrayDeClientes[] es el  array que le paso como parametro
 * \param limiteDeArrayDeClientes cantidad maxima del array
 *\param idDeClientesABorrar
 *\param indice
 * \return int Return (-1)si hubo un error - (0) if Ok
 */
int Clientes_removeCliente(Clientes arrayDeClientes[], int indice , int limiteDeArrayDeClientes, int idDeClientesABorrar)
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



/** \brief recibe como parametros un array de tipo Clientes y un limite hasta donde debe  iterar.
*agarra un array de tipo Clientes y lo ordena de menor a mayor , asi luego
*a la hora de los informes es mas facil encontrar en orden las cosas y  poder llevar un mejor conteo de lo pedido
*\param Clientes arrayDeClientes[]
*\param limite
* \return no devuelve nada
*/

void Clientes_ordenarClientesDeMenosAMayor(Clientes arrayDeClientes[] , int limite )
{
    int i;
    int j;
    int auxDeidCliente;
    int auxIsEmpty;
    char auxNombre[51];
    char auxApellido[51];
    int auxCuit;
    for (i = 1; i < limite ; i++) {
        auxDeidCliente = arrayDeClientes[i].idCliente;
        auxIsEmpty = arrayDeClientes[i].isEmpty;
        auxCuit= arrayDeClientes[i].cuit;
        strncpy(auxNombre,arrayDeClientes[i].nombre , 51);
        strncpy(auxApellido, arrayDeClientes[i].apellido , 51  );
        for (j = i; j > 0 && arrayDeClientes[j - 1].idCliente > auxDeidCliente; j--) {
            arrayDeClientes[j].idCliente = arrayDeClientes[j - 1].idCliente;
            arrayDeClientes[j].isEmpty = arrayDeClientes[j - 1].isEmpty;
            arrayDeClientes[j].cuit = arrayDeClientes[j - 1].cuit;
            strncpy(arrayDeClientes[j].nombre,arrayDeClientes[j - 1].nombre , 51);
            strncpy(arrayDeClientes[j].apellido, arrayDeClientes[j - 1].apellido , 20  );
        }
        arrayDeClientes[j].idCliente = auxDeidCliente;
        arrayDeClientes[j].isEmpty = auxIsEmpty;
        arrayDeClientes[j].cuit = auxCuit;
        strncpy(arrayDeClientes[j].nombre,auxNombre, 51);
        strncpy(arrayDeClientes[j].apellido, auxApellido , 20  );
    }
}






/** \brief no recibe parametros , lo que haces es crear  una variable permanente que se autoincrementa cada vez que la llamamos y nos devuelve el proximo ID
 * \return devuelve el siguiente ID
 *
 */
int  Clientes_obtenerSiguienteIdDeClientes()
{
    static int idDeClientes=0;
    idDeClientes++;
    return idDeClientes;
}

int clientesGetById(Clientes arrayDeCliente[] , int limite)
{
    int i;
    int IdDevuelto=-1;
    char cuit[8];

    if(arrayDeCliente != NULL && limite >0)
    {
        printf("\ningrese el cuit \n");
        if(utn_getString(cuit,8) == 0 && utn_isValidNombre(cuit , 8) == 1)
        {
            for( i = 0 ; i < limite ; i++)
            {
                if(arrayDeCliente[i].cuit == atoi(cuit))
                {
                    IdDevuelto = arrayDeCliente[i].idCliente;
                    break;
                }
            }
        }
    }

    return IdDevuelto;
}
