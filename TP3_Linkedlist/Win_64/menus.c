#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#include "menus.h"

int menu()
{
    system("mode con: cols=91 lines=25");
	int option;

	system("cls");
	frame(0);
    printf("  บ\t\t\t\tฑฒÛ M E N U Ûฒฑ \t\t\t\t\tบ\n");
    frame(1);
    printf("  บ\t1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).    บ\n");
    printf("  บ\t2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).  บ\n");
    printf("  บ\t3. Alta de empleado\t\t\t\t\t\t\t        บ\n");
    printf("  บ\t4. Modificar datos de empleado\t\t\t\t\t\t        บ\n");
    printf("  บ\t5. Baja de empleado\t\t\t\t\t\t\t        บ\n");
    printf("  บ\t6. Listar empleados\t\t\t\t\t\t\t        บ\n");
    printf("  บ\t7. Ordenar empleados\t\t\t\t\t\t\t        บ\n");
    printf("  บ\t8. Guardar los datos de los empleados en el archivo data.csv (modo texto).      บ\n");
    printf("  บ\t9. Guardar los datos de los empleados en el archivo data.csv (modo binario).    บ\n");
    printf("  บ\t10. Salir\t\t\t\t\t\t\t\t        บ\n");
    frame(1);

	utn_getEntero(&option, 3, "  บIngrese La opcion deseada: ", "  บERROR. Reingrese la opcion.\n", 1, 10);
	return option;
}

int menuEdit()
{
    system("mode con: cols=56 lines=25");
	int option;

	system("cls");
    frame(5);
	printf("  บ\t     ฑฒÛ M O D I F I C A R Ûฒฑ\t\tบ\n");
	frame(6);
	printf("  บ\t1. Nombre\t\t\t\tบ\n");
	printf("  บ\t2. Horas trabajadas\t\t\tบ\n");
	printf("  บ\t3. Sueldo\t\t\t\tบ\n");
	printf("  บ\t4. Salir\t\t\t\tบ");
	frame(7);

	utn_getEntero(&option, 3, "  บIngrese La opcion deseada: ", "  บERROR. Reingrese la opcion.\n", 1, 4);

	return option;
}

int menuSort()
{
    system("mode con: cols=56 lines=25");
	int option;

	system("cls");
    frame(5);
	printf("  บ\t      ฑฒÛ O R D E N A R Ûฒฑ\t\tบ\n");
	frame(6);
	printf("  บ\t1. Por ID\t\t\t\tบ\n");
	printf("  บ\t2. Por Nombre\t\t\t\tบ\n");
	printf("  บ\t3. Por Horas trabajadas\t\t\tบ\n");
	printf("  บ\t4. Por Sueldo\t\t\t\tบ\n");
	printf("  บ\t5. Salir\t\t\t\tบ");
	frame(7);

	utn_getEntero(&option, 3, "  บIngrese La opcion deseada: ", "  บERROR. Reingrese la opcion.\n", 1, 5);

	return option;
}

void frame(int type)
{
    switch(type)
    {
    case 0:
        printf("  ษอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออป\n");
        break;
    case 1:
        printf("  ฬอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออน\n");
        break;
    case 2:
        printf("\n  ฬอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ\n");
        break;
    case 3:
        printf("\n  ศอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ\n");
        break;
    case 4:
        printf("  บ                                                                                   บ\n");
        break;
    case 5:
        printf("  ษอออออออออออออออออออออออออออออออออออออออออออออป\n");
        break;
    case 6:
        printf("  ฬอออออออออออออออออออออออออออออออออออออออออออออน\n");
        break;
    case 7:
        printf("\n  ฬอออออออออออออออออออออออออออออออออออออออออออออผ\n");
        break;
    case 8:
        printf("\n  ศอออออออออออออออออออออออออออออออออออออออออออผ\n");
        break;
    case 9:
        printf("  บ                                           บ\n");
        break;
    }
}
