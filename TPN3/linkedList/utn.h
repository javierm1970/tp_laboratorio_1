
/** \brief recorta los espacios a la izquierda y
 *         a la derecha de una cadena de texto
 *
 * \param array_entrada cadena con dato original
 * \param array_salida cadena devuelta sin espacios iniciales
 *        ni finales
 * \return cadena devuelta sin espacios iniciales ni finales
 *
 */
void miTrim (const char array_entrada[], char array_salida[]);

int esSoloLetras(char str[]);

int muestraMenu(void);

char getChoiceForm(char titulo[],int CANT,int LENMENU);

int getInt(int *numero,char mensaje1[],char mensajeError1[],int minimo,int maximo);

void rellena_Espacio (char caracter,int can_col,int can_fila);

/** \brief despliega un mensaje y al presionar una tecla obtiene
 *         el valor de la misma
 * \param char mensaje a mostrar
 * \param
 * \return el valor de la tecla presionada
 *
 */

char getChar2(char mensaje[]);

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

/** \brief verifica si una cadena de caracteres es convertible a un float
 *
 * \param str[] char
 * \return int 1 si lo es -1 si no lo es
 *
 */
int esNumericoFlotante(char str[]);

/** \brief Una pausa en el sistema y muestra un mensaje orientativo
 *
 * \param mensaje[] char
 * \return void
 *
 */
void miPausa(char mensaje[]);

/** \brief limpia la pantalla
 *
 * \param void
 * \return void
 *
 */
void miCls(void);


/** \brief Input para una Cadena de caracteres
 *
 * \param array[] char se pasa un array vacio y se llena
 * \param tamano int tamano del array
 * \return void
 *
 */
void miFgets(char array[], int tamano);

/** \brief Busca y devuelve el proximo Id para una carga secuencial
 *
 * \param pArrayListEmployee LinkedList*
 * \return int devuelve un proximo Id
 *
 */
int nextIdLinkedList(LinkedList* pArrayListEmployee);

/** \brief A partir de un Id busca y devuelve el indice donde esta ese Id
 *
 * \param pArrayListEmployee LinkedList*
 * \param idLinkedlist int
 * \return int un indice buscado
 *
 */
int indexLinkedList(LinkedList* pArrayListEmployee,int idLinkedlist);

/** \brief un menu donde devuelve el orden a listar u ordenar
 *
 * \param void
 * \return int 1 Descendente 0 ascendente
 *
 */
int tipoDeOrden(void);

/** \brief Menu donde se pide que se elija por que campo se va a ordenar la lista
 *
 * \param void
 * \return char opcion
 *
 */
char menuOrdenamiento(void);

/** \brief
 *
 * \param titulo[] char
 * \param canFila int
 * \param canCol int
 * \return void
 *
 */
void encabezadoListados(char titulo[],int canFila, int canCol);
