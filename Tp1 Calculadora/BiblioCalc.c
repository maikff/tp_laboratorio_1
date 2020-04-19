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
        option=getValidOption("  �Ingrese La opcion deseada: ","  �ERROR Ingrese la opcion deseada: ",1,5);
        frame(1);

        switch(option)
        {
        case 1:
            system("color B");
            num1=getValidNumber("  �Ingrese el primer numero: ");
            initialFlag1++;
            system("cls");
            break;
        case 2:
            system("color B");
            num2=getValidNumber("  �Ingrese el segundo numero: ");
            initialFlag2++;
            system("cls");
            break;
        case 3:
            if(!initialFlag1||!initialFlag2)
            {
                system("color C");
                printf("  �Primero ingrese todos los numeros...\t\t�\n");
                Sleep(1500);
                system("cls");
            }
            else
            {
                suma=addFunction(num1,num2);
                resta=subtractFuntion(num1,num2);
                multiplicacion=multiplyFunction(num1,num2);
                printf("  �Realizando operaciones ");
                loading(90,22);
                frame(4);
                system("color A");
                printf("  �Las Operaciones Fueron Realizadas Con Exito! �");
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
                printf("  �Primero calcula todas las operaciones...\t�\n");
                Sleep(1500);
                system("cls");
            }
            else
            {
                printf("  �\ta- El resultado de %3d +%3d es: %-8d�\n",num1,num2,suma);
                printf("  �\tb- El resultado de %3d -%3d es: %-8d�\n",num1,num2,resta);
                if(!num2)
                {
                    printf("  �\tc- No es posible dividir un numero por \t�\n  �\t   cero\t\t\t\t\t�\n");
                }
                else
                {
                    division=divideFunction(num1,num2);
                    printf("  �\tc- El resultado de %3d /%3d es: %-8.2f�\n",num1,num2,division);
                }
                printf("  �\td- El resultado de %3d *%3d es: %-8lld�\n",num1,num2,multiplicacion);
                if(num1<0)
                {
                    printf("  �\te- No es posible hacer el factorial de\t�\n  �\t   %-3d ya que es un numero negativo.\t�\n",num1);
                }else if(num1>25)
                {
                    printf("  �\te- No es posible hacer el factorial de\t�\n  �\t   %-3d ya que es un numero muy grande.\t�\n",num1);
                }
                else
                {
                    factorialNum1=factorialFunction(num1);
                    printf("  �\te- El factorial de %2d! es: %-13.Lf�\n",num1,factorialNum1);
                }
                if(num2<0)
                {
                    printf("  �\t   No es posible hacer el factorial de\t�\n  �\t   %-3d ya que es un numero negativo.\t�",num2);
                }
                else if(num2>25)
                {
                    printf("  �\t   No es posible hacer el factorial de\t�\n  �\t   %-3d ya que es un numero muy grande.\t�",num2);
                }
                else
                {
                    factorialNum2=factorialFunction(num2);
                    printf("  �\t   El factorial de %2d! es: %-13.Lf�",num2,factorialNum2);
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
        printf("  �ERROR ingrese solo numeros: ");
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
        printf("  �\t\t    Calculadora\t\t\t�\n");
        frame(1);
        printf("  �\t1- Ingresar 1er operando A=%-13d�\n",*pNum1);
        printf("  �\t2- Ingresar 2do operando B=%-13d�\n",*pNum2);
        printf("  �\t3- Calcular todas las operaciones\t�\n");
        printf("  �\t   a) La Suma de %16d+%-6d�\n",*pNum1,*pNum2);
        printf("  �\t   b) La resta de %15d-%-6d�\n",*pNum1,*pNum2);
        printf("  �\t   c) La division de %12d/%-6d�\n",*pNum1,*pNum2);
        printf("  �\t   d) La multiplicacion de %6d*%-6d�\n",*pNum1,*pNum2);
        printf("  �\t   e) El factorial de %11d %-6d�\n",*pNum1,*pNum2);
        printf("  �\t4- Informar resultados\t\t\t�\n");
        printf("  �\t5- Salir\t\t\t\t�\n");
        frame(1);
    }
    else if(*pInitialFlag1)
    {
        frame(0);
        printf("  �\t\t    Calculadora\t\t\t�\n");
        frame(1);
        printf("  �\t1- Ingresar 1er operando A=%-13d�\n",*pNum1);
        printf("  �\t2- Ingresar 2do operando B=y\t\t�\n");
        printf("  �\t3- Calcular todas las operaciones\t�\n");
        printf("  �\t   a) La Suma de %16d+B\t�\n",*pNum1);
        printf("  �\t   b) La resta de %15d-B\t�\n",*pNum1);
        printf("  �\t   c) La division de %12d/B\t�\n",*pNum1);
        printf("  �\t   d) La multiplicacion de %6d*B\t�\n",*pNum1);
        printf("  �\t   e) El factorial de %11d B!\t�\n",*pNum1);
        printf("  �\t4- Informar resultados\t\t\t�\n");
        printf("  �\t5- Salir\t\t\t\t�\n");
        frame(1);
    }
    else if(*pInitialFlag2)
    {
        frame(0);
        printf("  �\t\t    Calculadora\t\t\t�\n");
        frame(1);
        printf("  �\t1- Ingresar 1er operando A=x\t\t�\n");
        printf("  �\t2- Ingresar 2do operando B=%-13d�\n",*pNum2);
        printf("  �\t3- Calcular todas las operaciones\t�\n");
        printf("  �\t   a) La Suma de\t\tA+%-6d�\n",*pNum2);
        printf("  �\t   b) La resta de\t\tA-%-6d�\n",*pNum2);
        printf("  �\t   c) La division de\t\tA/%-6d�\n",*pNum2);
        printf("  �\t   d) La multiplicacion de\tA*%-6d�\n",*pNum2);
        printf("  �\t   e) El factorial de\t\tA!%-6d�\n",*pNum2);
        printf("  �\t4- Informar resultados\t\t\t�\n");
        printf("  �\t5- Salir\t\t\t\t�\n");
        frame(1);
    }
    else
    {
        frame(0);
        printf("  �\t\t    Calculadora\t\t\t�\n");
        frame(1);
        printf("  �\t1- Ingresar 1er operando A=x\t\t�\n");
        printf("  �\t2- Ingresar 2do operando B=y\t\t�\n");
        printf("  �\t3- Calcular todas las operaciones\t�\n");
        printf("  �\t   a) La Suma de\t\tA+B\t�\n");
        printf("  �\t   b) La resta de\t\tA-B\t�\n");
        printf("  �\t   c) La division de\t\tA/B\t�\n");
        printf("  �\t   d) La multiplicacion de\tA*B\t�\n");
        printf("  �\t   e) El factorial de\t\tA!B!\t�\n");
        printf("  �\t4- Informar resultados\t\t\t�\n");
        printf("  �\t5- Salir\t\t\t\t�\n");
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
        printf("  ���������������������������������������������ͻ\n");
        break;
    case 1:
        printf("  ���������������������������������������������͹\n");
        break;
    case 2:
        printf("\n  ���������������������������������������������ͼ\n");
        break;
    case 3:
        printf("\n  ���������������������������������������������ͼ\n");
        break;
    case 4:
        printf("  �                                             �\n");
        break;
    }
}

void loading(int time,int cant)
{
    system("color E");
    int i;
    char loading='�';
    for(i=0;i<cant; i++)
    {
        printf("%c",loading);
        Sleep(time);
    }
    printf("�\n");
}
