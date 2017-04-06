#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"

float sumar(float a, float b) {

    return a + b;

}

float restar(float a, float b) {

    return a - b;

}

float multiplicar(float a, float b) {

    return a * b;

}

float dividir(float a, float b) {

    return a / b;

}

long long int factorial(long long int a) {

    if (a == 0) {

        return 1;

    } else {

        return a * factorial(a - 1);

    }

}

void mostrarMenu(float num1, float num2, int asig1, int asig2) {

    printf("\n\tCalculadora en C\n\n");

    if (asig1 == 1) {

        printf("1- Ingresar 1er operando. (A = ");
        printFloat(num1);
        printf(")\n");

    } else {

        printf("1- Ingresar 1er operando. (A = X)\n");

    }

    if (asig2 == 1) {

        printf("2- Ingresar 2do operando. (B = ");
        printFloat(num2);
        printf(")\n");

    } else {

        printf("2- Ingresar 2do operando. (B = Y)\n");

    }

    printf("3- Calcular la suma (A + B).\n");
    printf("4- Calcular la resta (A - B).\n");
    printf("5- Calcular la division (A / B).\n");
    printf("6- Calcular la multiplicacion (A * B).\n");
    printf("7- Calcular el factorial (A!).\n");
    printf("8- Calcular todas las operaciones.\n");
    printf("9- Salir.\n");
    printf("\nIngrese la opcion deseada: ");

}

void printFloat(float numFloat) {

    char numFlotante[20];
    sprintf(numFlotante, "%f", numFloat);

    int decimales;
    int i, j, h;
    int aux = 0, contador = 1;
    int SoloCeros = 0;

// Si quisiera usar como parametro de la funcion una cadena deberia usar el codigo de abajo tambien:

//    int contadorPuntos = 0;
//
//    for (i = 0; i < strlen(numFlotante); i++) {
//
//        if (numFlotante[i] == '.') {
//
//            contadorPuntos++;
//
//        }
//
//    }
//
//    while (contadorPuntos > 1) {
//
//        contadorPuntos = 0;
//
//        printf("Un flotante solo tiene un punto, reingrese: ");
//        scanf("%s", numFlotante);
//
//        for (i = 0; i < strlen(numFlotante); i++) {
//
//            if (numFlotante[i] == '.') {
//
//                contadorPuntos++;
//
//            }
//
//        }
//
//    }

//    num = atof(numFlotante);

    //printf("\n");

    // Buscando el punto

    for (h = 0; h < strlen(numFlotante); h++) {

        if (numFlotante[h] == '.') {

            // Buscando el primer cero

            for (i = h+1; i < strlen(numFlotante); i++) {

                if (SoloCeros != -1) {

                    aux++;

                    if (numFlotante[i] == '0') {

                        if ((i + 1) < strlen(numFlotante)) {

                            // Buscando la posicion en la que todos los decimales empiezan a ser cero

                            for (j = i+1; j < strlen(numFlotante); j++) {

                                contador++;

                                if (numFlotante[j] == '0') {

                                    SoloCeros = 1;

                                    if (j == ((strlen(numFlotante)) - 1)) {

                                        //printf("Solo siguen ceros desde la posicion decimal %i en adelante\n", aux);
                                        SoloCeros = -1;

                                        decimales = aux - 1;

                                    }

                                } else {

                                    aux += contador;
                                    contador = 0;
                                    SoloCeros = 0;

                                    if (j == ((strlen(numFlotante)) - 1)) {

                                        //printf("Solo siguen ceros desde la posicion decimal %i en adelante\n", aux);
                                        SoloCeros = -1;

                                        decimales = aux - 1;

                                    }

                                }

                            }

                        } else {

                            //printf("Solo siguen ceros desde la posicion decimal %i en adelante\n", aux);
                            SoloCeros = -1;

                            decimales = aux - 1;

                        }

                    }

                }

            }

        }

    }

    //printf("%i\n", SoloCeros);

    if (SoloCeros != -1) {

        //printf("\nNo se ingresaron ceros decimales.\n");
        decimales = aux;

    }

    //printf("\n%i\n\n", decimales);

    switch (decimales) {

        case 0:
            printf("%.0f", numFloat);
            break;

        case 1:
            printf("%.1f", numFloat);
            break;

        case 2:
            printf("%.2f", numFloat);
            break;

        case 3:
            printf("%.3f", numFloat);
            break;

        case 4:
            printf("%.4f", numFloat);
            break;

        case 5:
            printf("%.5f", numFloat);
            break;

        default:
            printf("%f", numFloat);

    }
}
