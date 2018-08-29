#include <stdio.h>
#include <stdlib.h>



int main()
{

    return 0;
}

int pedirEdad(int edad)
{
    int validador;
    printf("Ingresar edad : \");
    validador=scanf("%d",&edad);

}


int validarEdad(int maximo,int minimo, int edad)
{



    if (edad < minimo || edad > maximo)
    {
        return -1;
    }
    else
    {
        return edad;
    }

}
