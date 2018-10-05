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

int UTN_initClientes(Clientes arrayDeClientes[],int indice, int limiteDeArrayDeClientes);
int UTN_modificarClientes(Clientes arrayDeClientes[],int indice , int limiteDeArrayDeClientes, int idDeClientesAModificar);
int UTN_removeCliente(Clientes arrayDeClientes[], int indice , int limiteDeArrayDeClientes, int idDeClientesABorrar);

int UTN_addClientes(Clientes arrayDeClientes[],int indice ,int limiteDeArrayDeClientes,int idCliente, char* name,char*
lastName,char* cuit);
int  UTN_obtenerSiguienteIdDeClientes();

#endif // AFICHESVENDIDOS_H_INCLUDED

