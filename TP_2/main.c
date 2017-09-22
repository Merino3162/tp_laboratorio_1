#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"




int main()
{
    system("color F0");
    char seguir='s';    //menu principal para continuar o salir
    int opcion=0;       //elegir que opcion usar.

    eDatos TodosLosIngresos[20];//array con datos.
    int libre;                  //numero de item del array disponible para cargar
    int tamanho=20;             //tamaño total del array
    int i;                      //indice de multiples "for"
    int menor=0;                //contador de menores de 19
    int medio=0;                //contador de entre 19-35
    int mayor=0;                //contador de mayores de 35

    for(i=0 ; i<tamanho ; i++)
    {
        TodosLosIngresos[i].flagEstado=0;
    }


    while(seguir=='s')
    {
        printf("\t\t1- Agregar persona\n");
        printf("\t\t2- Borrar persona\n");
        printf("\t\t3- Imprimir lista ordenada por  nombre\n");
        printf("\t\t4- Imprimir grafico de edades\n\n");
        printf("\t\t5- Salir\n\n\t\t:");

        scanf("%d",&opcion);

        switch(opcion)
        {
        case 1:
            system("cls");
            libre=buscarLibre(TodosLosIngresos, tamanho);
            if(libre>=0)
            {
                pedirDatos(TodosLosIngresos, tamanho);
                if(TodosLosIngresos[libre].edad<19)
                {
                    menor++;
                } else if(TodosLosIngresos[libre].edad>18&&TodosLosIngresos[libre].edad<36)
                {
                    medio++;
                }else
                {
                    mayor++;
                }
            }
            else
                printf("No hay espacios vacios. Debe borrar un dato.");
            break;
        case 2:
            system("cls");
            borrarPorDni(TodosLosIngresos,tamanho);

            break;
        case 3:
            system("cls");
            mostrarTodo(TodosLosIngresos, tamanho);
            break;
        case 4:
            Grafico(TodosLosIngresos,tamanho,menor,medio,mayor);
        break;
    case 5:
        seguir = 'n';
        printf("presione una tecla para salir..\n\n\n");
        system("pause");
        break;
    }
}

return 0;
}




