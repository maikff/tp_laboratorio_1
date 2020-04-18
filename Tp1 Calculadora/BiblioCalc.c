#include "BiblioCalc.h"

void getOption(void)
{
    char continuar='s';
    int option;
    int num1=0;
    int num2=0;
    int suma,resta;
    long long int multiplicacion;
    float division;
    long double factorialNum1,factorialNum2;
    int initialFlag1=0,initialFlag2=0,finalFlag=0;
    do
    {
        initialMenu(&num1,&num2,&initialFlag1,&initialFlag2);
        option=getValidOption("Ingrese La opcion deseada: ","ERROR Ingrese la opcion deseada: ",1,5);

        switch(option)
        {
        case 1:
            num1=getValidNumber("\nIngrese el primer numero: ");
            initialFlag1++;
            system("cls");
            break;
        case 2:
            num2=getValidNumber("\nIngrese el segundo numero: ");
            initialFlag2++;
            system("cls");
            break;
        case 3:
            if(!initialFlag1||!initialFlag2)
            {
                printf("Primero ingrese todos los numeros...");
                Sleep(1500);
                system("cls");
            }
            else
            {
                suma=addFunction(num1,num2);
                resta=subtractFuntion(num1,num2);
                multiplicacion=multiplyFunction(num1,num2);
                printf("\n\tRealizando calculos...\n");
                Sleep(1000);
                printf("\n\tCalculos realizados.\n");
                Sleep(900);
                finalFlag++;
                system("cls");
            }
            break;
        case 4:
            if(!finalFlag)
            {
                printf("Primero debes calcular las operaciones...");
                Sleep(1500);
                system("cls");
            }
            else
            {
                printf("\ta- El resultado de %d+%d es: %d\n",num1,num2,suma);
                printf("\tb- El resultado de %d-%d es: %d\n",num1,num2,resta);
                if(!num2)
                {
                    printf("\tc- No es posible dividir un numero por cero\n");
                }
                else
                {
                    division=divideFunction(num1,num2);
                    printf("\tc- El resultado de %d/%d es: %.2f\n",num1,num2,division);
                }
                printf("\td- El resultado de %d*%d es: %lld\n",num1,num2,multiplicacion);
                if(num1<0)
                {
                    printf("\te- No es posible hacer el factorial de %d ya que es un numero negativo.\n",num1);
                }
                else
                {
                    factorialNum1=factorialFunction(num1);
                    printf("\te- El factorial de %d! es: %.Lf\n",num1,factorialNum1);
                }
                if(num2<0)
                {
                    printf("\t   No es posible hacer el factorial de %d ya que es un numero negativo.\n",num2);
                }
                else
                {
                    factorialNum2=factorialFunction(num2);
                    printf("\t   El factorial de %d! es: %.Lf\n",num2,factorialNum2);
                }
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
        printf("Ingrese solo numeros: ");
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
        printf("\n\tTrabajo Practico N#1\n\t    Calculadora\n\n");
        printf("1- Ingresar 1er operando (A=%d)\n",*pNum1);
        printf("2- Ingresar 2do operando (B=%d)\n",*pNum2);
        printf("3- Calcular todas las operaciones\n");
        printf("\ta) La Suma (%d+%d)\n",*pNum1,*pNum2);
        printf("\tb) La resta (%d-%d)\n",*pNum1,*pNum2);
        printf("\tc) La division (%d/%d)\n",*pNum1,*pNum2);
        printf("\td) La multiplicacion (%d*%d)\n",*pNum1,*pNum2);
        printf("\te) El factorial (%d!)(%d!)\n",*pNum1,*pNum2);
        printf("4- Informar resultados\n");
        printf("5- Salir\n");
    }
    else if(*pInitialFlag1)
    {
        printf("\n\tTrabajo Practico N#1\n\t    Calculadora\n\n");
        printf("1- Ingresar 1er operando (A=%d)\n",*pNum1);
        printf("2- Ingresar 2do operando (B=y)\n");
        printf("3- Calcular todas las operaciones\n");
        printf("\ta) La Suma (%d+B)\n",*pNum1);
        printf("\tb) La resta (%d-B)\n",*pNum1);
        printf("\tc) La division (%d/B)\n",*pNum1);
        printf("\td) La multiplicacion (%d*B)\n",*pNum1);
        printf("\te) El factorial (%d!)(B!)\n",*pNum1);
        printf("4- Informar resultados\n");
        printf("5- Salir\n");
    }
    else if(*pInitialFlag2)
    {
        printf("\n\tTrabajo Practico N#1\n\t    Calculadora\n\n");
        printf("1- Ingresar 1er operando (A=x)\n");
        printf("2- Ingresar 2do operando (B=%d)\n",*pNum2);
        printf("3- Calcular todas las operaciones\n");
        printf("\ta) La Suma (A+%d)\n",*pNum2);
        printf("\tb) La resta (A-%d)\n",*pNum2);
        printf("\tc) La division (A/%d)\n",*pNum2);
        printf("\td) La multiplicacion (A*%d)\n",*pNum2);
        printf("\te) El factorial (A!)(%d!)\n",*pNum2);
        printf("4- Informar resultados\n");
        printf("5- Salir\n");
    }
    else
    {
        printf("\n\tTrabajo Practico N#1\n\t    Calculadora\n\n");
        printf("1- Ingresar 1er operando (A=x)\n");
        printf("2- Ingresar 2do operando (B=y)\n");
        printf("3- Calcular todas las operaciones\n");
        printf("\ta) La Suma (A+B)\n");
        printf("\tb) La resta (A-B)\n");
        printf("\tc) La division (A/B)\n");
        printf("\td) La multiplicacion (A*B)\n");
        printf("\te) El factorial (A!)(B!)\n");
        printf("4- Informar resultados\n");
        printf("5- Salir\n");
    }

}

void reset(int*pInitialFlag1,int*pInitialFlag2,int*pFinalFlag)
{
    *pInitialFlag1=0;
    *pInitialFlag2=0;
    *pFinalFlag=0;
}
