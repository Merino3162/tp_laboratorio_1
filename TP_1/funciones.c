#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int deStringAEntero(char auxiliarString[], float* auxiliarNumero)//la funcion toma por direccion de memoria una char, al terminar, devuelve un float o una 'a' en caso de error.
{
    int i=0;
    int posicionPunto=0;//Si se encuentra un punto, se usara potencia para colocarlo en su lugar.
    float signo=1;
    float resultado=0;
    int flagDePunto=0;
    float auxiliarFlotante=0;
    if( auxiliarString[0] == '\0')//Si el primer digito es la terminacion de la variable, no se introdujeron datos. Error
    {
        return 0;
    }

    if( auxiliarString[0] == '-' ) //Si el primer digito es un -, es un numero negativo.
    {
        //SOLO TOMA EL GUION MEDIO, NO TOMA EL SIGNO - DEL TECLADO NUMERICO. NO ENCONTRE SOLUCION POR MI CUENTA
        signo= -1;
        i++;
    }
    else
    {
        //si no es un signo, ni la terminacion de la variable, comprueba si es un 0.
        if (auxiliarString[0]=='0' && auxiliarString[1]=='\0') //Si es un 0 la primer columna de la cadena, si es el unico digito, es un 0.
        {
            auxiliarNumero=0;
            return 1;
        }
    }

    for(i=0; auxiliarString[i]!= '\0' ; i++)//de no ser ni cero, ni final, comprueba los posibles digitos contando el punto (.) una unica vez y seguida de un numero.
    {
        if(flagDePunto==1)
        {
            posicionPunto++;
        }
        if ( auxiliarString[i]=='.')
        {
            if(flagDePunto==0)
            {
                auxiliarString[i]=0;
                flagDePunto=1;//la bandera en 1 indica que ya hubo un punto. No puede repetirse
            }
            else
            {
                return 0;//En caso de punto por error, retorna 'a'
            }

        }
        else//si el caracter no es ni punto, ni cero, ni menos, ni terminacion, se comprueba:
        {

            if ( auxiliarString[i] <= '9' && auxiliarString[i] >= '0') // si es entre 0 y 9, se lee el codigo ascii correspondiente y se traduce a float
            {

                switch(auxiliarString[i])
                {
                case 48:
                    auxiliarFlotante=0;
                    break;
                case 49:
                    auxiliarFlotante=1;
                    break;
                case 50:
                    auxiliarFlotante=2;
                    break;
                case 51:
                    auxiliarFlotante=3;
                    break;
                case 52:
                    auxiliarFlotante=4;
                    break;
                case 53:
                    auxiliarFlotante=5;
                    break;
                case 54:
                    auxiliarFlotante=6;
                    break;
                case 55:
                    auxiliarFlotante=7;
                    break;
                case 56:
                    auxiliarFlotante=8;
                    break;
                case 57:
                    auxiliarFlotante=9;
                    break;

                }

                resultado=resultado*10 +auxiliarFlotante;//a la sifra anterior, la multiplica por 10 para correr un espacio, se le suma la nueva sifra
            }
            else //en caso de no ser un numero de 0 a 9, se retorna 'a' como error. El while hara comprobar todo de vuelta.
            {
                printf("ingresaste un caracter no valido.");
                return 0;
            }
        }

    }
    if(flagDePunto==1)
    {
        resultado=resultado*signo*(pow(10,-posicionPunto));
        *auxiliarNumero=resultado;

        return 1; // PERO SOLO SE USA LA POTENCIA DE 10 PARA CALCULARLO
    }
    else
    {
        *auxiliarNumero=resultado*signo;
        return 1;
    }
//luego de comprobar que sea valido, se multiplica el resultado por 1 o -1 para saber si es o no negativo.
}//la funcion retorna "resultado" como flotante, multiplicado por signo, al ser flotante por entero, el resultado es flotante.


int tomarNumero (float* numero,char mensaje[])
{
    char auxiliarString[100];
    float auxiliarNumero=0;
    int auxiliarTrue=0;
    int banderaIngreso=0;

    do
    {
        if(banderaIngreso!=0)
        {
            system("color C4");
        }
        printf("\n %s \n",mensaje);
        scanf("%s",auxiliarString);
        auxiliarTrue=deStringAEntero(auxiliarString, &auxiliarNumero);
        banderaIngreso=1;
    }while(auxiliarTrue==0);
    //asigna a numeroA
    *numero=auxiliarNumero;
    system("color F1");
    return auxiliarTrue;
}

int opcionesDeMenu(float numeroA, float numeroB)
{
    int auxReturn=0;

        system ("color F1" );
        system("cls");
        printf("\n     Estas son las opciones disponibles:");
        printf("\n\n     1- Ingresar 1er operando (A = %.2f)\n", numeroA);
        printf("     2- Ingresar 2do operando (B = %.2f)\n", numeroB);
        printf("     3- Calcular la suma (A + B)\n");
        printf("     4- Calcular la resta (A - B)\n");
        printf("     5- Calcular la division ( A / B)\n");
        printf("     6- Calcular la multiplicacion (A x B)\n");
        printf("     7- Calcular el factorial (A!) (NUMERO MAS ALTO: 13) \n");
        printf("     8- Calcular todas las operacione\n");
        printf("     9- Salir\n     ");
        auxReturn=1;

        return auxReturn;
}



