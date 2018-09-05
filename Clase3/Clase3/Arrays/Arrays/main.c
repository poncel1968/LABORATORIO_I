#include <stdio.h>
#include <stdlib.h>
#define CANTIDAD 5

int retornarTotal(int array[],int cant );

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

suma=retornarTotal(listadoDeNotas,5);
printf("Suma conla funcion : %d",suma);


    return 0;
}



int retornarTotal(int listado[],int cant )
{
    int acumuladoNota = 0;
    int i;

    for (i=0;i<cant;i++)
    {
            acumuladoNota=listado[i] + acumuladoNota;
            printf("debug funcion listado[%d] = %d , \n" ,i,listado[i]);
    }
    printf("\nacumulado nota = %d",acumuladoNota);
    return acumuladoNota;
}


