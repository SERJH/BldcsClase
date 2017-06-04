#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

#include <stdlib.h>
#include <stdio.h>

typedef struct{

    char titulo[50];
    char genero[20];
    char descripcion[500];
    char linkImagen[500];
    int duracion;
    int puntaje;

} sMovie;

/** \brief Calcula la cantidad de peliculas en el archivo binario
  *
  * \param Archivo
  *
  * \return Cantidad de peliculas
  */

int cantPeliculas(FILE* pArchivo);

/** \brief Crea un archivo html con las peliculas cargadas
  *
  * \param Puntero de peliculas
  * \param Cantidad de peliculas
  *
  * \return No devuelve nada
  */

void crearSitio(sMovie* pMovie, int contMovie);

/** \brief Checkea si un caracter es letra o numero
  *
  * \param Caracter a checkear
  *
  * \return 1 si lo es, 0 de lo contrario
  */

int esLetraoNum(char a);

/** \brief Checkea si un caracter es letra
 *
 * \param Caracter a checkear
 *
 * \return 1 si lo es, 0 de lo contrario
 *
 */

int esLetra(char a);

/** \brief Checkea si un caracter es numero
 *
 * \param Caracter a checkear
 *
 * \return 1 si lo es, 0 de lo contrario
 */

int esNum(char a);

/** \brief Carga el archivo binario con peliculas
 *
 * \param Archivo binario
 * \param Puntero de peliculas
 * \param Cantidad de peliculas
 *
 * \return No devuelve nada
 */

void cargarArchivo(FILE* pArchivo, sMovie* pMovie, int cantMovies);

/** \brief Modifica una pelicula
 *
 * \param Puntero de peliculas
 * \param Cantidad de peliculas
 *
 * \return No devuelve nada
 */

void modificarPelicula(sMovie* pMovie, int movies);

/** \brief Valida entrada de string
 *
 * \param Cadena a validar
 *
 * \return Cadena validada
 */

char* getString(char cadena[]);

/** \brief Valida entrada de string con numeros
 *
 * \param Cadena a validar
 *
 * \return Cadena validada
 */

char* getStringNum(char cadena[]);

/** \brief Ingreso de datos de la pelicula a cargar
 *
 * \param Puntero de peliculas
 * \param Cantidad de peliculas
 *
 * \return No devuelve nada
 */

void ingresoDatosPelicula(sMovie* pMovie, int movies);

/** \brief Valida entrada de un entero con rango
 *
 * \param Cadena a validar
 * \param Rango minimo
 * \param Rango maximo
 *
 * \return Entero validado
 */

int getIntRange(char cadena[], int min, int max);

/** \brief Comprueba si en una cadena solo hay espacios
 *
 * \param Cadena a validar
 *
 * \return 1 si hay solo espacios, 0 de lo contrario
 */

int soloEspacios(char nombre[]);

/** \brief Comprueba si en una cadena solo hay letras (o espacios)
 *
 * \param Cadena a validar
 *
 * \return 1 si hay solo hay letras (o espacios), 0 de lo contrario
 */

int soloLetras(char nombre[]);

/** \brief Comprueba si en una cadena solo hay letras o numeros (o espacios)
 *
 * \param Cadena a validar
 *
 * \return 1 si hay solo hay letras o numeros (o espacios), 0 de lo contrario
 */

int soloLetrasONum(char nombre[]);

/** \brief Comprueba si en una cadena solo hay numeros
 *
 * \param Cadena a validar
 *
 * \return 1 si hay solo hay numeros, 0 de lo contrario
 */

int soloNumeros(char num[]);

/** \brief Muestra el menu principal
 *
 * \param Archivo binario
 *
 * \return No devuelve nada
 */

void mostrarMenu(FILE* pArchivo);

/** \brief Comprueba si un numero en un rango especificado
 *
 * \param Numero a validar
 * \param Rango minimo
 * \param Rango maximo
 *
 * \return 1 si esta dentro del rango, 0 de lo contrario
 */

int validarRangoInt(int num, int min, int max);

/** \brief Comprueba si un titulo esta repetido
 *
 * \param Puntero de peliculas
 * \param Cantidad de peliculas
 * \param Cadena a checkear
 *
 * \return 1 si se repite, 0 de lo contrario
 */

int tituloRepetido(sMovie* pMovie, int movies, char cad[]);

/** \brief Agrega una pelicula al puntero
 *
 * \param Puntero de peliculas
 * \param Cantidad de peliculas
 *
 * \return retorna 1 o 0 de acuerdo a si pudo agregar la pelicula o no
 */

int agregarPelicula(sMovie* movie, int movies, int* tam);

/** \brief Borra una pelicula del puntero
 *
 * \param Puntero de peliculas
 * \param Cantidad de peliculas
 *
 * \return 1 si la borro, 0 de lo contrario
 */

int borrarPelicula(sMovie* pMovie, int contMovies);

#endif // FUNCIONES_H_INCLUDED
