#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"

int main()
{
    char respuesta = 's';
    int asignado1 = 0, asignado2 = 0;
    int opcion = 0;
    float opcionB = 0;
    float num1, num2, suma, resta, multiplicacion, division;
    long long int numFac;


    while(respuesta == 's')
    {
        mostrarMenu(num1, num2, asignado1, asignado2);

        scanf("%f", &opcionB);

        opcion = (int)opcionB;

        switch(opcion)
        {
            case 1:
                printf("\nIngrese el primer operando: ");
                scanf("%f", &num1);
                asignado1 = 1;

                break;

            case 2:
                printf("\nIngrese el segundo operando: ");
                scanf("%f", &num2);
                asignado2 = 1;

                break;

            case 3:
                if ((asignado1 == 0) || (asignado2 == 0)) {

                    printf("\nAun faltan asignar operandos.\n");

                } else {

                    suma = sumar(num1, num2);
                    printf("\nEl resultado de la suma es: ");
                    printFloat(suma);
                    printf("\n");

                }
                break;

            case 4:
                if ((asignado1 == 0) || (asignado2 == 0)) {

                    printf("\nAun faltan asignar operandos.\n");

                } else {

                    resta = restar(num1, num2);
                    printf("\nEl resultado de la resta es: ");
                    printFloat(resta);
                    printf("\n");

                }
                break;

            case 5:
                if ((asignado1 == 0) || (asignado2 == 0)) {

                    printf("\nAun faltan asignar operandos.\n");

                } else if (num2 == 0) {

                    printf("No es posible dividir por 0.\nReingrese B utilizando la opcion 2.\n");

                } else {

                    division = dividir(num1, num2);
                    printf("\nEl resultado de la division es: ");
                    printFloat(division);
                    printf("\n");

                }
                break;

            case 6:
                if ((asignado1 == 0) || (asignado2 == 0)) {

                    printf("\nAun faltan asignar operandos.\n");

                } else {

                    multiplicacion = multiplicar(num1, num2);
                    printf("\nEl resultado de la multiplicacion es: ");
                    printFloat(multiplicacion);
                    printf("\n");

                }
                break;

            case 7:
                if (asignado1 == 0) {

                    printf("\nAun faltan asignar el primer operando.\n");

                } else if (num1 < 0) {

                    printf("\nA debe ser mayor o igual a 0 para calcular su factorial.\nReingrese utilizando la opcion 1.\n");

                } else if (num1 != (int)num1) {

                        printf("\nPara calcular el factorial A debe ser un numero entero.\nReingrese utilzando la opcion 1.\n");

                } else if (num1 > 20) {

                        printf("\nNo es posible calcular un faltorial tan grande. (MAX = 20).\n");

                    } else {

                        numFac = (long long int)num1;
                        printf("\nEl factorial de %lld es: %lld\n", numFac, factorial(numFac));

                    }

                break;

            case 8:
                if ((asignado1 == 0) || (asignado2 == 0)) {

                    printf("\nAun faltan asignar operandos.\n");

                } else {

                    suma = sumar(num1, num2);
                    printf("\nEl resultado de la suma es: ");
                    printFloat(suma);
                    printf("\n");

                    resta = restar(num1, num2);
                    printf("\nEl resultado de la resta es: ");
                    printFloat(resta);
                    printf("\n");

                    if (num2 == 0) {

                    printf("\nNo es posible dividir por 0.\nReingrese B utilizando la opcion 2.\n");

                    } else {

                    division = dividir(num1, num2);
                    printf("\nEl resultado de la division es: ");
                    printFloat(division);
                    printf("\n");

                    }

                    multiplicacion = multiplicar(num1, num2);
                    printf("\nEl resultado de la multiplicacion es: ");
                    printFloat(multiplicacion);
                    printf("\n");

                    if (num1 < 0) {

                        printf("\nA debe ser mayor o igual a 0 para calcular su factorial.\nReingrese utilizando la opcion 1.\n");

                    } else if (num1 != (int)num1) {

                        printf("\nPara calcular el factorial A debe ser un numero entero.\nReingrese utilzando la opcion 1.\n");

                    } else if (num1 > 20) {

                        printf("\nNo es posible calcular un faltorial tan grande. (MAX = 20).\n");

                    } else {

                        numFac = (long long int)num1;
                        printf("\nEl factorial de %lld es: %lld\n", numFac, factorial(numFac));

                    }

                }
                break;

            case 9:
                respuesta = 'n';

                break;
        }

        printf("\n");

        if (opcion != 9) {

            system("pause");

        }

        system("cls");

    }

    printf("\nGracias por utilizar la calculadora.\n");

    return 0;
}
