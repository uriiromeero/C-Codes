#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    // Declaración de variables
    float iu, galonesRepostados, importeXGalon, importeXLitro;
    int balesDescuento, balesDescuento_n;
    float balesDescuento_f;
    int desc;
    const float galonConversor = 3.78541; // Definimos una constante

    // Demandamos datos al usuario
    printf("Introduce el importe que pagaste:\n");
    scanf("%f", &iu);

    // Demandamos datos al usuario
    printf("Introduce el número de galones repostados:\n");
    scanf("%f", &galonesRepostados);

    // Demandamos datos al usuario
    printf("Introduce el número de bales de descuento de 1 Dollar que usaste:\n");
    scanf("%d", &balesDescuento);

    // Conversión de tipos
    balesDescuento_f = (float)balesDescuento;

    // Realizamos algunos cálculos
    importeXGalon = (iu + balesDescuento_f) / galonesRepostados;
    desc = (balesDescuento == 0);

    // Calculamos si te dieron nuevos bales de descuento
    if (desc) {
        if (iu < 10) {
            balesDescuento_n = 0;
        } else {
            balesDescuento_n = (int)(iu / 10);
        }
    } else {
        balesDescuento_n = 0;
    }

    importeXLitro = (iu + balesDescuento_f) / (galonesRepostados * galonConversor);

    // Mostramos los resultados
    printf("El precio en dólares de cada galón ha sido: %f\n", importeXGalon);
    printf("El precio en dólares de cada litro ha sido: %f\n", importeXLitro);
    printf("Has obtenido %d bales de descuento nuevos.\n", balesDescuento_n);

    system("pause");
    return 0;
}
