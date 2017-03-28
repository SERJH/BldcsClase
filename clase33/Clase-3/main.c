#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>

int main()
{
    int legajo;
    int edad;
    float sueldo;
    char sexo;
    char respuesta = 'y';

    while (respuesta == 'y') {

        printf("Ingrese el numero de legajo (4 cifras): ");
        scanf("%i", &legajo);

        validarEntero(legajo, 1000, 9999);

        printf("Ingrese el sueldo neto (1500 - 10000): ");
        scanf("%f", &sueldo);

        validarFloat(sueldo, 1500, 10000);

        printf("Ingrese el sexo (M - F): ");
        sexo = tolower(getche());

        validarChar(sexo);

        printf("Ingrese la edad: ");
        scanf("%i", &edad);

        validarEntero(edad, 18, 65);

    }

    return 0;
}

int validarEntero (int num, int min, int max) {

    while ((num < min) || (num > max)) {

        printf("Numero invalido. Reingrese (%i - %i): ", min, max);
        scanf("%i", %num);

    }

    return num;

}

float validarFloat (float num, int min, int max) {

    while ((num < min) || (num > max)) {

        printf("Numero invalido. Reingrese (%i - %i): ", min, max);
        scanf("%i", &num);

    }

    return num;

}

char validarChar (char caracter) {

    while ((caracter != 'f') && (caracter != 'm')) {

        printf("Caracter invalido. Reingrese (M - F): ");
        caracter = tolower(getche());

    }

    return caracter;

}
