
/** \brief a lo que devuelve fgets recorta el salto de carro y lo
 * cambia por '\0'
 * \param se pasa la variable por teclado a fgets
 * \param
 * \return lo que entrega fgets -1 '\0'
 *
 */

void miFgets(char array[], int tamano);

/** \brief recorta los espacios a la izquierda de una cadena de texto
 *
 * \param array_entrada cadena con dato original
 * \param array_salida cadena devuelta sin espacios iniciales
 * \return cadena devuelta sin espacios iniciales
 *
 */


void miLtrim (const char array_entrada[], char array_salida[]);

/** \brief recorta los espacios a la derecha de una cadena de texto
 *
 * \param array_entrada cadena con dato original
 * \param array_salida cadena devuelta sin espacios iniciales
 * \return cadena devuelta sin espacios al final de la cadena
 *
 */

void miRtrim (const char array_entrada[], char array_salida[]);

/** \brief recorta los espacios a la izquierda y
 *         a la derecha de una cadena de texto
 *
 * \param array_entrada cadena con dato original
 * \param array_salida cadena devuelta sin espacios iniciales
 *        ni finales
 * \return cadena devuelta sin espacios iniciales ni finales
 *
 */
void mi_Trim (const char array_entrada[], char array_salida[]);


/** \brief controla el ingreso de numeros float
 *
 * \param char mensaje1 mensaje para orientar al usuario
 * \param char mensajeError en caso de error muestra el mensaje
 * \param int minimo e int maximo validaciones
 * \return un dato float validado
 *
 */

float getFloat(float *numero,char mensaje1[],char mensajeError1[],int minimo,int maximo);


/** \brief despliega un mensaje y al presionar una tecla obtiene
 *         el valor de la misma
 * \param char mensaje a mostrar
 * \param
 * \return el valor de la tecla presionada
 *
 */

char getChar(char mensaje[]);


/** \brief despliega un mensaje y al presionar una tecla obtiene
 *         el valor de la misma
 * \param char mensaje a mostrar
 * \param
 * \return el valor de la tecla presionada
 *
 */

char getChar2(char mensaje[]);

/** \brief despliega un mensaje y espera el ingreso de un numero
 *         controla la validacion
 * \param char mensaje1 leyenda orientativa
 * \param char mensajeError1 guarda el mensaje para mostrar en caso
 *        de error
 * \return el numero solicitado
 *
 */

int getInt(int *numero,char mensaje1[],char mensajeError1[],int minimo,int maximo);


/** \brief ingreso de cadena de caracteres controla el tamaño
 *         ingresado y facilita un mensaje orientado
 * \param char mensaje mensaje a mostrar
 * \param char input variable donde guarda el valor a su salida
 * \param tamano es el tamaño maximo para la cadena
 * \return char input
 *
 */

void getString(char mensaje[],char input[],int tamano);

/** \brief es una herramienta de validacion numerica
 *
 * \param char str[] char a controlar como numerico
 * \param
 * \return -1 si no es numerico 0 si es numerico
 *
 */

int esNumerico(char str[]);

/** \brief validacion de char verifica que se hayan ingresado
 *         datos alfanumericos
 * \param char str[] dato a controlar
 * \param
 * \return -1 si existen valores no alfanumericos 0 si es asi
 *
 */

int esAlfaNumerico(char str[]);

/** \brief recorre el numero ingresado y verifica que sea realmente
 *         un numero pero ademas controla q solo haya un '.'
 * \param cha[] albrega el dato ingresado a controlar
 * \param
 * \return -1 si no es flotante 0 si es asi
 *
 */

int esNumericoFlotante(char str[]);

/** \brief herramienta para imprimir repeticiones de un caracter
 *         ejemplo hacer una linea de 78 asteriscos
 * \param char caracter es el caracter a imprimir,
 * \param can_col la cantidad de columnas
 * \param can_fila la cantidad de filas
 * \return void
 *
 */


void rellena_Espacio (char caracter,int can_col,int can_fila);

/** \brief muestra la vinculacion de dos arrays ej Empleados y
 *   sector para mostrar los empleados y la descrip de sector
 * \param Employee* list array employees
 * \param int len cantidad de elementos en el array empleados
 * \param int len2 cantidad de elementos en el array sector
 * \param int id id de empleado
 * \param char S[] array de sector
 * \return void
 *
 */

void Muestra_Employees(Employee* list,int len,int len2,int id,char S[]);

/** \brief recorre el array empleado (desc) hasta encontra el primer
 * lugar ocupado, suma 1 y es el proximo Id
 * \param Employee list array empleados
 * \param int len cantidad elementos del array
 * \return un indice id
 *
 */

int findEmpty(Employee* list, int len);

/** \brief recorre todo el array y devuelve el maximo
 *
 * \param Employee* list array empleados
 * \param int len tamaño del array
 * \return maximo id
 *
 */
int findEmpty2(Employee* list, int len);

// int findSectorById(Sector* list, int len,int id);

/** \brief Busca un sector por id
 *
 * \param array de sector
 * \param tamaño del array sector
 * \param id del sector
 * \param result [] es un puntero q devuelve la descripcion
 * \return descripcion y un int -1 si no lo encuentra, 0 si
 *
 */
int findSectorByDesc(Sector* list,int len,int id,char resul[]);

//int capturaIdSector(Employee* list, int len,int id);

//char * capturaDescSector(Sector* list, int len,int id);

/** \brief muestra los datos de los sectores como menu y
 * espera la entrada de una opcion para seleccionar su id
 * \param Sector opc[] toma la seleccion del usuario
 * \param char titulo titulo del menu
 * \param int cantidad e int tamaño las dimensiones del menu
 * \return la seleccion del usuario
 *
 */

char muestra_Sector(Sector opc[],char titulo[],int cantidad,int tamano);

/** \brief escriben en forma previa los valores del array sector
 *
 * \param sec [] array sector
 * \param len tamaño del array sector
 * \return void
 *
 */

int hardCord(Sector sec[],int len);

/** \brief escriben en forma previa los valores del array Menu
 *  y menu2
 * \param men y men2 [] array de menues
 * \param len tamaño del array men / len2 del men2
 * \return void
 *
 */

int hardCordMen(Menu men[],Menu men2[],int len,int len2);

/** \brief verifica que el array no este vacio
 *
 * \param list[] array de empleados
 * \param int len tamaño del array
 * \return -1 si esta vacio 0 si no esta vacio
 *
 */

int isAvailable(Employee* list, int len);

/** \brief recorre el array y busca el primer indice disponible
 *
 * \param list[] array de empleados
 * \param int len tamaño del array
 * \return -1 si esta lleno 0 si no lo encuentra
 *
 */

int findFirstAvailable(Employee* list, int len);

/** \brief realiza el menu de la parte de informes y listados
 *
 * \param emp[] array empleados
 * \param len tamaño del array
 * \param menu_sec array tiene las opciones del menu secundario
 * \param int lenM2 tamaño del array menu_sec
 * \param
 * \return las opciones que ingresan los usuarios
 *
 */

char menuImpresionint(Employee emp[],int len,Menu menu_sec[],int lenM2);

/** \brief imprime un empleado
 *
 * \param list array de empleados
 * \param sec  array de sector
 * \param len tamaño del array empleados
 * \param lenSector tamaño del array Sectores
 * \param
 * \param
 * \return void
 *
 */

int printOneEmployees(Employee list,Sector* sec,int len,int lenSector);


Employee carga_Employees2(Sector* list,Employee* empleados3,int len,int len2,int id,char name[],
                          char lastName[],float salary,int sector,int registro);

Employee carga_Employees(Sector* list,Employee empleados3,int len,int lenSector,int id);

//int mostrarEmployee(Employee list[],Sector sec[],int lenE,int lenS,int id);



/** \brief se pasan las variables y la funcion llena
 *         el array
 * \param array empleados variable emp del tipo empleados
 * \param id identificaicon dentro del array y len tamaño
 * \return una variable del tipo empleados
 *
 */

Employee llenaEmployee (Employee employ[],Employee emp,int id,int len);

/** \brief una funcion menu
 *
 * \param array opc[] del tipo menu
 * \param char titulo titulo del menu
 * \param int CANT cantidad de elementos del array opc
 * \param int LENMENU una constante del tamaña del array opc
 * \return char opcion elegida
 *
 */

char getChoice(Menu opc[],char titulo[],int CANT,int LENMENU);

/** \brief muestra la cabecera de una pantalla de carga
 *
 * \param char titulo titulo de cabecera
 * \param int CANT constante de filas a imprimir
 * \param LENMENU constante del largo del menu
 * \return void
 *
 */

char getChoiceForm(char titulo[],int CANT,int LENMENU);

/** \brief valida los errores que reciben las funciones
 *
 * \param int signed codigo recibe el codigo de error
 * \param int codfun el codigo de la funcion
 * \return devuelve un mensaje de error cuando se produce
 *
 */

int validaciones(int signed codigo,int codFun);

/** \brief tomo los datos pasados y los muestra por pantalla
 *
 * \param emp array employees / sec array Sectores
 * \param int id id de empleado
 * \param int len tamaño del array employees
 * \param int lenSector tamaño del array sector
 * \param
 * \return
 *
 */

int MuestraUnEmployee (Employee emp,Sector sec[],int id,int len,int lenSector);

/** \brief realiza la carga del empleado antes de ser grabado
 *
 * \param employ[]array de employees sec[] array de Sector
 * \param int len tamano del array employees / lenSector de sec
 * \return los datos para cargar un registro en el array employees
 *
 */

int ModificaUnEmployee (Employee employ[],Sector sec[],int len,int lenSector);



/** \brief calcula e imprime en pantalla total de salarios, promedio
 *         y cantidad de empleados que superan la media
 * \param list Employee* list array de employees
 * \param len int tamaño del array
 * \return int -1 si el array esta vacio
 *
 */
int salarioPromedio(Employee* list, int len);


