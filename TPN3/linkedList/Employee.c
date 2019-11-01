#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    if (this!=NULL && nombre!=NULL && esSoloLetras(nombre)==0)
    {
        strcpy(this->nombre,nombre);
        r=1;
    }
    return r;
}

int employee_getNombre(Employee* this,char* nombre)
{
    int r=-1;
    if (this!=NULL && this->nombre!=NULL && esSoloLetras(this->nombre)==0)
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





