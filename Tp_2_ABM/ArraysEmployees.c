#include "ArraysEmployees.h"

static int generarNextId()
{
    static int id = 0;
    id ++;
    return id;
}

int initEmployees(eEmployee* list, int len)
{
    int retorno = -1;
    int i;
    if(len > 0 && list != NULL)
    {
        retorno = 0;
        for(i=0; i<len; i++)
        {
            list[i].isEmpty=1;
            retorno=0;
        }
    }
    return retorno;
}

int freeSpace(eEmployee* list, int len)
{
    int i;
    int retorno= -1;

    if(len>0 && list!=NULL)
    {
        for(i=0; i<len; i++)
        {
            if(list[i].isEmpty == 1)
            {
                retorno=i;
                break;
            }
        }
    }

    return retorno;
}

int addEmployee(eEmployee* list, int len, int id,char name[],char lastName[],float salary,int sector)
{
    int i, retorno=-1;


    if(len>0 && list!= NULL)
    {
        i = freeSpace(list,len);

        if(i >= 0)
        {
            printf("---Alta de empleado---\n\n");

            if(!getValidString("Ingrese el nombre: ", "Ingrese solo letras. ","Rango: [3-30]", name, 3,30, 3))
            {
                if(!getValidString("Ingrese el apellido: ", "Ingrese solo letras. ", "Rango: [4-30]", lastName, 4,30, 3))
                {
                    if(!getValidFloat(&salary, "Ingrese el salario: ", "Ingrese solo numeros. Rango: [1-9999999]. ", 1, 999999, 3))
                    {
                        if(!getValidInt(&sector,"Ingrese el sector: ", "Ingrese solo numeros. Rango: [1-5]. ", 1, 5, 3))
                        {
                            printf("Se dio de alta: %s %s\n\n", name, lastName);

                            strcpy(list[i].name, name);
                            strcpy(list[i].lastName, lastName);
                            list[i].salary=salary;
                            list[i].sector=sector;
                            list[i].id=generarNextId();
                            list[i].isEmpty = 0;
                            retorno=0;
                        }
                    }
                }
            }
        }
        else
        {
            printf("No hay lugar");
        }

    }

    return retorno;
}

int findEmployeeById(eEmployee* list, int len,int id)
{
    for(int i=0; i<len; i++)
    {
        if(list[i].id == id)
        {
            return i;
        }
    }

    return -1;
}

int printEmployees(eEmployee* list, int length)
{
    printf(" ID\t    NOMBRE\t    APELLIDO\t    SALARIO\t    SECTOR\n");
    for(int i=0; i<length; i++)
    {
        if(!list[i].isEmpty)
        {
            printf(" %d\t    %s\t    %s\t    %f\t    %d \n",list[i].id,list[i].name,list[i].lastName,list[i].salary,list[i].sector);
        }
    }
    return 0;
}

int modifyEmployee(eEmployee* list, int len, int id)
{
    int found;
    char respuesta;
    int opcion=0;

    printf("\n Ingrese el Id que desea modificar:");
    scanf("%d", &id);

    found=findEmployeeById(list, len, id);

    if(found>=0)
    {
        printf("\n Datos del ID ingredado \n ID: %d \n Nombre: %s \n Apellido: %s \n Salario: %f \n Sector: %d\n",list[found].id,list[found].name,list[found].lastName,list[found].salary,list[found].sector);
        printf("\n Desea modificar los datos? s/n: ");
        fflush(stdin);
        scanf("%c",&respuesta);

        if(respuesta=='s')
        {
            do
            {
                system("cls");
                printf("\n >>>MENU DE MODIFICACIONES<<<\n\n");
                printf(" 1. Modificar nombre\n");
                printf(" 2. Modificar apellido\n");
                printf(" 3. Modificar salario\n");
                printf(" 4. Modificar sector\n");
                printf(" 5. Salir\n");
                printf(" Selecione una opcion: ");
                scanf("%d",&opcion);

                switch(opcion)
                {
                case 1:
                    getValidString("\n Ingrese nuevo nombre: ", " Ingrese solo letras. ", " Rango: [3-15]", list[found].name, 3,15, 3);
                    system("pause");
                    break;

                case 2:
                    getValidString("\n Ingrese nuevo apellido: ", " Ingrese solo letras. ", " Rango: [3-15]", list[found].lastName, 3,15, 3);
                    break;

                case 3:
                    getValidFloat(&list[found].salary, "\n Ingrese nuevo salario: ", " Ingrese solo numeros", 1, 9999999, 3);
                    break;

                case 4:
                    getValidInt(&list[found].sector, "\n Ingrese nuevo sector: ", " Ingrese solo numeros. ", 1, 5, 3);
                    break;
                case 5:
                    printf("\n Cambios Realizados: \n Nombre: %s \n Apellido: %s \n Salario: %f \n Sector: %d \n\n", list[found].name, list[found].lastName, list[found].salary, list[found].sector);
                    break;

                default:
                    printf("\n Opcion incorrecta.\n\n");
                    system("pause");
                    break;
                }
            }
            while(opcion!=5);
        }
        system("pause");

    }

    else
    {
        printf("\n ERROR. Ese ID no existe\n\n");
        fflush(stdin);
        system("pause");
    }

    return -1;
}

int removeEmployee(eEmployee* list, int len, int id)
{
    int found;

    printf("\n Ingrese el id que desea eliminar: ");
    scanf("%d",&id);

    found=findEmployeeById(list, len, id);

    for(int i=0; i<len; i++)
    {
        if(found >= 0)
        {
            printf("\n El usuario fue eliminado.\n");
            list[found].isEmpty = 1;
            system("pause");
            break;
        }

        else
        {
            printf("\n No existe ese id.\n");
            system("pause");
            break;
        }
    }

    return -1;
}

int sortEmployees(eEmployee* list, int len, int order)
{
    eEmployee employee;

    printf("\n 0. Ordenar de manera descendente. \n 1. Ordenar de manera ascendente.\n Seleccione una opcion: ");
    fflush(stdin);
    scanf("%d",&order);

    if(order==1)
    {
        for(int i=0; i<len-1; i++) ///ASCENDENTE
        {
            for(int j=i+1; j<len; j++)
            {
                if(strcmp(list[j].lastName,list[i].lastName)<0)
                {
                    employee = list[i];
                    list[i] = list[j];
                    list[j] = employee;
                }

                else if(strcmp(list[j].lastName, list[i].lastName) == 0 && list[i].sector>list[j].sector)
                {
                    employee = list[i];
                    list[i] = list[j];
                    list[j] = employee;

                }

            }
        }
    }

    if(order==0)
    {
        for(int i=0; i<len-1; i++) ///DESCENDENTE
        {
            for(int j=i+1; j<len; j++)
            {
                if(strcmp(list[j].lastName,list[i].lastName)>0)
                {
                    employee = list[i];
                    list[i] = list[j];
                    list[j] = employee;
                }

                else if(strcmp(list[j].lastName, list[i].lastName) == 0 && list[i].sector<list[j].sector)
                {
                    employee = list[i];
                    list[i] = list[j];
                    list[j] = employee;
                }
            }
        }
    }

    printEmployees(list,len);
    system("pause");

    return 0;
}

int reportSalary(eEmployee* list, int len)
{
    float totalSalarios=0, promedio;
    int contadorSalario=0, contadorEmpleados=0;

    for(int i=0; i<len; i++)
    {
        if(list[i].isEmpty==0)
        {
            totalSalarios=totalSalarios+list[i].salary;
            contadorSalario++;
            promedio=totalSalarios/contadorSalario;
        }
    }

    for(int i=0; i<len; i++)
    {
        if((list[i].isEmpty==0) && (list[i].salary > promedio))
        {
            contadorEmpleados++;
        }
    }
    printf("*** Informe de salarios ***\n");
    printf("\nEl total de los salarios es: %.2f\n",totalSalarios);
    printf("\nEl promedio de los salarios es: %.2f\n",promedio);
    printf("\nLos empleados que pasan el promedio son: %d\n\n",contadorEmpleados);
    system("pause");

    return 0;

}

void hardCode(eEmployee* x)
{


    eEmployee y[] =
    {
        {1, "Juan", "Perez", 16593, 4,0},
        {2, "Alberto", "Sanchez", 20000, 3,0},
        {3, "Lucia", "Torres", 26390, 5,0},
        {4, "Martina", "Alvarez", 50000, 2,0},
        {5, "Sofia", "Fernandez", 100000, 1,0},
        {6, "Miguel", "Gonzales", 986532, 2,0},
        {7, "Daniela", "Juarez", 75482, 1,0}
    };

    for(int i=0; i<10; i++)
    {
        x[i] = y[i];
    }
}
