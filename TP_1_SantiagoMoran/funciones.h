#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

float sumar(float, float);

/** \ Suma dos numeros
 *
 *  \ Primer numero (a)
 *  \ Segundo numero (b)
 *
 *  \ Devuelve el resultado de la suma de a y b
 */

float restar(float, float);

/** \ Resta dos numeros
 *
 *  \ Primer numero (a)
 *  \ Segundo numero (b)
 *
 *  \ Devuelve el resultado de la resta de a y b
 */


float multiplicar(float, float);

/** \ Multiplica dos numeros
 *
 *  \ Primer numero (a)
 *  \ Segundo numero (b)
 *
 *  \ Devuelve el resultado de la multiplicacion de a y b
 */

float dividir(float, float);

/** \ Divide dos numeros
 *
 *  \ Primer numero (a)
 *  \ Segundo numero (b)
 *
 *  \ Devuelve el resultado de la division de a y b
 */

long long int factorial(long long int);

/** \ Calcula el factorial de un numero entero
 *
 *  \ Numero (a)
 *
 *  \ Devuelve el factorial de a
 */

void mostrarMenu(float, float, int, int);

/** \ Muestra el menu principal
 *
 *  \ Primer numero (a)
 *  \ Segundo numero (b)
 *  \ Estado de a (si fue asignado o no)
 *  \ Estado de b (si fue asignado o no)
 *
 *  \ No devuelve nada
 */

 void printFloat(float);

 /** \ Muestra un flotante sin ceros irrelevantes
  *
  *  \ Numero flotante
  *
  *  \ No devuelve nada
  */

#endif // FUNCIONES_H_INCLUDED
