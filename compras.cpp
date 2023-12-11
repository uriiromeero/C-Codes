#define _CRT_SECURE_NO_WARNINGS
// Incluimos las librerías (estandar para C#)
#include <stdio.h> 
#include <stdlib.h>

int main(void) {
    const float PUNTOSxEURO = 0.25;

// Declaración de variables
    int producto, producto_max, n, cantidad;
    float precio, precio_max, precio_min, total, media;
    
// Inicialización de variables
    total = 0.0;
    media = 0.0;
    precio_max = 0.0;
    producto_max = 0;
    cantidad = 0;
    n = 0;
    producto = 0;
    while (producto > 0) {
        
// Lectura de datos
        printf("Introduce el código del producto: ");
        scanf("%d", &producto);
        if (producto > 0) {
            printf("Introduce el precio del producto en euros: ");
            scanf("%f", &precio);
            printf("Introduce la cantidad de producto comprado: ");
            scanf("%d", &cantidad);
            
// Cálculos
            total += precio * cantidad;

            if (n == 0) {
                precio_min = precio;
            }
            if (precio > precio_max) {
                precio_max = precio;
                producto_max = producto;
            }
            if (precio < precio_min) {
                precio_min = precio;
            }
            n++;
        }
    }
    if (n > 0) {
        media = total / (float)n;
    }
    
// Resultados
    printf("Importe total de la compra en euros: %.2f\n", total);
    printf("Media en importe de los productos de la compra: %.2f\n", media);
    printf("Código del producto más caro: %d\n", producto_max);
    printf("Precio del producto más caro: %.2f\n", precio_max);
    printf("Precio del producto más barato: %.2f\n", precio_min);
    printf("Puntos acumulados por la compra: %.2f\n", PUNTOSxEURO * total);
    system("pause");
    return 0;
}
