#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "usuario.h"
#include "clientes.h"
#include "ventas.h"
#define CANTCLIENTES 100
#define CANTVENTAS 1000

int main()
{

cliente eClientes[CANTCLIENTES];
ventas eVentas[CANTVENTAS];

clientes_init(eClientes,CANTCLIENTES);
ventas_init(eVentas,CANTVENTAS);

/*
int clientes_filler(eClientes, CANTCLIENTES,"leonard", "perez", "2223331" );
int clientes_filler(eClientes, CANTCLIENTES,"leonard", "perez", "2223331" );
int clientes_filler(eClientes, CANTCLIENTES,"leonard", "perez", "2223331" );
*/

clientes_menu("\n1. Alta de cliente\n2. Modificacion cliente\n3. Baja de cliente\n99. Ir a Menu Ventas\n",eClientes, CANTCLIENTES);
ventas_menu("\n1. Alta de Ventas \n99. Para Salir\n",eVentas, CANTVENTAS);

///ventas_alta(eVentas,CANTVENTAS);

return 0;
}
