#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "utn.h"
#include "parser.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */

int controller_loadFromText(char* path, LinkedList* pArrayListEmployee)
{
    int r=-1;
    FILE* pFile;

    if(path!=NULL && pArrayListEmployee!=NULL)
    {
        pFile= fopen(path,"r");

        if(pFile!=NULL)
        {
            r=parser_EmployeeFromText(pFile,pArrayListEmployee);
        }
    }

    fclose(pFile);
    return r;
}


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */

int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
    FILE* pFile;
    Employee* auxEmp;
    int size=ll_len(pArrayListEmployee);
    int r=-1;

    int id;
    int hours;
    int salary;

    char name[130];

    if(pArrayListEmployee!=NULL && path!=NULL)
    {
        if(size>0)
        {
            pFile=fopen(path,"w");
            if(pFile!=NULL)
            {
                for(int i=0; i<size; i++)
                {
                    auxEmp=(Employee*)ll_get(pArrayListEmployee,i);
                    employee_getId(auxEmp,&id);
                    employee_getNombre(auxEmp,name);
                    employee_getHorasTrabajadas(auxEmp,&hours);
                    employee_getSueldo(auxEmp,&salary);
                    fprintf(pFile,"%d,%s,%d,%d\n",id,name,hours,salary);
                }
                fclose(pFile);
                r=1;
            }
            else
            {
                 r=0;
            }
        }
    }
    return r;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
    return 1;
}

