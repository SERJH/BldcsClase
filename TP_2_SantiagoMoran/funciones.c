#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "funciones.h"
#define A 20


void mostrarMenu() {

    printf("\n\t\t~ Bienvenido ~\n\n");

    printf("1- Agregar persona\n");
    printf("2- Borrar persona\n");
    printf("3- Imprimir lista ordenada por nombre\n");
    printf("4- Imprimir grafico de edades\n");
    printf("5- Salir\n");

    printf("\nIngrese la opcion deseada: ");

}

void startupPersonas(sPersona personas[], int tam) {

    int i;

    for (i = 0; i < tam; i++) {

        personas[i].estado = 0;

    }

}

int soloEspacios(char nombre[]) {

    int i;
    int soloEsp = 1;
    int cantString = strlen(nombre);

    for (i = 0; i < cantString; i++) {

        if (nombre[i] != 32) {

            soloEsp = 0;
            return soloEsp;

        }

    }

    return soloEsp;

}

int soloLetras(char nombre[]) {

    int i;
    int testLetra;
    int cantString = strlen(nombre);

    for (i = 0; i < cantString; i++) {

        testLetra = esLetra(nombre[i]);

        if (testLetra == 1) {

            if (i == (cantString - 1)) {

                return 1;

            }

        } else {

            return 0;

        }

    }

}

int esLetra(char a) {

    if ((a >= 65 && a <= 90) || (a >= 97 && a <= 122) || (a >= 160 && a <= 165) || (a == 32)) {

        return 1;

    } else {

        return 0;

    }

}

int soloNumeros(char num[]) {

    int i;
    int testNum;
    int cantString = strlen(num);

    for (i = 0; i < cantString; i++) {

        testNum = esNum(num[i]);

        if (testNum == 1) {

            if (i == (cantString - 1)) {

                return 1;

            }

        } else {

            return 0;

        }

    }

}

int esNum(char a) {

    if (a >= 48 && a <= 57) {

        return 1;

    } else {

        return 0;

    }

}

int validarRangoInt(int num, int min, int max) {

    if (num >= min && num <= max) {

        return 1;

    } else {

        return 0;

    }

}

char validarChar(char caracter, char opcion1, char opcion2) {

    if (caracter == opcion1 || caracter == opcion2) {

        return caracter;

    } else {

        while (caracter != opcion1 && caracter != opcion2) {

            printf("\n\nRespuesta invalida (%c/%c).", toupper(opcion1), toupper(opcion2));
            printf("\nReingrese: ");
            caracter = tolower(getche());

        }

        return caracter;

    }

}

int dniRepetido(int dni, sPersona personas[], int tam) {

    int i;

    for (i = 0; i < tam; i++) {

        if (personas[i].dni == dni && personas[i].estado == 1) {

            return 1;

        }

    }

    return 0;

}

int obtenerEspacioLibre(sPersona personas[], int tam) {

    int i;

    for (i = 0; i < tam; i++) {

        if (personas[i].estado == 0) {

            return i;

        }

    }

    return -1;

}

void cargarPersona(sPersona persona[], int libre) {

    int minEdad = 1;
    int maxEdad = 110;
    int minDNI = 5000000;
    int maxDNI = 50000000;
    char auxNum[25];

    printf("\nIngrese el nombre de la persona: ");
    fflush(stdin);
    gets(persona[libre].nombre);

    while ((soloLetras(persona[libre].nombre) == 0) || (soloEspacios(persona[libre].nombre) == 1)) {

        if (soloEspacios(persona[libre].nombre) == 1) {

            printf("\nError. El nombre debe contener al menos una letra.\n");
            printf("\nReingrese: ");
            fflush(stdin);
            gets(persona[libre].nombre);

        } else {

            printf("\nError. El nombre solo puede contener letras y espacios.\n");
            printf("Reingrese: ");
            fflush(stdin);
            gets(persona[libre].nombre);

        }

    }

    printf("\nIngrese la edad de %s: ", persona[libre].nombre);
    gets(auxNum);

    while (soloNumeros(auxNum) == 0 || validarRangoInt(atoi(auxNum), minEdad, maxEdad) == 0) {

        printf("\nLa edad debe ser un numero entre %i y %i.", minEdad, maxEdad);
        printf("\nReingrese: ");
        gets(auxNum);

    }

    persona[libre].edad = atoi(auxNum);

    printf("\nIngrese el DNI de %s: ", persona[libre].nombre);
    gets(auxNum);

    while (soloNumeros(auxNum) == 0 || validarRangoInt(atoi(auxNum), minDNI, maxDNI) == 0 || (dniRepetido(atoi(auxNum), persona, A) == 1)) {

        if (dniRepetido(atoi(auxNum), persona, A) == 1) {

            printf("\nEl DNI ingresado pertenece a otra persona.");
            printf("\nReingrese: ");
            gets(auxNum);

        } else {

            printf("\nEl DNI debe ser un numero entre %i y %i.", minDNI, maxDNI);
            printf("\nReingrese: ");
            gets(auxNum);

        }

    }

    persona[libre].dni = atoi(auxNum);
    persona[libre].estado = 1;

}

int buscarPorDni(sPersona personas[], int tam) {

    int i;
    int dni;
    int minDNI = 5000000;
    int maxDNI = 50000000;
    char dniC[15];

    printf("\nIngrese el DNI de la persona: ");
    gets(dniC);

    while (soloNumeros(dniC) == 0 || validarRangoInt(atoi(dniC), minDNI, maxDNI) == 0) {

        printf("\nEl DNI debe ser un numero entre %i y %i.", minDNI, maxDNI);
        printf("\nReingrese: ");
        gets(dniC);

    }

    dni = atoi(dniC);

    for (i = 0; i < tam; i++) {

        if (personas[i].dni == dni && personas[i].estado == 1) {

            return i;

        }

    }

    return -1;

}

char confirmarBorrado(sPersona personas[], int index) {

    char opcionBorrar;

    printf("\n%cEsta seguro que desea borrar a %s? (S/N): ", 168, personas[index].nombre);
    opcionBorrar = tolower(getche());

    return opcionBorrar;

}

void borrarPersona(sPersona personas[], int index) {

    personas[index].estado = 0;
    printf("\n\nSe ha eliminado con exito a %s.\n", personas[index].nombre);

}

int hayPersonas(sPersona personas[], int tam) {

    int i;
    int hay = 0;

    for (i = 0; i < tam; i++) {

        if (personas[i].estado == 1) {

            hay = 1;
            return hay;

        }

    }

    printf("\nNo hay ninguna persona en el sistema.");
    printf("\nPor favor utilize la opcion 1 para cargar una y vuelva a intentar.\n");

    return hay;

}

void mostrarLista(sPersona personas[], int tam) {

    int i, j;
    sPersona personasOrdenadas[tam];
    sPersona auxPersona[tam];

    for (i = 0; i < tam; i++) {

        personasOrdenadas[i] = personas[i];

    }

    for (i = 0; i < (tam - 1); i++) {

        for (j = i+1; j < tam; j++) {

            if (strcmp(personasOrdenadas[i].nombre, personasOrdenadas[j].nombre) == 1) {

                auxPersona[i] = personasOrdenadas[i];
                personasOrdenadas[i] = personasOrdenadas[j];
                personasOrdenadas[j] = auxPersona[i];

            }

        }

    }

    printf("\n\t\tNombre\t\t\tEdad\tDNI\n");

    for (i = 0; i < tam; i++) {

        if (personasOrdenadas[i].estado == 1) {

            if (strlen(personasOrdenadas[i].nombre) < 8) {

                printf("\n%s\t\t\t\t\t%i\t%i", personasOrdenadas[i].nombre, personasOrdenadas[i].edad, personasOrdenadas[i].dni);

            } else if (strlen(personasOrdenadas[i].nombre) < 16) {

                printf("\n%s\t\t\t\t%i\t%i", personasOrdenadas[i].nombre, personasOrdenadas[i].edad, personasOrdenadas[i].dni);

            } else if (strlen(personasOrdenadas[i].nombre) < 24) {

                printf("\n%s\t\t\t%i\t%i", personasOrdenadas[i].nombre, personasOrdenadas[i].edad, personasOrdenadas[i].dni);

            } else if (strlen(personasOrdenadas[i].nombre) < 32){

                printf("\n%s\t\t%i\t%i", personasOrdenadas[i].nombre, personasOrdenadas[i].edad, personasOrdenadas[i].dni);

            } else {

                printf("\n%s\t%i\t%i", personasOrdenadas[i].nombre, personasOrdenadas[i].edad, personasOrdenadas[i].dni);

            }

        }

    }

}

void imprimirGrafico(sPersona personas[], int tam) {

    int i, j;

    int menores = 0;
    int media = 0;
    int mayores = 0;
    int max;

    char barra = 219;
    char graph[20][3];

    // Cantidad de personas en cada grupo de edad

    for (i = 0; i < tam; i++) {

        if (personas[i].edad < 18 && personas[i].estado == 1) {

            menores++;

        } else if (personas[i].edad >= 18 && personas[i].edad < 35 && personas[i].estado == 1) {

            media++;

        } else if (personas[i].estado == 1) {

            mayores++;

        }

    }

    // Encuentro el maximo para no dibujar lineas de mas

    if (menores >= media && menores >= mayores) {

        max = menores;

    } else if (media >= menores && media >= mayores) {

        max = media;

    } else if (mayores >= menores && mayores >= media) {

        max = mayores;

    }

    // Dibujar una barra donde corresponda en la matriz del grafico

    for (i = 0; i < 20; i++) {

        if (i < menores) {

            graph[i][0] = barra;

        }

        if (i < media) {

            graph[i][1] = barra;

        }

        if (i < mayores) {

            graph[i][2] = barra;

        }

    }

    // Printear el grafico terminado

    for (i = (max - 1); i >= 0; i--) {

        if (i < 9) {

            printf("\n0%i|\t", i+1);

        } else {

            printf("\n%i|\t", i+1);

        }

        for (j = 0; j < 3; j++) {

            if (graph[i][j] == barra) {

                printf("%c", graph[i][j]);

            }

            printf("\t");

        }

    }

    printf("\n--|---------------------------");

    printf("\n\t<18\t18-35\t>35");

    printf("\n\nCant:\t%i\t%i\t%i", menores, media, mayores);
}
