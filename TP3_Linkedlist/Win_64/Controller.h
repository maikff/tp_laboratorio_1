#include "LinkedList.h"

/** \brief carga los datos del archivo data.csv(modo texto)
 *
 * \param path char* path al archique que quiere cargar
 * \param pArrayListEmployee LinkedList*
 * \return int retorna 0 si fue exitoso o -1 si hubo un error
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee);

/** \brief carga los datos del archivo data.bin(modo binario)
 *
 * \param path char* path al archivo que quiere cargar
 * \param pArrayListEmployee LinkedList*
 * \return int retorna 0 si fue exitoso o -1 si hubo un error
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee);

/** \brief nuevo empleado con la linkedlist
 *
 * \param pArrayListEmployee LinkedList*
 * \return int retorna 0 si fue exitoso o -1 si hubo un error
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee);

/** \brief edit un empleado del linkedlist
 *
 * \param pArrayListEmployee LinkedList*
 * \return int retorna 0 si fue exitoso o -1 si hubo un error
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee);

/** \brief elimina un empleado de la linkedlist
 *
 * \param pArrayListEmployee LinkedList*
 * \return int retorna 0 si fue exitoso o -1 si hubo un error
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee);

/** \brief lista los empleados
 *
 * \param pArrayListEmployee LinkedList*
 * \return int retorna 0 si fue exitoso o -1 si hubo un error
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee);

/** \brief ordena a los empleados
 *
 * \param pArrayListEmployee LinkedList*
 * \return int retorna 0 si fue exitoso o -1 si hubo un error
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee);

/** \brief guarda los datosn en modo texto
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int retorna 0 si fue exitoso o -1 si hubo un error
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee);

/** \brief guarda los datos en modo binario
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int retorna 0 si fue exitoso o -1 si hubo un error
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee);


