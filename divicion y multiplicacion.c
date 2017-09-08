#include <stdio.h>
#include <stdlib.h>

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
