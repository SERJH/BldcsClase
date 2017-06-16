#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "funciones.h"
#include "ArrayList.h"

//                                          ********** MENUES **********

void mostrarMenu() {

    printf("\n\n\t\t\t\t~ Bienvenido ~\n\n");

    printf("1- Agregar pelicula\n");
    printf("2- Borrar pelicula\n");
    printf("3- Modificar pelicula\n");
    printf("4- Generar pagina web\n");
    printf("5- Salir\n");

    printf("\nIngrese la opcion deseada: ");

}

void mostrarMenu1() {

    system("cls");

    printf("\n\t\t~ Blizzard ~\n\n");
    printf("1- Listar empleados disponibles\n");
    printf("2- Listar empleados ocupados\n");

    printf("\nIngrese la opcion deseada: ");

}

void mostrarMenu3() {

    system("cls");

    printf("\n\t\t~ Blizzard ~\n\n");
    printf("1- Solo mostrar todos los juegos en desarrollo\n");
    printf("2- Acciones sobre los juegos\n");

    printf("\nIngrese la opcion deseada: ");

}

void mostrarMenu3a(ArrayList* juegosEnDesarrollo) {

    system("cls");
    printf("\n\t\t~ Blizzard ~\n\n");
    printJuegosArrayInd(juegosEnDesarrollo);

    printf("\nIngrese el indice del juego deseado: ");

}

void mostrarMenu3b() {

    system("cls");
    printf("\n\t\t~ Blizzard ~\n\n");
    printf("1- Asignar empleados a equipos de trabajo\n");
    printf("2- Marcar tarea como completa\n");
    printf("3- Presentar cinematica\n");
    printf("4- Iniciar marketing\n");
    printf("5- Publicar juego\n");

    printf("\nIngrese la opcion deseada: ");

}

void mostrarMenu3b2() {

    system("cls");
    printf("\n\t\t~ Blizzard ~\n\n");
    printf("1- Codigo\n");
    printf("2- Modelado\n");
    printf("3- Animacion\n");
    printf("4- Cinematica\n");
    printf("5- Marketing\n");

    printf("\nIngrese la opcion deseada: ");

}

void menuUpdateCodigo() {

    system("cls");
    printf("\n\t\t~ Blizzard ~\n\n");
    printf("1- Diagrama completo\n");
    printf("2- Implementacion completa\n");
    printf("3- Testeo completo\n");

    printf("\nIngrese la opcion deseada: ");

}

void menuUpdateModelado() {

    system("cls");
    printf("\n\t\t~ Blizzard ~\n\n");
    printf("1- Boceto completo\n");
    printf("2- Arte completo\n");
    printf("3- Implementacion completa\n");

    printf("\nIngrese la opcion deseada: ");

}

void menuUpdateAnimacion() {

    system("cls");
    printf("\n\t\t~ Blizzard ~\n\n");
    printf("1- Animado completo\n");
    printf("2- Implementacion completa\n");

    printf("\nIngrese la opcion deseada: ");

}

void menuUpdateCinematica() {

    system("cls");
    printf("\n\t\t~ Blizzard ~\n\n");
    printf("1- Ambientacion completa\n");
    printf("2- Historia completa\n");

    printf("\nIngrese la opcion deseada: ");

}

void menuUpdateMarketing() {

    system("cls");
    printf("\n\t\t~ Blizzard ~\n\n");
    printf("1- Publicidades completas\n");

    printf("\nIngrese la opcion deseada: ");

}

void switches1(ArrayList* juegosEnDesarrollo, ArrayList* juegosDesarrollados, ArrayList* empleadosCodigo, ArrayList* empleadosCodigoOcupados, ArrayList* empleadosModelado, ArrayList* empleadosModeladoOcupados, ArrayList* empleadosAnimacion, ArrayList* empleadosAnimacionOcupados, ArrayList* empleadosCinematica, ArrayList* empleadosCinematicaOcupados, ArrayList* empleadosMarketing, ArrayList* empleadosMarketingOcupados) {

    int opcionIn;
    int index;

    mostrarMenu3();
    opcionIn = getIntRange(1,2);

    switch (opcionIn)
    {

        case 1:
            printJuegosArray(juegosEnDesarrollo);
            break;

        case 2:
            mostrarMenu3a(juegosEnDesarrollo);
            index = getIntRange(1,juegosEnDesarrollo->len(juegosEnDesarrollo));
            index -= 1;
            mostrarMenu3b();
            opcionIn = getIntRange(1,6);

            switch (opcionIn)
            {

                case 1:
                    mostrarMenu3b2();
                    opcionIn = getIntRange(1,5);

                    switch (opcionIn)
                    {

                        case 1:
                            cargarEmpleadosEquipo(empleadosCodigo, empleadosCodigoOcupados, ((sJuego*)juegosEnDesarrollo->pElements[index])->codigo->equipo);
                            break;
                        case 2:
                            cargarEmpleadosEquipo(empleadosModelado, empleadosModeladoOcupados, ((sJuego*)juegosEnDesarrollo->pElements[index])->modelado->equipo);
                            break;
                        case 3:
                            cargarEmpleadosEquipo(empleadosAnimacion, empleadosAnimacionOcupados, ((sJuego*)juegosEnDesarrollo->pElements[index])->animacion->equipo);
                            break;
                        case 4:
                            cargarEmpleadosEquipo(empleadosCinematica, empleadosCinematicaOcupados, ((sJuego*)juegosEnDesarrollo->pElements[index])->cinematica->equipo);
                            break;
                        case 5:
                            cargarEmpleadosEquipo(empleadosMarketing, empleadosMarketingOcupados, ((sJuego*)juegosEnDesarrollo->pElements[index])->marketing->equipo);
                            break;

                    }
                    break;
                case 2:

                    switches2(juegosEnDesarrollo, index);
                    break;

                case 3:

                    if (sectorCompletoCinematica(juegosEnDesarrollo, index) == 1) {

                        presentarCinematica(juegosEnDesarrollo, index);

                    } else {

                        printf("\nEl equipo de cinematica aun no ha terminado su trabajo\n");

                    }
                    break;

                case 4:

                    if (sectorCompletoMarketing(juegosEnDesarrollo, index) == 1) {

                        if (cinematicaPublicada(juegosEnDesarrollo, index) == 1) {

                            iniciarMarketing(juegosEnDesarrollo, index);

                        } else {

                            printf("\nPara iniciar el marketing se debe anteriormente haber publicado la cinematica\n");

                        }

                    } else {

                        printf("\nEl equipo de marketing aun no terminado su trabajo\n");

                    }
                    break;

                case 5:

                    if (cinematicaPublicada(juegosEnDesarrollo, index) == 1 && marketingIniciado(juegosEnDesarrollo, index) == 1) {

                        publicarJuego(juegosEnDesarrollo, juegosDesarrollados, index);
                        liberarEmpleados(empleadosCodigo, empleadosCodigoOcupados);
                        liberarEmpleados(empleadosModelado, empleadosModeladoOcupados);
                        liberarEmpleados(empleadosAnimacion, empleadosAnimacionOcupados);
                        liberarEmpleados(empleadosCinematica, empleadosCinematicaOcupados);
                        liberarEmpleados(empleadosMarketing, empleadosMarketingOcupados);

                    } else {

                        printf("\nPara publicar el juego la cinematica debe ser publicada y el marketing debe ser iniciado\n");

                    }
                    break;

            }

            break;

    }

}

void switches2(ArrayList* juegosEnDesarrollo, int index) {

    int opcionIn;

    mostrarMenu3b2();
    opcionIn = getIntRange(1,5);

    switch (opcionIn)
    {
        case 1:
            if (sectorCompletoCodigo(juegosEnDesarrollo, index) == 0) {
                if (equipoCodigoVacio(juegosEnDesarrollo, index) == 0) {

                    menuUpdateCodigo();
                    opcionIn = getIntRange(1,3);
                    switch(opcionIn)
                    {
                        case 1:
                            actualizarCodigoDiagrama(juegosEnDesarrollo, index);
                            break;
                        case 2:
                            actualizarCodigoImplementacion(juegosEnDesarrollo, index);
                            break;
                        case 3:
                            actualizarCodigoTesteo(juegosEnDesarrollo, index);
                            break;
                    }
                } else {

                    printf("\nEl equipo de coders no cuenta con integrantes. Asigne para avanzar con las tareas.\n");

                }

            } else {

                printf("\nEl equipo de codigo ya completo todas sus tareas\n");

            }

            break;
        case 2:
            if (sectorCompletoModelado(juegosEnDesarrollo, index) == 0) {
                if (equipoModeladoVacio(juegosEnDesarrollo, index) == 0) {

                    menuUpdateModelado();
                    opcionIn = getIntRange(1,3);
                    switch(opcionIn)
                    {
                        case 1:
                            actualizarModeladoBoceto(juegosEnDesarrollo, index);
                            break;
                        case 2:
                            actualizarModeladoArte(juegosEnDesarrollo, index);
                            break;
                        case 3:
                            actualizarModeladoImplementacion(juegosEnDesarrollo, index);
                            break;
                    }
                } else {

                    printf("\nEl equipo de modeladores no cuenta con integrantes. Asigne para avanzar con las tareas.\n");

                }
            } else {

                printf("\nEl equipo de modelado ya completo todas sus tareas\n");

            }

            break;
        case 3:
            if (sectorCompletoAnimacion(juegosEnDesarrollo, index) == 0) {
                if (equipoAnimacionVacio(juegosEnDesarrollo, index) == 0) {

                    menuUpdateAnimacion();
                    opcionIn = getIntRange(1,2);
                    switch(opcionIn)
                    {
                        case 1:
                            actualizarAnimacionAnimado(juegosEnDesarrollo, index);
                            break;
                        case 2:
                            actualizarAnimacionImplementacion(juegosEnDesarrollo, index);
                            break;
                    }
                } else {

                    printf("\nEl equipo de animadores no cuenta con integrantes. Asigne para avanzar con las tareas.\n");

                }
            } else {

                printf("\nEl equipo de animacion ya completo todas sus tareas\n");

            }

            break;
        case 4:
            if (sectorCompletoCinematica(juegosEnDesarrollo, index) == 0) {
                if (equipoCinematicaVacio(juegosEnDesarrollo, index) == 0) {

                    menuUpdateCinematica();
                    opcionIn = getIntRange(1,2);
                    switch(opcionIn)
                    {
                        case 1:
                            actualizarCinematicaHistoria(juegosEnDesarrollo, index);
                            break;
                        case 2:
                            actualizarCinematicaAmbientacion(juegosEnDesarrollo, index);
                            break;
                    }
                } else {

                    printf("\nEl equipo de cineastas no cuenta con integrantes. Asigne para avanzar con las tareas.\n");

                }
            } else {

                printf("\nEl equipo de cinematica ya completo todas sus tareas\n");

            }

            break;
        case 5:
            if (sectorCompletoMarketing(juegosEnDesarrollo, index) == 0) {
                if (equipoMarketingVacio(juegosEnDesarrollo, index) == 0) {

                    menuUpdateMarketing();
                    opcionIn = getIntRange(1,1);
                    switch(opcionIn)
                    {
                        case 1:
                            actualizarMarketingPublicidades(juegosEnDesarrollo, index);
                            break;
                    }
                } else {

                    printf("\nEl equipo de vendedores no cuenta con integrantes. Asigne para avanzar con las tareas.\n");

                }
            } else {

                printf("\nEl equipo de marketing ya completo todas sus tareas\n");

            }

            break;
    }

}



//                                          ********** PRINTERS **********


// Print Empleado

void printEmpleado(sEmpleado* empleado) {

    printf("NOMBRE: %s\n", empleado->nombre);

}

void printJuego(sJuego* juego) {

    printf("NOMBRE: %s\tGENERO: %s\n", juego->nombre, juego->genero);

}

void printJuegosArray(ArrayList* arrList) {

    int i;
    int tam;

    if (arrList != NULL) {

        tam = arrList->len(arrList);

        for (i = 0; i < tam; i++) {

            sJuego* aux = arrList->get(arrList,i);
            //printf("%i- ", i);
            printJuego(aux);

        }

    }

}

void printJuegosArrayInd(ArrayList* arrList) {

    int i;
    int tam;

    if (arrList != NULL) {

        tam = arrList->len(arrList);

        for (i = 0; i < tam; i++) {

            sJuego* aux = arrList->get(arrList,i);
            printf("%i- ", i+1);
            printJuego(aux);

        }

    }

}

void printTodosCategoria(ArrayList* codigo, ArrayList* modelado, ArrayList* animacion, ArrayList* cinematica, ArrayList* marketing) {

    printf("\nProgramadores:\n\n");
    printEmpleadosArray(codigo);
    printf("\nModeladores:\n\n");
    printEmpleadosArray(modelado);
    printf("\nAnimadores:\n\n");
    printEmpleadosArray(animacion);
    printf("\nCineastas:\n\n");
    printEmpleadosArray(cinematica);
    printf("\nVendedores:\n\n");
    printEmpleadosArray(marketing);

}

// Print ArrayList Empleados

void printEmpleadosArray(ArrayList* arrList) {

    int i;
    int tam;

    if (arrList != NULL) {

        tam = arrList->len(arrList);

        for (i = 0; i < tam; i++) {

            sEmpleado* aux = arrList->get(arrList,i);
            printf("%i- ", i+1);
            printEmpleado(aux);

        }

    }

}

//                                          ********** SETTERS **********


// ----- Setters codigo -----

void actualizarCodigoDiagrama(ArrayList* juegos, int index) {

    sJuego* juego = juegos->pElements[index];

    if (juego->codigo->diagramas == 0) {

        ((sJuego*)juegos->pElements[index])->codigo->diagramas = 1;
        printf("\nTarea completada con exito\n");

    } else {

        printf("\nEsta tarea ya fue completada\n");

    }
}

void actualizarCodigoImplementacion(ArrayList* juegos, int index) {

    sJuego* juego = juegos->pElements[index];

    if (juego->codigo->implementacion == 0) {

        if (juego->codigo->diagramas != 0) {

            ((sJuego*)juegos->pElements[index])->codigo->implementacion = 1;
            printf("\nTarea completada con exito\n");

        } else {

            printf("\nLos diagramas deben estar completos para implementar el codigo\n");

        }

    } else {

        printf("\nEsta tarea ya fue completada\n");

    }
}

void actualizarCodigoTesteo(ArrayList* juegos, int index) {

    sJuego* juego = juegos->pElements[index];

    if (juego->codigo->testeo == 0) {

        if (juego->codigo->diagramas != 0 && juego->codigo->implementacion != 0) {

            ((sJuego*)juegos->pElements[index])->codigo->diagramas = 1;
            ((sJuego*)juegos->pElements[index])->codigo->estado = 1;
            printf("\nTarea completada con exito\n");
            printf("\nTodo el trabajo del sector codigo esta listo\n");


        } else {

            printf("\nTanto los diagramas como la implementacion deben completarse para realizar el testeo\n");

        }

    } else {

        printf("\nEsta tarea ya fue completada\n");

    }
}

// ----- Setters modelado -----

void actualizarModeladoBoceto(ArrayList* juegos, int index) {

    sJuego* juego = juegos->pElements[index];

    if (juego->modelado->boceto == 0) {

        ((sJuego*)juegos->pElements[index])->modelado->boceto = 1;
        printf("\nTarea completada con exito\n");

    } else {

        printf("\nEsta tarea ya fue completada\n");

    }
}

void actualizarModeladoArte(ArrayList* juegos, int index) {

    sJuego* juego = juegos->pElements[index];

    if (juego->modelado->arte == 0) {

        if (juego->modelado->boceto != 0) {

            ((sJuego*)juegos->pElements[index])->modelado->arte = 1;
            printf("\nTarea completada con exito\n");

        } else {

            printf("\nLos bocetos deben estar completos para realizar el arte\n");

        }

    } else {

        printf("\nEsta tarea ya fue completada\n");

    }
}

void actualizarModeladoImplementacion(ArrayList* juegos, int index) {

    sJuego* juego = juegos->pElements[index];

    if (juego->modelado->implementacion == 0) {

        if (juego->modelado->boceto != 0 && juego->modelado->arte != 0) {

            ((sJuego*)juegos->pElements[index])->modelado->implementacion = 1;
            ((sJuego*)juegos->pElements[index])->modelado->estado = 1;
            printf("\nTarea completada con exito\n");
            printf("\nTodo el trabajo del sector modelado esta listo\n");

        } else {

            printf("\nTanto el boceto com el arte deben terminarse para realizar la implementacion\n");

        }

    } else {

        printf("\nEsta tarea ya fue completada\n");

    }
}

// ----- Setters Animacion -----

void actualizarAnimacionAnimado(ArrayList* juegos, int index) {

    sJuego* juego = juegos->pElements[index];

    if (juego->modelado->estado == 1) {

        if (juego->animacion->animado == 0) {

            ((sJuego*)juegos->pElements[index])->animacion->animado = 1;
            printf("\nTarea completada con exito\n");

        } else {

            printf("\nEsta tarea ya fue completada\n");

        }

    } else {

        printf("\nPara comenzar con los trabajos de animacion el sector de modelado debe terminar su trabajo\n");

    }
}

void actualizarAnimacionImplementacion(ArrayList* juegos, int index) {

    sJuego* juego = juegos->pElements[index];

    if (juego->modelado->estado == 1) {

        if (juego->animacion->animado != 0) {

            if (juego->animacion->implementacion == 0) {

                ((sJuego*)juegos->pElements[index])->animacion->implementacion = 1;
                ((sJuego*)juegos->pElements[index])->animacion->estado = 1;
                printf("\nTarea completada con exito\n");
                printf("\nTodo el trabajo del sector animacion esta listo\n");

            } else {

                printf("\nEsta tarea ya fue completada\n");

            }

        } else {

            printf("\nEl animado debe estar completo para realizar la implementacion\n");

        }

    } else {

        printf("\nPara comenzar con los trabajos de animacion el sector de modelado debe terminar su trabajo\n");

    }
}

// ----- Setters Cinematica -----

void actualizarCinematicaAmbientacion(ArrayList* juegos, int index) {

    sJuego* juego = juegos->pElements[index];

    if (juego->animacion->estado == 1) {

        if (juego->cinematica->ambientacion == 0) {

            ((sJuego*)juegos->pElements[index])->cinematica->ambientacion = 1;
            printf("\nTarea completada con exito\n");
            if (juego->cinematica->historia == 1) {

                ((sJuego*)juegos->pElements[index])->cinematica->estado = 1;
                printf("\nTodo el trabajo del sector cinematica esta listo\n");

            }

        } else {

            printf("\nEsta tarea ya fue completada\n");

        }

    } else {

        printf("\nPara comenzar con los trabajos de cinematica el sector de animacion debe terminar su trabajo\n");

    }
}

void actualizarCinematicaHistoria(ArrayList* juegos, int index) {

    sJuego* juego = juegos->pElements[index];

    if (juego->animacion->estado == 1) {

        if (juego->cinematica->historia == 0) {

            ((sJuego*)juegos->pElements[index])->cinematica->historia = 1;
            printf("\nTarea completada con exito\n");
            if (juego->cinematica->ambientacion == 1) {

                ((sJuego*)juegos->pElements[index])->cinematica->estado = 1;
                printf("\nTodo el trabajo del sector cinematica esta listo\n");

            }

        } else {

            printf("\nEsta tarea ya fue completada\n");

        }

    } else {

        printf("\nPara comenzar con los trabajos de cinematica el sector de animacion debe terminar su trabajo\n");

    }
}

// ----- Setters Marketing -----

void actualizarMarketingPublicidades(ArrayList* juegos, int index) {

    sJuego* juego = juegos->pElements[index];

    if (juego->modelado->estado == 1 && juego->cinematica->estado == 1) {

        if (juego->marketing->publicidades == 0) {

            ((sJuego*)juegos->pElements[index])->marketing->publicidades = 1;
            ((sJuego*)juegos->pElements[index])->marketing->estado = 1;
            printf("\nTarea completada con exito\n");
            printf("\nTodo el trabajo del sector marketing esta listo\n");

        } else {

            printf("\nEsta tarea ya fue completada\n");

        }

    } else {

        printf("\nPara comenzar con los trabajos de marketing los sectores de modelado y cinematica deben terminar su trabajo\n");

    }
}

//                                         ********** CONSTRUCTORES **********


// Constructor empleado

sEmpleado* nuevoEmpleado(char nombre[], int especialidad) {

    sEmpleado* returnAux = NULL;
    sEmpleado* pEmpleado = malloc(sizeof(sEmpleado));

    if(pEmpleado != NULL) {

        strcpy(pEmpleado->nombre, nombre);
        pEmpleado->especialidad = especialidad;
        returnAux = pEmpleado;

    }

    return returnAux;
}

// Constructor codigo

sCodigo* nuevoCodigo(ArrayList* equipo) {

    sCodigo* returnAux = NULL;
    sCodigo* pCodigo = malloc(sizeof(sCodigo));

    if(pCodigo != NULL) {

        pCodigo->diagramas = 0;
        pCodigo->testeo = 0;
        pCodigo->implementacion = 0;
        pCodigo->estado = 0;
        pCodigo->equipo = equipo;
        returnAux = pCodigo;

    }

    return returnAux;
}

// Constructor modelado

sModelado* nuevoModelado(ArrayList* equipo) {

    sModelado* returnAux = NULL;
    sModelado* pModelado = malloc(sizeof(sModelado));

    if(pModelado != NULL) {

        pModelado->arte = 0;
        pModelado->boceto = 0;
        pModelado->implementacion = 0;
        pModelado->estado = 0;
        pModelado->equipo = equipo;
        returnAux = pModelado;

    }

    return returnAux;
}

// Constructor animacion

sAnimacion* nuevoAnimacion(ArrayList* equipo) {

    sAnimacion* returnAux = NULL;
    sAnimacion* pAnimacion = malloc(sizeof(sAnimacion));

    if(pAnimacion != NULL) {

        pAnimacion->animado = 0;
//        pAnimacion->modelos = 0;
        pAnimacion->implementacion = 0;
        pAnimacion->estado = 0;
        pAnimacion->equipo = equipo;
        returnAux = pAnimacion;

    }

    return returnAux;
}

// Constructor cinematica

sCinematica* nuevoCinematica(ArrayList* equipo) {

    sCinematica* returnAux = NULL;
    sCinematica* pCinematica = malloc(sizeof(sCinematica));

    if(pCinematica != NULL) {

//        pCinematica->animacion = 0;
        pCinematica->ambientacion = 0;
        pCinematica->historia = 0;
        pCinematica->presentada = 0;
        pCinematica->estado = 0;
        pCinematica->equipo = equipo;
        returnAux = pCinematica;

    }

    return returnAux;
}

// Constructor marketing

sMarketing* nuevoMarketing(ArrayList* equipo) {

    sMarketing* returnAux = NULL;
    sMarketing* pMarketing = malloc(sizeof(sMarketing));

    if(pMarketing != NULL) {

//        pMarketing->cinematica = 0;
//        pMarketing->modelo = 0;
        pMarketing->publicidades = 0;
        pMarketing->iniciado = 0;
        pMarketing->estado = 0;
        pMarketing->equipo = equipo;
        returnAux = pMarketing;

    }

    return returnAux;
}

// Constructor juego

sJuego* nuevoJuego(char nombre[], char genero[], sCodigo* codigo, sModelado* modelado, sAnimacion* animacion, sCinematica* cinematica, sMarketing* marketing) {

    sJuego* returnAux = NULL;
    sJuego* pJuego = malloc(sizeof(sJuego));

    if (pJuego != NULL) {

        strcpy(pJuego->nombre, nombre);
        strcpy(pJuego->genero, genero);
        pJuego->codigo = codigo;
        pJuego->modelado = modelado;
        pJuego->animacion = animacion;
        pJuego->cinematica = cinematica;
        pJuego->marketing = marketing;
        pJuego->estado = 0;
        returnAux = pJuego;

    }

    return returnAux;
}


//                                      ********** OTRAS **********

void publicarJuego(ArrayList* juegosEnDesarrollo, ArrayList* juegosDesarrollados, int index) {

    juegosDesarrollados->add(juegosDesarrollados, juegosEnDesarrollo->pop(juegosEnDesarrollo, index));

    printf("\nEl juego se ha publicado con exito\n");

}

void liberarEmpleados(ArrayList* empleados, ArrayList* empleadosOcupados) {

    int i;
    int tam;

    tam = empleadosOcupados->len(empleadosOcupados);

    for (i = 0; i < tam; i++) {

        empleados->add(empleados, empleadosOcupados->pop(empleadosOcupados, 0));

    }

}

void presentarCinematica(ArrayList* juegosEnDesarrollo, int index) {

    sJuego* juego = juegosEnDesarrollo->pElements[index];

    juego->cinematica->presentada = 1;

    printf("\nCinematica exitosamente publicada\n");

}

void iniciarMarketing(ArrayList* juegosEnDesarrollo, int index) {

    sJuego* juego = juegosEnDesarrollo->pElements[index];

    juego->marketing->iniciado = 1;

    printf("\nMarketing exitosamente iniciado\n");

}

int cinematicaPublicada(ArrayList* juegos, int index) {

    sJuego* juego = juegos->pElements[index];

    if (juego->cinematica->presentada == 1) {

        return 1;

    } else {

        return 0;

    }

}

int marketingIniciado(ArrayList* juegos, int index) {

    sJuego* juego = juegos->pElements[index];

    if (juego->marketing->iniciado == 1) {

        return 1;

    } else {

        return 0;

    }

}

void cargarEmpleadosEquipo(ArrayList* lista, ArrayList* listaOcupados, ArrayList* equipo) {

    int i, op;
    char resp;
    sEmpleado* aux;

    for (i = 0; i < 5; i++) {

        if (lista->len(lista) == 0) {

            break;

        }

        system("cls");
        printEmpleadosArray(lista);
        printf("\nEmpleado numero %i: ",i+1);

        op = getIntRange(1, lista->len(lista));
        aux = lista->pop(lista, op-1);

        if (aux != NULL) {

            equipo->add(equipo, aux);
            listaOcupados->add(listaOcupados, aux);

        }

        printf("\n%cDesea seguir agregando empleados al equipo? (S/N): ", 168);
        resp = validarChar('s', 'n');

        if (resp == 'n') {

            break;
        }

    }

}

int equipoCodigoVacio(ArrayList* juegos, int index) {

    sJuego* juego = juegos->pElements[index];

    if (juego->codigo->equipo->len(juego->codigo->equipo) == 0) {

        return 1;

    } else {

        return 0;

    }

}

int equipoModeladoVacio(ArrayList* juegos, int index) {

    sJuego* juego = juegos->pElements[index];

    if (juego->modelado->equipo->len(juego->modelado->equipo) == 0) {

        return 1;

    } else {

        return 0;

    }

}

int equipoAnimacionVacio(ArrayList* juegos, int index) {

    sJuego* juego = juegos->pElements[index];

    if (juego->animacion->equipo->len(juego->animacion->equipo) == 0) {

        return 1;

    } else {

        return 0;

    }

}

int equipoCinematicaVacio(ArrayList* juegos, int index) {

    sJuego* juego = juegos->pElements[index];

    if (juego->cinematica->equipo->len(juego->cinematica->equipo) == 0) {

        return 1;

    } else {

        return 0;

    }

}

int equipoMarketingVacio(ArrayList* juegos, int index) {

    sJuego* juego = juegos->pElements[index];

    if (juego->marketing->equipo->len(juego->marketing->equipo) == 0) {

        return 1;

    } else {

        return 0;

    }

}

int sectorCompletoCodigo(ArrayList* juegos, int index) {

    sJuego* juego = juegos->pElements[index];

    if (juego->codigo->estado == 1) {

        return 1;

    } else {

        return 0;

    }
}

int sectorCompletoModelado(ArrayList* juegos, int index) {

    sJuego* juego = juegos->pElements[index];

    if (juego->modelado->estado == 1) {

        return 1;

    } else {

        return 0;

    }
}

int sectorCompletoAnimacion(ArrayList* juegos, int index) {

    sJuego* juego = juegos->pElements[index];

    if (juego->animacion->estado == 1) {

        return 1;

    } else {

        return 0;

    }
}

int sectorCompletoCinematica(ArrayList* juegos, int index) {

    sJuego* juego = juegos->pElements[index];

    if (juego->cinematica->estado == 1) {

        return 1;

    } else {

        return 0;

    }
}

int sectorCompletoMarketing(ArrayList* juegos, int index) {

    sJuego* juego = juegos->pElements[index];

    if (juego->marketing->estado == 1) {

        return 1;

    } else {

        return 0;

    }
}

//                                      ********** INGRESO DE DATOS **********

char validarChar(char opcion1, char opcion2) {

    char caracter;
    caracter = tolower(getche());

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

void inicializarEmpleados(ArrayList* empleados, ArrayList* empleadosCodigo, ArrayList* empleadosModelado, ArrayList* empleadosAnimacion, ArrayList* empleadosCinematica, ArrayList* empleadosMarketing) {


    char nombres[20][50] = {"Juan", "Pedro", "Matias", "John", "Santiago", "Micaela", "Denisse", "Rocio", "Hugo", "Steve", "Roberto", "Michelle", "Rodrigo", "Lucia", "Gastley", "George", "Hoff", "Erika", "Ruth", "Damniel"};
    int especialidades[20] = {1,2,3,1,5,4,3,4,2,3,1,1,2,5,4,3,4,3,2,1};
    int i;

    sEmpleado* auxEmpleado;

    for (i = 0; i < 20; i++) {

        auxEmpleado = nuevoEmpleado(nombres[i], especialidades[i]);
        empleados->add(empleados, auxEmpleado);

        if (especialidades[i] == CODIGO) {

            empleadosCodigo->add(empleadosCodigo, auxEmpleado);

        } else if (especialidades[i] == MODELADO) {

            empleadosModelado->add(empleadosModelado, auxEmpleado);

        } else if (especialidades[i] == ANIMACION) {

            empleadosAnimacion->add(empleadosAnimacion, auxEmpleado);

        } else if (especialidades[i] == CINEMATICA) {

            empleadosCinematica->add(empleadosCinematica, auxEmpleado);

        } else {

            empleadosMarketing->add(empleadosMarketing, auxEmpleado);

        }

    }

}

char* getString() {

    char cadena[250];

    fflush(stdin);
    gets(cadena);

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

char* getStringNum() {

    char cadena[250];

    fflush(stdin);
    gets(cadena);

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

int getIntRange(int min, int max) {

    char cadena[250];

    fflush(stdin);
    gets(cadena);

    int soloNum = soloNumeros(cadena);
    int valid = validarRangoInt(atoi(cadena), min, max);

    while (!soloNum || !valid) {

        printf("Entrada invalida. Reingrese (%i - %i): ", min, max);
        fflush(stdin);
        gets(cadena);

        soloNum = soloNumeros(cadena);
        valid = validarRangoInt(atoi(cadena), min, max);

    }

    return atoi(cadena);
}

int getInt() {

    char cadena[250];

    printf("\nIngrese un numero: ");
    fflush(stdin);
    gets(cadena);

    int soloNum = soloNumeros(cadena);

    while (!soloNum) {

        printf("Entrada invalida. Reingrese: ");
        fflush(stdin);
        gets(cadena);

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

    if ((a >= 65 && a <= 90) || (a >= 97 && a <= 122) || (a >= 160 && a <= 165) || (a == 32) || (a >= 48 && a <= 57)) {

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
