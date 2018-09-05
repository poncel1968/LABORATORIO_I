#include <stdio.h>
#include <stdlib.h>
#include "unt.h"

int retornarTotal(int listado[],int cant )
{
    int acumuladoNota = 0;
    int i;

    for (i=0;i<cant;i++)
    {
            acumuladoNota=listado[i] + acumuladoNota;
    }
    return acumuladoNota;
}

void cargarListado(int listado[],int cant)
{
    int numeroIngresado;
    int i;

    for(i=0;i<cant;i++)
    {
        printf("Ingrese nota : ");
        scanf("%d",&numeroIngresado);
        listado[i]=numeroIngresado;
    }

}

