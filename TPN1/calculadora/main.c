//declaracion de bibliotecas standars
#include <stdio.h>
#include <stdlib.h>
//declaracion de bibliotecas personales
#include ".\operaciones_calc.h"

int main()
{
    //declaracion de variables
    int op1=0, op2=0;
    int res_Suma, res_Resta;
    int res_Multiplicacion;
    int res_Factorial1, res_Factorial2;
    int oper_Calc=0;
    int flag=0;
    int flag_op1=0;
    int flag_op2=0;
    char op1_Carga='N';
    char op2_Carga='N';
    int flag_calculo=0;
    float res_Division;

    while (flag==0) //bucle hasta que el usuario lo desee
    {
        system("cls");

        //Muestra un menu y solicita que se seleccione una opcion
        printf(" 1- Ingrese Operando 1: %d  %c",op1,op1_Carga);
        printf("\n 2- Ingrese Operando 2: %d  %c",op2,op2_Carga);
        printf("\n 3- Calcular: ");
        printf("\n 4- Muestra Calculos: ");
        printf("\n 5- Salida: ");

        fflush(stdin);

        printf(" \nIngrese una Opcion: ");
        scanf("%d",&oper_Calc);
        printf("\n");

        switch(oper_Calc) //segun la seleccion del usuario resulve operaciones matematicas
        {
            case 1: //carga de datos por teclado Operador1

                printf("operando 1: ");
                scanf("%d",&op1);
                flag_op1 = 1;
                op1_Carga='S';
                break;

            case 2: //carga de datos por teclado Operador2

                printf("operando 2: ");
                scanf("%d",&op2);
                flag_op2 = 1;
                op2_Carga='S';
                break;

            case 3: // Realiza cálculos a traves de las funciones

                if (flag_op1 != 1 || flag_op2 !=1 )
                {
                    printf("No se han cargado los 2 Operandos, Ingreselos...\n");
                    system("pause");
                    break;
                }
                else
                {

                    res_Suma=suma(op1,op2); //llama a la funcion suma

                    res_Resta=resta(op1,op2); //llama a la funcion resta

                    res_Multiplicacion=multiplicacion(op1,op2);  // llama a la funcion multiplicacion


                    if (op2!=0)   // funcion Division
                    {
                        res_Division=division(op1,op2);
                    }
                    else
                    {
                        printf("error, no se puede dividir por 0 \n");
                        system("pause");
                        res_Division=0.00;
                    }

                    if (op1 >= 0)   // funcion factorial...
                    {
                        res_Factorial1=factorial(op1);  // llama a la funcion factorial
                        res_Factorial2=factorial(op2);  // llama a la funcion factorial

                    }
                    else
                    {
                        printf("error, No se puede realizar el factorial... Operando1 es negativo \n");
                        system("pause");
                    }

                    printf("\nTermino el proceso de Calculo...\n");
                    flag_op1=0;
                    flag_op2=0;

                    flag_calculo=1;

                    system("pause");

                    break;
                }

            case 4: // Imprime por pantalla los resultados de los cálculos

                if (flag_calculo == 1)
                    {
                        printf("El resultado de la Suma es............ : %d\n",res_Suma);
                        printf("El resultado de la Resta es........... : %d\n",res_Resta);
                        printf("El resultado de la Multiplicacion es.. : %d\n",res_Multiplicacion);
                        if (op2!=0)
                        {
                            printf("El resultado de la Division es........ : %.2f\n",res_Division);
                        }
                        else
                        {
                            printf("El resultado de la Division es........ : %.2f Error\n",res_Division);
                        }
                        printf("El resultado del Factorial 1 es....... : %d\n",res_Factorial1);
                        printf("El resultado del Factorial 2 es....... : %d\n",res_Factorial2);
                        system("pause");
                        op1=0;
                        op2=0;
                        op1_Carga='N';
                        op2_Carga='N';
                        flag_calculo = 0;

                    }
                else
                    {
                        printf("No se ha realizado el calculo...\n");
                        system("pause");
                    }

                break;

            case 5:  //Salida del bucle

                flag=1;
                break;

            default : //mensaje de error, opcion invalida

                printf("No ha ingresado una opcion correcta, reintente...\n");
                system("pause");

        }


    }

    return 0;

}
