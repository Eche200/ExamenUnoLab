#include <stdio.h>
#include <stdlib.h>

int pedirEdad();
int validarEdad(int edad,int minimo, int maximo);

int main()
{
    int edad;
    edad=pedirEdad();
    printf("La edad ingresada es %d",edad);

}
int pedirEdad()
{
    int edad;
    printf("ingrese edad\n");
    scanf("%d",&edad);
    edad=validarEdad(edad,1,100);
}

int validarEdad(int edad,int minimo, int maximo)
{
    int contador;
    contador=0;
    while(edad<minimo||edad>maximo&&contador<=3)
    {
        contador++;
        if(contador==3)
        {
        edad=-1;
        break;
        }
        printf("Reingrese su edad ");
        scanf("%d",&edad);
    }
    return edad;

}
