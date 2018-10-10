#ifndef Clientes_H_INCLUDED
#define Clientes_H_INCLUDED
#include "AfichesVendidos.h"

typedef struct sClientes
{
    int idCliente;
    int isEmpty;
    char nombre[51];
    char apellido[51];
    int cuit;
}Clientes;

int Clientes_initClientes(Clientes arrayDeClientes[],int indice, int limiteDeArrayDeClientes);
int Clientes_modificarClientes(Clientes arrayDeClientes[],int indice , int limiteDeArrayDeClientes, int idDeClientesAModificar);
int Clientes_removeCliente(Clientes arrayDeClientes[], int indice , int limiteDeArrayDeClientes, int idDeClientesABorrar);

int Clientes_addClientes(Clientes arrayDeClientes[],int indice ,int limiteDeArrayDeClientes,int idCliente, char* name,char*
lastName,char* cuit);
int  Clientes_obtenerSiguienteIdDeClientes();

void Clientes_ordenarClientesDeMenosAMayor(Clientes arrayDeClientes[] , int limite );
int clientesGetById(Clientes arrayDeCliente[] , int limite);


#endif // AFICHESVENDIDOS_H_INCLUDED

