#include "ventas.h"

typedef struct
{
    char nombre[50];
    char apellido [50];
    char cuit[13];
    int id;
    int isEmpty;

}cliente;

int clientes_alta(cliente* nuevoCliente,int limitearray);
int clientes_menu(char* opcionesMenu,cliente* array, int limite);
int clientes_init(cliente* cliente,int limitearray);
int clientes_modificar(cliente* array,int limite);
int clientes_baja(cliente* array,int limite);
int clientes_buscarLugarVacio(cliente* array, int limitearray);
int clientes_existeId(cliente* array, int limite, int idBuscar);
