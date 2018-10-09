#ifndef AFICHESVENDIDOS_H_INCLUDED
#define AFICHESVENDIDOS_H_INCLUDED
#include "Clientes.h"
typedef struct sAfichesVendidos
{
    int idAficheVendido;
    int isEmpty;
    int cantidadDeAfichesAVender;
    char nombreDelArchivo[51];
    char zona[20];
}AfichesVendidos;

int UTN_initAfichesVendidos(AfichesVendidos arrayDeAfichesVendidos[],int indice, int limiteDeArrayDeAfichesVendidos);

int UTN_addAfichesVendidos(AfichesVendidos arrayDeAfichesVendidos[],int indice ,int limiteDeArrayDeAfichesVendidos,int idAfichesVendidos, char* nombreDelArchivos,
                           char* cantidadDeAfiches,char* zona , void* arrayDeClientesVoid);
int UTN_modificarAfichesVendidos(AfichesVendidos arrayDeAfichesVendidos[],int indice , int limiteDeArrayDeAfichesVendidos, int idDeAfichesVendidosAModificar);


int  UTN_obtenerSiguienteIdDeAfichesVendidos();

void listarClientes(AfichesVendidos arrayDeAfichesVendidos[] , int indice , int limite );

#endif // AFICHESVENDIDOS_H_INCLUDED
