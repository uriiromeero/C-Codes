#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Función para generar un número aleatorio en un rango dado
int NumeroAleatorio(int rangoInicio, int rangoFin) {
    return rand() % (rangoFin - rangoInicio + 1) + rangoInicio;
}

// Función para llenar un arreglo con números aleatorios en el rango del 1 al 4
void AleatorioLlenaArray(int NumerosGenerados[], int CantidadNumeros) {
    for (int i = 0; i < CantidadNumeros; ++i) {
        NumerosGenerados[i] = NumeroAleatorio(1, 4);
    }
}

// Función para que el jugador llene un arreglo con números introducidos, validando el rango
void JugadorLlenaArray(int NumerosIntroducidos[], int CantidadNumeros) {
    for (int i = 0; i < CantidadNumeros; ++i) {
        do {
            printf("Introduce el entero del 1 al 4. Numero: ");
            scanf_s("%d", &NumerosIntroducidos[i]);

            if (NumerosIntroducidos[i] < 1 || NumerosIntroducidos[i] > 4) {
                printf("Epp! Este numero no es un numero entre 1 y 4.\n");
            }
        } while (NumerosIntroducidos[i] < 1 || NumerosIntroducidos[i] > 4);
    }
}

// Función para contar el número de aciertos entre dos arreglos
int NumeroNumeroAcierto(int NumerosGenerados[], int NumerosIntroducidos[], int CantidadNumeros) {
    int NumerosAcertados = 0;
    for (int i = 0; i < CantidadNumeros; ++i) {
        if (NumerosGenerados[i] == NumerosIntroducidos[i]) {
            NumerosAcertados++;
        }
    }
    return NumerosAcertados;
}

// Función para mostrar aciertos o fallos según la bandera mostrarAciertos
void AciertosFallos(int NumerosGenerados[], int NumerosIntroducidos[], int CantidadNumeros, int mostrarAciertos) {
    printf(mostrarAciertos ? "Has acertado:\n" : "Has Fallado:\n");
    printf("\n");
    for (int i = 0; i < CantidadNumeros; ++i) {
        if ((NumerosGenerados[i] == NumerosIntroducidos[i] && mostrarAciertos) ||
            (NumerosGenerados[i] != NumerosIntroducidos[i] && !mostrarAciertos)) {
            printf("Posicion %d has indicado un %d y habia un %d\n", i, NumerosIntroducidos[i], NumerosGenerados[i]);
            printf("\n");
        }
    }
}

// Función para mostrar un resumen de las introducciones
void MuestraAciertosFallos(int NumerosGenerados[], int NumerosIntroducidos[], int CantidadNumeros) {
    printf("El resumen de las introducciones es el siguiente:\n");
    for (int i = 0; i < CantidadNumeros; ++i) {
        printf("Posicion %d: Se habia generado aleatoriamente un %d y has indicado que podria haber un %d por lo tanto has %s\n",
            i, NumerosGenerados[i], NumerosIntroducidos[i],
            (NumerosGenerados[i] == NumerosIntroducidos[i] ? "ACERTADO!" : "FALLADO!"));
        printf("\n");
    }
}

int main() {
    // Inicializar la semilla del generador de números aleatorios
    srand((unsigned int)time(NULL));

    // Generar cantidad aleatoria de números entre 5 y 10
    int CantidadNumeros = NumeroAleatorio(5, 10);

    // Arreglos para almacenar números generados e introducidos por el usuario
    int NumerosGenerados[10];
    int NumerosIntroducidos[10];

    // Mensajes iniciales
    printf("++++++++++++++++++++++++++++++++++++++\n");
    printf("Se generarán %d números aleatorios:\n", CantidadNumeros);
    printf("++++++++++++++++++++++++++++++++++++++\n");

    // Llenar el arreglo de números generados de manera aleatoria
    AleatorioLlenaArray(NumerosGenerados, CantidadNumeros);

    // Llenar el arreglo de números introducidos por el jugador
    JugadorLlenaArray(NumerosIntroducidos, CantidadNumeros);

    // Contar el número de aciertos
    int NumerosAcertados = NumeroNumeroAcierto(NumerosGenerados, NumerosIntroducidos, CantidadNumeros);

    // Mostrar resultados
    printf("\n");
    printf("++++++++++++++++++++++++++++++++++++++\n");
    printf("Has acertado %d números de %d\n", NumerosAcertados, CantidadNumeros);
    printf("Lo que representa un %.2f por ciento\n", (float)NumerosAcertados / CantidadNumeros * 100);
    printf("++++++++++++++++++++++++++++++++++++++\n");

    // Mostrar aciertos y fallos
    AciertosFallos(NumerosGenerados, NumerosIntroducidos, CantidadNumeros, 1);
    AciertosFallos(NumerosGenerados, NumerosIntroducidos, CantidadNumeros, 0);

    // Mostrar resumen de las introducciones
    MuestraAciertosFallos(NumerosGenerados, NumerosIntroducidos, CantidadNumeros);

    return 0;
}
