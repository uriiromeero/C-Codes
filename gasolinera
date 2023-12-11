#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

// Función principal del programa
int main(void)
{
    // Declaración de variables
    float iu, galonesRepostados, importeXGalon, importeXLitro;
    int valesDescuento, valesDescuento_n;
    float valesDescuento_f;
    int desc;

    // Constante que define la relación de conversión de galones a litros
    const float galonConversor = 3.79;

    // Entrada de datos: importe pagado
    printf("Introduce el importe que pagaste:\n");
    scanf("%f", &iu);

    // Entrada de datos: galones repostados
    printf("Introduce el numero de galones repostados:\n");
    scanf("%f", &galonesRepostados);

    // Entrada de datos: vales de descuento
    printf("Introduce el numero de vales de descuento de 1 Dollar que usaste:\n");
    scanf("%d", &valesDescuento);

    // Conversión de vales de descuento a tipo float para facilitar cálculos
    valesDescuento_f = (float)valesDescuento;

    // Cálculo del precio por galón
    importeXGalon = (iu + valesDescuento_f) / galonesRepostados;

    // Comprobación de si se utilizaron vales de descuento
    desc = (valesDescuento == 0);

    // Cálculo de nuevos vales de descuento si no se utilizaron vales previos
    if (desc) {
        if (iu < 10) {
            valesDescuento_n = 0;
        }
        else {
            valesDescuento_n = (int)(iu / 10);
        }
    }
    else {
        valesDescuento_n = 0;
    }

    // Cálculo del precio por litro
    importeXLitro = (iu + valesDescuento_f) / (galonesRepostados * galonConversor);

    // Salida de resultados
    printf("El precio en dolares de cada galón ha sido: %f\n", importeXGalon);
    printf("El precio en dolares de cada litro ha sido: %f\n", importeXLitro);
    printf("Has obtenido %d vales de descuento nuevos.\n", valesDescuento_n);

    // Pausa antes de cerrar la consola (Solo para entornos Windows)
    system("pause");

    // Éxito del programa
    return 0;
}
