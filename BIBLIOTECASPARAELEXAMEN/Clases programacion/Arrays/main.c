#include <stdio.h>
#include <stdlib.h>
#define CANTIDAD 5
int retornoTotal(int listado[],int tamanio);
int retornoPromedio(int listado[],int tamanio);
void cargarListado(int listado[],int tamanio);
void mostrarListado(int listado[],int tamanio);
void mostrarInformacionDelArray(int listado[],int tamanio);
int retornoMayor(int listado[],int tamanio);
int retornoMenor(int listado[],int tamanio);
int retornoCantidadDePares(int listado[],int tamanio);
int retornarCantidadEntreNotas(int listado[],int tamanio,int limiteInferior,int limiteSuperior);
int main()
{
    int listaDeNotas[CANTIDAD];
    cargarListado(listaDeNotas,CANTIDAD);
    mostrarListado(listaDeNotas,CANTIDAD);
    mostrarInformacionDelArray(listaDeNotas,CANTIDAD);
    return 0;
}
int retornoTotal(int listado[],int tamanio)
{
    int total = 0,i;
    for(i=0;i<tamanio;i++)
    {
        total += listado[i];
    }
    return total;
}
int retornoPromedio(int listado[],int tamanio)
{
    int suma;
    int promedio;
    suma = retornoTotal(listado,tamanio);
    promedio = suma / tamanio;
    return promedio;
}
void cargarListado(int listado[],int tamanio)
{
    int i;
    int numeroIngresado;
    for(i=0;i<tamanio;i++)
    {
        printf("\nIngrese nota n %d: ",i+1);
        scanf("%d",&numeroIngresado);
        listado[i]=numeroIngresado;
        system("cls");
    }
}
void mostrarListado(int listado[],int tamanio)
{
    int i;
    for(i=0;i<tamanio;i++)
    {
        printf("\nLa nota n %d es: %d",i+1,listado[i]);
    }
}
void mostrarInformacionDelArray(int listado[],int tamanio)
{
    int mayor;
    int menor;
    int cantidadDePares;
    int total;
    int promedio;
    int aprobados;
    int aFinal;
    int desaprobados;
    mayor = retornoMayor(listado,tamanio);
    menor = retornoMenor(listado,tamanio);
    cantidadDePares = retornoCantidadDePares(listado,tamanio);
    total = retornoTotal(listado,tamanio);
    promedio = retornoPromedio(listado,tamanio);
    aprobados = retornarCantidadEntreNotas(listado,tamanio,6,10);
    aFinal = retornarCantidadEntreNotas(listado,tamanio,4,5);
    desaprobados = retornarCantidadEntreNotas(listado,tamanio,1,3);
    printf("\n\nLa mayor nota es: %d",mayor);
    printf("\n\nLa menor nota es: %d",menor);
    printf("\n\nLa cantidad de pares es: %d",cantidadDePares);
    printf("\n\nLa suma total de las notas es: %d",total);
    printf("\n\nEl promedio de las notas es: %d",promedio);
    printf("\n\nLa cantidad de aprobados es: %d",aprobados);
    printf("\n\nLa cantidad de gente a final es: %d",aFinal);
    printf("\n\nLa cantidad de desaprobados es: %d\n",desaprobados);
}
int retornoMayor(int listado[],int tamanio)
{
    int i;
    int mayor;
    for(i=0;i<tamanio;i++)
    {
       if(listado[i]>mayor || i==0)
       {
           mayor = listado[i];
       }
    }
    return mayor;
}
int retornoMenor(int listado[],int tamanio)
{
    int i;
    int menor;
    for(i=0;i<tamanio;i++)
    {
        if(listado[i]<menor || i==0)
       {
           menor = listado[i];
       }
    }
    return menor;
}
int retornoCantidadDePares(int listado[],int tamanio)
{
    int i;
    int cantidadDePares = 0;
    for(i=0;i<tamanio;i++)
    {
        if(listado[i]%2==0)
        {
            cantidadDePares++;
        }
    }
    return cantidadDePares;
}
int retornarCantidadEntreNotas(int listado[],int tamanio,int limiteInferior,int limiteSuperior)
{
    int i;
    int cantidadEntreNotas = 0;
    for(i=0;i<tamanio;i++)
    {
        if(listado[i]>=limiteInferior && listado[i]<=limiteSuperior)
        {
            cantidadEntreNotas++;
        }
    }
    return cantidadEntreNotas;
}
