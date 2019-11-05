#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
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
    int flagLoadLinkedList=0;

    LinkedList* listaEmpleados = ll_newLinkedList();

    do{
        switch(muestraMenu())
        {
        case 1:

            if(!flagLoadLinkedList)
            {
                r=controller_loadFromText("./data.csv",listaEmpleados);
                validaciones(r,1);
                if (r==1){
                    flagLoadLinkedList=1;
                }
            }
            else
            {
                miPausa("\nExiste un archivo cargado\n");

            }

            break;

        case 2:

            if(!flagLoadLinkedList)
            {
                r=controller_loadFromBinary("./data.bin",listaEmpleados);
                validaciones(r,2);
                if (r==1){
                    flagLoadLinkedList=1;
                }
            }
            else
            {
                miPausa("\nExiste un archivo cargado\n");

            }
            break;

        case 3:

            r=controller_addEmployee(listaEmpleados);
            //addOk=statusAddEmployee(result);
            //if(addOk==1)
            //    flagAdd=1;
            break;

        case 4:

            r=controller_editEmployee(listaEmpleados);
            validaciones(r,4);

            break;

        case 5:

            r=controller_removeEmployee(listaEmpleados);
            validaciones(r,5);
            break;

        case 6:
            r=controller_ListEmployee(listaEmpleados);
            validaciones(r,6);
            break;

        case 7:
            //ll_sort2(listaEmpleados,ordenaPorSalario,1);
            //r=controller_ListEmployee(listaEmpleados);
            r=controller_sortEmployee(listaEmpleados);
            validaciones(r,7);
            break;

        case 8:
            r=controller_saveAsText("./data.csv",listaEmpleados);
            validaciones(r,8);
            if (r==1){
                //ll_deleteLinkedList(listaEmpleados);
                //listaEmpleados=ll_newLinkedList();
            }
            break;

        case 9:
            r=controller_saveAsBinary("./data.bin",listaEmpleados);
            validaciones(r,9);
            if(r==1)
            {
                //ll_deleteLinkedList(listaEmpleados);
                //listaEmpleados=ll_newLinkedList();
            }
            break;

        case 10:
            option=10;
            break;
        }
    }while(option != 10);
    return 0;
}
