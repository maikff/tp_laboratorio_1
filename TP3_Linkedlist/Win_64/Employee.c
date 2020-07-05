#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "Controller.h"
#include "Employee.h"
#include "menus.h"

Employee* employee_new()
{
    return (Employee*) malloc(sizeof(Employee));
}

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr)
{
    Employee* this = NULL;
    this=employee_new();

    if(this != NULL && idStr != NULL && nombreStr != NULL && horasTrabajadasStr != NULL)
    {
        if(employee_setId(this,atoi(idStr))==-1||employee_setNombre(this, nombreStr)==-1||employee_setHorasTrabajadas(this,atoi(horasTrabajadasStr))==-1||employee_setSueldo(this,atoi(sueldoStr))==-1)
        {
            employee_delete(this);
            this=NULL;
        }
    }
    return this;
}

int employee_delete(Employee* this)
{
    int r = -1;
    if(this != NULL)
    {
        free(this);
        this = NULL;
        r = 0;
    }
    return r;
}

int employee_setId(Employee* this,int id)
{
    int r=-1;

    if(this!=NULL&&id>=0)
    {
        this->id=id;
        r=0;
    }
    return r;
}

int employee_getId(Employee* this,int* id)
{
    int r=-1;

    if(this != NULL && id != NULL)
    {
        *id=this->id;
        r=0;
    }
    return r;
}

int employee_setNombre(Employee* this,char* nombre)
{
    int r=-1;

    if(this!=NULL&&nombre!=NULL)
    {
        if(isValidName(nombre,30))
        {
            strncpy(this->nombre,nombre,30);
            r=0;
        }
    }
    return r;
}
int employee_getNombre(Employee* this,char* nombre)
{
    int r=-1;

    if(this!=NULL&&nombre!=NULL)
    {
        strncpy(nombre,this->nombre,30);
        r=0;
    }
    return r;
}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
    int r=-1;

    if(this!=NULL&&horasTrabajadas>=0)
    {
        this->horasTrabajadas=horasTrabajadas;
        r=0;
    }
    return r;
}

int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
    int r=-1;

    if(this!=NULL&&horasTrabajadas!=NULL)
    {
        *horasTrabajadas=this->horasTrabajadas;
        r=0;
    }
    return r;
}

int employee_setSueldo(Employee* this,int sueldo)
{
    int r=-1;

    if(this!=NULL&&sueldo>=0)
    {
        this->sueldo=sueldo;
        r=0;
    }
    return r;
}
int employee_getSueldo(Employee* this,int* sueldo)
{
    int r=-1;

    if(this!=NULL&&sueldo!=NULL)
    {
        *sueldo=this->sueldo;
        r=0;
    }
    return r;
}

int employee_SearchForId(LinkedList* pArrayListEmployee, int id)
{
    int r=-1,idAux;
    Employee* pEmployee;

    for(int indx = 0; indx < ll_len(pArrayListEmployee); indx++)
    {
        pEmployee = ll_get(pArrayListEmployee, indx);

        if(employee_getId(pEmployee, &idAux) == 0 &&
                idAux == id)
        {
            r=indx;
        }
    }
    return r;
}

int employee_printEmployee(LinkedList* pArrayListEmployee, int indx)
{
    int r=-1,auxId,auxHora,auxSalario;
    char auxNombre[30];
    Employee* pEmployee;

    if(pArrayListEmployee!=NULL&&indx>=0)
    {
        pEmployee = ll_get(pArrayListEmployee, indx);
        if(employee_getId(pEmployee,&auxId)==0&&employee_getNombre(pEmployee,auxNombre)==0&&employee_getHorasTrabajadas(pEmployee,&auxHora)==0&&employee_getSueldo(pEmployee,&auxSalario)==0)
        {
            printf("  º%5d    %10s    %10d    %10d\tº\n", auxId, auxNombre, auxHora, auxSalario);
        }
        else
        {
            printf("  ºError\n");
        }

    }
    return r;

}

int changeName(LinkedList* pArrayListEmployee,int indx)
{
    int r=-1;
    char nuevoNombre[30];
    Employee* pEmployee;

    pEmployee = ll_get(pArrayListEmployee, indx);

    if(utn_getCadena(nuevoNombre, 30, 2, "  ºIngrese nuevo nombre: ","  ºError, nombre invalido.\n") == 0)
    {
        normalizeStr(nuevoNombre);
        employee_setNombre(pEmployee, nuevoNombre);
        r = 0;
    }

    return r;
}

int changeHours(LinkedList* pArrayListEmployee, int indx)
{
    int r = -1,nuevaHora;
    Employee* pEmployee;

    pEmployee = ll_get(pArrayListEmployee, indx);

    if(utn_getEntero(&nuevaHora, 2, "  ºIngrese actualizacion de horas trabajadas: ", "  ºError, invalido.\n", 0, 100000) == 0)
    {
        employee_setHorasTrabajadas(pEmployee, nuevaHora);
        r = 0;
    }

    return r;
}

int changeSalary(LinkedList* pArrayListEmployee, int indx)
{
    int r = -1,nuevoSalario;
    Employee* pEmployee;

    pEmployee = ll_get(pArrayListEmployee, indx);

    if(utn_getEntero(&nuevoSalario, 2, "  ºIngrese nuevo sueldo de 18000 aa 300000: ", "  ºError, suedo invalido.\n", 18000, 300000) == 0)//hasta 300000
    {
        employee_setHorasTrabajadas(pEmployee, nuevoSalario);
        r = 0;
    }

    return r;
}

int employee_lastId(LinkedList* pArrayListEmployee)
{
    int len=ll_len(pArrayListEmployee),auxId,lastId=0,flag=0;
    Employee* pEmployee;

    if(pArrayListEmployee != NULL)
    {
        for(int i=0;i<len;i++)
        {
            pEmployee=(Employee*) ll_get(pArrayListEmployee,i);
            employee_getId(pEmployee, &auxId);

            if(auxId>lastId||flag==0)
            {
                lastId=auxId;
                flag=1;
            }
        }
    }
    return lastId;
}


int employee_sort(LinkedList* pArrayListEmployee)
{
    int r = -1,tipoOrden;

    if(pArrayListEmployee!=NULL)
    {
        switch(menuSort())
        {
        case 1:
            utn_getEntero(&tipoOrden, 2, "  º1 ascendente o 0 descendente: ", "  ºError\n", 0, 1);
            printf("  ºEspere unos segundos, por favor.\n");
            ll_sort(pArrayListEmployee, employee_sortById, tipoOrden);
            controller_ListEmployee(pArrayListEmployee);
            r = 0;
            break;
        case 2:
            utn_getEntero(&tipoOrden, 2, "  º1 ascendente o 0 descendente: ", "  ºError\n", 0, 1);
            printf("  ºEspere unos segundos, por favor.\n");
            ll_sort(pArrayListEmployee, employee_sortByName, tipoOrden);
            controller_ListEmployee(pArrayListEmployee);
            r = 0;
            break;
        case 3:
            utn_getEntero(&tipoOrden, 2, "  º1 ascendente o 0 descendente: ", "  ºError\n", 0, 1);
            printf("  ºEspere unos segundos, por favor.\n");
            ll_sort(pArrayListEmployee, employee_sortByHours, tipoOrden);
            controller_ListEmployee(pArrayListEmployee);
            r = 0;
            break;
        case 4:
            utn_getEntero(&tipoOrden, 2, "  º1 ascendente o 0 descendente: ", "  ºError\n", 0, 1);
            printf("  ºEspere unos segundos, por favor.\n");
            ll_sort(pArrayListEmployee, employee_sortBySalary, tipoOrden);
            controller_ListEmployee(pArrayListEmployee);
            r = 0;
            break;
        case 5:
            break;
        default:
            printf("  ºNo es una opcion valida\n");
            break;
        }
    }
    return r;
}

int employee_sortById(void* firstEmployee, void* secondEmployee)
{
    int r=0,primId,segId;

    employee_getId(firstEmployee,&primId);
    employee_getId(secondEmployee,&segId);

    if(primId>segId)
    {
        r=1;
    }
    else if(primId<segId)
    {
        r=-1;
    }

    return r;
}

int employee_sortByName(void* firstEmployee, void* secondEmployee)
{
    int r=0;
    char primNombre[30],segNombre[30];

    employee_getNombre(firstEmployee, primNombre);
    employee_getNombre(secondEmployee, segNombre);

    if(strcmp(primNombre, segNombre) > 0)
    {
        r = 1;
    }
    else if(strcmp(primNombre, segNombre) < 0)
    {
        r = -1;
    }

    return r;
}

int employee_sortByHours(void* firstEmployee, void* secondEmployee)
{
    int r = 0,primHora,segHoras;

    employee_getHorasTrabajadas(firstEmployee, &primHora);
    employee_getHorasTrabajadas(secondEmployee, &segHoras);

    if(primHora > segHoras)
    {
        r = 1;
    }
    else if(primHora<segHoras)
    {
        r = -1;
    }

    return r;
}

int employee_sortBySalary(void* firstEmployee, void* secondEmployee)
{
    int r = 0,primHoras,segHoras;

    employee_getSueldo(firstEmployee, &primHoras);
    employee_getSueldo(secondEmployee, &segHoras);

    if(primHoras > segHoras)
    {
        r = 1;
    }
    else if(primHoras < segHoras)
    {
        r = -1;
    }
    return r;
}
