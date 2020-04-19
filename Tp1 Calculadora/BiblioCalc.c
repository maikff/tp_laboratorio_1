#include "BiblioCalc.h"

void getOption(void)
{
    char continuar='s';
    int option;
    int num1=0,num2=0;
    int suma,resta;
    long long int multiplicacion;
    float division;
    long double factorialNum1,factorialNum2;
    int initialFlag1=0,initialFlag2=0,finalFlag=0;
    do
    {
        system("color B");
        initialMenu(&num1,&num2,&initialFlag1,&initialFlag2);
        option=getValidOption("  บIngrese La opcion deseada: ","  บERROR Ingrese la opcion deseada: ",1,5);
        frame(1);

        switch(option)
        {
        case 1:
            system("color B");
            num1=getValidNumber("  บIngrese el primer numero: ");
            initialFlag1++;
            system("cls");
            break;
        case 2:
            system("color B");
            num2=getValidNumber("  บIngrese el segundo numero: ");
            initialFlag2++;
            system("cls");
            break;
        case 3:
            if(!initialFlag1||!initialFlag2)
            {
                system("color C");
                printf("  บPrimero ingrese todos los numeros...\t\tบ\n");
                Sleep(1500);
                system("cls");
            }
            else
            {
                suma=addFunction(num1,num2);
                resta=subtractFuntion(num1,num2);
                multiplicacion=multiplyFunction(num1,num2);
                printf("  บRealizando operaciones ");
                loading(90,22);
                frame(4);
                system("color A");
                printf("  บLas Operaciones Fueron Realizadas Con Exito! บ");
                frame(3);
                Sleep(1500);
                finalFlag++;
                system("cls");
            }
            break;
        case 4:
            if(!finalFlag)
            {
                system("color C");
                printf("  บPrimero calcula todas las operaciones...\tบ\n");
                Sleep(1500);
                system("cls");
            }
            else
            {
                printf("  บ\ta- El resultado de %3d +%3d es: %-8dบ\n",num1,num2,suma);
                printf("  บ\tb- El resultado de %3d -%3d es: %-8dบ\n",num1,num2,resta);
                if(!num2)
                {
                    printf("  บ\tc- No es posible dividir un numero por \tบ\n  บ\t   cero\t\t\t\t\tบ\n");
                }
                else
                {
                    division=divideFunction(num1,num2);
                    printf("  บ\tc- El resultado de %3d /%3d es: %-8.2fบ\n",num1,num2,division);
                }
                printf("  บ\td- El resultado de %3d *%3d es: %-8lldบ\n",num1,num2,multiplicacion);
                if(num1<0)
                {
                    printf("  บ\te- No es posible hacer el factorial de\tบ\n  บ\t   %-3d ya que es un numero negativo.\tบ\n",num1);
                }else if(num1>25)
                {
                    printf("  บ\te- No es posible hacer el factorial de\tบ\n  บ\t   %-3d ya que es un numero muy grande.\tบ\n",num1);
                }
                else
                {
                    factorialNum1=factorialFunction(num1);
                    printf("  บ\te- El factorial de %2d! es: %-13.Lfบ\n",num1,factorialNum1);
                }
                if(num2<0)
                {
                    printf("  บ\t   No es posible hacer el factorial de\tบ\n  บ\t   %-3d ya que es un numero negativo.\tบ",num2);
                }
                else if(num2>25)
                {
                    printf("  บ\t   No es posible hacer el factorial de\tบ\n  บ\t   %-3d ya que es un numero muy grande.\tบ",num2);
                }
                else
                {
                    factorialNum2=factorialFunction(num2);
                    printf("  บ\t   El factorial de %2d! es: %-13.Lfบ",num2,factorialNum2);
                }
                frame(3);
                printf("   ");
                system("pause");
                reset(&initialFlag1,&initialFlag2,&finalFlag);
                system("cls");
            }
            break;
        case 5:
            continuar='n';
            break;
        }
    }
    while(continuar!='n');
}

int getValidOption(char message[],char messageError[],int lInf,int lSup)
{
    int option;
    option=getValidNumber(message);
    while(option<lInf||option>lSup)
    {
        system("color C");
        option=getValidNumber(messageError);
    }
    return option;
}

int getValidNumber(char message[])
{
    char stringNumber[20];
    int numFin;
    printf("%s",message);
    fflush(stdin);
    scanf("%s",stringNumber);
    while(validNumber(stringNumber)!=0)
    {
        system("color C");
        printf("  บERROR ingrese solo numeros: ");
        fflush(stdin);
        scanf("%s",stringNumber);
    }
    numFin=atoi(stringNumber);
    return numFin;
}

int validNumber(char number[])
{
    int valid,i;

    for(i=0; i<strlen(number); i++)
    {
        if(number[i]>=48&&number[i]<=57)
        {
            valid=0;
        }
    }
    return valid;
}

int addFunction(int number1,int number2)
{
    int result;
    result=number1+number2;
    return result;
}

int subtractFuntion(int number1,int number2)
{
    int result;
    result=number1-number2;
    return result;
}

long long int multiplyFunction(int number1,int number2)
{
    long long int result;
    result=number1*number2;
    return result;
}

float divideFunction(int number1,int number2)
{
    float result;
    result=(float)number1/number2;
    return result;
}

long double factorialFunction(int num)
{
    long double result;
    if(num==1||num==0)
    {
        result=1;
    }
    else
    {
        result=num*factorialFunction(num-1);
    }
    return result;
}

void initialMenu(int*pNum1,int*pNum2,int*pInitialFlag1,int*pInitialFlag2)
{
    if(*pInitialFlag1&&*pInitialFlag2)
    {
        frame(0);
        printf("  บ\t\t    Calculadora\t\t\tบ\n");
        frame(1);
        printf("  บ\t1- Ingresar 1er operando A=%-13dบ\n",*pNum1);
        printf("  บ\t2- Ingresar 2do operando B=%-13dบ\n",*pNum2);
        printf("  บ\t3- Calcular todas las operaciones\tบ\n");
        printf("  บ\t   a) La Suma de %16d+%-6dบ\n",*pNum1,*pNum2);
        printf("  บ\t   b) La resta de %15d-%-6dบ\n",*pNum1,*pNum2);
        printf("  บ\t   c) La division de %12d/%-6dบ\n",*pNum1,*pNum2);
        printf("  บ\t   d) La multiplicacion de %6d*%-6dบ\n",*pNum1,*pNum2);
        printf("  บ\t   e) El factorial de %11d %-6dบ\n",*pNum1,*pNum2);
        printf("  บ\t4- Informar resultados\t\t\tบ\n");
        printf("  บ\t5- Salir\t\t\t\tบ\n");
        frame(1);
    }
    else if(*pInitialFlag1)
    {
        frame(0);
        printf("  บ\t\t    Calculadora\t\t\tบ\n");
        frame(1);
        printf("  บ\t1- Ingresar 1er operando A=%-13dบ\n",*pNum1);
        printf("  บ\t2- Ingresar 2do operando B=y\t\tบ\n");
        printf("  บ\t3- Calcular todas las operaciones\tบ\n");
        printf("  บ\t   a) La Suma de %16d+B\tบ\n",*pNum1);
        printf("  บ\t   b) La resta de %15d-B\tบ\n",*pNum1);
        printf("  บ\t   c) La division de %12d/B\tบ\n",*pNum1);
        printf("  บ\t   d) La multiplicacion de %6d*B\tบ\n",*pNum1);
        printf("  บ\t   e) El factorial de %11d B!\tบ\n",*pNum1);
        printf("  บ\t4- Informar resultados\t\t\tบ\n");
        printf("  บ\t5- Salir\t\t\t\tบ\n");
        frame(1);
    }
    else if(*pInitialFlag2)
    {
        frame(0);
        printf("  บ\t\t    Calculadora\t\t\tบ\n");
        frame(1);
        printf("  บ\t1- Ingresar 1er operando A=x\t\tบ\n");
        printf("  บ\t2- Ingresar 2do operando B=%-13dบ\n",*pNum2);
        printf("  บ\t3- Calcular todas las operaciones\tบ\n");
        printf("  บ\t   a) La Suma de\t\tA+%-6dบ\n",*pNum2);
        printf("  บ\t   b) La resta de\t\tA-%-6dบ\n",*pNum2);
        printf("  บ\t   c) La division de\t\tA/%-6dบ\n",*pNum2);
        printf("  บ\t   d) La multiplicacion de\tA*%-6dบ\n",*pNum2);
        printf("  บ\t   e) El factorial de\t\tA!%-6dบ\n",*pNum2);
        printf("  บ\t4- Informar resultados\t\t\tบ\n");
        printf("  บ\t5- Salir\t\t\t\tบ\n");
        frame(1);
    }
    else
    {
        frame(0);
        printf("  บ\t\t    Calculadora\t\t\tบ\n");
        frame(1);
        printf("  บ\t1- Ingresar 1er operando A=x\t\tบ\n");
        printf("  บ\t2- Ingresar 2do operando B=y\t\tบ\n");
        printf("  บ\t3- Calcular todas las operaciones\tบ\n");
        printf("  บ\t   a) La Suma de\t\tA+B\tบ\n");
        printf("  บ\t   b) La resta de\t\tA-B\tบ\n");
        printf("  บ\t   c) La division de\t\tA/B\tบ\n");
        printf("  บ\t   d) La multiplicacion de\tA*B\tบ\n");
        printf("  บ\t   e) El factorial de\t\tA!B!\tบ\n");
        printf("  บ\t4- Informar resultados\t\t\tบ\n");
        printf("  บ\t5- Salir\t\t\t\tบ\n");
        frame(1);
    }

}

void reset(int*pInitialFlag1,int*pInitialFlag2,int*pFinalFlag)
{
    *pInitialFlag1=0;
    *pInitialFlag2=0;
    *pFinalFlag=0;
}
void frame(int type)
{
    switch(type)
    {
    case 0:
        printf("  ษอออออออออออออออออออออออออออออออออออออออออออออป\n");
        break;
    case 1:
        printf("  ฬอออออออออออออออออออออออออออออออออออออออออออออน\n");
        break;
    case 2:
        printf("\n  ฬอออออออออออออออออออออออออออออออออออออออออออออผ\n");
        break;
    case 3:
        printf("\n  ศอออออออออออออออออออออออออออออออออออออออออออออผ\n");
        break;
    case 4:
        printf("  บ                                             บ\n");
        break;
    }
}

void loading(int time,int cant)
{
    system("color E");
    int i;
    char loading='Û';
    for(i=0;i<cant; i++)
    {
        printf("%c",loading);
        Sleep(time);
    }
    printf("บ\n");
}
