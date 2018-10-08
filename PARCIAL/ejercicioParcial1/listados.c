#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "clientes.h"
#include "ventas.h"
#include "listados.h"

typedef struct
{
    int idCliente;
    int cantAfiches;

}clienteAfiche;

/*
@brief : lista clientes por orden del apellido
@param : array de la estructura
@param : limite de la estructura
@param : id cliente a quien pertenece la venta
@value : 0 is successful
*/

int listados_clientes_ordenarPorApellido(cliente* array, int limite)
{
int  j,i;
cliente aux;
int flag=1;

while (flag==1)
{
    flag=0;
    for (j = 1; j < limite; j++)
    {
        if (strcmp(array[j-1].apellido,array[j].apellido)>0 )
        {
        strncpy(aux.nombre,array[j].nombre,50);
        strncpy(aux.apellido,array[j].apellido,50);
        strncpy(aux.cuit,array[j].cuit,13);
        aux.id=array[j].id;
        aux.isEmpty=array[j].isEmpty;

        strncpy(array[j].nombre,array[j-1].nombre,50);
        strncpy(array[j].apellido,array[j-1].apellido,50);
        strncpy(array[j].cuit,array[j-1].cuit,13);
        array[j].id=array[j-1].id;
        array[j].isEmpty=array[j-1].isEmpty;

        strncpy(array[j-1].nombre,aux.nombre,50);
        strncpy(array[j-1].apellido,aux.apellido,50);
        strncpy(array[j-1].cuit,aux.cuit,13);
        array[j-1].id=aux.id;
        array[j-1].isEmpty=aux.isEmpty;

        flag=1;
        }
    }
}
for(i=0;i<limite;i++)
{
    if (array[i].isEmpty==0)
    {
        printf("Apellido y nombre cliente : %s , %s \n",array[i].apellido,array[i].nombre);
        printf("Cuit : %s , Id : %d \n",array[i].cuit,array[i].id);
    }
}
return 0;
}

/*
@brief : listado de ventas por cliente
@param : array de la estructura clientes
@param : limite de la estructura clientes
@param : array de la estructura ventas
@param : limite de la estructura ventas
@value : 0 is successful
*/
int listados_ventasPorIdCliente(cliente* arrayClientes,int limiteCliente, ventas* arrayVentas, int limiteVentas)
{
int i,j;
for (i=0;i<limiteCliente;i++)
{
    if (arrayClientes[i].isEmpty==0)
    {
        printf("Cliente Id : %d , Apellido y nombre : %s , %s\n",arrayClientes[i].id,arrayClientes[i].apellido,arrayClientes[i].nombre);

        for(j=0;j<limiteVentas;j++)
        {
            if (arrayVentas[j].idCliente==arrayClientes[i].id && arrayVentas[j].isEmpty==0)
            {
                printf("   Cantidad de Afiches %d - Nombre archivo : %s \n",arrayVentas[j].cantAfiches,arrayVentas[j].nombreArchivo);
                printf("   Zona : %s - Estado Venta = %s \n",arrayVentas[j].zona,arrayVentas[j].estado);
            }
        }
    }
}
return 0;
}

/*
@brief : listado  de clientes ordenados por cantidad de afiches totales que posee
@param : array de la estructura clientes
@param : limite de la estructura clientes
@param : array de la estructura ventas
@param : limite de la estructura ventas
@value : 0 is successful
*/
int listados_clientesPorCantidadAfiches(cliente* arrayClientes,int limiteCliente, ventas* arrayVentas, int limiteVentas)
{
///array auxiliar
clienteAfiche auxiliar[limiteCliente];
clienteAfiche aux;
cliente* pCliente;


int i,j,k=0;
int acumulador,flag=1;
for (i=0;i<limiteCliente;i++)
{
    acumulador=0;
    if (arrayClientes[i].isEmpty==0)
    {
       for(j=0;j<limiteVentas;j++)
        {
            if (arrayVentas[j].idCliente==arrayClientes[i].id && arrayVentas[j].isEmpty==0)
            {
               acumulador=acumulador+arrayVentas[j].cantAfiches;
            }
        }
    auxiliar[k].idCliente=arrayClientes[i].id;
    auxiliar[k].cantAfiches=acumulador;
    k++;
    }
}

///ordenamiento del array auxiliar
while(flag==1)
{
    flag=0;
    for (i=1;i<=k;i++)
    {
        if (auxiliar[i-1].cantAfiches<auxiliar[i].cantAfiches)
        {
            aux.cantAfiches=auxiliar[i].cantAfiches;
            aux.idCliente=auxiliar[i].idCliente;

            auxiliar[i].cantAfiches=auxiliar[i-1].cantAfiches;
            auxiliar[i].idCliente=auxiliar[i-1].idCliente;

            auxiliar[i-1].cantAfiches=aux.cantAfiches;
            auxiliar[i-1].idCliente=aux.idCliente;

            flag=1;
        }
    }
}

for(i=0;i<k;i++)
{
    pCliente=clientes_getElementById(arrayClientes,limiteCliente,auxiliar[i].idCliente);
    if( pCliente != NULL)
    {
        printf("Cliente : %s, %s - Id: %d \n",pCliente->apellido,pCliente->nombre,pCliente->id);
        printf("  Cantidad afiches : --> %d \n",auxiliar[i].cantAfiches);
    }
}

return 0;
}
