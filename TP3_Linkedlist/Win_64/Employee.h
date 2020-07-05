#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED

#include "LinkedList.h"

typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;

/** \brief reserva memoria con malloc
 *
 * \return Employee* retorna un puntero a empleado
 *
 */
Employee* employee_new();

/** \brief llama a los sets para cargar los campos del empleado
 *
 * \param idStr char* Id de empleado
 * \param nombreStr char* Nombre del empleado
 * \param horasTrabajadasStr char* Horas trabajadas
 * \param sueldoStr char* Sueldo del empleado
 * \return Employee* retorna un puntero a empleado
 *
 */
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr);

/** \brief Borra un empleado
 *
 * \param this Employee* puntero a empleado
 * \return int retorna 0 si logro borrarlo o -1 si hubo un error
 *
 */
int employee_delete(Employee* this);

/** \brief carga el id del empleado
 *
 * \param this Employee* puntero a empleado
 * \param id int Id a cargar
 * \return int retorna 0 si fue exitoso o -1 si hubo un error
 *
 */
int employee_setId(Employee* this,int id);

/** \brief carga el id empleado al puntero empleado que le pasamos
 *
 * \param this Employee* puntero a empleado
 * \param id int* puntero a la variable id
 * \return int retorna 0 si fue exitoso o -1 si hubo un error
 *
 */
int employee_getId(Employee* this,int* id);

/** \brief carga el nombre en el puntero de empleado
 *
 * \param this Employee* puntero a empleado
 * \param nombre char* nombre a cargar
 * \return int retorna 0 si fue exitoso o -1 si hubo un error
 *
 */
int employee_setNombre(Employee* this,char* nombre);

/** \brief cargar el nombre del empleado en el puntero que le pasemos
 *
 * \param this Employee* puntero a empleado
 * \param nombre char* el nombre a cargar
 * \return int retorna 0 si fue exitoso o -1 si hubo un error
 *
 */
int employee_getNombre(Employee* this,char* nombre);

/** \brief carga las horas trabajadas
 *
 * \param this Employee* puntero a empleado
 * \param horasTrabajadas int horas trabajadas
 * \return int retorna 0 si fue exitoso o -1 si hubo un error
 *
 */
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);


/** \brief
 *
 * \param this Employee*
 * \param horasTrabajadas int*
 * \return int
 *
 */
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);

/** \brief
 *
 * \param this Employee*
 * \param sueldo int
 * \return int
 *
 */
int employee_setSueldo(Employee* this,int sueldo);

/** \brief
 *
 * \param this Employee*
 * \param sueldo int*
 * \return int
 *
 */
int employee_getSueldo(Employee* this,int* sueldo);

/** \brief
 *
 * \param pArrayListEmployee LinkedList*
 * \param id int
 * \return int
 *
 */
int employee_SearchForId(LinkedList* pArrayListEmployee, int id);

/** \brief
 *
 * \param pArrayListEmployee LinkedList*
 * \param index int
 * \return int
 *
 */
int employee_printEmployee(LinkedList* pArrayListEmployee, int index);

/** \brief
 *
 * \param pArrayListEmployee LinkedList*
 * \param index int
 * \return int
 *
 */
int changeName(LinkedList* pArrayListEmployee, int index);

/** \brief
 *
 * \param pArrayListEmployee LinkedList*
 * \param index int
 * \return int
 *
 */
int changeHours(LinkedList* pArrayListEmployee, int index);

/** \brief
 *
 * \param pArrayListEmployee LinkedList*
 * \param index int
 * \return int
 *
 */
int changeSalary(LinkedList* pArrayListEmployee, int index);

/** \brief
 *
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int employee_lastId(LinkedList* pArrayListEmployee);

/** \brief
 *
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int employee_sort(LinkedList* pArrayListEmployee);

/** \brief
 *
 * \param firstEmployee void*
 * \param secondEmployee void*
 * \return int
 *
 */
int employee_sortById(void* firstEmployee, void* secondEmployee);

/** \brief
 *
 * \param firstEmployee void*
 * \param secondEmployee void*
 * \return int
 *
 */
int employee_sortByName(void* firstEmployee, void* secondEmployee);

/** \brief
 *
 * \param firstEmployee void*
 * \param secondEmployee void*
 * \return int
 *
 */
int employee_sortByHours(void* firstEmployee, void* secondEmployee);

/** \brief
 *
 * \param firstEmployee void*
 * \param secondEmployee void*
 * \return int
 *
 */
int employee_sortBySalary(void* firstEmployee, void* secondEmployee);


#endif // employee_H_INCLUDED
