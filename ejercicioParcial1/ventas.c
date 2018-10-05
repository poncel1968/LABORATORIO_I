#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "ventas.h"

static int getNextIdVenta();

static int getNextIdVenta()
{
    static int newId;
    return newId++;

}

int ventas_init(ventas* array,int limite)
{
    int i;
    for(i=0;i<limite;i++)
    {
    array[i].isEmpty = 1;
    }
return 0;
}


int ventas_alta(ventas* array,int limite)
{
    int idCliente;
    int cantAfiches;
    char nombreArchivo[100];
    char zona[100];
    int i;
    int flag=0;
    int retorno=-1;

    for(i=0;i<limite;i++)
    {
        if(array[i].isEmpty==1)
        {
            flag=1;
            break;
        }
    }

    if (flag==1 &&
    utn_getInt(&idCliente,5)==0 &&
    utn_getInt(&cantAfiches,5)==0 &&
    utn_getString(nombreArchivo,100,"Ingrese nombre Archivo : ","Error")== 0 &&
    utn_getString(zona,100,"Ingrese zona : ","error")== 0)
    {

        strncpy(array[i].nombreArchivo,nombreArchivo,(strlen(nombreArchivo)));
        strncpy(array[i].zona,zona,(strlen(zona)));

        array[i].idVenta=getNextIdVenta();
        array[i].isEmpty=0;
        strncpy(array[i].estado,"a cobrar",strlen("a cobrar"));
        retorno=0;
    }
    else
    {
        printf("Error Alta venta");
    }

return retorno;

}

int ventas_menu(char* opcionesMenu,ventas* array, int limite)
{
    int salir = 99;
    int opcion=0;

    do
    {
    printf("OPCIONES DEL MENU VENTAS");
    printf(opcionesMenu);
    utn_getInt(&opcion,5);
    switch (opcion)
    {
        case 1:
        ventas_alta(array,limite);
        printf("\nVenta Ok  \n");
        break;

        case 99:
        system("clear");
        printf("Exit Menu Ventas");
        break;

        default:
        printf("\nOpcion Incorrecta!!\n");
        system("clear");
    }
    }while (opcion !=salir );

    return 0;
}

