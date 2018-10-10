#ifndef AFICHESVENDIDOS_H_INCLUDED
#define AFICHESVENDIDOS_H_INCLUDED
#include "Clientes.h"
typedef struct sAfichesVendidos
{
    int idAficheVendido;
    int idCliente;
    int cobrado;
    int isEmpty;
    int cantidadDeAfichesAVender;
    char nombreDelArchivo[51];
    char zona[20];
}AfichesVendidos;

int AfiVend_initAfichesVendidos(AfichesVendidos arrayDeAfichesVendidos[],int indice, int limiteDeArrayDeAfichesVendidos);

int AfiVend_addAfichesVendidos(AfichesVendidos arrayDeAfichesVendidos[],int indice ,int limiteDeArrayDeAfichesVendidos,int idAfichesVendidos, char* nombreDelArchivos,
                            char* cantidadDeAfiches,int idCliente ,char* zona , void* arrayDeClientesVoid);
int AfiVend_modificarAfichesVendidos(AfichesVendidos arrayDeAfichesVendidos[],int indice , int limiteDeArrayDeAfichesVendidos, int idDeAfichesVendidosAModificar);

int AfiVend_CobrarAfichesVendidos(AfichesVendidos arrayDeAfichesVendidos[], int indice , int limiteDeArrayDeAfichesVendidos);

int  AfiVend_obtenerSiguienteIdDeAfichesVendidos();

void AfiVend_ordenarAfichesDeMenosAMayor(AfichesVendidos arrayDeAfichesVendidos[] , int limite );


#endif // AFICHESVENDIDOS_H_INCLUDED
