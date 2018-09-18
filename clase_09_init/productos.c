#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "productos.h"


int producto_altaProducto_init(Producto arrayProducto[],int len, int valor)
{
    int retorno = -1;
    int i;

    if (arrayProducto != NULL && len >0 )
    {
        for(i=0;i<len;i++)
        {
            arrayProducto[i].isEmpty = 1;

        }

    }



    return retorno;

}

int producto_altaProducto(Producto arrayProducto[],int len, int indice)
{
    int retorno = -1;
    char auxNombre[50];
    char auxDescripcion[200];
    float auxPrecio =0;

    if (arrayProducto != NULL && len >= 0 && indice<len && arrayProducto[indice].isEmpty)
    {
        if(!utn_getNombre(auxNombre,50,"Ingrese Nombre\n","nombre no valido\n",5) && !utn_getNombre(auxDescripcion,200,"Descripcion producto\n","nombre no valido\n",5))
        {
          strncpy(arrayProducto[indice].nombre,auxNombre,50);
          strncpy(arrayProducto[indice].descripcion,auxDescripcion,200);
          arrayProducto[indice].precio=auxPrecio;
          arrayProducto[indice].isEmpty=0;


          retorno = 0;
        }


    }



    return retorno;

}
