#ifndef BIBLIOCALC_H_INCLUDED
#define BIBLIOCALC_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <Windows.h>

/** \brief pide un dato numerico si no es numero lo vuelve a pedir
 *
 * \param message[] char mensaje pidiendo el dato
 * \return int retorna el numero ya validado
 *
 */
int getValidNumber(char message[]);

/** \brief esta funcion verifica si es numero
 *
 * \param number[] char es el numero a verificar
 * \return int devuelve 0 si es numero
 *
 */
int validNumber(char number[]);

/** \brief actua segun la opcion deseada
 *
 * \param void
 * \return void
 *
 */
void getOption(void);

/** \brief valida que la opcion ingresada este dentro del rango requerido
 *
 * \param char[] mensaje pidiendo la opcion
 * \param char[] mensaje informando Sobre opcion invalida y pidiendo que se ingrese nuevamente
 * \param int Limite inferior
 * \param int limite superior
 * \return int retorna la opcion correcta
 *
 */
int getValidOption(char message[],char messageError[],int lInf,int lSup);

/** \brief suma los dos numeros de los parametros parametros;
 *
 * \param number1 int primer numero a sumar;
 * \param numer2 int segundo numero a sumar;
 * \return int retorna el resultado de la suma;
 *
 */
int addFunction(int number1,int number2);

/** \brief resta los dos numeros de los parametros;
 *
 * \param number1 int primer numero a restar;
 * \param number2 int segundo numero a restar;
 * \return int retorna el resultado de la resta;
 *
 */
int subtractFuntion(int number1,int number2);

/** \brief multiplica los numeros del parametro
 *
 * \param number1 int primer numero a multiplicar
 * \param number2 int segundo numero a multiplicar
 * \return int retorna el resultado de la multilpicacion
 *
 */
long long int multiplyFunction(int number1,int number2);

/** \brief divide los numeros del parametro;
 *
 * \param number1 int primer numero a multiplicar;
 * \param number2 int segundo numero a multiplicar;
 * \return float retorna el resultado de la division;
 *
 */
float divideFunction(int number1,int number2);

/** \brief calcula el factorial del parametro;
 *
 * \param num int numero a factorear;
 * \return unsigned long long retorna el resultado de factorial;
 *
 */
long double factorialFunction(int num);

void initialMenu(int*pNum1,int*pNum2,int*pInitialFlag1,int*pInitialFlag2);

void reset(int*pInitialFlag1,int*pInitialFlag2,int*pFinalFlag);

#endif // BIBLIOCALC_H_INCLUDED
