#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main()
{
    int i;
    int seguir = 1;
    int opcion;
    int *tam, tamA, contMovie;
    char auxChar[50];
    FILE* pArchivo;
    sMovie movie, auxMovie;
    sMovie* pMovie = NULL;
    sMovie* pAuxMovie = NULL;

    tam = &tamA;
    pMovie = &movie;
    pAuxMovie = &auxMovie;

    if((pArchivo = fopen("movies.dat", "rb")) == NULL) {

        if((pArchivo = fopen("movies.dat", "wb") )== NULL) {

            printf("\nEl archivo no puede ser abierto");
            exit (1);
        }

        pMovie = (sMovie*)malloc(2 * sizeof(sMovie));
        *tam = 2;
        fclose(pArchivo);

    } else {

        fclose(pArchivo);

        contMovie = cantPeliculas(pArchivo);
        pAuxMovie = (sMovie*)malloc((contMovie+2) * sizeof(sMovie));

        *tam = contMovie + 2;

        pArchivo = fopen("movies.dat", "rb");

        if (fread(pAuxMovie, sizeof(sMovie), contMovie, pArchivo) != contMovie) {

            exit(1);

        }

        fclose(pArchivo);

        if (pAuxMovie != NULL) {

            pMovie = pAuxMovie;

        } else {

            exit(1);

        }

    }

    while(seguir == 1)
    {
        mostrarMenu(pArchivo);
        contMovie = cantPeliculas(pArchivo);
        fflush(stdin);
        gets(auxChar);
        opcion = getIntRange(auxChar, 1, 5);

        switch(opcion)
        {
            case 1:

                ingresoDatosPelicula(pMovie, contMovie);

                if (contMovie >= *tam - 1) {

                    printf("\nLimite alcanzado. Se agregaran 5 lugares mas para proximas cargas.\n");

                    pAuxMovie = (sMovie*)realloc(pMovie, (*tam + 5) * sizeof(sMovie));

                    if (pAuxMovie != NULL) {

                        pMovie = pAuxMovie;
                        *tam += 5;

                    } else {

                        printf("\nNo pudo agrandarse el espacio.\n");

                    }

                }

                contMovie++;
                cargarArchivo(pArchivo, pMovie, contMovie);

                break;

            case 2:

                if ((borrarPelicula(pMovie, contMovie)) == 1) {

                    contMovie--;
                    cargarArchivo(pArchivo, pMovie, contMovie);

                }

                break;

            case 3:

                modificarPelicula(pMovie, contMovie);
                cargarArchivo(pArchivo, pMovie, contMovie);
                crearSitio(pMovie, contMovie);
                break;

            case 4:

                crearSitio(pMovie, contMovie);
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
