#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float divicion (float ingresoA, float ingresoB)
{
    float total;
    if(ingresoB<0 || ingresoB>0)
    {
        total=ingresoA/ingresoB;
        return total;
    }
    else
    {
        return 0;
    }
}

float factorial(float a)
{
    system ("color F1" );
    a=1;
    int i=1;
    for(i=0; i <= a; i++) //para calcular factorial se necesita un for. Con una funcion retornable se sobrecarga el procesador.
    {
        a=a*i;
    }
    return a;
}

float resta (float ingresoA, float ingresoB)
{
    float total;
    total=ingresoA-ingresoB;
    return total;
}

float suma (float ingresoA, float ingresoB)
{
    float total;
    total=ingresoA+ingresoB;
    printf("3- la suma da = %.2f\n\n\n",total);
    return total;
}

