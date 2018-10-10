#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Clientes.h"
#include "AfichesVendidos.h"
#include "FuncionesParaTodo.h"

/**
*en la funcion  ordenaremos el array de menor a  mayor por ID , para que sea mas facil el conteo  para luego
*ver quien es el  cliente con mas ventas a cobrar .
*\param AfichesVendidos arrayDeAfichesVendidos[]
*\param int limiteAfiches
*\return no devuelve nada
*/
void Informar_informarClientesConMasVentasACobrar (AfichesVendidos arrayDeAfichesVendidos[] ,
  int limiteAfiches)
{
    AfiVend_ordenarAfichesDeMenosAMayor( arrayDeAfichesVendidos , limiteAfiches);

    int i;
    int contadorDeVentas=0;
    int maximoDePedidos=0;
    int IdClienteConMasVentasAcobrar;
    if(arrayDeAfichesVendidos != NULL && limiteAfiches > 0)
    {
        for( i = 0 ; i < limiteAfiches ; i++)
        {
            if(i == 0 && arrayDeAfichesVendidos[i].cobrado == 1 )
            {
                contadorDeVentas++;
            }
            else if(arrayDeAfichesVendidos[i].idCliente == arrayDeAfichesVendidos[i-1].idCliente &&
             arrayDeAfichesVendidos[i].cobrado == 1)
            {
                contadorDeVentas++;
            }
            else if( arrayDeAfichesVendidos[i].idCliente != arrayDeAfichesVendidos[i-1].idCliente)
            {
                if(maximoDePedidos < contadorDeVentas)
                {
                    maximoDePedidos = contadorDeVentas;
                    IdClienteConMasVentasAcobrar = arrayDeAfichesVendidos[i-1].idCliente;
                }
                contadorDeVentas= 0;
                if(arrayDeAfichesVendidos[i].cobrado == 1)
                {
                    contadorDeVentas = 1;
                }
            }
        }
        printf("\n El cliente con mas ventas a cobrar es  el cliente con el ID : %d , con un total de %d Ventas a cobrar",
        IdClienteConMasVentasAcobrar , maximoDePedidos);
    }
}


/**
*en la funcion  ordenaremos el array de menor a  mayor por ID , para que sea mas facil el conteo  para luego
*ver quien es el  cliente con mas ventas cobradas .
*\param AfichesVendidos arrayDeAfichesVendidos[]
*\param int limiteAfiches
*\return no devuelve nada
*/
void Informar_informarClientesConMasVentasACobradas (AfichesVendidos arrayDeAfichesVendidos[] ,
  int limiteAfiches)
{
    AfiVend_ordenarAfichesDeMenosAMayor( arrayDeAfichesVendidos , limiteAfiches);
    int i;
    int contadorDeVentasCobradas=0;
    int maximoDePedidosCobrados=0;
    int IdClienteConMasVentasCobradas;
    if( arrayDeAfichesVendidos != NULL  && limiteAfiches > 0)
    {
        for( i = 0 ; i < limiteAfiches ; i++)
        {
            if(i == 0 && arrayDeAfichesVendidos[i].cobrado == 0 )
            {
                contadorDeVentasCobradas++;
            }
            else if(arrayDeAfichesVendidos[i].idCliente == arrayDeAfichesVendidos[i-1].idCliente  )
            {
                contadorDeVentasCobradas++;
            }
            else if( arrayDeAfichesVendidos[i].idCliente != arrayDeAfichesVendidos[i-1].idCliente)
            {
                if(maximoDePedidosCobrados < contadorDeVentasCobradas)
                {
                    maximoDePedidosCobrados = contadorDeVentasCobradas;
                    IdClienteConMasVentasCobradas = arrayDeAfichesVendidos[i-1].idCliente;
                }
                contadorDeVentasCobradas = 0;
            }
        }
        printf("\n El cliente con mas ventas Cobradas es  el cliente con el ID : %d , con un total de %d Ventas a cobrar",
        IdClienteConMasVentasCobradas , maximoDePedidosCobrados);
    }
}


/**
*ordenamos de mayor a menor a traves de zonas , y luego mostramos todo  ordenado
*\param AfichesVendidos arrayDeAfichesVendidos[]
*\param int limite
*\return no devuelve nada
*/
void Informar_ordenarAfichesDeMenosAMayorPorZona(AfichesVendidos arrayDeAfichesVendidos[] , int limite )
{
    int i;
    int j;
    int auxDeId;
    int auxIsEmpty;
    int auxCantidadDeAfichesAVender;
    int auxAfichesCobrados;
    char auxNombreDelArchivo[51];
    char auxZona[20];
    if(arrayDeAfichesVendidos != NULL && limite > 0)
    {
        for (i = 1; i < limite ; i++) {
            auxDeId = arrayDeAfichesVendidos[i].idAficheVendido;
            auxIsEmpty = arrayDeAfichesVendidos[i].isEmpty;
            auxCantidadDeAfichesAVender= arrayDeAfichesVendidos[i].cantidadDeAfichesAVender;
            auxAfichesCobrados = arrayDeAfichesVendidos[i].cobrado;
            strncpy(auxNombreDelArchivo,arrayDeAfichesVendidos[i].nombreDelArchivo , 51);
            strncpy(auxZona, arrayDeAfichesVendidos[i].zona , 20  );
            for (j = i; j > 0 && strcmp(arrayDeAfichesVendidos[j - 1].zona , auxZona) > 0 ; j--) {
                arrayDeAfichesVendidos[j].idAficheVendido = arrayDeAfichesVendidos[j - 1].idAficheVendido;
                arrayDeAfichesVendidos[j].isEmpty = arrayDeAfichesVendidos[j - 1].isEmpty;
                arrayDeAfichesVendidos[j].cantidadDeAfichesAVender = arrayDeAfichesVendidos[j - 1].cantidadDeAfichesAVender;
                arrayDeAfichesVendidos[j].cobrado = arrayDeAfichesVendidos[j - 1].cobrado;
                strncpy(arrayDeAfichesVendidos[j].nombreDelArchivo,arrayDeAfichesVendidos[j - 1].nombreDelArchivo , 51);
                strncpy(arrayDeAfichesVendidos[j].zona, arrayDeAfichesVendidos[j - 1].zona , 20  );
            }
            arrayDeAfichesVendidos[j].idAficheVendido = auxDeId;
            arrayDeAfichesVendidos[j].isEmpty = auxIsEmpty;
            arrayDeAfichesVendidos[j].cantidadDeAfichesAVender = auxCantidadDeAfichesAVender;
            arrayDeAfichesVendidos[j].cobrado = auxAfichesCobrados;
            strncpy(arrayDeAfichesVendidos[j].nombreDelArchivo,auxNombreDelArchivo, 51);
            strncpy(arrayDeAfichesVendidos[j].zona, auxZona , 20  );
        }
        printf("ID\t Cantidad de afiches vendidos \t Cobrados \t Nombre del archivo \t Zona");
        for ( i = 0; i < limite ; i++)
        {
            printf("\n\n\n%d \t %d \t %d \t %s \t %s\n\n\n\n",arrayDeAfichesVendidos[i].idAficheVendido,arrayDeAfichesVendidos[j].cantidadDeAfichesAVender,
             arrayDeAfichesVendidos[i].cobrado,arrayDeAfichesVendidos[j].nombreDelArchivo ,arrayDeAfichesVendidos[j].zona);
        }
    }
}



/**
*ordenamos de mayor a menor por zonas , y luego hacemos un conteo ordenado de  que cantidad de ventas
*hay por cada zona
*\param AfichesVendidos arrayDeAfichesVendidos[]
*\param limiteAfiches
*\return no retorna nada
*/
void Informar_informarVentasPorZona(AfichesVendidos arrayDeAfichesVendidos[] ,
  int limiteAfiches)
{
    int i;
    int contadorDeVentas=0;
    char auxZona[20];
    Informar_ordenarAfichesDeMenosAMayorPorZona(arrayDeAfichesVendidos , limiteAfiches);

    if(arrayDeAfichesVendidos != NULL  && limiteAfiches > 0)
    {
        for( i = 0 ; i < limiteAfiches ; i ++)
        {
            strncpy(auxZona , arrayDeAfichesVendidos[i].zona ,20);
            if(i == 0)
            {
                contadorDeVentas++;
            }
            else if (arrayDeAfichesVendidos[i].zona != arrayDeAfichesVendidos[i-1].zona )
            {
                printf("la zona : %s , tiene esta cantidad de afiches vendidos: %d\n\n",arrayDeAfichesVendidos[i-1].zona , contadorDeVentas );

            }
            else
            {
                contadorDeVentas++;
            }
        }
    }
}
