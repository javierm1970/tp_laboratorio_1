#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>

#include "./ArrayEmployees.h"
#include "./misFunciones.h"

#define ELEMENTS 1000
#define CANMENU 4
#define CANMENU2 4
#define LENMENU 78
#define CANSECTOR 5

int main()
{
    Employee employees[ELEMENTS];
    //Employee aux[ELEMENTS];
    Employee empleados;

    Menu menu[CANMENU];
    Menu menu2[CANMENU2];

    Sector sectores[CANSECTOR];

    hardCord(sectores,CANSECTOR);

    hardCordMen(menu,menu2,CANMENU,CANMENU2);

    int r2;
    int id;
    int init=1; //corresponde a la funcion initEmployees
    char opcion;
    char opcion2;
    char opcion4;
    int r;
    int flagSalida=0;
    int flagSalida2=0;
    int flagSalida3=0;
    int flagSalida4=0;

    r=initEmployees(employees,ELEMENTS);
    r=validaciones(r,init);
    if (r<0)return -1;

    do{

        fflush(stdin);
        opcion=getChoice(menu,"ABM de Empleados",CANMENU,LENMENU);
        printf("\n\n");


        switch (opcion){

            case '1':

                do{
                    system("cls");
                    flagSalida2=0;

                    r=findEmpty2(employees,ELEMENTS);
                    id=r;

                    r=validaciones(r,7);//1 refiere a registro lleno
                    if (r>=ELEMENTS){
                        system("cls");
                        break;
                    }
                    empleados=carga_Employees(sectores,empleados,ELEMENTS,CANSECTOR,id);

                    r=addEmployee(employees,ELEMENTS,empleados.id,empleados.name,
                                  empleados.lastName,empleados.salary,empleados.sector);

                    r=validaciones(r,3); //3 referida a funcion addEmployees

                    printf("\n\n");
                    opcion2=getChar2("Presione una tecla para continuar / <Esc> Para salir");

                    if (opcion2==27){
                        flagSalida2=1;
                        system("cls");
                        break;
                    }

                  }while (flagSalida2==0);

                break;

            case '2':

                do{
                    system("cls");
                    flagSalida3=0;

                    r=removeEmployee(employees,sectores,ELEMENTS,CANSECTOR);

                    if (r<0){
                        break;
                    }
                    opcion=getChar2("\n\n<Esc> Para Salir / Una Tecla seguir borrando");

                    if (opcion==27){
                        system("cls");
                        break;
                    }

                }while (flagSalida3==0);

                break;

            case '3':

                do{
                    system("cls");
                    flagSalida=0;

                    r=ModificaUnEmployee(employees,sectores,ELEMENTS,CANSECTOR);

                    if (r<0){
                        break;
                    }
                    opcion2=getChar2("<Esc> Salida / Una Tecla para continuar");

                    if (opcion2==27){
                        r=-1;
                        system("cls");
                        break;
                    }else{
                        r=0;
                        continue;
                    }

                }while (flagSalida==0);

                break;

            case '4':

                do{
                    r2=isAvailable(employees,ELEMENTS);
                    if (r2>ELEMENTS){
                        r2=validaciones(r2,7);//se refiere a Reg Vacio
                        system("cls");
                        break;
                    }

                    fflush(stdin);
                    opcion4=menuImpresionint(employees,ELEMENTS,menu2,CANMENU2);

                    switch(opcion4){

                        case '1':
                            sortEmployees(employees,ELEMENTS,0);
                            system("cls");
                            printEmployees(employees,sectores,ELEMENTS,CANSECTOR);
                            system("pause");
                            break;

                        case '2':
                            sortEmployees(employees,ELEMENTS,1);
                            system("cls");
                            printEmployees(employees,sectores,ELEMENTS,CANSECTOR);
                            system("pause");

                            break;

                        case '3':
                            r=salarioPromedio(employees,ELEMENTS);

                            system("pause");
                            break;

                        case '0':
                            getChar2("\nOopcion erronea vuelva a intentar");
                            system("cls");
                            break;

                        case 'S':
                            getChar2("\nha presionado salida");
                            system("cls");
                            flagSalida4=1;
                        break;

                        default:
                            flagSalida4=1;
                            break;
                    }

                }while(flagSalida4==0);
                break;

            case 27:

                system("cls");
                flagSalida=1;
                break;

            default:

                system("cls");
                break;
         }

    }while(flagSalida==0);

    return 0;
}
