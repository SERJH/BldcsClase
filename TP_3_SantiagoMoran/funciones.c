#include <stdlib.h>
#include <string.h>
#include "funciones.h"

void mostrarMenu(FILE* pArchivo) {

    int contMovie;

    printf("\n\n\t\t\t\t~ Peliculas UTN ~\n\n");

    contMovie = cantPeliculas(pArchivo);
    printf("Cantidad de peliculas: %i\n\n", contMovie);

    printf("1- Agregar pelicula\n");
    printf("2- Borrar pelicula\n");
    printf("3- Modificar pelicula\n");
    printf("4- Generar pagina web\n");
    printf("5- Salir\n");

    printf("\nIngrese la opcion deseada: ");

}

int borrarPelicula(sMovie* pMovie, int contMovies) {

    char auxChar[50];
    int i, indice = -1;

    printf("\nListado de peliculas:\n");

    for (i = 0; i < contMovies; i++) {

        printf("\n%s", strupr((pMovie+i)->titulo));

    }

    printf("\n\nIngrese pelicula a borrar: ");
    fflush(stdin);
    gets(auxChar);

    for (i = 0; i < contMovies; i++) {

        if (strcmpi(auxChar, (pMovie+i)->titulo) == 0) {

            indice = i;
            break;

        }

    }



    if (indice != -1) {

        for (i = indice; i < contMovies; i++) {

            pMovie[i] = pMovie[i+1];

        }
//        (pMovie+indice)->puntaje = 0;
        printf("\nSe borro la pelicula con exito.\n");
        return 1;

    } else {

        printf("\nNo se encontro la pelicula.\n");
        return 0;

    }

}

int agregarPelicula(sMovie* pMovie, int movies, int* tam) {

    sMovie* pAuxMovie;

    pAuxMovie = pMovie;

    if (movies >= *tam - 1) {

        printf("\nLimite alcanzado. Se añadiran 5 lugares mas al finalizar esta carga.\n");

        pAuxMovie = (sMovie*)realloc(pMovie, (*tam + 5) * sizeof(sMovie));

        if (pAuxMovie != NULL) {

            pMovie = pAuxMovie;
            *tam += 5;

        } else {

            printf("\nNo pudo agrandarse el tamaño.\n");
            return 0;

        }

    }

    ingresoDatosPelicula(pMovie, movies);

    return 1;
}

void cargarArchivo(FILE* pArchivo, sMovie* pMovie, int cantMovies) {

    int test;

    if ((pArchivo = fopen("movies.dat", "wb") )== NULL) {

        printf("\nEl archivo no puede ser abierto");
        exit (1);

    } else {

        test = fwrite(pMovie, sizeof(sMovie), cantMovies, pArchivo);

        if (test < cantMovies) {

            printf("\nError.");

        } else {

            printf("\nArchivo cargado con exito.\n");

        }

        fclose(pArchivo);

    }

}

void ingresoDatosPelicula(sMovie* pMovie, int movies) {

    char auxChar[500];
    int tituloRep;

    printf("\nIngrese el titulo: ");
    fflush(stdin);
    gets(auxChar);

    strcpy((pMovie+movies)->titulo, getStringNum(auxChar));
    tituloRep = tituloRepetido(pMovie, movies, auxChar);

    while (tituloRep) {

        printf("\nEntrada invalida. Reingrese: ");
        fflush(stdin);
        gets(auxChar);
        tituloRep = tituloRepetido(pMovie, movies, auxChar);
        strcpy((pMovie+movies)->titulo, getStringNum(auxChar));

    }

    printf("\nIngrese el genero: ");
    fflush(stdin);
    gets(auxChar);

    strcpy((pMovie+movies)->genero, getString(auxChar));

    printf("\nIngrese la descripcion: ");
    fflush(stdin);
    gets(auxChar);

    strcpy((pMovie+movies)->descripcion, getStringNum(auxChar));

    printf("\nIngrese el link de la imagen: ");
    fflush(stdin);
    gets(auxChar);

    strcpy((pMovie+movies)->linkImagen, auxChar);

    printf("\nIngrese la duracion: ");
    fflush(stdin);
    gets(auxChar);

    (pMovie+movies)->duracion = getIntRange(auxChar, 10, 400);

    printf("\nIngrese el puntaje: ");
    fflush(stdin);
    gets(auxChar);

    (pMovie+movies)->puntaje = getIntRange(auxChar, 1, 10);
}

int tituloRepetido(sMovie* pMovie, int movies, char cad[]) {

    int i;

    for (i = 0; i < movies; i++) {

        if (strcmpi(cad, (pMovie+i)->titulo) == 0) {

            return 1;

        }

    }

    return 0;
}

void modificarPelicula(sMovie* pMovie, int movies) {

    char auxChar[500];
    int opcion;
    int i;
    int index = -1;

    printf("\nLista de peliculas:\n");

    for (i = 0; i < movies; i++) {

        printf("\n%s", strupr((pMovie+i)->titulo));

    }

    printf("\n");

    printf("\nIngrese la pelicula que desea modificar: ");
    fflush(stdin);
    gets(auxChar);

    for (i = 0; i < movies; i++) {

        if (strcmpi((pMovie+i)->titulo, auxChar) == 0) {

            index = i;

        }

    }

    if (index != -1) {

        printf("\n1- Modificar titulo");
        printf("\n2- Modificar genero");
        printf("\n3- Modificar descripcion");
        printf("\n4- Modificar link de imagen");
        printf("\n5- Modificar duracion");
        printf("\n6- Modificar puntaje\n");

        printf("\nIngrese la opcion deseada: ");
        scanf("%i", &opcion);

        switch (opcion)
        {

            case 1:

                printf("\nIngrese el nuevo titulo: ");
                fflush(stdin);
                gets(auxChar);
                strcpy((pMovie+index)->titulo, getStringNum(auxChar));
                printf("\nSe modifico exitosamente la pelicula.\n");

                break;

            case 2:

                printf("Ingrese el nuevo genero: ");
                fflush(stdin);
                gets(auxChar);
                strcpy((pMovie+index)->genero, getString(auxChar));
                printf("\nSe modifico exitosamente la pelicula.\n");

                break;

            case 3:

                printf("Ingrese la nueva descripcion: ");
                fflush(stdin);
                gets(auxChar);
                strcpy((pMovie+index)->descripcion, getStringNum(auxChar));
                printf("\nSe modifico exitosamente la pelicula.\n");

                break;

            case 4:

                printf("Ingrese el nuevo link de imagen: ");
                fflush(stdin);
                gets(auxChar);
                strcpy((pMovie+index)->linkImagen, auxChar);
                printf("\nSe modifico exitosamente la pelicula.\n");

                break;

            case 5:

                printf("Ingrese la nueva duracion: ");
                fflush(stdin);
                gets(auxChar);
                (pMovie+index)->duracion = getIntRange(auxChar, 10, 400);
                printf("\nSe modifico exitosamente la pelicula.\n");

                break;

            case 6:

                printf("Ingrese el nuevo puntaje: ");
                fflush(stdin);
                gets(auxChar);
                (pMovie+index)->puntaje = getIntRange(auxChar, 1, 10);
                printf("\nSe modifico exitosamente la pelicula.\n");

                break;

            default:

                printf("\nOpcion invalida");
                break;

        }

    } else {

        printf("\nNo se encontro la pelicula especificada.\n");

    }

}

int cantPeliculas(FILE* pArchivo) {

    int cant = 0;
    int test;
    char lectura[2500];

    if((pArchivo = fopen("movies.dat", "rb")) == NULL) {

        printf("\nNo pudo ser abierto el archivo.");
        return -1;

    } else {

        while (!feof(pArchivo)) {

            test = fread(lectura, sizeof(sMovie), 1, pArchivo);

            if (test == 1) {

                cant++;

            }

        }

    }

    fclose(pArchivo);

    return cant;
}

void crearSitio(sMovie* pMovie, int contMovie) {

    FILE *pWeb;
    int i;

    pWeb = fopen("Movies.html","w");

    fprintf(pWeb, "<!DOCTYPE html>\
                      <html lang='en'>\
                          <head>\
                              <meta charset='utf-8'>\
                              <meta http-equiv='X-UA-Compatible' content='IE=edge'>\
                              <meta name='viewport' content='width=device-width, initial-scale=1'>\
                              <title>Lista peliculas</title>\
                              <link href='css/bootstrap.min.css' rel='stylesheet'>\
                              <link href='css/custom.css' rel='stylesheet'>\
                          </head>\
                          <body style = 'background-image: url(http://wallpaper-gallery.net/images/movie-background-wallpaper/movie-background-wallpaper-1.jpg)'>\
                              <div class='container'>\
                                  <div class='row'>");

    fprintf(pWeb,"<h1 style=\"margin-bottom:100px ; background-color:white ; text-align: center\"><a href='#'>Peliculas UTN</a></h1>");

    for(i = 0; i < contMovie; i++) {

        fprintf(pWeb,"<article class='col-md-4 article-intro'>\
                          <a href='#'>\
                            <img class='img-responsive img-rounded' src='%s' alt=''>\
                          </a>\n",(pMovie+i)->linkImagen);

        fprintf(pWeb,"<h3 style = 'background-color: white ; text-align: center'><a href='#'>%s</a></h3>\n",(pMovie+i)->titulo);

        fprintf(pWeb,"<ul style = 'background-color: white'>\
                          <li>Genero: %s</li>\n\
                          <li>Puntaje: %i</li>\n\
                          <li>Duracion: %i</li>\
                      </ul>\n",(pMovie+i)->genero,(pMovie+i)->puntaje,(pMovie+i)->duracion);

        fprintf(pWeb,"<p style = 'background-color: white'>\t%s</p></article>",(pMovie+i)->descripcion);

    }

    fprintf(pWeb,"</div>\
              </div>\
              <script src='js/jquery-1.11.3.min.js'></script>\
              <script src='js/bootstrap.min.js'></script>\
              <script src='js/ie10-viewport-bug-workaround.js'></script>\
              <script src='js/holder.min.js'></script>\
          </body>\
      </html>");

    printf("\nSe creo exitosamente la pagina web.\n");

    fclose(pWeb);
}

char* getString(char cadena[]) {

    int soloEsp = soloEspacios(cadena);
    int soloLet = soloLetras(cadena);

    while (soloEsp || !soloLet) {

        printf("Entrada invalida. Reingrese: ");
        fflush(stdin);
        gets(cadena);

        soloEsp = soloEspacios(cadena);
        soloLet = soloLetras(cadena);

    }

    return cadena;
}

char* getStringNum(char cadena[]) {

    int soloEsp = soloEspacios(cadena);
    int soloLetNum = soloLetrasONum(cadena);

    while (soloEsp || !soloLetNum) {

        printf("Entrada invalida. Reingrese: ");
        fflush(stdin);
        gets(cadena);

        soloEsp = soloEspacios(cadena);
        soloLetNum = soloLetrasONum(cadena);

    }

    return cadena;
}

int getIntRange(char cadena[], int min, int max) {

    int soloEsp = soloEspacios(cadena);
    int soloNum = soloNumeros(cadena);
    int valid = validarRangoInt(atoi(cadena), min, max);

    while (soloEsp || !soloNum || !valid) {

        printf("Entrada invalida. Reingrese: ");
        fflush(stdin);
        gets(cadena);

        soloEsp = soloEspacios(cadena);
        soloNum = soloNumeros(cadena);
        valid = validarRangoInt(atoi(cadena), min, max);

    }

    return atoi(cadena);
}

int getInt(char cadena[]) {

    int soloEsp = soloEspacios(cadena);
    int soloNum = soloNumeros(cadena);

    while (soloEsp || !soloNum) {

        printf("Entrada invalida. Reingrese: ");
        fflush(stdin);
        gets(cadena);

        soloEsp = soloEspacios(cadena);
        soloNum = soloNumeros(cadena);

    }

    return atoi(cadena);
}

int validarRangoInt(int num, int min, int max) {

    if (num >= min && num <= max) {

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

int soloLetrasONum(char nombre[]) {

    int i;
    int testLetra;
    int cantString = strlen(nombre);

    for (i = 0; i < cantString; i++) {

        testLetra = esLetraoNum(nombre[i]);

        if (testLetra == 1) {

            if (i == (cantString - 1)) {

                return 1;

            }

        } else {

            return 0;

        }

    }

}

int esLetraoNum(char a) {

    if ((a >= 65 && a <= 90) || (a >= 97 && a <= 122) || (a >= 160 && a <= 165) || (a == 32) || (a >= 48) || (a <= 57)) {

        return 1;

    } else {

        return 0;

    }

}

int esLetra(char a) {

    if ((a >= 65 && a <= 90) || (a >= 97 && a <= 122) || (a >= 160 && a <= 165) || (a == 32)) {

        return 1;

    } else {

        return 0;

    }

}

int esNum(char a) {

    if (a >= 48 && a <= 57) {

        return 1;

    } else {

        return 0;

    }

}
