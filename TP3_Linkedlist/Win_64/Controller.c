#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "Controller.h"
#include "menus.h"
#include "utn.h"

int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
	int r = -1;
	FILE* pFile;
	pFile = fopen(path, "r");


	if(pFile != NULL)
	{
		if(parser_EmployeeFromText(pFile, pArrayListEmployee) == 0)
		{
			printf("  �Archivo de texto cargado exitosamente\n");
			r = 0;
		}
		else
		{
			printf("  �Error id\n");
		}
	}
	else
	{
		printf("  �Error null\n");
	}
	fclose(pFile);
    return r;
}


int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
	int r = -1;
	FILE* pFile;

	pFile = fopen(path, "rb");

	if(pFile != NULL)
	{
		if(!parser_EmployeeFromBinary(pFile, pArrayListEmployee))
		{
			r = 0;
			printf("  �Archivo de texto cargado exitosamente\n");
		}
		else
		{
			printf("  �Error\n");
		}
	}
	else
	{
		printf("  �Error\n");
	}
	fclose(pFile);
    return r;
}



int controller_addEmployee(LinkedList* pArrayListEmployee)
{
	int r = -1,auxHora,auxSalario,sigId;
	char auxNombre[30];

	Employee* pEmployee = employee_new();

	if(pArrayListEmployee != NULL && pEmployee != NULL)
	{
		if(!utn_getCadena(auxNombre, 30, 2, "  �Ingrese nombre: ", "  �Error, nombre invalido") &&
		   !utn_getEntero(&auxHora, 2, "  �Ingrese cantidad de horas trabajadas: ", "  �Error, cantidad invalida\n", 0, 100000) &&
		   !utn_getEntero(&auxSalario, 2, "  �Ingrese salario de 18000 a 40000: ", "  �Error, salario invalido\n", 18000, 400000))
		{
			normalizeStr(auxNombre);
				sigId = employee_lastId(pArrayListEmployee) + 1;

				if(!employee_setId(pEmployee, sigId) &&
				   !employee_setNombre(pEmployee, auxNombre) &&
				   !employee_setHorasTrabajadas(pEmployee, auxHora) &&
				   !employee_setSueldo(pEmployee, auxSalario))
				{
					ll_add(pArrayListEmployee, pEmployee);
					printf("  �Alta exitosa\n");
				}
				else
				{
					free(pEmployee);
				}
		}
		else
		{
			free(pEmployee);
		}
	}
    return r;
}


int controller_editEmployee(LinkedList* pArrayListEmployee)
{
	int auxId,ultId,r = -1,indx,confirma = 0;
	Employee* pEmployee;

	if(pArrayListEmployee != NULL)
	{
		controller_ListEmployee(pArrayListEmployee);
		for(int i = 0; i < ll_len(pArrayListEmployee); i++)
		{
			pEmployee = ll_get(pArrayListEmployee, i);

			employee_getId(pEmployee, &auxId);
			if(auxId >= ultId)
			{
				ultId = auxId;
			}
		}

		if(!utn_getEntero(&auxId, 2, "  �Ingrese ID de empleado a modificar.\n", "  �Error, ID invalido", 0, ultId))
		{
			indx = employee_SearchForId(pArrayListEmployee, auxId);
			if(indx > -1)
			{
				printf("\n  �ID       Nombre     Horas Trabajadas  Sueldo\n\n");
				employee_printEmployee(pArrayListEmployee, indx);

				do
				{
					switch(menuEdit())
					{
						case 1:
							if(changeName(pArrayListEmployee, indx) == 0)
							{
								printf("  �Nombre modificado exitosamente.\n");
								employee_printEmployee(pArrayListEmployee, indx);
							}
							else
							{
								printf("  �Error.\n");
							}
							break;
						case 2:
							if(changeHours(pArrayListEmployee, indx) == 0)
							{
								printf("  �Horas trabajadas actualizadas exitosamente.\n");
								employee_printEmployee(pArrayListEmployee, indx);
							}
							else
							{
								printf("  �Error.\n");
							}
							break;
						case 3:
							if(changeSalary(pArrayListEmployee, indx) == 0)
							{
								printf("  �Sueldo modificado exitosamente.\n");
								employee_printEmployee(pArrayListEmployee, indx);
							}
							else
							{
								printf("  �Error.\n");
							}
							break;
						case 4:
							confirma = 1;
							break;
					}
					system("pause");
				}while(confirma == 0);
			}
		}
	}
	return r;
}


int controller_removeEmployee( LinkedList* pArrayListEmployee)
{
	int r=-1,auxId,ultId,indx;
	char confirmBorrar;
	Employee* pEmployee;

	if(pArrayListEmployee != NULL)
	{
		controller_ListEmployee(pArrayListEmployee);

		ultId = employee_lastId(pArrayListEmployee);

		if(!utn_getEntero(&auxId, 2, "  �Ingrese ID de empleado a eliminar del sistema: ", "  �Error, ID invalido", 0, ultId))
		{
			indx = employee_SearchForId(pArrayListEmployee, auxId);
			if(indx > -1)
			{
				pEmployee = ll_get(pArrayListEmployee, indx);
				printf("\n  �ID    Nombre   Horas Trabajadas   Sueldo\n\n");
				employee_printEmployee(pArrayListEmployee, indx);

				printf("  �Confirma baja del empleado? s/n: ");
				scanf("%c", &confirmBorrar);
				if(confirmBorrar == 's')
				{
					ll_remove(pArrayListEmployee, indx);
					if(employee_delete(pEmployee) == 0)
					{
						printf("  �Baja realizada exitosamente\n");
						r = 0;
					}
				}
			}
		}
	}
    return r;
}


int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
	int r=-1;
	if(pArrayListEmployee != NULL)
	{
		printf("\n  �ID       Nombre     Horas Trabajadas  Sueldo\t�\n\n");
		for(int i = 0; i < ll_len(pArrayListEmployee); i++)
		{
			employee_printEmployee(pArrayListEmployee, i);
		}
	}
	else
	{
		printf("  �No hay empleados cargados en la lista.\t�\n");
	}

    return r;
}


int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
	int r=-1;

	if(pArrayListEmployee != NULL)
	{
		if(employee_sort(pArrayListEmployee) == 0)
		{
			printf("  �Empleados ordenados exitosamente.\t\t\t�\n");
		}
	}
	else
	{
		printf("  �Error\n");
	}
    return r;
}


int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
	int r=-1,auxId,auxHora,auxSalario;
	char auxNombre[30];
	FILE* pFile;
	Employee* pEmployee;

	if(pArrayListEmployee != NULL && path != NULL)
	{
		pFile = fopen(path, "w");
		if(pFile != NULL)
		{
			r = 0;
			for(int i = 1; i < ll_len(pArrayListEmployee); i++)
			{
				pEmployee = ll_get(pArrayListEmployee, i);
				if(!employee_getId(pEmployee, &auxId) &&!employee_getNombre(pEmployee, auxNombre)&&!employee_getHorasTrabajadas(pEmployee, &auxHora)&&!employee_getSueldo(pEmployee, &auxSalario))
				{
					fprintf(pFile, "%d,%s,%d,%d\n", auxId, auxNombre, auxHora, auxSalario);
				}
			}
			fclose(pFile);
			printf("  �Archivo guardado exitosamente\n");
		}
	}
    return r;
}


int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
	int r=-1;
	FILE* pFile;
	Employee* pEmployee;

	if(pArrayListEmployee != NULL && path != NULL)
	{
		pFile = fopen(path, "wb");

		for(int i = 1; i < ll_len(pArrayListEmployee); i++)
		{
			pEmployee = (Employee*) ll_get(pArrayListEmployee, i);
			fwrite(pEmployee, sizeof(Employee), 1, pFile);
		}
		printf("  �Archivo guardado exitosamente\n");
		fclose(pFile);
		r = 0;
	}
    return r;
}

