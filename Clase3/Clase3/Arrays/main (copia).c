#include <stdio.h>
#include <stdlib.h>
#include "unt.h"
#define CANTIDAD 5


int main()
{
    int listadoDeNotas[CANTIDAD];
    int numeroIngresado;
    int i;
    int mayor;
    int menor;
    int acumuladoNota = 0;
    int suma;

/*
    printf(" Tamaño : %d \n",sizeof(numeroIngresado));
    printf(" Tamaño : %d \n",sizeof(listadoDeNotas));
    printf("  direccion variable %d \n",&numeroIngresado);
    printf("  direccion array %d \n",&listadoDeNotas);
    for (i=0;i<10;i++)
    {
        printf(" direccion de cada elemento : %d \n", &listadoDeNotas[i]);
        printf(" contenido de cada elemento : %d \n", listadoDeNotas[i]);

    }

    */

    for(i=0;i<CANTIDAD;i++)
    {
        printf("Ingrese nota : ");
        scanf("%d",&numeroIngresado);
        listadoDeNotas[i]=numeroIngresado;
    }

    for(i=0;i<CANTIDAD;i++)
    {
        printf("La Nota es : %d \n",listadoDeNotas[i]);

    }

    for (i=0;i<CANTIDAD;i++)
    {
        if (i==0 || listadoDeNotas[i]>mayor)
        {
            mayor=listadoDeNotas[i];
        }

    }
    printf("\nEl mayor es : %d \n",mayor);


    for (i=0;i<CANTIDAD;i++)
    {
        if (i==0 || listadoDeNotas[i]<mayor)
        {
            menor=listadoDeNotas[i];
        }
    }
    printf("\nEl mayor es : %d \n",menor);

    for (i=0;i<CANTIDAD;i++)
    {
            acumuladoNota=listadoDeNotas[i] + acumuladoNota;
    }
printf("\nEl promedio es : %d \n",acumuladoNota/CANTIDAD);
suma=retornarTotal(listadoDeNotas,CANTIDAD);
printf("Suma con la funcion : %d \n\n",suma);
printf("Cargar listado con funcion \n");
cargarListado(listadoDeNotas,CANTIDAD);

return 0;
}


