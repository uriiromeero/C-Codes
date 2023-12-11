#include <stdio.h>

int main() {
    // Declaración de variables
    int n, contador = 0;
    int capicua;
    
    // Inicialización de n
    n = 1;

    // Bucle principal: busca números capicúas hasta 9999 o hasta que se encuentren 150
    while (n <= 9999 && contador < 150) {
        capicua = 0; // Inicialización de la bandera capicua

        // Verifica si el número tiene un solo dígito
        if (n < 10) {
            capicua = 1; // Marca como capicúa
        }
        // Verifica si el número tiene dos dígitos y son iguales
        else if (n < 100) {
            if (n % 10 == n / 10) {
                capicua = 1; // Marca como capicúa
            }
        }
        // Verifica si el número tiene tres dígitos y el primer y último son iguales
        else if (n < 1000) {
            if (n % 10 == n / 100) {
                capicua = 1; // Marca como capicúa
            }
        }
        // Verifica si el número tiene cuatro dígitos y los extremos son iguales
        else {
            if (n % 10 == n / 1000 && ((n / 10) % 10 == ((n / 100) % 10))) {
                capicua = 1; // Marca como capicúa
            }
        }

        // Si el número es capicúa, imprímelo y actualiza el contador
        if (capicua) {
            printf("%d\n", n);
            contador++;
        }

        // Incremento para pasar al siguiente número
        n++;
    }

    return 0;
}
