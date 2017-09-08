#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include "operaciones.h"


int main()
{
    system ("color F1" );
    /*                                   ┌  0 = Negro       8 = Gris
                     ^                   |  1 = Azul        9 = Azul claro
                     |                   |  2 = Verde       A = Verde claro
                     |---------------->  |  3 = Aguamarina  B = Aguamarina claro
                     |                   |  4 = Rojo        C = Rojo claro
                 system("color AB")      |  5 = Púrpura     D = Púrpura claro
                da colo a la consola :   |  6 = Amarillo    E = Amarillo claro
                    A=consola.           └  7 = Blanco      F = Blanco brillante
                    B=letras.                                                   */
    char seguir='s';
    int opcion=0;
    float auxOpcion=0;
    float numeroA=0; //cargo la opcion 1;
    float numeroB=0; //cargp la opcion 2;
    float total=0;   //realizo las operaciones segun la opcion introducida, cargo la variable total.
    int flagA=0;   //bandera de opcion 1;
    int flagB=0;   //bandera de opcion 2;
    printf("\n\n              Bienvenido a la calculadora!!)\n\n   ");

    system("pause");

    while(seguir=='s')
    {
        system("cls");
        opcionesDeMenu( numeroA, numeroB);
        if (tomarNumero(&auxOpcion,"ingresa una opcion"))
        opcion=(int)auxOpcion;
        switch(opcion)
        {
        case 1:                //case 1: tomar valores para A y validarlos.
            fflush(stdin);
            tomarNumero(&numeroA,"ingrese el numero A");
            flagA=1;
            break;
        case 2:                 //case 2: Tomar valores para B y validarlos.
            fflush(stdin);
            tomarNumero(&numeroB,"ingrese el numero B");
            flagB=1;
            system ("color F1" );
            break;
        case 3:   //case 3: Suma los terminos A y B;
            system("cls");//borramos todo el contenido de la coonsola.
            if(flagA==0 && flagB==0)
            {
                //las banderas bajas indican que no se introducieron valores a las variables.
                printf("primero debe ingresar los dos numeros\n");
                system ("color C4" );//caso de error, cambia el color en la consola.
                system("pause");
                break;
            }
            else
            {
                total=suma(numeroA, numeroB);
                system ("color F1" );
            }
            system("pause");//se pausa el sistema para poder mostrar valores.
            break;
        case 4:                  //Resta de A - B; Solo si hay valores agregados.
            system("cls");
            if(flagA!=1 && flagB!=1)
            {
                printf("primero debe ingresar los dos numeros\n");
                system ("color C4" );
                system("pause");
                break;
            }
            else
            {
                total=resta(numeroA, numeroB);
                printf("El total de la resta A - B es; %.2f\n\n\n", total);
                system ("color F1" );
            }
            system("pause");//se pausa el sistema para poder mostrar resultados.
            break;
        case 5:             //Se realiza divicion, solo si hay datosintroducidos.
            system("cls");
            if(flagA!=1 && flagB!=1)
            {
                printf("primero debe ingresar los dos numeros\n");
                system ("color C4" );
                system("pause");
                break;
            }
            else
            {
                total=divicion(numeroA,numeroB);
                printf("El total de la divicion a / b es: %f", total);
                system ("color F1" );
            }
            break;
        case 6:                           //Se realiza multiplicacion, solo si hay valores agregados.
            system("cls");
            if(flagA!=1 && flagB!=1)
            {
                printf("primero debe ingresar los dos numeros\n");
                system ("color C4" );
                system("pause");
                break;
            }
            else
            {
                total=numeroA * numeroB;
                printf("La multiplicacion de los numeros da = %.2f\n\n\n", total);
                system ("color F1" );
                system("pause");//se pausa la consola para poder mostrar los resultados
            }
            break;
        case 7:                        //se realiza el factorial del numeroA, siempre que haya sido ingresado menor que 13.
            system("cls");
            if(flagA!=1)
            {
                printf("primero debe ingresar los dos numeros\n");
                system ("color C4" );
                system("pause");
            }
            else
            {
                if(numeroA>13)
                {
                    printf("\n     USTED INGRESO UN NUMERO MAYOR A 13. POR FAVOR, INGRESE UN NUMERO IGUAL O MENOR A 13 EN OPCION 1\n     ");
                    system ("color C4" ); //↑↑-El factorial mayor a 13 desborda la memoria y devuelve numero basura.
                    system("pause");//pausa sistema para mostrar el error
                    break;
                }
                else
                {
                    system ("color F1" );
                    total=factorial(numeroA);
                    printf("El resultado del factorial es %.2f\n\n\n", total);
                    system("pause");//se pausa para mostrar los resultados.
                }
            }
            break;
        case 8:                            //Se realiza un chequeo de los datos, y se realizan mostrando cada uno de los calculos.
            system("cls");
            if(flagA!=1 && flagB!=1)
            {
                printf("primero debe ingresar los dos numeros\n");
                system ("color C4");
                system("pause");
                break;
            }
            else
            {
                system ("color F1" );
                total=suma(numeroA,numeroB);
                printf("3- la suma da = %.2f\n\n\n",total);                             //
                total=resta(numeroA,numeroB);                                           //|
                printf("la resta A-B es = %.2f\n\n\n", total);                          //|     > Se ejecutan todas las funciones
                printf("la dibicion A/B es = %.2f\n\n\n", total);                       //|----/   simultaneamente.
                total=numeroA*numeroB;                                                  //|
                printf("La multiplicacion de los numeros da = %.2f\n\n\n", total);      //┘
                total=factorial(numeroA);
                printf("El factorial es: %.2f\n\n",total);
            }
            system("pause");
            break;
        case 9:
            printf("Desea seguir? s/n\n :");
            scanf("%s",&seguir);
            while(seguir!='n'&&seguir!='s')
            {
                printf("Ingresar s para seguir, n para salir.\n :");
                scanf("%s",&seguir);
            }//Para salir, pide una confirmacion por n o s.
            break;         default:
            system ("color C4" );
            printf("\n\nINGRESA NUMEROS VALIDOS\n\n");
            system("pause");

            break;

        }
    }

    return 0;//fin del programa. Al tocar una tecla se cierra.
}
