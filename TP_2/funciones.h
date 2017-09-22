#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct
{
    char nomobre[40];
    int edad;
    int dni;
    int flagEstado;
}eDatos;

/**
 * Obtiene el primer indice libre del array.
 * @param lista el array se pasa como parametro.
 * @param entero que se pasa como parametro. Identifica la cantidad de items que contiene el array.
 * @return el primer indice disponible
 */
int buscarLibre (eDatos[],int);

/**
 * Obtiene el indice que coincide con el dni pasado por parametro.
 * @param lista el array se pasa como parametro.
 * @param dni el dni a ser buscado en el array.
 * @return el indice en donde se encuentra el elemento que coincide con el parametro dni
 */
void borrarPorDni(eDatos[], int);

#endif // FUNCIONES_H_INCLUDED

/** \brief funcion que crea un grafico de rango de edades.
 *
 * \param edatos: array que se pasa como parametro, contiene los datos de personas.
 * \param tamaño del array.
 * @param cantidad de personas menores de 19 años.
 * @param cantidad de personas entre 19 y 35 años.
 * @param cantidad de personas mayores de 35 años.
 * \return No retorna. Void, usado solo para graficar.
 *
 */

void Grafico(eDatos[], int, int, int, int);

/** \brief funcion para cargar cada uno de los item del array con datos.
 *
 * \param eDato: Array con los espacios para guardar informacion.
 * \param Tamaño del array. Necesario para no desbordar memoria.
 * \return Retorna los datos ingresados en el espacio libre, previamente calculado.
 *
 */
eDatos pedirDatos(eDatos[], int);

/** \brief Imprime en consola todos los datos de cada uno de los items del array eDatos.
 *
 * \param eDatos: Array que contiene todos los datos a imprimir.
 * \param Tamaño del array.
 * \return No retorna. void: Se usa solo para imprimir.
 *
 */
void mostrarTodo(eDatos[], int);
