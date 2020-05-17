#include "ArraysEmployees.h"
#include "menu.h"

#define ELEMENTS 1000

int main()
{
    eEmployee employee[ELEMENTS];
    char seguir='s',name[20],lastName[20];
    int sector,id,flag=0,opcion,order;
    float salary;

    initEmployees(employee,ELEMENTS);

    //hardCode(employee);

    do
    {
        switch(showMenu())
        {
        case 1: //Altas de empleados
            system("cls");
            addEmployee(employee,ELEMENTS, id, name, lastName, salary, sector);
            flag=1;
            system("pause");
            break;
        case 2://Modificar empleados
            if (flag==1)
            {
                system("cls");
                modifyEmployee(employee, ELEMENTS, id);
            }
            else
            {
                printf("\n No ha ingresado ningun empleado\n\n");
                system("pause");
            }
            break;
        case 3://Baja de empleados
            if(flag==1)
            {
                removeEmployee(employee,ELEMENTS, employee[ELEMENTS].id);
            }
            else
            {
                printf("No ha ingresado ningun empleado.\n\n");
                system("pause");
            }
            break;
        case 4://Informe
            flag=1;
            if(flag==1)
            {
                printEmployees(employee, ELEMENTS);
                printf("\n 1. Listado de los empleados ordenados alfabeticamente por Apellido y Sector. \n 2. Total y promedio de los salarios, y cuantos empleados superan el salario promedio. \n Seleccione una opcion: ");
                fflush(stdin);
                scanf("%d",&opcion);
                if(opcion==1)
                {
                    sortEmployees(employee, ELEMENTS, order);
                }
                else if(opcion==2)
                {
                    reportSalary(employee, ELEMENTS);
                }
            }
            else
            {
                printf("\n No ha ingresado ningun empleado.\n\n");
                system("pause");
            }
            break;
        case 5:
            printf("\n\n Gracias por utilizar el ABM...");
            seguir = 'n';
            break;
        default:
            printf("Opcion incorrecta!");
            break;
        }
    }
    while(seguir=='s');

    return 0;
}
