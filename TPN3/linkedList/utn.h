
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

int esNumericoFlotante(char str[]);

void miPausa(char mensaje[]);

void miCls(void);

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */
void miFgets(char array[], int tamano);

int nextIdLinkedList(LinkedList* pArrayListEmployee);

int indexLinkedList(LinkedList* pArrayListEmployee,int idLinkedlist);

int tipoDeOrden(void);

char menuOrdenamiento(void);
