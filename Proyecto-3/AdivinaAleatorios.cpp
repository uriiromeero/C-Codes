#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// Función para generar un número aleatorio en un rango dado
int NumeroAleatorio(int rangoInicio, int rangoFin) {
    return rand() % (rangoFin - rangoInicio + 1) + rangoInicio;
}

// Función para llenar un arreglo con números aleatorios en el rango del 1 al 4
void aleatorioLlenaArray(int NumerosGenerados[], int CantidadNumeros) {
    for (int i = 0; i < CantidadNumeros; ++i) {
        NumerosGenerados[i] = NumeroAleatorio(1, 4);
    }
}

// Función para que el jugador llene un arreglo con números introducidos, validando el rango
void jugadorLlenaArray(int NumerosIntroducidos[], int CantidadNumeros) {
    for (int i = 0; i < CantidadNumeros; ++i) {
        do {
            cout << "Introduce el entero del 1 al 4. Numero: ";
            cin >> NumerosIntroducidos[i];

            if (NumerosIntroducidos[i] < 1 || NumerosIntroducidos[i] > 4) {
                cout << "Epp! Este numero no es un numero entre 1 y 4.\n";
            }
        } while (NumerosIntroducidos[i] < 1 || NumerosIntroducidos[i] > 4);
    }
}

// Función para contar el número de aciertos entre dos arreglos
int numeroNumeroAcierto(const int NumerosGenerados[], const int NumerosIntroducidos[], int CantidadNumeros) {
    int NumerosAcertados = 0;
    for (int i = 0; i < CantidadNumeros; ++i) {
        if (NumerosGenerados[i] == NumerosIntroducidos[i]) {
            NumerosAcertados++;
        }
    }
    return NumerosAcertados;
}

// Función para mostrar aciertos o fallos según la bandera mostrarAciertos
void AciertosFallos(const int NumerosGenerados[], const int NumerosIntroducidos[], int CantidadNumeros, bool mostrarAciertos) {
    cout << (mostrarAciertos ? "Has acertado:" : "Has Fallado:") << endl;
    cout << "\n";
    for (int i = 0; i < CantidadNumeros; ++i) {
        if ((NumerosGenerados[i] == NumerosIntroducidos[i] && mostrarAciertos) ||
            (NumerosGenerados[i] != NumerosIntroducidos[i] && !mostrarAciertos)) {
            cout << "Posicion " << i << " has indicado un " << NumerosIntroducidos[i] << " y habia un " << NumerosGenerados[i] << endl;
            cout << "\n";
        }
    }
}

// Función para mostrar un resumen de las introducciones
void muestraAciertosFallos(const int NumerosGenerados[], const int NumerosIntroducidos[], int CantidadNumeros) {
    cout << "El resumen de las introducciones es el siguiente:" << endl;
    for (int i = 0; i < CantidadNumeros; ++i) {
        cout << "Posicion " << i << ": Se habia generado aleatoriamente un " << NumerosGenerados[i]
            << " y has indicado que podria haber un " << NumerosIntroducidos[i] << " por lo tanto has "
            << ((NumerosGenerados[i] == NumerosIntroducidos[i]) ? "ACERTADO!" : "FALLADO!") << endl;
    }
}

int main() {
    // Inicializar la semilla del generador de números aleatorios
    srand(time(nullptr));

    // Generar cantidad aleatoria de números entre 5 y 10
    int CantidadNumeros = rand() % 6 + 5;

    // Arreglos para almacenar números generados e introducidos por el usuario
    int NumerosGenerados[10];
    int NumerosIntroducidos[10];

    // Mensajes iniciales
    cout << "++++++++++++++++++++++++++++++++++++++\n";
    cout << "Se generarán " << CantidadNumeros << " números aleatorios:\n";
    cout << "++++++++++++++++++++++++++++++++++++++\n";

    // Llenar el arreglo de números generados de manera aleatoria
    aleatorioLlenaArray(NumerosGenerados, CantidadNumeros);

    // Llenar el arreglo de números introducidos por el jugador
    jugadorLlenaArray(NumerosIntroducidos, CantidadNumeros);

    // Contar el número de aciertos
    int NumerosAcertados = numeroNumeroAcierto(NumerosGenerados, NumerosIntroducidos, CantidadNumeros);

    // Mostrar resultados
    cout << "\n";
    cout << "++++++++++++++++++++++++++++++++++++++\n";
    cout << "Has acertado " << NumerosAcertados << " números de " << CantidadNumeros << "\n";
    cout << "Lo que representa un " << (float)NumerosAcertados / CantidadNumeros * 100 << " por ciento\n";
    cout << "++++++++++++++++++++++++++++++++++++++\n";

    // Mostrar aciertos y fallos
    AciertosFallos(NumerosGenerados, NumerosIntroducidos, CantidadNumeros, true);
    AciertosFallos(NumerosGenerados, NumerosIntroducidos, CantidadNumeros, false);

    // Mostrar resumen de las introducciones
    muestraAciertosFallos(NumerosGenerados, NumerosIntroducidos, CantidadNumeros);

    return 0;
}
