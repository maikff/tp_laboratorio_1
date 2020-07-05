
#ifndef MENUS_H_INCLUDED
#define MENUS_H_INCLUDED

/** \brief muestra el menu principal
 *
 * \return int retorna la opcion elegida
 *
 */
int menu();

/** \brief muestra el menu de modificacion
 *
 * \return int devuelve la opcion elegida
 *
 */
int menuEdit();

/** \brief muestra el menu de ordenamiento
 *
 * \return int retorna la opcion elegida
 *
 */
int menuSort();

/** \brief marcos
 *
 * \param type int tipo de marco
 * \return void grafico de marco
 *
 */
void frame(int type);

#endif // MENUS_H_INCLUDED
