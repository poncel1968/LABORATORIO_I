#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "clientes.h"
#include "ventas.h"


static int getNextId();

/*
@brief : otroga un numero usado para id secuencial creciente
@value : numero id
*/
static int getNextId()
{
    static int newId;
    return newId++;

}

/*
@brief : alta de cliente
@param : array con estructura de clientes
@param : tamaño array anterior:
@value : id is successful ;-1 error
*/

int clientes_alta(cliente* nuevoCliente,int limitearray)
{
    char nombre[50];
    char apellido[50];
    char cuit[13];
    int i;
    int flag=0;
    int retorno=-1;

    for(i=0;i<limitearray;i++)
    {
        if(nuevoCliente[i].isEmpty==1)
        {
            flag=1;
            break;
        }
    }

    if (flag==1 && utn_getNombre(nombre,50,"Ingrese nombre cliente : ")== 0 &&
    utn_getNombre(apellido,50,"Ingrese Apellido cliente : ")== 0 &&
    utn_getString(cuit,13,"Ingrese CUIT Cliente : ","Error CUIT")==0)
    {

        strncpy(nuevoCliente[i].nombre,nombre,(strlen(nombre)));
        strncpy(nuevoCliente[i].apellido,apellido,(strlen(apellido)));
        strncpy(nuevoCliente[i].cuit,cuit,(strlen(cuit)));
        nuevoCliente[i].id=getNextId();
        nuevoCliente[i].isEmpty=0;
        nuevoCliente[i].id=getNextId();
        retorno=0;
    }
    else
    {
        printf("Error Alta Cliente");
    }

return retorno;

}

/*
@brief : despliega un menu de clientes
@param : array con texto a mostrar
@param : array de estructura
@param : limite de la estructura
@value : 0 is successful
*/

int clientes_menu(char* opcionesMenu,cliente* array, int limite)
{
    int salir = 99;
    int opcion=0;
    int aux;
    do
    {
    printf("OPCIONES DEL MENU PRINCIPAL");
    printf(opcionesMenu);
    utn_getInt(&opcion,5);
    switch (opcion)
    {
        case 1:
        aux=clientes_alta(array,limite);
        printf("\nEl Id generado es %d \n",aux);
        break;

        case 2:
        clientes_modificar(array,limite);
        break;

        case 3:
        clientes_baja(array,limite);
        break;

        case 99:
        system("clear");
        printf("Exit");

        default:
        printf("\nOpcion Incorrecta!!\n");
        system("clear");
    }
    }while (opcion !=salir );

    return 0;
}

/*
@brief : inicializa valores isEmpty del array
@param : array de la estructura
@param : limite de la estructura
@value : 0 is successful
*/
int clientes_init(cliente* cliente,int limitearray)
{
    int i;
    for(i=0;i<limitearray;i++)
    {
    cliente[i].isEmpty = 1;
    }
return 0;

}

/*
@brief : modificacion elemento del array
@param : array de la estructura
@param : limite de la estructura
@value : 0 is successful
*/

int clientes_modificar(cliente* array,int limite)
{
    char nombre[50];
    char apellido[50];
    char cuit[13];
    int i;
    int flag=0;
    int retorno=-1;
    int idBuscado;

    printf("\nIngrese Id a Modificar :");
    utn_getInt(&idBuscado,5);

    for (i=0;i<limite;i++)
    {
        if (array[i].id==idBuscado && array[i].isEmpty==0)
        {
            flag=1;
            break;
        }
    }



    if (flag==1 && utn_getNombre(nombre,50,"Ingrese nombre cliente : ")== 0 &&
    utn_getNombre(apellido,50,"Ingrese Apellido cliente : ")== 0 &&
    utn_getString(cuit,13,"Ingrese CUIT Cliente : ","Error CUIT")==0)
    {

        strncpy(array[i].nombre,nombre,(strlen(nombre)));
        strncpy(array[i].apellido,apellido,(strlen(apellido)));
        strncpy(array[i].cuit,cuit,(strlen(cuit)));
        retorno=0;

    }
    else
    {
        printf("\Error Modificacion Cliente\n");
    }

return retorno;

 }

int clientes_baja(cliente* array,int limite)
{
    int i;
    int flag=0;
    int retorno=-1;
    int idBuscado;
    char confirmacion;

    printf("\nIngrese Id a Dar de Baja :");
    utn_getInt(&idBuscado,5);

    for (i=0;i<limite;i++)
    {
        if (array[i].id==idBuscado && array[i].isEmpty==0)
        {
                flag=1;
                break;
        }
    }


    if (flag==1 )
    {
        array[idBuscado].isEmpty=1;
        retorno=0;

    }
    else
    {
        printf("\Error Baja de Cliente\n");
    }

return retorno;

 }
/*
 int clientes_filler(cliente* array, int limite, char* nombre, char* apellido, char* cuit )
{

    int retorno=-1;
    int i = clientes_buscarLugarVacio(array,limite);

    if ( i >= 0)
    {
        strncpy(array[i].nombre,nombre,strlen(nombre));
        strncpy(array[i].apellido,apellido,strlen(apellido));
        strncpy(array[i].cuit,cuit,strlen(cuit));
        array[i].isEmpty=0;
        array[i].id=getNextId();
        retorno=0;

    }
    return retorno;
}

int clientes_buscarLugarVacio(cliente* array, int limitearray)
{
    int retorno =-1;
    int i;
    for(i=0;i<limitearray;i++)
    {
        if(array[i].isEmpty==1)
        {
            retorno=i;
            break;
        }
    }
    return retorno;
}

*/

