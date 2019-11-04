#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "LinkedList.h"
#include "Employee.h"
#include "utn.h"


Employee* employee_new()
{
    Employee* this=(Employee*) malloc(sizeof(Employee));
    return this;
}

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldo)
{
    int rIdStr;
    int rNomStr;
    int rHTStr;
    int rSuel;

    Employee* this;
    if (idStr!=NULL && nombreStr!=NULL && horasTrabajadasStr!=NULL && sueldo !=NULL)
    {
        this=employee_new();
        if (this!=NULL)
        {
            rIdStr=employee_setId(this,atoi(idStr)),
            rNomStr=employee_setNombre(this,nombreStr);
            rHTStr=employee_setHorasTrabajadas(this,atoi(horasTrabajadasStr));
            rSuel=employee_setSueldo(this,atoi(sueldo));

            if (!rIdStr || !rNomStr || !rHTStr || !rSuel)
            {
                free(this);
                this=NULL;
            }
        }
    }
    return this;
}

void employee_delete()
{

}



int employee_setId(Employee* this,int id)
{
    int r=-1;
    if (this!=NULL && id>0)
    {
        this->id=id;
        r=1;
    }
    return r;
}


int employee_getId(Employee* this,int* id)
{
    int r=-1;
    if (this!=NULL && this->id>0)
    {
        *id=this->id;
        r=1;
    }
    return r;
}



int employee_setNombre(Employee* this,char* nombre)
{
    int r=-1;

    if (this!=NULL && nombre!=NULL && esSoloLetras(nombre)==1)
    {
        strcpy(this->nombre,nombre);
        r=1;
    }
    return r;
}

int employee_getNombre(Employee* this,char* nombre)
{
    int r=-1;
    if (this!=NULL && this->nombre!=NULL && esSoloLetras(this->nombre)==1)
    {
        strcpy(nombre,this->nombre);
        r=1;
    }
    return r;
}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
    int r=-1;
    if (this!=NULL && horasTrabajadas>=0)
    {
        this->horasTrabajadas=horasTrabajadas;
        r=1;
    }
    return r;
}
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
    int r=-1;
    if (this!=NULL && this->horasTrabajadas>=0)
    {
        *horasTrabajadas=this->horasTrabajadas;
        r=1;
    }
    return r;
}

int employee_setSueldo(Employee* this,int sueldo)
{
    int r=-1;
    if (this!=NULL && sueldo>=0)
    {
        this->sueldo=sueldo;
        r=1;
    }
    return r;
}
int employee_getSueldo(Employee* this,int* sueldo)
{
    int r=-1;
    if (this!=NULL && this->sueldo>=0)
    {
        *sueldo=this->sueldo;
        r=1;
    }
    return r;
}

void muestraEmpleados(LinkedList* pArrayLinkedList)
{
    int j=0;

    if(pArrayLinkedList!=NULL)
    {
        for(int i=0;i<ll_len(pArrayLinkedList);i++)
        {
            if (j==19)
            {
                miPausa("Una tecla para continuar... ");
                j=0;
            }
            j++;

            muestraUnEmpleado((Employee*) ll_get(pArrayLinkedList,i));
        }
        printf("\n\n");
    }
}


void muestraUnEmpleado(Employee* emp)
{
    if(emp!=NULL)
    printf("\t%5d  %s               \t%s \t%4d  \t%6d\n",emp->id,emp->nombre," ",emp->horasTrabajadas,emp->sueldo);
}
/*
void ll_sort2(LinkedList* pArrayLinkedList, int ord)
{
    int i=-1;
    int j;
    int r;
    int len;
    int flagNoEstaOrdenado = 1;
    //Clientes aux;
    Employee* p1;
    Employee* p2;
    //Employee* aux;

    LinkedList* lista=ll_clone(pArrayLinkedList);
    len=ll_len(pArrayLinkedList);
    printf("%d",len);
    miPausa("");

    while (flagNoEstaOrdenado==1)
    {
        flagNoEstaOrdenado = 0;

        for (j = 1; j < len; j++)
	    {
            i++;
            //p1=((Employee* ) ll_get(pArrayLinkedList,j))
            p2=((Employee* ) ll_get(pArrayLinkedList,i));
            p1=((Employee* ) ll_get(pArrayLinkedList,j));

            printf("\n%d     %s     %d   %s     %d",p1->id, p1->nombre,p2->id,p2->nombre,i);
            miPausa("");
            if(p1->id>p2->id)
	        {
                r=employee_setId(p1,p2->id),
                r=employee_setNombre(p1,p2->nombre);
                r=employee_setHorasTrabajadas(p1,p2->horasTrabajadas);
                r=employee_setSueldo(p1,p2->sueldo);

                flagNoEstaOrdenado = 1;
            }
        }
        i=-1;
     }
     //aux=NULL;
}
*/

int ordenaPorId(void* emp1, void* emp2)
{
    int retorno=0;
    Employee* p1;
    Employee* p2;

    if(emp1 != NULL && emp2 != NULL)
    {
        p1=(Employee*) emp1;
        p2=(Employee*) emp2;


        if(p1->id > p2->id)
            retorno = 1;
        else if(p1->id < p2->id)
            retorno=-1;
        else
            retorno=0;
    }
    return retorno;
}


int ordenaPorNombre(void* emp1, void* emp2)
{
    int retorno=0;
    Employee* p1;
    Employee* p2;

    if(emp1 != NULL && emp2 != NULL)
    {
        p1=(Employee*) emp1;
        p2=(Employee*) emp2;

        if(strcmp(p1->nombre,p2->nombre)==-1)
            retorno = 1;
        else if(strcmp(p1->nombre,p2->nombre)==1)
            retorno=-1;
        else
            retorno=0;
    }
    return retorno;
}

int ordenaPorHorasTrabajadas(void* emp1 , void* emp2)
{
    int retorno=0;
    Employee* p1;
    Employee* p2;

    if(emp1 != NULL && emp2 != NULL)
    {
        p1=(Employee*) emp1;
        p2=(Employee*) emp2;

        if(p1->horasTrabajadas > p2->horasTrabajadas)
            retorno = 1;
        else if(p1->horasTrabajadas < p2->horasTrabajadas)
            retorno=-1;
        else
            retorno=0;
    }
    return retorno;
}

int ordenaPorSalario(void* emp1, void* emp2)
{
    int retorno=0;
    Employee* p1;
    Employee* p2;

    if(emp1 != NULL && emp2 != NULL)
    {
        p1=(Employee*) emp1;
        p2=(Employee*) emp2;

        if(p1->sueldo > p2->sueldo)
            retorno = 1;
        else if(p1->sueldo < p2->sueldo)
            retorno=-1;
        else
            retorno=0;
    }
    return retorno;
}


