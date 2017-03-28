#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <conio.h>

int validarEntero(int, int, int);
float validarFloat(float, int, int);
char validarChar(char, char, char);
void promedioEmpleados(int, int);

int main()
{
    int legajo;
    int edad;
    int cantM = 0;
    int cantF = 0;
    int cantMSueldo = 0;
    int cantFEdad = 0;
    int primerM = 1;
    int primerF = 1;
    int legajoMayorSueldo;
    int legajoMayorEdad;
    float cantAPagar = 0;
    float mayorSueldoM;
    float mayorEdadF;
    float sueldo;
    char sexo;
    char respuesta = 'y';

    while (respuesta == 'y') {

        printf("Ingrese el numero de legajo (4 cifras): ");
        scanf("%i", &legajo);

        validarEntero(legajo, 1000, 9999);

        printf("\nIngrese el sueldo neto (1500 - 10000): ");
        scanf("%f", &sueldo);

        validarFloat(sueldo, 1500, 10000);

        printf("\nIngrese el sexo (M/F): ");
        sexo = tolower(getche());

        validarChar(sexo, 'm', 'f');

        printf("\n\nIngrese la edad (18 - 65): ");
        scanf("%i", &edad);

        validarEntero(edad, 18, 65);

        printf("\n%cDesea seguir ingresando? (Y/N): ", 168);

        respuesta = tolower(getche());

        respuesta = validarChar(respuesta, 'y', 'n');

        if (sexo == 'm') {

            if ((sueldo >= 2000) && (sueldo <= 7500)) {

                cantMSueldo++;

            }

            if (primerM == 1) {

                primerM = 0;
                mayorSueldoM = sueldo;
                legajoMayorSueldo = legajo;

            } else {

                if (sueldo > mayorSueldoM) {

                    mayorSueldoM = sueldo;
                    legajoMayorSueldo = legajo;

                }

            }

            cantM++;

        } else {

            if (edad > 38) {

                cantFEdad++;

            }

            if (primerF == 1) {

                primerF = 0;
                mayorEdadF = edad;
                legajoMayorEdad = legajo;

            } else {

                if (edad > mayorEdadF) {

                    mayorEdadF = edad;
                    legajoMayorEdad = legajo;

                }

            }

            cantF++;

        }

        cantAPagar += sueldo;

        printf("\n\n");

    }

    printf("Empleados masculinos con suelto entre 2000 y 7500: %i", cantMSueldo);
    printf("\n\nEmpleadas fememinas de edad mayor a 38: %i\n", cantFEdad);

    promedioEmpleados(cantM, cantF);

    printf("\nCantidad a pagar entre todos los empleados ingresados: %f", cantAPagar);
    printf("\n\nLegajo del empleado masculino con mayor suedo: %i", legajoMayorSueldo);
    printf("\n\nLegajo de la empleada femenina de mayor edad: %i\n", legajoMayorEdad);

    return 0;
}

int validarEntero (int num, int min, int max) {

    while ((num < min) || (num > max)) {

        printf("\nNumero invalido. Reingrese (%i - %i): ", min, max);
        scanf("%i", &num);

    }

    return num;

}

float validarFloat (float num, int min, int max) {

    while ((num < min) || (num > max)) {

        printf("\nNumero invalido. Reingrese (%i - %i): ", min, max);
        scanf("%f", &num);

    }

    return num;

}

char validarChar (char caracter, char a, char b) {

    while ((caracter != a) && (caracter != b)) {

        printf("\n\nCaracter invalido. Reingrese (%c - %c): ", a, b);
        caracter = tolower(getche());

    }

    return caracter;

}

void promedioEmpleados (int cantM, int cantF) {

    int cantTotal = cantM + cantF;

    float promM = (cantM * 100) / cantTotal;
    float promF = (cantF * 100) / cantTotal;

    printf("\nPromedio de hombres: %f%c", promM, 37);
    printf("\n\nPromedio de mujeres: %f%c\n", promF, 37);

}
