#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

#include <stdlib.h>
#include <stdio.h>
#include "ArrayList.h"

#define CODIGO 1
#define MODELADO 2
#define ANIMACION 3
#define CINEMATICA 4
#define MARKETING 5

typedef struct {

    char nombre[50];
    int especialidad;

} sEmpleado;

typedef struct {

    int diagramas;
    int implementacion;
    int testeo;
    ArrayList* equipo;
    int estado;

} sCodigo;

typedef struct {

    int boceto;
    int arte;
    int implementacion;
    ArrayList* equipo;
    int estado;

} sModelado;

typedef struct {

    int animado;
    int implementacion;
    ArrayList* equipo;
    int estado;

} sAnimacion;

typedef struct {

    int ambientacion;
    int historia;
    ArrayList* equipo;
    int presentada;
    int estado;

} sCinematica;

typedef struct {

    int publicidades;
    ArrayList* equipo;
    int iniciado;
    int estado;

} sMarketing;

typedef struct {

    char nombre[50];
    char genero[50];
    sCodigo* codigo;
    sModelado* modelado;
    sAnimacion* animacion;
    sCinematica* cinematica;
    sMarketing* marketing;
    int estado;

} sJuego;

/** \brief Muestra un menu
 *
 *
 * \return No devuelve nada
 */

void mostrarMenu();

/** \brief Muestra un menu
 *
 *
 * \return No devuelve nada
 */

void mostrarMenu1();

/** \brief Muestra un menu
 *
 *
 * \return No devuelve nada
 */

void mostrarMenu3();

/** \brief Muestra un menu
 *
 * \param Arraylist juegos
 *
 * \return No devuelve nada
 */

void mostrarMenu3a(ArrayList* juegosEnDesarrollo);

/** \brief Muestra un menu
 *
 *
 * \return No devuelve nada
 */

void mostrarMenu3b();

/** \brief Muestra un menu
 *
 *
 * \return No devuelve nada
 */

void mostrarMenu3b2();

/** \brief Muestra un menu
 *
 *
 * \return No devuelve nada
 */

void menuUpdateCodigo();

/** \brief Muestra un menu
 *
 *
 * \return No devuelve nada
 */

void menuUpdateModelado();

/** \brief Muestra un menu
 *
 *
 * \return No devuelve nada
 */

void menuUpdateAnimacion();

/** \brief Muestra un menu
 *
 *
 * \return No devuelve nada
 */

void menuUpdateAnimacion();

/** \brief Muestra un menu
 *
 *
 * \return No devuelve nada
 */

void menuUpdateMarketing();

/** \brief Switch del menu en una funcion para organizar mejor
 *
 * \param Arraylist juegos en desarrollo
 * \param Arraylist juegos desarrollados
 * \param Empleados codigo
 * \param Empleados codigo ocupados
 * \param Empleados modelado
 * \param Empleados modelado ocupados
 * \param Empleados animacion
 * \param Empleados animacion ocupados
 * \param Empleados cinematica
 * \param Empleados cinematica ocupados
 * \param Empleados marketing
 * \param Empleados marketing ocupados
 *
 * \return No devuelve nada
 */

void switches1(ArrayList* juegosEnDesarrollo, ArrayList* juegosDesarrollados, ArrayList* empleadosCodigo, ArrayList* empleadosCodigoOcupados, ArrayList* empleadosModelado, ArrayList* empleadosModeladoOcupados, ArrayList* empleadosAnimacion, ArrayList* empleadosAnimacionOcupados, ArrayList* empleadosCinematica, ArrayList* empleadosCinematicaOcupados, ArrayList* empleadosMarketing, ArrayList* empleadosMarketingOcupados);

/** \brief Switch del menu en una funcion para organizar mejor
 *
 * \param Arraylist juegos en desarrollo
 * \param index
 *
 * \return No devuelve nada
 */

void switches2(ArrayList* juegosEnDesarrollo, int index);

/** \brief Muestra un empleado
 *
 * \param Empleado a mostrar
 *
 * \return No devuelve nada
 */

void printEmpleado(sEmpleado* empleado);

/** \brief Muestra un juego
 *
 * \param Juego a mostrar
 *
 * \return No devuelve nada
 */

void printJuego(sJuego* juego);

/** \brief Muestra un arraylist de juegos
 *
 * \param Juegos a mostrar
 *
 * \return No devuelve nada
 */

void printJuegosArray(ArrayList* arrList);

/** \brief Muestra un arraylist de juegos con indice
 *
 * \param Juegos a mostrar
 *
 * \return No devuelve nada
 */

void printJuegosArrayInd(ArrayList* arrList);

/** \brief Muestra todos los empleados con sus categorias
 *
 * \param Empleados codigo
 * \param Empleados modelado
 * \param Empleados animacion
 * \param Empleados cinematica
 * \param Empleados marketing
 *
 * \return No devuelve nada
 */

void printTodosCategoria(ArrayList* codigo, ArrayList* modelado, ArrayList* animacion, ArrayList* cinematica, ArrayList* marketing);

/** \brief Muestra un arraylist de empleados
 *
 * \param Empleados a mostrar
 *
 * \return No devuelve nada
 */

void printEmpleadosArray(ArrayList* arrList);

/** \brief Completa una tarea
 *
 * \param Juegos
 * \param Index
 *
 * \return No devuelve nada
 */

void actualizarCodigoDiagrama(ArrayList* juegos, int index);

/** \brief Completa una tarea
 *
 * \param Juegos
 * \param Index
 *
 * \return No devuelve nada
 */

void actualizarCodigoImplementacion(ArrayList* juegos, int index);

/** \brief Completa una tarea
 *
 * \param Juegos
 * \param Index
 *
 * \return No devuelve nada
 */

void actualizarCodigoTesteo(ArrayList* juegos, int index);

/** \brief Completa una tarea
 *
 * \param Juegos
 * \param Index
 *
 * \return No devuelve nada
 */

void actualizarModeladoBoceto(ArrayList* juegos, int index);

/** \brief Completa una tarea
 *
 * \param Juegos
 * \param Index
 *
 * \return No devuelve nada
 */

void actualizarModeladoArte(ArrayList* juegos, int index);

/** \brief Completa una tarea
 *
 * \param Juegos
 * \param Index
 *
 * \return No devuelve nada
 */

void actualizarModeladoImplementacion(ArrayList* juegos, int index);

/** \brief Completa una tarea
 *
 * \param Juegos
 * \param Index
 *
 * \return No devuelve nada
 */

void actualizarAnimacionAnimado(ArrayList* juegos, int index);

/** \brief Completa una tarea
 *
 * \param Juegos
 * \param Index
 *
 * \return No devuelve nada
 */

void actualizarAnimacionImplementacion(ArrayList* juegos, int index);

/** \brief Completa una tarea
 *
 * \param Juegos
 * \param Index
 *
 * \return No devuelve nada
 */

void actualizarCinematicaAmbientacion(ArrayList* juegos, int index);

/** \brief Completa una tarea
 *
 * \param Juegos
 * \param Index
 *
 * \return No devuelve nada
 */

void actualizarCinematicaHistoria(ArrayList* juegos, int index);

/** \brief Completa una tarea
 *
 * \param Juegos
 * \param Index
 *
 * \return No devuelve nada
 */

void actualizarMarketingPublicidades(ArrayList* juegos, int index);

/** \brief Crea un nuevo empleado
 *
 * \param Nombre
 * \param Especialidad
 *
 * \return Puntero a sEmpleado
 */

sEmpleado* nuevoEmpleado(char nombre[], int especialidad);

/** \brief Crea un nuevo codigo
 *
 * \param Equipo
 *
 * \return Puntero a sCodigo
 */

sCodigo* nuevoCodigo(ArrayList* equipo);

/** \brief Crea un nuevo modelado
 *
 * \param Equipo
 *
 * \return Puntero a sModelado
 */

sModelado* nuevoModelado(ArrayList* equipo);

/** \brief Crea una nueva animacion
 *
 * \param Equipo
 *
 * \return Puntero a sAnimacion
 */

sAnimacion* nuevoAnimacion(ArrayList* equipo);

/** \brief Crea una nueva cinematica
 *
 * \param Equipo
 *
 * \return Puntero a sCinematica
 */

sCinematica* nuevoCinematica(ArrayList* equipo);

/** \brief Crea un nuevo marketing
 *
 * \param Equipo
 *
 * \return Puntero a sMarketing
 */

sMarketing* nuevoMarketing(ArrayList* equipo);

/** \brief Crea un nuevo juego
 *
 * \param Nombre
 * \param Genero
 * \param Codigo
 * \param Modelado
 * \param Animacion
 * \param Cinematica
 * \param Marketing
 *
 * \return Puntero a sJuego
 */

sJuego* nuevoJuego(char nombre[], char genero[], sCodigo* codigo, sModelado* modelado, sAnimacion* animacion, sCinematica* cinematica, sMarketing* marketing);

/** \brief Publica un juego
 *
 * \param Juegos en desarrollo
 * \param Juegos desarrollados
 * \param Index
 *
 * \return No devuelve nada
 */

void publicarJuego(ArrayList* juegosEnDesarrollo, ArrayList* juegosDesarrollados, int index);

/** \brief Libera empleados que anteriormente estaban en un proyecto pero concluyeron
 *
 * \param Empleados
 * \param Empleados ocupados
 *
 * \return No devuelve nada
 */

void liberarEmpleados(ArrayList* empleados, ArrayList* empleadosOcupados);

/** \brief Presenta la cinematica
 *
 * \param Juegos en desarrollo
 * \param Index
 *
 * \return No devuelve nada
 */

void presentarCinematica(ArrayList* juegosEnDesarrollo, int index);

/** \brief Inicia el marketing
 *
 * \param Juegos en desarrollo
 * \param Index
 *
 * \return No devuelve nada
 */

void iniciarMarketing(ArrayList* juegosEnDesarrollo, int index);

/** \brief Checkea si la cinematica fue publicada
 *
 * \param Juegos
 * \param Index
 *
 * \return 1 si fue publicada, 0 de lo contrario
 */

int cinematicaPublicada(ArrayList* juegos, int index);

/** \brief Checkea si el marketing fue iniciado
 *
 * \param Juegos
 * \param Index
 *
 * \return 1 si fue iniciado, 0 de lo contrario
 */

int marketingIniciado(ArrayList* juegos, int index);

/** \brief Carga empleados a los equipos de trabajo
 *
 * \param Lista empleados
 * \param Lista empleados ocupados
 * \param Equipo
 *
 * \return No devuelve nada
 */

void cargarEmpleadosEquipo(ArrayList* lista, ArrayList* listaOcupados, ArrayList* equipo);

/** \brief Checkea si un equipo de trabajo esta vacio
 *
 * \param Juegos
 * \param Index
 *
 * \return 1 si esta vacio, 0 de lo contrario
 */

int equipoCodigoVacio(ArrayList* juegos, int index);

/** \brief Checkea si un equipo de trabajo esta vacio
 *
 * \param Juegos
 * \param Index
 *
 * \return 1 si esta vacio, 0 de lo contrario
 */

int equipoModeladoVacio(ArrayList* juegos, int index);

/** \brief Checkea si un equipo de trabajo esta vacio
 *
 * \param Juegos
 * \param Index
 *
 * \return 1 si esta vacio, 0 de lo contrario
 */

int equipoAnimacionVacio(ArrayList* juegos, int index);

/** \brief Checkea si un equipo de trabajo esta vacio
 *
 * \param Juegos
 * \param Index
 *
 * \return 1 si esta vacio, 0 de lo contrario
 */

int equipoCinematicaVacio(ArrayList* juegos, int index);

/** \brief Checkea si un equipo de trabajo esta vacio
 *
 * \param Juegos
 * \param Index
 *
 * \return 1 si esta vacio, 0 de lo contrario
 */

int equipoMarketingVacio(ArrayList* juegos, int index);

/** \brief Checkea si un sector termino su trabajo
 *
 * \param Juegos
 * \param Index
 *
 * \return 1 si lo termino, 0 de lo contrario
 */

int sectorCompletoCodigo(ArrayList* juegos, int index);

/** \brief Checkea si un sector termino su trabajo
 *
 * \param Juegos
 * \param Index
 *
 * \return 1 si lo termino, 0 de lo contrario
 */

int sectorCompletoModelado(ArrayList* juegos, int index);

/** \brief Checkea si un sector termino su trabajo
 *
 * \param Juegos
 * \param Index
 *
 * \return 1 si lo termino, 0 de lo contrario
 */

int sectorCompletoAnimacion(ArrayList* juegos, int index);

/** \brief Checkea si un sector termino su trabajo
 *
 * \param Juegos
 * \param Index
 *
 * \return 1 si lo termino, 0 de lo contrario
 */

int sectorCompletoCinematica(ArrayList* juegos, int index);

/** \brief Checkea si un sector termino su trabajo
 *
 * \param Juegos
 * \param Index
 *
 * \return 1 si lo termino, 0 de lo contrario
 */

int sectorCompletoMarketing(ArrayList* juegos, int index);

/** \brief Inicializa los empleados en cada sector
 *
 * \param Empleados
 * \param Empleados codigo
 * \param Empleados modelado
 * \param Empleados animacion
 * \param Empleados cinematica
 * \param Empleados marketing
 *
 * \return No devuelve nada
 */

void inicializarEmpleados(ArrayList* empleados, ArrayList* empleadosCodigo, ArrayList* empleadosModelado, ArrayList* empleadosAnimacion, ArrayList* empleadosCinematica, ArrayList* empleadosMarketing);

/** \brief Valida un char para que sea solo una de dos opciones
 *
 * \param Opcion 1
 * \param Opcion 2
 *
 * \return Devuelve una de las dos opciones
 */

 char validarChar(char opcion1, char opcion2);

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

/** \brief Valida entrada de string
 *
 * \return Cadena validada
 */

char* getString();

/** \brief Valida entrada de string con numeros
 *
 * \return Cadena validada
 */

char* getStringNum();

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */


int getInt();

/** \brief Valida entrada de un entero con rango
 *
 * \param Rango minimo
 * \param Rango maximo
 *
 * \return Entero validado
 */

int getIntRange(int min, int max);

/** \brief Comprueba si en una cadena solo hay espacios
 *
 * \return 1 si hay solo espacios, 0 de lo contrario
 */

int soloEspacios();

/** \brief Comprueba si en una cadena solo hay letras (o espacios)
 *
 * \return 1 si hay solo hay letras (o espacios), 0 de lo contrario
 */

int soloLetras();

/** \brief Comprueba si en una cadena solo hay letras o numeros (o espacios)
 *
 * \return 1 si hay solo hay letras o numeros (o espacios), 0 de lo contrario
 */

int soloLetrasONum();

/** \brief Comprueba si en una cadena solo hay numeros
 *
 * \return 1 si hay solo hay numeros, 0 de lo contrario
 */

int soloNumeros();

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

#endif // FUNCIONES_H_INCLUDED

