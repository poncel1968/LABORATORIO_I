#ifndef VENTAS
#define VENTAS

typedef struct
{
    int idCliente;
    int cantAfiches;
    char nombreArchivo[100];
    char zona[100];
    int idVenta;
    int isEmpty;
    char estado[50];
}ventas;

int ventas_alta(ventas* array,int limite);
int ventas_menu(char* opcionesMenu,ventas* array, int limite);
int ventas_init(ventas* array,int limite);

#endif
