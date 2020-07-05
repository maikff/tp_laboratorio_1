#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "menus.h"
#include "utn.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/



int main()
{
    system("title TP3: LinkedList");
    system("color A");
    int flagInicialTxt=0,flagInicialBin=0;
    char confirma='n',seguir='n';

    LinkedList* listaEmpleados=ll_newLinkedList();

    do
    {
        system("cls");
        switch(menu())
        {
        case 1:
            if(!flagInicialTxt&&!flagInicialBin)
            {
                if(controller_loadFromText("data.csv",listaEmpleados)==0)
                {
                    flagInicialTxt=1;
                }
            }
            else
            {
                printf("  ºEl archivo ya fue cargado.\n");
            }
            break;
        case 2:
            if(!flagInicialTxt&&!flagInicialBin)
            {
                if(!controller_loadFromBinary("data.bin", listaEmpleados))
                {
                    flagInicialBin = 1;
                }
            }
            else
            {
                printf("  ºEl archivo ya fue cargado.\n");
            }
            break;
        case 3:
            if(flagInicialTxt||flagInicialBin)
            {
                controller_addEmployee(listaEmpleados);
            }
            else
            {
                printf("  ºError. Aun no se cargo ningun archivo.\n");
            }
            break;
        case 4:
            if(flagInicialTxt||flagInicialBin)
            {
                controller_editEmployee(listaEmpleados);
            }
            else
            {
                printf("  ºError. Aun no se cargo ningun archivo.\n");
            }
            break;
        case 5:
            if(flagInicialTxt||flagInicialBin)
            {
                controller_removeEmployee(listaEmpleados);
            }
            else
            {
                printf("  ºError. Aun no se cargo ningun archivo.\n");
            }
            break;
        case 6:
            if(flagInicialTxt||flagInicialBin)
            {
                controller_ListEmployee(listaEmpleados);
            }
            else
            {
                printf("  ºError. Aun no se cargo ningun archivo.\n");
            }
            break;
        case 7:
            if(flagInicialTxt||flagInicialBin)
            {
                controller_sortEmployee(listaEmpleados);
            }
            else
            {
                printf("  ºError. Aun no se cargo ningun archivo.\n");
            }
            break;
            break;
        case 8:
            if(flagInicialTxt||flagInicialBin)
            {
                controller_saveAsText("data.csv", listaEmpleados);
            }
            else
            {
                printf("  ºError. Aun no se cargo ningun archivo.\n");
            }
            break;
        case 9:
            if(flagInicialTxt||flagInicialBin)
            {
                controller_saveAsBinary("data.bin", listaEmpleados);
            }
            else
            {
                printf("  ºError. Aun no se cargo ningun archivo.\n");
            }
            break;
        case 10:
            printf("  ºConfirma salir? s/n: ");
            fflush(stdin);
            scanf("%c",&confirma);
            if(confirma=='s')
            {
                seguir='s';
                ll_deleteLinkedList(listaEmpleados);
            }
            break;
        }
        system("pause");

    }
    while(seguir=='n');
    return 0;
}

