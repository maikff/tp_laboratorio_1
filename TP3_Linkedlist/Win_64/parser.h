

/** \brief Parser los datos del archivo data.csv (modo texto).
 *
 * \param pFile FILE* puntero al archivo;
 * \param pArrayListEmployee LinkedList* Linkedlist;
 * \return int retorna 0 en caso de exito y -1 si ocurrio un error;
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee);

/** \brief Parser los datos del archivo data.csv (modo binario).
 *
 * \param pFile FILE*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee);
