#include "menu.h"
#include <stdio.h>

int showMenu()
{
    int opcion;

    printf("***** Gestion de Empleados *****\n");
    printf("1. Altas\n");
    printf("2. Modificar\n");
    printf("3. Baja\n");
    printf("4. Informar\n");
    printf("5. Salir\n\n");
    printf("Ingrese opcion: ");
    fflush(stdin);
    scanf("%d", &opcion);

    return opcion;
}

