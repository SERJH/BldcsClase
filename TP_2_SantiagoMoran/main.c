#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include <string.h>
#include "funciones.h"
#define A 20


int main()
{
    int libre, encontrado, hayIngresados;
    int seguir = 1;
    int opcion;
    char opcionC[100];
    char opcionBorrar;
    sPersona personas[A];

    startupPersonas(personas, A);

    while (seguir == 1) {

        mostrarMenu();

        gets(opcionC);

        system("cls");

        if (soloNumeros(opcionC) == 0) {

            opcion = -1;

        } else {

            opcion = atoi(opcionC);

        }

        switch (opcion)
        {
            case 1:

                libre = obtenerEspacioLibre(personas, A);

                if (libre != -1) {

                    cargarPersona(personas, libre);

                } else {

                    printf("\nNo hay lugares disponibles.\n\n");

                }

                break;

            case 2:

                hayIngresados = hayPersonas(personas, A);

                if (hayIngresados != 0) {

                    encontrado = buscarPorDni(personas, A);

                    if (encontrado != -1) {

                        opcionBorrar = confirmarBorrado(personas, encontrado);
                        opcionBorrar = validarChar(opcionBorrar, 's', 'n');

                        if (opcionBorrar == 's') {

                            borrarPersona(personas, encontrado);

                        } else {

                            printf("\n\nHa cancelado el borrado.\n");

                        }

                    } else {

                        printf("\nNo se ha encontrado el DNI ingresado.");

                    }

                }

                break;

            case 3:

                hayIngresados = hayPersonas(personas, A);

                if (hayIngresados != 0) {

                    mostrarLista(personas, A);

                }

                break;

            case 4:

                hayIngresados = hayPersonas(personas, A);

                if (hayIngresados != 0) {

                    imprimirGrafico(personas, A);

                }

                break;

            case 5:

                seguir = 0;
                break;

            default:

                printf("\nOpcion invalida.\n");

        }

    printf("\n");
    system("pause");
    system("cls");

    }

    return 0;
}
