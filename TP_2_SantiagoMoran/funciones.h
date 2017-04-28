#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct {

    char nombre[50];
    int edad;
    int dni;
    int estado;

} sPersona;

/** \brief Muestra el menu principal
  *
  *  \param No lleva parametros
  *
  *  \return No devuelve nada
  */

void mostrarMenu();

/** \brief Inicializa el vector de personas para que todas tengan 0 como estado inicial
  *
  * \param Vector de personas
  * \param Tamaño del vector
  *
  * \return No devuelve nada
  */

void startupPersonas(sPersona personas[], int tam);

/** \brief Valida un entero para que solo pueda estar entre un determinado rango ingresado
  *
  * \param Minimo
  * \param Maximo
  *
  * \return Devuelve el entero validado
  */

int validarRangoInt(int num, int min, int max);

/** \brief Comprueba si en la cadena ingresada solo hay espacios
  *
  * \param Cadena a checkear
  *
  * \return Devuelve 1 si son todos espacios y 0 de lo contrario
  */

int soloEspacios(char nombre[]);

/** \brief Comprueba si la cadena ingresada contiene solo letras (o espacios)
  *
  * \param Cadena a checkear
  *
  * \return Devuelve 1 si son todas letras (o espacios) y 0 de lo contrario
  */

int soloLetras(char nombre[]);

/** \brief Comprueba si un caracter ingresado es una letra (o espacio)
  *
  * \param Caracter a checkear
  *
  * \return Devuelve 1 si es una letra (o espacio) y 0 de lo contrario
  */

int esLetra(char a);

/** \brief Comprueba si la cadena ingresada contiene solo numeros
  *
  * \param Cadena a checkear
  *
  * \return Devuelve 1 si son todos numeros y 0 de lo contrario
  */

int soloNumeros(char num[]);

/** \brief Comprueba si un caracter ingresado es un numero
  *
  * \param Caracter a checkear
  *
  * \return Devuelve 1 si es un numero y 0 de lo contrario
  */

int esNum(char a);

/** \brief Valida un caracter ingresado para que solo pueda ser una de las dos opciones dadas
  *
  * \param Caracter a validar
  * \param Posible caracter opcion 1
  * \param Posible caracter opcion 2
  *
  * \return Devuelve el caracter validado
  */

char validarChar(char caracter, char opcion1, char opcion2);

/** \brief Comprueba si un DNI ingresado esta repetido en un vector de personas dado
  *
  * \param Numero de DNI a comparar
  * \param Vector de personas
  * \param Tamaño del vector de personas
  *
  * \return Devuelve 1 si el DNI ya se encuentra en el vector personas y 0 de lo contrario
  */

int dniRepetido(int dni, sPersona personas[], int tam);

/**
  * \brief Obtiene el primer indice libre del array
  *
  * \param Vector en el que se quiere buscar lugar
  * \param Tamaño del vector dado
  *
  * \return El primer indice disponible
  */

int obtenerEspacioLibre(sPersona personas[], int tam);

/**
  * \brief Obtiene el indice que coincide con el dni pasado por parametro
  *
  * \param Vector en el que se quiere buscar el DNI
  * \param Tamaño del vector dado
  *
  * \return El indice en donde se encuentra el elemento que coincide con el parametro dni
  */

int buscarPorDni(sPersona personas[], int tam);

/** \brief Pide confirmacion antes de borrar la persona que se pidio
  *
  * \param Vector de personas
  * \param Index en el que se encuentra la persona que se busca borrar
  *
  * \return Devuelve S si se decidio continuar y N de lo contrario
  */

char confirmarBorrado(sPersona personas[], int index);

/** \brief Borra a una persona cambiando su estado a 0
  *
  * \param Vector de personas
  * \param Index en el que se encuentra la persona que se busca borrar
  *
  * \return No devuelve nada
  */

void borrarPersona(sPersona personas[], int index);

/**
  * \brief Carga una persona al sistema
  *
  * \param Lista de personas
  * \param Indice donde hay espacio libre
  *
  * \return No devuelve nada
  */

void cargarPersona(sPersona persona[], int libre);

/** \brief Comprueba si hay personas ingresadas
  *
  * \param Vector de personas a checkear
  * \param Tamaño del vector
  *
  * \return Devuelve 1 si hay personas ingresadas y 0 de lo contrario
  */

int hayPersonas(sPersona personas[], int tam);

/** \brief Muestra la lista ordenada de personas (Nombre -- Edad -- DNI)
  *
  * \param Vector de personas
  * \param Tamaño del vector
  *
  * \return No devuelve nada
  */

void mostrarLista(sPersona personas[], int tam);

/** \brief Imprime un grafico de barras que indica la cantidad de personas en cada grupo de edad
  *
  * \param Vector de personas
  * \param Tamaño del vector
  *
  * \return No devuelve nada
  */

void imprimirGrafico(sPersona personas[], int tam);

#endif // FUNCIONES_H_INCLUDED
