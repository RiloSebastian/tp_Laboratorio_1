#ifndef VALIDACIONES_H_INCLUDED
#define VALIDACIONES_H_INCLUDED

float set_float(float flt );
int set_integer(int intg );
int set_name(char str[], int len);
int set_string(char str[], int len);
float set_marginFloat(float flt, float min, float max);
int set_marginInt(int intg, int min, int max);

int validar_flotante(char str[], int len);
int validar_entero(char str[],int len);
int validar_alfabetico(char str[], int len);
int validar_alfanumerico(char str[], int len);

#endif // VALIDACIONES_H_INCLUDED
