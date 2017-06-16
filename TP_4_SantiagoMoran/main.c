#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"

int main()
{
    int seguir = 1;
    int opcion, opcionIn;
    char auxNombre[50];
    char auxGenero[50];

    ArrayList* empleados = al_newArrayList();
    ArrayList* empleadosCodigo = al_newArrayList();
    ArrayList* empleadosCodigoOcupados = al_newArrayList();
    ArrayList* empleadosModelado = al_newArrayList();
    ArrayList* empleadosModeladoOcupados = al_newArrayList();
    ArrayList* empleadosAnimacion = al_newArrayList();
    ArrayList* empleadosAnimacionOcupados = al_newArrayList();
    ArrayList* empleadosCinematica = al_newArrayList();
    ArrayList* empleadosCinematicaOcupados = al_newArrayList();
    ArrayList* empleadosMarketing = al_newArrayList();
    ArrayList* empleadosMarketingOcupados = al_newArrayList();

    ArrayList* juegosEnDesarrollo = al_newArrayList();
    ArrayList* juegosDesarrollados = al_newArrayList();

    inicializarEmpleados(empleados, empleadosCodigo, empleadosModelado, empleadosAnimacion, empleadosCinematica, empleadosMarketing);

    while (seguir == 1) {

        printf("\n\t\t~ Blizzard ~\n\n");

        printf("1- Lista de empleados\n");
        printf("2- Nuevo juego\n");
        printf("3- Juegos en desarrollo\n");
        printf("4- Juegos publicados\n");
        printf("5- Salir\n");

        printf("\nIngrese la opcion deseada: ");
        opcion = getIntRange(1, 5);

        switch (opcion)
        {
            case 1:

                mostrarMenu1();
                opcionIn = getIntRange(1, 2);

                switch (opcionIn)
                {
                    case 1:

                        printTodosCategoria(empleadosCodigo, empleadosModelado, empleadosAnimacion, empleadosCinematica, empleadosMarketing);
                        break;

                    case 2:

                        printTodosCategoria(empleadosCodigoOcupados, empleadosModeladoOcupados, empleadosAnimacionOcupados, empleadosCinematicaOcupados, empleadosMarketingOcupados);
                        break;

                }

                break;

            case 2:

                printf("\nIngrese el nombre del juego: ");
                strcpy(auxNombre, getStringNum());
                printf("\nIngrese el genero del juego: ");
                strcpy(auxGenero, getString());

                printf("\nElija hasta 5 coders para el equipo:\n");

                ArrayList* equipoCodigo = al_newArrayList();
                sCodigo* codigoJuego;
                cargarEmpleadosEquipo(empleadosCodigo, empleadosCodigoOcupados, equipoCodigo);
                codigoJuego = nuevoCodigo(equipoCodigo);

                printf("\nElija hasta 5 modeladores para el equipo:\n");

                ArrayList* equipoModelado = al_newArrayList();
                sModelado* modeladoJuego;
                cargarEmpleadosEquipo(empleadosModelado, empleadosModeladoOcupados, equipoModelado);
                modeladoJuego = nuevoModelado(equipoModelado);

                printf("\nElija hasta 5 animadores para el equipo:\n");

                ArrayList* equipoAnimacion = al_newArrayList();
                sAnimacion* animacionJuego;
                cargarEmpleadosEquipo(empleadosAnimacion, empleadosAnimacionOcupados, equipoAnimacion);
                animacionJuego = nuevoAnimacion(equipoAnimacion);

                printf("\nElija hasta 5 cineastas para el equipo:\n");

                ArrayList* equipoCinematica = al_newArrayList();
                sCinematica* cinematicaJuego;
                cargarEmpleadosEquipo(empleadosCinematica, empleadosCinematicaOcupados, equipoCinematica);
                cinematicaJuego = nuevoCinematica(equipoCinematica);

                printf("\nElija hasta 5 vendedores para el equipo:\n");

                ArrayList* equipoMarketing = al_newArrayList();
                sMarketing* marketingJuego;
                cargarEmpleadosEquipo(empleadosMarketing, empleadosMarketingOcupados, equipoMarketing);
                marketingJuego = nuevoMarketing(equipoMarketing);

                sJuego* juego = nuevoJuego(auxNombre, auxGenero, codigoJuego, modeladoJuego, animacionJuego, cinematicaJuego, marketingJuego);
                juegosEnDesarrollo->add(juegosEnDesarrollo, juego);

                system("cls");
                printJuegosArray(juegosEnDesarrollo);
                break;

            case 3:

                if (juegosEnDesarrollo->isEmpty(juegosEnDesarrollo) != 1) {

                    switches1(juegosEnDesarrollo, juegosDesarrollados, empleadosCodigo, empleadosCodigoOcupados, empleadosModelado, empleadosModeladoOcupados, empleadosAnimacion, empleadosAnimacionOcupados, empleadosCinematica, empleadosCinematicaOcupados, empleadosMarketing, empleadosMarketingOcupados);

                } else {

                    printf("\nNo hay juegos en desarrollo\n");

                }

                break;

            case 4:

                if (juegosDesarrollados->isEmpty(juegosDesarrollados) != 1) {

                    printJuegosArray(juegosDesarrollados);

                } else {

                    printf("\nNo hay juegos desarrollados\n");

                }

                break;

            case 5:

                seguir = 0;
                break;

        }

    printf("\n");
    system("pause");
    system("cls");

    }

    return 0;
}
