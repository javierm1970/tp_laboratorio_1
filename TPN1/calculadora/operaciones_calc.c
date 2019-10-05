//incluir bibliotecas
#include <stdio.h>
#include <stdlib.h>


//función suma (ingresan 2 parametros int el segundo se suma al primero)
//devuelve el resultado int
int suma(int operando1, int operando2)
{
    int resultado;
    resultado = operando1 + operando2;
    return resultado;
}

//función resta (ingresan 2 parametros el segundo se resta al primero)
//devuelve el resultado int
int resta(int operando1, int operando2)
{
    int resultado;
    resultado = operando1 - operando2;
    return resultado;
}

//función multiplicacion  (ingresan 2 parametros el segundo multiplica al primero
//devuelve el resultado int
int multiplicacion(int operando1, int operando2)
{
    int resultado;
    resultado = operando1 * operando2;
    return resultado;
}

//función division (ingresan 2 parametros int el segundo divide al primero
//devuelve el resultado float
float division(int operando1, int operando2)
{
    float resultado;
    resultado = (float) operando1 / operando2;
    return resultado;
}

//función Factorial (ingresa un parametro int
//Devuelve el Resultado (int)
//que surge de multiplicar sucesivamente una variable 'resultado'
//que inicia con el valor del operando recibido
//por otra variable que se incrementa en 1 hasta llegar al valor del (Operando - 1)

int factorial (int operando1)
{
    int res,i;

    if (operando1 == 0)
        {
            res = 1;
        }
    else
        {

        res = operando1;

        for (i = 1; i < operando1; i ++)
            {
                res = res * i;

            }

        }

    return res;
}
