#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "utn.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/


int main()
{
    int option = 0;
    int r;
    int flagLoadTLinkedList=0;

    LinkedList* listaEmpleados = ll_newLinkedList();

    do{
        switch(muestraMenu())
        {
        case 1:

            if(!flagLoadTLinkedList)
            {
                system("pause");
                r=controller_loadFromText("./data.csv",listaEmpleados);
                //statusLoadFromText(result);
                flagLoadTLinkedList=1;

            }
            else
            {
                printf("\nYa hay un archivo cargado\n");
            }

            break;

        case 8:

            r=controller_saveAsText("dataSave.csv",listaEmpleados);
            if(r==1)
            {
                printf("Se guardo correctamente\n");
                flagLoadTLinkedList=0;
                //flagAdd=0;
                ll_deleteLinkedList(listaEmpleados);
                listaEmpleados=ll_newLinkedList();
            }
            else if(r==-1)
                printf("Error al ejecutar la opcion\n");
            break;

        case 10:
            option=10;
            break;

        }
    }while(option != 10);
    return 0;
}
