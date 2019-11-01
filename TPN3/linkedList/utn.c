#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"
#include "utn.h"

int esSoloLetras(char str[])
{
   int i=0;

   while(str[i] != '\0')
   {
       if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
           return 0;
       i++;
   }
   return 1;
}

int muestraMenu(void)
{
    int opcion;
    system("cls");
    getChoiceForm(" Menu Principal ",1,78);

    printf("\n1. Cargar los datos de los empleados desde el archivo data.csv (modo texto)");
    printf("\n2. Cargar los datos de los empleados desde el archivo data.csv (modo binario)");
    printf("\n3. Alta de empleado");
    printf("\n4. Modificar datos de empleado");
    printf("\n5. Baja de empleado");
    printf("\n6. Listar empleados");
    printf("\n7. Ordenar empleados");
    printf("\n8. Guardar los datos de los empleados en el archivo data.csv (modo texto)");
    printf("\n9. Guardar los datos de los empleados en el archivo data.csv (modo binario)");
    printf("\n10. Salir");


    printf("\n\n ");
    do{
        getInt(&opcion,"Ingrese una Opcion: ","Error, la opcion no es correcta",1,10);

    }while (!(opcion>0 || opcion<=10));

    printf("\n ");
    return opcion;

}

char getChoiceForm(char titulo[],int CANT,int LENMENU)
{

    int margen;

    margen=((LENMENU-2)-(strlen(titulo)))/2;

    rellena_Espacio('*',LENMENU,1);
    printf("\n");

    rellena_Espacio('*',margen,1);
    printf(" %s ",titulo);
    rellena_Espacio('*',margen,1);

    printf("\n");
    rellena_Espacio('*',LENMENU,1);
    printf("\n");

    return 0;
}

int getInt(int *numero,char mensaje1[],char mensajeError1[],int minimo,int maximo)
{
    int num;
    //int cant;
    int flagSalida=0;
    int resultado=0;

    printf("%s",mensaje1);
    while(flagSalida==0)
    {

        fflush(stdin);
        if (scanf("%d",&num)==1)
        {
            if (num >= minimo && num <= maximo)
            {
                    break;
            }
        }
        printf("%s",mensajeError1);
    }

    *numero=num;
    return resultado;
}

void rellena_Espacio (char caracter,int can_col,int can_fila)
{
    int i=0;
    int j;

    //printf("\n");

    for (i=0; i<can_fila; i++)
    {
        for (j=0; j<can_col; j++)
        {
            printf("%c",caracter);
        }
    //printf("\n");
    }

}
