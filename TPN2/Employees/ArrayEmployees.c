#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>

#include "./ArrayEmployees.h"
#include "./misFunciones.h"



int initEmployees(Employee* list, int len)
{
    int i;
    //int j=0;
    int signed resul=0;

    for (i=0; i<len; i++)
    {
        list[i].isEmpty=1;
        list[i].id=0;
    }

    if (i!=len)
    {
        resul=-1;
    }

return resul;
}

int addEmployee(Employee* list, int len, int id, char name[],char lastName[],float salary,int sector)
{
    char res_Alta2;
    int id_reg;
    int r=0;
    int i=0;
    int signed resul;

    r=id_reg=findFirstAvailable(list,len);
    i=r;
    if (i>len)
    {
        printf("Error... No hay registros disponibles para dar de Alta");
        resul=-1;
        system("pause");
    }

    res_Alta2=getChar2("\n\nPresione una tecla para Grabar / <Esc> NO GRABA");

    if (res_Alta2!=27)
    {
        list[i].id=id;
        strcpy(list[i].name,name);
        strcpy(list[i].lastName,lastName);
        list[i].salary=salary;
        list[i].sector=sector;
        list[i].isEmpty=0;
        resul=0;
    }
    else
    {
        getChar("\nNo fue posible dar el Alta...");
        resul=0;
    }

return resul;
}



int findEmployeeById(Employee* list, int len,int id)
{
    int signed resul=-1;
    int i;

    for (i=0; i<len; i++)
    {
        if (id==list[i].id && list[i].isEmpty==0)
        {
            resul=i;
            break;
        }
    }

    return resul;
}

int removeEmployee(Employee* list,Sector* sec,int len,int len2)
{
    int i;
    char opc;
    int r=0;
    int r2=0;
    int flagSalida=0;
    int idE;

    Employee emp;

    do{
        r2=isAvailable(list,len);

        if (r2>len){

            r2=validaciones(r2,7);//se refiere a Reg Vacio
            flagSalida=1;
            r=-1;
            system("cls");
            break;
        }
        system("cls");
        getChoiceForm("Baja de Empleados",1,78);

        r2=getInt(&idE,"Ingrese Id (1-1000): ","Error Numero invalido, verifique el rango",1,1000);

        r=findEmployeeById(list,len,idE);

        if (r<0){

            r=validaciones(r,5); //se refiere a busqueda de Empleados
            continue;
        }
        i=r;

        emp=llenaEmployee(list,emp,idE,len);

        r2=MuestraUnEmployee(emp,sec,idE,len,len2);

        if (r2<0){
            validaciones(r2,5);
            r=-1;
            flagSalida=1;
        }

        rellena_Espacio('*',78,1);
        getChoiceForm("ADVERTENCIA, Verifique los datos antes de proceder",1,78);
        getChoiceForm("Ultime los esfuerzo y Cerciorese antes de continuar",1,78);
        rellena_Espacio('*',78,1);

        opc=getChar2("\n\nTecla <B> Para Borrar / Cualquier Otra Tecla sale sin Borrar");

        if (opc!='B' && opc!='b'){

            getChar2("\n\nRegistro \"NO\" Borrado, una tecla para continuar");
            r=0;
            break;;
        }
        else
        {
            fflush(stdin);
            opc=getChar2("\n\nEsta Seguro? S / Otra Tecla sale sin Borrar");

            if (opc=='s' || opc=='S'){
                list[i].isEmpty=1;
                getChar2("\n\nEl Registro ha sido borrado, una tecla para continuar");
                r=0;
                break;
            }
            r=0;
            flagSalida=1;

        }

    }while(flagSalida==0);

 return r;
}

int sortEmployees(Employee* list2,int len, int order)

{
    int i;
    int j;
    int res=-1;

    Employee emp;

    if(order==1)
    {
        for(i=0; i<len-1; i++)
        {
            if (list2[i].isEmpty==1)
            {
                continue;
            }
                for(j=i+1; j<len; j++)
                {

                    if (strcmp(list2[i].lastName,list2[j].lastName)<0)
                    {
                        emp=list2[i];
                        list2[i]=list2[j];
                        list2[j]=emp;
                    }

                    if (strcmp(list2[i].lastName,list2[j].lastName)==0)
                    {
                        if (list2[i].sector<list2[j].sector)
                        {
                        emp=list2[i];
                        list2[i]=list2[j];
                        list2[j]=emp;

                        }


                    }

                }

        }

    }
    else
    {
        for(i=0; i<len-1; i++)
        {
            if (list2[i].isEmpty==1)
            {
                continue;
            }
                for(j=i+1; j<len; j++)
                {

                    if (strcmp(list2[i].lastName,list2[j].lastName)>0)
                    {
                        emp=list2[i];
                        list2[i]=list2[j];
                        list2[j]=emp;
                    }

                    if (strcmp(list2[i].lastName,list2[j].lastName)==0)
                    {
                        if (list2[i].sector>list2[j].sector)
                        {
                        emp=list2[i];
                        list2[i]=list2[j];
                        list2[j]=emp;

                        }
                    }
                }
        }
    }
    return res;
}

int printEmployees(Employee* list,Sector* sec,int len,int lenS)
{
    int i;
    printf("\n\tId \tNombre \tApellido  \tSalario \tSector \n");
    rellena_Espacio('-',78,1);

    for (i=0;i<len;i++)
    {

        if (list[i].isEmpty!=1)
        {
            printOneEmployees(list[i],sec,len,lenS);
        }
    }
 printf("\n\n");
 return 0;
}



