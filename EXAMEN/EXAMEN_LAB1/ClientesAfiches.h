#ifndef CLIENTESAFICHES_H_INCLUDED
#define CLIENTESAFICHES_H_INCLUDED
typedef struct sClientesAfiches
{
    int idClientesAfiches;
    int isEmpty;
    int idCliente;
    int idAficheVendido;

}ClientesAfiches;

int UTN_initClientesAfiches(ClientesAfiches arrayDeClientesAfiches[],int indice, int limiteDeArrayDeClientesAfiches);

int UTN_modificarClientesAfiches(ClientesAfiches arrayDeClientesAfiches[],int indice , int limiteDeArrayDeClientesAfiches, int idDeClientesAfiches);

int UTN_addClientesAfiches(ClientesAfiches arrayDeClientesAfiches[],int indice ,int limiteDeArrayDeClientesAfiches,int idClientesAfiches, char* idClientes,char*
idAfichesVendidos);


int  UTN_obtenerSiguienteIdDeClientesAfiches();

#endif // CLIENTESAFICHES_H_INCLUDED
