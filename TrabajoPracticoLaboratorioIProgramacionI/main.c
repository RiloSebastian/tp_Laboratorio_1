#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "FuncionesTP.h"
#include "ValidacionesTP.h"

int main()
{
    float operandoA=0;
    float operandoB=0;
    int opcion=0;
    float resultadoSuma;
    float ResultadoResta;
    float resultadoMultiplicacion;
    float resultadoDivision;
    long int resultadoFactorialUno;
    long int resultadoFactorialDos;

    do
    {
        printf("\n 1.Ingresar primer operando (A=%.2f)\n",operandoA);
        printf(" 2.Ingresar segundo operando (B=%.2f)\n",operandoB);
        printf(" 3.Calcular todas las operaciones\n");
        printf("   a) Calcular la suma (A+B)\n");
        printf("   b) Calcular la resta (A-B)\n");
        printf("   c) Calcular la multiplicacion (A*B)\n");
        printf("   d) Calcular la division (A/B)\n");
        printf("   e) Calcular el factorial (A!) *los numero flotantes se castearan a enteros\n");
        printf(" 4.Informar todos los resultados \n");
        printf("   a) El resultado de  A+B  es: r\n");
        printf("   b) El resultado de  A-B  es: r\n");
        printf("   c) El resultado de  A*B  es: r\n");
        printf("   d) El resultado de  A/B  es: r\n");
        printf("   e) El factorial de A! es: r1 y El factorial de B! es: r2 \n");
        printf(" 5.Salir\n");
        printf(" opcion: ");

        opcion=validarNumero(opcion);
        switch(opcion)
        {
        case 1:
            printf("\n ingrese el operando A\n ");
            operandoA=validarFlotante(operandoA);
            break;
        case 2:
            printf("\n ingrese el operando B\n ");
            operandoB=validarFlotante(operandoB);
            break;
        case 3:
            resultadoSuma=sumar(operandoA,operandoB);
            ResultadoResta=restar(operandoA,operandoB);
            resultadoMultiplicacion=multiplicar(operandoA,operandoB);
            resultadoDivision=dividir(operandoA,operandoB);
            resultadoFactorialUno=factorial(operandoA);
            resultadoFactorialDos=factorial(operandoB);
            printf(" Calculos realizados\n");
            break;
        case 4:
            printf("\n El resultado de %.2f + %.2f es: %.2f\n",operandoA,operandoB,resultadoSuma);
            printf("\n El resultado de %.2f - %.2f es: %.2f\n",operandoA,operandoB,ResultadoResta);
            printf("\n El resultado de %.2f * %.2f es: %.2f\n",operandoA,operandoB,resultadoMultiplicacion);
            printf("\n El resultado de %.2f / %.2f es: %.2f\n",operandoA,operandoB,resultadoDivision);
            printf("\n El factorial de %.f! es: %d y El factorial de %.f! es: %d\n",operandoA,resultadoFactorialUno,operandoB,resultadoFactorialDos);
            break;
        case 5:
            break;
        default :
            printf("esta opcion no existe \n");
            break;
        }
    }
    while(opcion != 5);
    return 0;
}
