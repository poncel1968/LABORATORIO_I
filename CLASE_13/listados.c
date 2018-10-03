#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "pantalla.h"
#include "utn.h"
#include "Contratacion.h"
#include "informar.h"
#include "listados.h"


int listado_ordenado (Pantalla * array, int limite)
{

int  j;
Pantalla aux;
int flag =1;

while (flag==1)
{
    flag=0;
    for (j = 1; j < limite; j++)
{

    if (array[j-1].precio <array[j].precio)
    {
        strncpy(aux.direccion,array[j].direccion,50);
        strncpy(aux.nombre,array[j].nombre,50);
        aux.idPantalla=array[j].idPantalla;
        aux.isEmpty=array[j].isEmpty;
        aux.precio=array[j].precio;
        aux.tipo=array[j].tipo;

        strncpy(array[j].direccion,array[j-1].direccion,50);
        strncpy(array[j].nombre,array[j-1].nombre,50);
        array[j].idPantalla=array[j-1].idPantalla;
        array[j].isEmpty=array[j-1].isEmpty;
        array[j].precio=array[j-1].precio;
        array[j].tipo=array[j-1].tipo;

        strncpy(array[j-1].direccion,aux.direccion,50);
        strncpy(array[j-1].nombre,aux.nombre,50);
        array[j-1].idPantalla=aux.idPantalla;
        array[j-1].isEmpty=aux.isEmpty;
        array[j-1].precio=aux.precio;
        array[j-1].tipo=aux.tipo;

        flag=1;
    }

    if (array[j-1].precio ==array[j].precio && strcmp(array[j-1].nombre,array[j].nombre)>1)
    {
        strncpy(aux.direccion,array[j].direccion,50);
        strncpy(aux.nombre,array[j].nombre,50);
        aux.idPantalla=array[j].idPantalla;
        aux.isEmpty=array[j].isEmpty;
        aux.precio=array[j].precio;
        aux.tipo=array[j].tipo;

        strncpy(array[j].direccion,array[j-1].direccion,50);
        strncpy(array[j].nombre,array[j-1].nombre,50);
        array[j].idPantalla=array[j-1].idPantalla;
        array[j].isEmpty=array[j-1].isEmpty;
        array[j].precio=array[j-1].precio;
        array[j].tipo=array[j-1].tipo;

        strncpy(array[j-1].direccion,aux.direccion,50);
        strncpy(array[j-1].nombre,aux.nombre,50);
        array[j-1].idPantalla=aux.idPantalla;
        array[j-1].isEmpty=aux.isEmpty;
        array[j-1].precio=aux.precio;
        array[j-1].tipo=aux.tipo;

        flag=1;
    }

}
}
    return 0 ;
}


int listado_pantallas (Pantalla * array, int limite)
{


    int i;

    for(i=0;i<limite;i++)
    {
        if (array[i].isEmpty==0)
        {
        printf(" Nombre : %s \n",array[i].nombre);
        printf(" Direccion : %s \n",array[i].direccion);
        printf(" Precio : %f \n",array[i].precio);
        printf(" Tipo : %d \n",array[i].tipo);
        printf(" Id : %d \n",array[i].idPantalla);
        }
    }

        return 0;

}


int listado_pantallasMenor (Pantalla * array, int limite,int valor)
{


    int i;

    for(i=0;i<limite;i++)
    {
        if (array[i].isEmpty==0 && array[i].precio<valor)
        {
        printf(" Nombre : %s \n",array[i].nombre);
        printf(" Direccion : %s \n",array[i].direccion);
        printf(" Precio : %f \n",array[i].precio);
        printf(" Tipo : %d \n",array[i].tipo);
        printf(" Id : %d \n",array[i].idPantalla);
        }
    }

        return 0;

}

int promedio_preciopantalla (Pantalla * array, int limite,float* promedio)
{
    int retorno=-1;
    int i;
    float acumulado = 0;
    int contador = 0;
    for (i=0;i<limite;i++)
    {
        if(array[i].isEmpty==0)
        {
        acumulado= acumulado+array[i].precio;
        contador++;
        }
    }

    *promedio=acumulado/contador;
    retorno=0;

    return retorno;
}


int listado_pantallasMenorPromedio (Pantalla* array, int limite,float* promedio)
{

    int i;
    printf("El promedio es : %.2f",*promedio);
    for(i=0;i<limite;i++)
    {
        if (array[i].isEmpty==0 && array[i].precio<*promedio)
        {
        printf(" Nombre : %s \n",array[i].nombre);
        printf(" Direccion : %s \n",array[i].direccion);
        printf(" Precio : %f \n",array[i].precio);
        printf(" Tipo : %d \n",array[i].tipo);
        printf(" Id : %d \n",array[i].idPantalla);
        }
    }
        return 0;
}

