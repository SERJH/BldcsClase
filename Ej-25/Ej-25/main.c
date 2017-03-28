#include <stdio.h>
#include <stdlib.h>

int main()
{
    int vendedor1 = 0;
    int vendedor2 = 0;
    int vendedor3 = 0;
    int vendedor;
    int respuesta = 1;
    float importe;
    float porcentGanancia = 0.05;
    float gananciaV1 = 0;
    float gananciaV2 = 0;
    float gananciaV3 = 0;

    printf("Comienza el ingreso de las boletas.");

    do {

        if (vendedor1 == 0) {

            printf("\n\nIngrese el numero de vendedor: ");
            scanf("%i", &vendedor);

            vendedor1 = vendedor;

        while (vendedor1 <= 0 || vendedor1 > 100) {

            printf("\nEl numero ingresado no es valido.\n");
            printf("\nIngrese el numero de vendedor: ");
            scanf("%i", &vendedor);

            vendedor1 = vendedor;

            }

        } else  {

            printf("\nIngrese el numero de vendedor: ");
            scanf("%i", &vendedor);

            while (vendedor1 <= 0 || vendedor1 > 100) {

                printf("\nEl numero ingresado no es valido.\n");
                printf("\nIngrese el numero de vendedor: ");
                scanf("%i", &vendedor);

            }

            if ((vendedor != vendedor1) && (vendedor2 == 0)) {

                vendedor2 = vendedor;

            } else if ((vendedor != vendedor1) && (vendedor2 != 0) && (vendedor3 == 0)) {

                vendedor3 = vendedor;

            } else {

                while ((vendedor != vendedor1) && (vendedor != vendedor2) && (vendedor != vendedor3)) {

                    printf("\nYa ha ingresado los tres vendedores (%i - %i - %i). Por favor ingrese uno de esos numeros.\n",
                           vendedor1, vendedor2, vendedor3);
                    printf("\nIngrese el numero de vendedor: ");
                    scanf("%i", &vendedor);

                }

            }

        }

        printf("\nIngrese el importe de la boleta: ");
        scanf("%f", &importe);

        while (importe < 1) {

            printf("\nError. Ingrese un importe mayor a 0.\n");
            printf("\nIngrese el importe de la boleta: ");
            scanf("%f", &importe);

        }

        if (vendedor == vendedor1) {

            gananciaV1 += (importe * porcentGanancia);

        } else if (vendedor == vendedor2) {

            gananciaV2 += (importe * porcentGanancia);

        } else if (vendedor == vendedor3) {

            gananciaV3 += (importe * porcentGanancia);

        }

        printf("\n%cDesea seguir ingresando boletas? (1 para seguir - 0 para salir): ", 168);
        scanf("%i", &respuesta);

        while ((respuesta != 0) && (respuesta != 1)) {

            printf("\nLa respuesta debe ser uno (1) o cero (0).\n");
            printf("\n%cDesea seguir ingresando boletas? (1 para seguir - 0 para salir): ", 168);
            scanf("%i", &respuesta);

        }

    } while (respuesta != 0);

    printf("\nGanancias del vendedor %i: %f\n", vendedor1, gananciaV1);

    if (vendedor2 != 0) {

        printf("\nGanancias del vendedor %i: %f\n", vendedor2, gananciaV2);

        if (vendedor3 != 0) {

            printf("\nGanancias del vendedor %i: %f\n", vendedor3, gananciaV3);

        } else {

            printf("\nEl tercer vendedor no obtuvo ganancias.\n");

        }

    } else {

        printf("\nEl segundo vendedor no obtuvo ganancias.\n");
        printf("\nEl tercer vendedor no obtuvo ganancias.\n");

    }

    return 0;
}
