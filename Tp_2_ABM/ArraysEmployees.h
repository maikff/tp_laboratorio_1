#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "utn.h"

#ifndef ARRAYSEMPLOYEES_H_INCLUDED
#define ARRAYSEMPLOYEES_H_INCLUDED

typedef struct
{
	int id;
	char name[51];
	char lastName[51];
	float salary;
	int sector;
	int isEmpty;
} eEmployee;

#endif // STRUCTLIB_H_INCLUDED


/** \brief To indicate that all position in the array are empty,
 * this function put the flag (isEmpty) in TRUE in all
 * position of the array
 * \param list eEmployee* Pointer to array of employees
 * \param len int Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */

int initEmployees(eEmployee* list, int len);

/** \brief add in a existing list of employees the values received as parameters
 * in the first empty position
 * \param list eEmployee*
 * \param len int
 * \param id int
 * \param name[] char
 * \param lastName[] char
 * \param salary float
 * \param sector int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or without free space] - (0) if Ok
 */

int addEmployee(eEmployee* list, int len, int id,char name[],char lastName[],float salary,int sector);

/** \brief find an Employee by Id en returns the index position in array.
* * \param list eEmployee* * \param len int
  * \param id int
  * \return Return employee index position or (-1) if [Invalid length or NULL pointer received or employee not found] * */

int findEmployeeById(eEmployee* list, int len,int id);

/** \brief print the content of employees array *
  * \param list eEmployee*
  * \param length int
  * \return int * */

int printEmployees(eEmployee* list, int length);

/** \brief Remove a Employee by Id (put isEmpty Flag in 1) *
  * \param list eEmployee*
  * \param len int
  * \param id int
  * \return int Return (-1) if Error [Invalid length or NULL pointer or if can't find a employee] - (0) if Ok * */

int removeEmployee(eEmployee* list, int len, int id);

/** \brief Sort the elements in the array of employees, the argument order indicate UP or DOWN order *
  * \param list eEmployee*
  * \param len int
  * \param order int  [1] indicate UP - [0] indicate DOWN
  * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok * */

int sortEmployees(eEmployee* list, int len, int order);

/** \brief Search for free places in the employee array
 *
 * \param list eEmployee*
 * \param len int
 * \return int Return (-1) if Error, (0) if Ok *
 */

int freeSpace(eEmployee list[], int len);

/** \brief Modify employee data
 *
 * \param list eEmployee*
 * \param len int
 * \param id int
 * \return int Return (-1) if Error, (0) if Ok *
 *
 */

int modifyEmployee(eEmployee* list, int len, int id);

/** \brief Report the total, average wages
 *
 * \param list eEmployee*
 * \param len int
 * \return int Return (-1) if Error, (0) if Ok *
 *
 */

int reportSalary(eEmployee* list, int len);

void hardCode(eEmployee* x);
