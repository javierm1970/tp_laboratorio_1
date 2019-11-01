#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "utn.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile, LinkedList* pArrayListEmployee)
{
    int itsOk=-1;
    int counter;
    char buffer[4][150];

    if(pFile!=NULL && pArrayListEmployee!=NULL)
    {
        Employee* employeeNew;
            while(!feof(pFile))
            {
                counter=fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n] \n",buffer[0],buffer[1],buffer[2],buffer[3]);


                    if(counter==4)
                    {
                        employeeNew=employee_newParametros(buffer[0],buffer[1],buffer[2],buffer[3]);
                        if(employeeNew!=NULL)
                        {
                            ll_add(pArrayListEmployee,employeeNew);
                            itsOk=1;
                        }
                    }

            }
    }
    return itsOk;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{

    return 1;
}
