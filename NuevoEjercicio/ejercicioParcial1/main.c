#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "usuario.h"

#define CANTIDADUSUARIOS 20

int main()
{
usuario eUsuarios[CANTIDADUSUARIOS];
usuario_init(eUsuarios,CANTIDADUSUARIOS);
usuario_filler(eUsuarios, CANTIDADUSUARIOS, "LUIS PEREZ", "AV CORRIENTES 200", "42236658" );
usuario_filler(eUsuarios, CANTIDADUSUARIOS, "MARIA PEREZ", "AV CORRIENTES 100", "42299658" );
usuario_filler(eUsuarios, CANTIDADUSUARIOS, "LUIS GOMEZ", "AV CORRIENTES 200", "42236658" );
usuario_filler(eUsuarios, CANTIDADUSUARIOS, "LUISA PEREZ", "AV INDEPENDENCIA 200", "99936658" );
usuario_menu("\n1. Listar Usuarios\n99. Salir\n",eUsuarios, CANTIDADUSUARIOS);



return 0;
}
