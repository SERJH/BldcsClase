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
    sMovie movie;
    sMovie* pMovie;
    sMovie* pAuxMovie = NULL;

    tam = &tamA;
    pMovie = &movie;

    if((pArchivo = fopen("movies.dat", "rb")) == NULL) {

        if((pArchivo = fopen("movies.dat", "wb") )== NULL) {

            printf("\nEl archivo no puede ser abierto");
            exit (1);
        }

        pMovie = (sMovie*)malloc(5 * sizeof(sMovie));
        *tam = 5;
        fclose(pArchivo);

    } else {

        fclose(pArchivo);

        contMovie = cantPeliculas(pArchivo);
        pAuxMovie = (sMovie*)malloc((contMovie+5) * sizeof(sMovie));

        *tam = contMovie + 5;

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

                if (agregarPelicula(pMovie, contMovie, tam) == 1) {

                    contMovie++;
                    cargarArchivo(pArchivo, pMovie, contMovie);

                }

                break;

            case 2:

                if ((borrarPelicula(pMovie, contMovie)) == 1) {

                    contMovie--;
                    cargarArchivo(pArchivo, pMovie, contMovie);

                }

                break;

            case 3:

                modificarPelicula(pMovie, contMovie);
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
