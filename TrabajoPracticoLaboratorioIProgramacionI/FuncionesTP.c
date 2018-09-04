#include <stdio.h>
#include <stdlib.h>
#include "ValidacionesTP.h"

float sumar (float numeroUno, float numeroDos)
{
    float resultado=0;
    resultado= numeroUno+numeroDos;
    return resultado;
}

float restar(float numeroUno, float numeroDos)
{
    float resultado=0;
    resultado= numeroUno-numeroDos;
    return resultado;
}

float multiplicar (float numeroUno, float numeroDos)
{
    float resultado=0;
    resultado= numeroUno*numeroDos;
    return resultado;
}

float dividir (float numeroUno, float numeroDos)
{
    float resultado=1;
    resultado= numeroUno/numeroDos;
    return resultado;
}

long int factorial(float numero)
{
    long int resultado=1;
    int operandoEntero;
    int i;

    operandoEntero=(int)numero;
    if(operandoEntero > 0 )
    {
        for(i=operandoEntero; i>=1; i--)
        {
            resultado= resultado*i;
        }
    }
    else if(operandoEntero < 0 )
    {
        resultado= NULL;
    }
    return resultado;
}


