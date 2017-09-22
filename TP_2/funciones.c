#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

void Grafico(eDatos TodosLosIngresos[], int tamanho, int menor, int medio, int mayor){


    system("cls");

    int i;
    int flagMedio;
    int flagMenor;
    int flagMayor;

            printf("\n\n\n");
            for(i=tamanho; i>0; i--)
            {
                printf("%02d|",i);
                flagMedio=0;
                flagMenor=0;
                flagMayor=0;
                    if(i==1 && TodosLosIngresos[i-1].flagEstado!=1)
                    {
                        printf("\n    No hay datos..\n");
                        break;
                    }
                else
                {
                    if(mayor>=i)
                    {
                        flagMayor=1;
                    }
                    if(medio>=i)
                    {
                        flagMedio=1;
                    }
                    if(menor>=i)
                    {
                        flagMenor=1;
                    }


                    if(flagMayor==1&&flagMedio==1&&flagMenor==1)
                    {
                        printf("*\t  *\t *");
                    }
                    if(flagMayor==0&&flagMedio==1&&flagMenor==1)
                    {
                        printf("*\t  *\t  ");
                    }
                    if(flagMayor==1&&flagMedio==0&&flagMenor==1)
                    {
                        printf("*\t   \t *");
                    }
                    if(flagMayor==1&&flagMedio==1&&flagMenor==0)
                    {
                        printf(" \t  *\t *");
                    }if(flagMayor==0&&flagMedio==1&&flagMenor==0)
                    {
                        printf(" \t  *\t  ");
                    }
                    if(flagMayor==1&&flagMedio==0&&flagMenor==0)
                    {
                        printf(" \t   \t *");
                    }if(flagMayor==0&&flagMedio==0&&flagMenor==1)
                    {
                        printf("*\t   \t  ");
                    }
                        printf("\n");
                }
            }

        printf("--+^------^------^+");
        printf("\n  |-19| 19-35 |+35|");
        printf("\n  +---------------+");
        printf("\n    %02d |  %02d  | %02d\n\n", menor, medio, mayor);
}


void borrarPorDni(eDatos TodosLosIngresos[], int tamanho){
           int i;
           int borrador;
           printf("ingrese DNI:\n\t");
           scanf("%d",&borrador);

            for(i=0;i<tamanho;i++)
                {
                    if(TodosLosIngresos[i].dni==borrador)
                    {
                        TodosLosIngresos[i].flagEstado=0;
                        printf("Datos borrados con exito!");
                        break;
                    }
                    if(i == tamanho-1 && TodosLosIngresos[i].dni != borrador)
                    {
                        printf("DNI no encontrado.");
                    }
                }
}

eDatos pedirDatos(eDatos datosVacios[], int tam){
int i;

    for(i=0 ; i<tam ; i++)
    {
        if(datosVacios[i].flagEstado==0)
        {

            printf("\nIngrese nombre: ");
            fflush(stdin);
            gets(datosVacios[i].nomobre);

            printf("\ningrese edad: ");
            scanf("%d",&datosVacios[i].edad);
            while(datosVacios[i].edad<0||datosVacios[i].edad>100)
            {
                printf("\ningrese edad valida entre 1 y 100: ");
                scanf("%d",&datosVacios[i].edad);
            }


            printf("\nIngrese DNI: ");
            scanf("%d",&datosVacios[i].dni);
            while(datosVacios[i].dni<100000)
            {
                printf("\nIngrese DNI valido: ");
                scanf("%d",&datosVacios[i].dni);
            }

            datosVacios[i].flagEstado=1;
            break;
        }
    }
    return datosVacios[i];
}

int buscarLibre (eDatos buscar[],int tam)
{
    int i;
    int libre;
    for(i=0; i<tam; i++)
    {
        if(buscar[i].flagEstado==0)
        {
            libre=i;
            break;
        }
        if(i==tam-1&&buscar[i].flagEstado!=0)
        {
            libre=-1;
        }
    }
    return libre;

}


void mostrarTodo(eDatos datosParaMostrar[], int tam)
{
    int i;
    int flag=0;
    for(i=0 ; i<tam ; i++)
    {
        if(datosParaMostrar[i].flagEstado==1)
        {
            flag=1;
            printf("NOMBRE: %s\nDNI: %d\nEDAD: %d\n\n", datosParaMostrar[i].nomobre, datosParaMostrar[i].dni, datosParaMostrar[i].edad);
        }
        if(i==tam-1&&flag==0)
        {
            printf("\n\n\tNo hay datos ingresados.");
        }
    }
}
