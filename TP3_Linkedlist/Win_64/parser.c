#include <stdio.h>
#include <stdlib.h>
#include "Employee.h"
#include "LinkedList.h"

int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int r=-1,sigID=0;;
	Employee *pEmployee;
	char id[200],nombre[200],horasTrabajadas[200],sueldo[200];

	if(pFile != NULL && pArrayListEmployee != NULL)
	{
		fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,horasTrabajadas,sueldo);
		do
		{
			if(fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,horasTrabajadas,sueldo)==4)
			{
				pEmployee = employee_newParametros(id, nombre, horasTrabajadas, sueldo);

				if(pEmployee != NULL)
				{
					ll_add(pArrayListEmployee, pEmployee);
					r = 0;
				}
			}
			else
			{
				break;
			}

		}while(feof(pFile) == 0);
		r = sigID;
	}

    return r;
}


int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int r = -1;
	Employee* pEmployee;

	if(pFile != NULL)
	{
		do
		{
			pEmployee = employee_new();
			if(fread(pEmployee, sizeof(Employee), 1, pFile) == 1)
			{
				ll_add(pArrayListEmployee, pEmployee);
				r = 0;
			}
		}while(!feof(pFile));
	}

    return r;
}
