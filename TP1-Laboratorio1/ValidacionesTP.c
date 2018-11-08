#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>


float validarFlotante(float numero)
{
    float num;
    int i;
    int j=0;
    int retorno;
    char numeroAuxiliar[30];

    do
    {
        fflush(stdin);
        gets(numeroAuxiliar);
        i=strlen(numeroAuxiliar);
        while(j<i)
        {

            if((numeroAuxiliar[j]> 47 && numeroAuxiliar[j]<58) || (numeroAuxiliar[j]>43 && numeroAuxiliar[j]<47))
            {
                retorno= 0;
                j++;
            }
            else
            {
                retorno= 1;
                break;
            }
        }
        if(retorno!=0)
        {
            printf("Error: vuelva a ingresar: ");
        }
    }
    while(retorno!=0);
    num=atof(numeroAuxiliar);
    numero=num;
    return numero;
}

int validarNumero(int numero)
{
    int num;
    int i;
    int j=0;
    int retorno;
    char numeroAuxiliar[30];

    do
    {
        fflush(stdin);
        gets(numeroAuxiliar);
        i=strlen(numeroAuxiliar);
        while(j<i)
        {

            if((numeroAuxiliar[j]> 47 && numeroAuxiliar[j]<58) || (numeroAuxiliar[j]>43 && numeroAuxiliar[j]<47))
            {
                retorno= 0;
                j++;
            }
            else
            {
                retorno= 1;
                break;
            }
        }
        if(retorno!=0)
        {
            printf("Error: vuelva a ingresar: ");
        }
    }
    while(retorno!=0);
    num=atoi(numeroAuxiliar);
    numero=num;
    return numero;
}
