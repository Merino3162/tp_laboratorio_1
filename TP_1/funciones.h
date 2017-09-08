/** \brief Esta funcion recibe un char, verifica que contenga numeros y no letras, y devuelve un float.
 *
 * \param En "main.c" se modifica un dato de tipo char para los numeros ingresador por el usuario. Esto se debe a que existe al ingresar
          por parte del usuario una letra en un dato tipo float, un error y tildaba el programa.

 * \param Dicho dato, almacenado en una variable char (auxiliar), se envia a una funcion que toma datos en char, verifica letra por letra
          que, valga la redundancia, no sean letras, sino numeros con maximo un punto por palabra (para los numeros con coma), y que pueden empezar con -
          en su primer caracter, esto para, efectivamente, los numeros negativos. No verifica fracciones, las da por error. y de cumplirse los requisitos
          asi, convierte la variable char(auxiliar), en variable tipo float (resultado) para poder realizar cada uno de los calculos solicitados.

 * \return Se retorna 1 como valido, y 0 como error. Estos retornos se utilizan para validar los ingresos. Los datos se envian todos por direccion de memoria.
 *
 */

int deStringAEntero(char[], float*);

/** \brief Esta funcion toma numeros por char, llama a otra funcion y verifica que dichos caracteres sean numeros.
 *
 * \param float: se le envia la direccion de memoria de un flotante en main.c. esa direccion, luego contendra un flotante
            resultante de la funcion.
 * \param char: simplemente es el mensaje que muestra la funcion para pedir el numero. Se lo envia como parametro cuando
                se llama a la funcion.
 * \return  retorna un entero. Como error retorna 0, y como valido retorna 1. Estos retornos se usaran para validar los ingresos.
 *
 */

int tomarNumero (float*, char[]);

/** \brief Imprime el menu y muestra opciones. Tambien imprime los numeros ya ingresados.
 *
 * \param A: Se usa para imprimir el valor de A. no se modifica.
 * \param B: se usa para imprimir el valor de B. no se modifica.
 * \return Retorna 1 sin un fin especifico.
 *
 */

int opcionesDeMenu(float, float);


