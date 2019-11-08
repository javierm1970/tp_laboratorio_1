
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>

#include "./ArrayEmployees.h"
#include "./misFunciones.h"

void miFgets(char array[], int tamano)
{

    int cant=0;
    fflush(stdin);

    fgets(array, tamano, stdin);

    cant = strlen(array);
    array[cant-1] = '\0';

}

void miLtrim (const char array_entrada[], char array_salida[])
{
    int i,j=0,inicioCadena=0;
    int tamano=strlen(array_entrada);
    char aux[tamano];
    aux[0]='\0';

    for (i=0; array_entrada[i]!='\0' ; i++)
    {

        if (array_entrada[i]!=' ' || inicioCadena !=0)
            {
                aux[j] = array_entrada[i];
                j++;
                inicioCadena = 1;
            }
    }

    aux[j++]='\0';
    strcpy(array_salida,aux);
}

void miRtrim (const char array_entrada[], char array_salida[])
{
    int i;
    int tamano=strlen(array_entrada);

    for (i=tamano; i>=0 ; i--)
    {
        if (array_entrada[i]!=' ' && array_entrada[i]!='\0' )
            {
                array_salida[i+1] = '\0';
                break;
            }
    }
}

void mi_Trim (const char array_entrada[], char array_salida[])
{
    int i,j=0,inicioCadena=0;
    int tamano=strlen(array_entrada);
    char aux[tamano];

    //Empieza Ltrim
    for (i=tamano; i>=0 ; i--)
    {
        if (array_entrada[i]!=' ' && array_entrada[i]!='\0' )
            {
                array_salida[i+1] = '\0';
                break;
            }
    }
    //Empieza Rtrim

    aux[0]='\0';

    for (i=0; array_entrada[i]!='\0' ; i++)
    {
        if (array_entrada[i]!=' ' || inicioCadena !=0)
            {
                aux[j] = array_entrada[i];
                j++;
                inicioCadena = 1;
            }
    }
    aux[j++]='\0';
    strcpy(array_salida,aux);

    //Empieza quitar los espacio en medio

    aux[0]='\0';
    inicioCadena=0;
    j=0;

    for (i=0; array_entrada[i]!='\0' ; i++)
    {
        if (inicioCadena==0)
        {
            aux[j] = array_entrada[i];
            j++;
            inicioCadena = 1;

        } else if (array_entrada[i]!=' ' || array_entrada[i-1]!= ' ')
            {
                aux[j] = array_entrada[i];
                j++;
            }
    }
    aux[j++]='\0';
    strcpy(array_salida,aux);
}


float getFloat(float *numero,char mensaje1[],char mensajeError1[],int minimo,int maximo)
{
    float num;
    //int cant;
    int flagSalida=0;
    int resultado=0;

    printf("%s",mensaje1);
    while(flagSalida==0)
    {

        fflush(stdin);
        if (scanf("%f",&num)==1)
        {
            if (num >= minimo && num <= maximo)
            {
                    break;
            }
        }
        //fflush(stdin); //EN LINUX UTILIZAR __fpurge(stdin)
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


char getChar(char mensaje[])
{
    char auxiliar;
    printf("%s",mensaje);
    fflush(stdin);
    scanf("%c",&auxiliar);
    return auxiliar;
}


char getChar2(char mensaje[])
{
    char auxiliar;
    printf("%s",mensaje);
    fflush(stdin);
    auxiliar=getch();
    return auxiliar;
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

void getString(char mensaje[],char input[],int tamano)
{
    printf("%s",mensaje);
    fflush(stdin);
    miFgets(input,tamano);

    //scanf ("%[^\n]s", input);
}

int esNumerico(char str[])
{
    int i=0;
    int resultado=0;
    int cant = strlen(str);

    for(i=0; i<cant; i++)
        {
            if(!isdigit(str[i]))
            {
                resultado=1;
                break;
            }
        }

return resultado;
}

int esNumericoFlotante(char str[])
{
    int i=0;
    int resultado=1;
    int cant = strlen(str);
    int cantPunto=0;

    for(i=0; i<cant; i++)
        {
            if (str[i]!='.')
            {
                if(!isdigit(str[i]))
                {
                    resultado=0;
                    break;
                }
             }
             else
             {
                 cantPunto++;
                 if (cantPunto>1)
                 {
                    resultado=0;
                    break;
                 }
             }
        }

return resultado;
}

int esAlfaNumerico(char str[])
{
   int i=0;
   while(str[i] != '\0')
   {
       if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z') && (str[i] < '0' || str[i] > '9'))
           return 0;
       i++;
   }
   return 1;
}

int findSectorByDesc (Sector* list,int len,int id,char resul[])
{
    int i;
    int r=0-1;

    for (i=0; i<len; i++)
    {
        if (id==list[i].id3)
        {
            strcpy(resul,list[i].descripcion3);
            r=0;
            break;
        }
    }
    return r;
}

int findSectorById (Sector* list, int len,int id)
{
    int resul;
    int i;
    int flagFinal=0;

    for (i=0; i<len; i++)
    {
        if (id==list[i].id3)
        {
            resul=list[i].id3;
            flagFinal=1;
            break;
        }
    }

    if (flagFinal==0)
    {
        resul=-1;
    }


    return resul;
}

int findFirstAvailable(Employee* list, int len)
{
    int i;
    int resul=0;
    int flagSalida=0;

    for (i=0; i<len; i++)
    {
        if (list[i].isEmpty==1)
        {
            flagSalida=1;

            break;
        }
    }
    resul=i;

    if (flagSalida==0){

        resul=1010;
    }

    return resul;
}

int findEmpty2(Employee* list, int len)
{
    int i;
    int maxId=0;

    for (i=0; i<len; i++)
    {

        if (list[i].id>maxId)
        {
            maxId=list[i].id;
        }
    }
    maxId++;


return maxId;
}


int findEmpty(Employee* list, int len)
{
    int i;

    for (i=(len); i>=0; i--)
    {

        if (list[i].isEmpty==0)
        {

            printf("%d",i);
            break;
        }
    }
    i=i+1;

    if (i>len || i<0){
        i=-1;
    }

    return i;
}

int isAvailable(Employee* list, int len)
{
    int resul;
    int i;
    int flagFinal=0;

    for (i=0; i<len; i++)
    {
        if (list[i].isEmpty==0)
        {
            flagFinal=1;
            break;
        }
    }
    resul=i+1;
    if (flagFinal==0)
    {
        resul=1010; //Marco errro de excedido...
    }

    return resul;
}

Employee carga_Employees(Sector* list,Employee empleados3,int len,int lenSector,int id)
{

    int r;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty=0;
    char descrip[60];
    int valida_nom;
    int valida_ape;
    int valida_sector;

    system("cls");

    getChoiceForm("Alta de Empleados",1,78);

    printf("\nId de Empleado: %d\n",id);

    do{
        getString("ingrese un nombre(50): ",name,51);
        valida_nom=esAlfaNumerico(name);
        if (valida_nom) break;
        printf("Contiene caracteres no permitidos, reintente... ");
    }while (valida_nom!=1);
    do{
        getString("ingrese un apellido(50): ",lastName,51);
        valida_ape=esAlfaNumerico(name);
        if (valida_ape) break;
        printf("Contiene caracteres no permitidos, reintente... ");
    }while (valida_ape!=1);

    fflush(stdin);
    getFloat(&salary,"Ingrese Salario(hasta  10,000,000.00): ",
                     "Error Salario(hasta  10,000,000.00) ",0,10000000);

    muestra_Sector(list,"Sectores de la Empresa",5,78);

    do{
        fflush(stdin);
        getInt(&sector,"Ingrese Codigo de sector: ","Error el Sector NO Existe ",1,5);

        r=findSectorByDesc(list,lenSector,sector,descrip);

        r=validaciones(r,2);
        if (r){
            continue;
        }
        printf("%s",descrip);
        valida_sector=1;

     }while(valida_sector!=1);

        empleados3.id=id;
        strcpy(empleados3.name,name);
        strcpy(empleados3.lastName,lastName);
        empleados3.salary=salary;
        empleados3.sector=sector;
        empleados3.isEmpty=isEmpty;

return empleados3;
}

void Muestra_Employees(Employee* list,int len,int len2,int id,char S[])
{
    int i;

    //int cod_Sector;

    for (i=0; i<len; i++)
    {
        if (list[i].id==id && list[i].isEmpty==0)
        {
            //cod_Sector=list[i].sector;
            break;
        }
    }

    printf("\nId                 : %d",list[i].id);
    printf("\nNombre             : %s",list[i].name);
    printf("\nApellido           : %s",list[i].lastName);
    printf("\nSalario            : %.2f",list[i].salary);
    printf("\nCod Sector         : %d %s",list[i].sector,S);

}
int capturaIdSector (Employee* list, int len,int id)
{
    int signed resul;
    int i;
    int flagFinal=0;

    for (i=0; i<len; i++)
    {
        if (id==list[i].id && list[i].isEmpty==0)
        {
            resul=list[i].sector;
            flagFinal=1;
            break;
        }
    }

    if (flagFinal==0)
    {
        resul=-1;
    }

    return resul;
}

char * capturaDescSector (Sector* list, int len,int id)
{
    char *resul;
    int i;
    int flagFinal=0;


    for (i=0; i<len; i++)
    {
        if (id==list[i].id3)
        {
            resul=list[i].descripcion3;
            flagFinal=1;
            break;
        }
    }

    if (flagFinal==0)
    {
        system("pause");
        //resul='';
    }

    return resul;
}

char muestra_Sector(Sector opc[],char titulo[],int cantidad,int tamano)
{
    int i;
    int margen;
    int margen2;

    margen=((tamano-2)-(strlen(titulo)))/2;

    rellena_Espacio('*',tamano,1);
    printf("\n");

    rellena_Espacio('*',margen,1);
    printf(" %s ",titulo);
    rellena_Espacio('*',margen,1);

    printf("\n");
    rellena_Espacio('*',tamano,1);
    printf("\n");

        for (i=0; i<cantidad; i++)
        {
            margen2=((tamano-4)-(strlen(opc[i].descripcion3)))/2;
            rellena_Espacio('*',margen2,1);
            printf("   %s  ",opc[i].descripcion3);
            rellena_Espacio('*',margen2,1);
            printf("\n");

        }
    rellena_Espacio('*',tamano,1);
    printf("\n");
    //rellena_Espacio('*',LENMENU,1);
    //printf("\n");

    return 0;
}
char getChoice(Menu opc[],char titulo[],int CANT,int LENMENU)
{
    char auxiliar;
    int i;
    int margen;
    int margen2;

    margen=((LENMENU-2)-(strlen(titulo)))/2;

    rellena_Espacio('*',LENMENU,1);
    printf("\n");

    rellena_Espacio('*',margen,1);
    printf(" %s ",titulo);
    rellena_Espacio('*',margen,1);

    printf("\n");
    rellena_Espacio('*',LENMENU,1);
    printf("\n");

        for (i=0; i<CANT; i++)
        {
            margen2=((LENMENU-4)-(strlen(opc[i].descripcion)))/2;
            rellena_Espacio('*',margen2,1);
            printf("   %s  ",opc[i].descripcion);
            rellena_Espacio('*',margen2,1);
            printf("\n");

        }
    rellena_Espacio('*',LENMENU,1);
    printf("\n");
    rellena_Espacio('*',LENMENU,1);
    printf("\n");

    fflush(stdin);
    auxiliar=getChar2("\nIngrese una Opcion / <Esc> Salir ");

    return auxiliar;
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

char menuImpresionint(Employee emp[],int len,Menu menu_sec[],int lenM2)
{
    char opc;
    char opcion;
    char opcion2;
    int flagSalida=0;
    int flagSalida2=0;

    do{
        flagSalida=0;
        system("cls");

        opcion=getChoice(menu_sec,"   I N F O R M E S  ",lenM2,78);


        switch (opcion)
        {
            case '1':

                opcion2=getChar2("\n 1- Forma Ascendente  \n 2- Forma Descendente\n");
                printf("\n");
                //menu1

                do{

                    switch (opcion2){

                        case '1':
                            opc='1';
                            flagSalida2=1;
                            flagSalida=1;
                            //menu2 1
                            //getChar2("Informe de Empleados (Ascendente)");
                            break;

                        case '2':
                            flagSalida2=1;
                            flagSalida=1;
                            opc='2';
                            //menu2 2
                            //getChar2("Informe de Empleados (Descendente)");
                            break;

                        default:
                            //getChar2("Opcion invalida, reintente");
                            continue;
                    }

                }while (flagSalida2==0);
                break;

            case '2':
                //getChar2("\nse realizan los calculos para los totales");
                flagSalida=1;
                opc='3';
                // menu 2
                break;

            case 27:
                opc='S';
                flagSalida=1;
                break;

            default:
                continue;
                break;
        }

    }while(flagSalida==0);

  return opc;
}

int printOneEmployees(Employee list,Sector* sec,int len,int lenSector)
{
    int r;
    char descrip[60];

    r=findSectorByDesc(sec,lenSector,list.sector,descrip);

    if (r==-1){
        strcpy(descrip,"sector no encontrado");
    }

    printf("\n\t%d \t%s \t%s \t\t%.2f \t\t%s ",list.id,
           list.name,list.lastName,list.salary,descrip);

    return 0;
}

int validaciones(int signed codigo,int codFun)
{

     switch (codFun){

        case 0:
            //ok para cualquier funcion...
            break;

        case 1:
            if (codigo==-1){

                getChar2("\nError de Inicializacion...Comunicarse con IT Support.\n");
            }

            break;

        case 2:
            if (codigo==-1){

                getChar2("\nError...Sector no encontrado, reintente\n");
            }
            break;

        case 3:
            if (codigo==-1){

            getChar2("\nError...Registro lleno o Inconsistencia en los datos\n");
            }
            break;

        case 4:
            if (codigo==-1){

            getChar2("\nError...Fuera de Rango o Numero invalido\n");
            }
            break;

        case 5: //se refiere a Empleado no Encontrado
            if (codigo==-1){

            getChar2("\nRegistro no encontrado...\n");
            }
            break;

        case 6: //se refiere opcion ingresada erronea
            if (codigo==-1){

            getChar2("\nOpcion Incorrecta / Verifique y reintente...\n");
            }
            break;

        case 7: //se refiere Registros de empleados vacio
            if (codigo==1010 || codigo==-1){

            getChar2("\nRegistros esta Vacio...Realice un alta de Empleado para continuar\n");
            }
            break;

        default:

            getChar2("Error Inesperado... Comunicarse con IT Support.");

            break;
    }

    return codigo;
}

int hardCord(Sector sec[],int len)
{
    int res=0;
    int i;

            Sector aux1[5]={{1,"1-Compras       "},
                            {2,"2-Ventas        "},
                            {3,"3-Facturacion   "},
                            {4,"4-Gerencia      "},
                            {5,"5-IT_Support    "}};

    for (i=0;i<len;i++){

         sec[i]=aux1[i];
    }

    return res;
}

int hardCordMen(Menu men[],Menu men2[],int len,int len2)
{
    int res=0;
    int i;
    int j;

            Menu aux1[4]={{1,"1- Altas   "},
                            {2,"2- Bajas   "},
                            {3,"3- Modifica"},
                            {4,"4- Informar"}};

            Menu aux2[4]={{1," 1- Empleados (Alfabetico y por Sector)      "},
                          {2,"                                             "},
                          {3," 2- Totales y Promedios de Salarios,         "},
                          {4,"    Cant. de Empleados que superan la media  "}};

            for (i=0;i<len;i++){

                 men[i]=aux1[i];
            }
            for (j=0;j<len2;j++)
            {
                men2[j]=aux2[j];
            }


    return res;
}

Employee llenaEmployee (Employee employ[],Employee emp,int id,int len)
{
    int i;
    //int r;

    for (i=0;i<len;i++){

        if (id==employ[i].id)
        {
            emp.id=employ[i].id;
            strcpy(emp.name,employ[i].name);
            strcpy(emp.lastName,employ[i].lastName);
            emp.salary=employ[i].salary;
            emp.sector=employ[i].sector;
            emp.isEmpty=employ[i].isEmpty;

            break;

        }

    }

    return emp;
}

int MuestraUnEmployee (Employee emp,Sector sec[],int id,int len,int lenSector)
{
    int r=0;
    char descrip[60];

            printf("\nId: %d",emp.id);
            printf("\nNombre: %s",emp.name);
            printf("\nApellido: %s",emp.lastName);
            printf("\nSalario: %.2f",emp.salary);

            r=findSectorByDesc(sec,lenSector,emp.sector,descrip);
            printf("\nSector: %s",descrip);
            printf("\n");
            r=0;

    return r;
}

int ModificaUnEmployee (Employee employ[],Sector sec[],int len,int lenSector)
{
    int i;
    int idE;
    char opc;
    char opcion2;
    int r=0;
    int r2;
    char descrip[60];
    int flagSalida=0;
    int flagPrimeraVez=0;
    int valida_Nom;
    int valida_Ape;
    int valida_Sector;

    Employee emp;
//********************************
    system("cls");

    r2=isAvailable(employ,len);

    if (r2>len){
        r2=validaciones(r2,7);//se refiere a Reg Vacio
        flagSalida=1;
        r=-1;
        system("cls");
        return -1;
    }

    getChoiceForm("Modifica Empleados",1,78);

    getInt(&idE,"Ingrese Id (1-1000): ","Error Numero invalido, verifique el rango",1,1000);

    r=findEmployeeById(employ,len,idE);

    if (r<0){

        r=validaciones(r,5); //se refiere a busqueda de Empleados
        return 0;
    }
    i=r;
//*****************************************************
    emp=llenaEmployee(employ,emp,idE,len);

    do{

        if (flagPrimeraVez!=0){

            system("cls");
            getChoiceForm("Modifica Empleados",1,78);
            printf("\n");
        }
        flagPrimeraVez=1;

        r=MuestraUnEmployee(emp,sec,idE,len,lenSector);

        printf("\n");
//------------------------------
        printf("\nQue desea modificar?: \n");
        opc=getChar2("1-Nombre / 2-Apellido /3-Salario /4-Sector /5-Salir \n");

        if (opc<'1' && opc>'5'){
            continue;
        }

        switch(opc){

            case '1':

                do{
                    getString("ingrese un nombre(50): ",emp.name,51);
                    valida_Nom=esAlfaNumerico(emp.name);
                    if (valida_Nom) break;
                    printf("Contiene caracteres no permitidos, reintente... ");
                }while (valida_Nom!=1);

                continue;

            case '2':

                do{
                    getString("ingrese un apellido(50): ",emp.lastName,51);
                    valida_Ape=esAlfaNumerico(emp.lastName);
                    if (valida_Ape) break;
                    printf("Contiene caracteres no permitidos, reintente... ");
                }while (valida_Ape!=1);

                continue;

            case '3':

                fflush(stdin);
                getFloat(&emp.salary,"Ingrese Salario(hasta  10,000,000.00): ",
                                 "Error Salario(hasta  10,000,000.00) ",0,10000000);

                continue;
            case '4':

                muestra_Sector(sec,"Sectores de la Empresa",5,78);

                do{
                    fflush(stdin);
                    getInt(&emp.sector,"Ingrese Codigo de sector: ","Error el Sector NO Existe ",1,5);

                    r=findSectorByDesc(sec,lenSector,emp.sector,descrip);

                    r=validaciones(r,2);
                    if (r){
                        continue;
                    }
                    printf("%s",descrip);
                    valida_Sector=1;

                 }while(valida_Sector!=1);

                continue;

            case '5':
                flagSalida=1;
                break;

            default:

                getChar2("Error, Opcion erronea, vuelva a intentarlo...");
                continue;
        }
        opcion2=getChar2("\n\nDesea Guardar los Cambios? S\n");

        flagSalida=1;

        if (opcion2=='s' || opcion2=='S'){

            employ[i]=emp;
            r=0;
        }

     //--------------
     }while(flagSalida==0);

    return r;
}

int salarioPromedio(Employee* list, int len)
{
    int i;
    int j;
    int res=-1;
    float prom=0;
    float promedio=0;
    int empleado=0;
    int supProm=0;

    for (i=0;i<=len;i++)
    {
        if(list[i].isEmpty==0)
        {
            prom = prom + list[i].salary;
            empleado++;

        }
    }
    promedio=prom/empleado;
    printf("\n\n\n");
    printf("\nEl promedio de todos los salarios es: %2.f \n",promedio);
    printf("\nLa suma de todos los salarios es: %2.f \n",prom);
    for (j=0;j<=len;j++)
    {
        if (list[j].isEmpty==0)
        {
            if (list[j].salary>=promedio)
            {
                supProm++;
            }
        }
    }

    printf("\nLa cantidad de empleados que supera el salario promedio es: %d \n\n\n",supProm);
    printf("\n\n\n");
    res=0;

    return res;
}
