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
    printf("  �\t\t\t\t��� M E N U ۲� \t\t\t\t\t�\n");
    frame(1);
    printf("  �\t1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).    �\n");
    printf("  �\t2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).  �\n");
    printf("  �\t3. Alta de empleado\t\t\t\t\t\t\t        �\n");
    printf("  �\t4. Modificar datos de empleado\t\t\t\t\t\t        �\n");
    printf("  �\t5. Baja de empleado\t\t\t\t\t\t\t        �\n");
    printf("  �\t6. Listar empleados\t\t\t\t\t\t\t        �\n");
    printf("  �\t7. Ordenar empleados\t\t\t\t\t\t\t        �\n");
    printf("  �\t8. Guardar los datos de los empleados en el archivo data.csv (modo texto).      �\n");
    printf("  �\t9. Guardar los datos de los empleados en el archivo data.csv (modo binario).    �\n");
    printf("  �\t10. Salir\t\t\t\t\t\t\t\t        �\n");
    frame(1);

	utn_getEntero(&option, 3, "  �Ingrese La opcion deseada: ", "  �ERROR. Reingrese la opcion.\n", 1, 10);
	return option;
}

int menuEdit()
{
    system("mode con: cols=56 lines=25");
	int option;

	system("cls");
    frame(5);
	printf("  �\t     ��� M O D I F I C A R ۲�\t\t�\n");
	frame(6);
	printf("  �\t1. Nombre\t\t\t\t�\n");
	printf("  �\t2. Horas trabajadas\t\t\t�\n");
	printf("  �\t3. Sueldo\t\t\t\t�\n");
	printf("  �\t4. Salir\t\t\t\t�");
	frame(7);

	utn_getEntero(&option, 3, "  �Ingrese La opcion deseada: ", "  �ERROR. Reingrese la opcion.\n", 1, 4);

	return option;
}

int menuSort()
{
    system("mode con: cols=56 lines=25");
	int option;

	system("cls");
    frame(5);
	printf("  �\t      ��� O R D E N A R ۲�\t\t�\n");
	frame(6);
	printf("  �\t1. Por ID\t\t\t\t�\n");
	printf("  �\t2. Por Nombre\t\t\t\t�\n");
	printf("  �\t3. Por Horas trabajadas\t\t\t�\n");
	printf("  �\t4. Por Sueldo\t\t\t\t�\n");
	printf("  �\t5. Salir\t\t\t\t�");
	frame(7);

	utn_getEntero(&option, 3, "  �Ingrese La opcion deseada: ", "  �ERROR. Reingrese la opcion.\n", 1, 5);

	return option;
}

void frame(int type)
{
    switch(type)
    {
    case 0:
        printf("  �������������������������������������������������������������������������������������ͻ\n");
        break;
    case 1:
        printf("  �������������������������������������������������������������������������������������͹\n");
        break;
    case 2:
        printf("\n  �����������������������������������������������������������������������������������ͼ\n");
        break;
    case 3:
        printf("\n  �����������������������������������������������������������������������������������ͼ\n");
        break;
    case 4:
        printf("  �                                                                                   �\n");
        break;
    case 5:
        printf("  ���������������������������������������������ͻ\n");
        break;
    case 6:
        printf("  ���������������������������������������������͹\n");
        break;
    case 7:
        printf("\n  ���������������������������������������������ͼ\n");
        break;
    case 8:
        printf("\n  �������������������������������������������ͼ\n");
        break;
    case 9:
        printf("  �                                           �\n");
        break;
    }
}
