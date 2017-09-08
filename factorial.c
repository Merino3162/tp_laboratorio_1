#include <stdio.h>
#include <stdlib.h>

float factorial(float a)
{
    system ("color F1" );
    float resultado=1;
    int i=1;
    for(i; i <= a; i++) //para calcular factorial se necesita un for. Con una funcion retornable se sobrecarga el procesador.
    {
        resultado=resultado*i;
    }
    return resultado;
}
