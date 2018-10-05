#include <stdio.h>
#include <stdlib.h>
#define CANTIDAD 5

int retornarTotal(int listado[],int tamaño );
int retornarPromedio(int listado[],int tamaño );
void cargarListado(int listado[],int tamaño);
int retornarCantidadEntreNotas(int listado[],int tamaño, int limInferior, int limSuperior);


int main()
{

    int listadoDeNotas[CANTIDAD];
    cargarListado(listadoDeNotas,CANTIDAD);
    mostraListado(listadoDeNotas,CANTIDAD);
    mostrarInformacionDelArray(listadoDeNotas,CANTIDAD);
    return 0;
}
/*brief
    a-el mayor
    b-el menor
    c-cant de pares
    d-suma total
    e-promedio

*/


int retornarTotal(int listado[],int tamaño )
{
    int sumaDeNotas=0;
    int i;
    for(i=0;i<tamaño,i++)
    {
         sumaDeNotas=sumaDeNotas+listadoDeNotas[i];
    }
        return sumaDeNotas;

}
int retornarPromedio(int listado[],int tamaño )
{
    int suma;
    int promedio;
    suma=retornarTotal(listado,tamaño);
    promedio=suma/tamaño;
    return promedio;

}
void cargarListado(int listado[],int tamaño)
{
    int i;
    int numeroIngresado;
    for(i=0;i<tamaño;i++)
    {
         printf("ingrese nota n %d:",i+1);
         scanf("%d",&numeroIngresado);

         listado[i]=numeroIngresado;
    }
}

 int mayor ()
 {

 }
