typedef struct
{
int id;
char name[51];
char lastName[51];
float salary;
int sector;
int isEmpty;
}Employee;

typedef struct
{
int id2;
char descripcion[60];
}Menu;

typedef struct
{
int id3;
char descripcion3[60];
}Sector;

/** \brief add in a existing list of employees the values received as parameters
* in the first empty position
* \param list employee*
* \param len int
* \param id int
* \param name[] char
* \param lastName[] char
* \param salary float
* \param sector int
* \return int Return (-1) if Error [Invalid length or NULL pointer or without
free space] - (0) if Ok
*
*/

int initEmployees(Employee* list, int len);


/** \brief add in a existing list of employees the values received as parameters
 * in the first empty position
 * \param list employee*
 * \param len int
 * \param id int
 * \param name[] char
 * \param lastName[] char
 * \param salary float
 * \param sector int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or without
 * free space] - (0) if Ok
 */

int addEmployee(Employee* list, int len, int id, char name[],char lastName[],float salary,int sector);

/** \brief find an Employee by Id en returns the index position in array.
 *
 * \param list Employee*
 * \param len int
 * \param id int
 * \return Return employee index position or (-1) if [Invalid length or NULL
pointer received or employee not found]
 *
 */

int findEmployeeById(Employee* list, int len,int id);

/** \brief Remove a Employee by Id (put isEmpty Flag in 1)
 *
 * \param list Employee*
 * \param len int
 * \param id int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
find a employee] - (0) if Ok
 *
 */

int removeEmployee(Employee* list,Sector* sec,int len,int len2);

/** \brief Sort the elements in the array of employees, the argument order
indicate UP or DOWN order
 *
 * \param list Employee*
 * \param len int
 * \param order int [1] indicate UP - [0] indicate DOWN
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */

int sortEmployees(Employee* list2,int len, int order);

/** \brief print the content of employees array
 *
 * \param list Employee*
 * \param length int
 * \return int
 *
 */

 int printEmployees(Employee* list,Sector* sec,int len,int lenS);

 /** \brief Ordena el array de empleados por apellido y sector
 *          de manera ascendente o descendente segun el orden
 * \param Employee* list puntero al array de empleados.
 * \param int order, 1 ascendente 0 indica descendente
 * \param int len, cantidad del array de empleados.
 * \return Retorna -1 si el puntero es nulo o el limite es menor a 0, 0 si salio todo bien y fue ordenado con exito.
 */

int sortEmployees(Employee* list2,int len, int order);


