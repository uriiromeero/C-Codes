using System;

class Programa
{
    // Función para generar un número aleatorio en un rango dado
    static int NumeroAleatorio(int rangoInicio, int rangoFin)
    {
        Random aleatorio = new Random();
        return aleatorio.Next(rangoInicio, rangoFin + 1);
    }

    // Función para llenar un arreglo con números aleatorios
    static void AleatorioLlenaArray(int[] NumerosGenerados, int CantidadNumeros)
    {
        for (int i = 0; i < CantidadNumeros; ++i)
        {
            NumerosGenerados[i] = NumeroAleatorio(1, 4);
        }
    }

    // Función para que el jugador llene un arreglo con números introducidos
    static void JugadorLlenaArray(int[] NumerosIntroducidos, int CantidadNumeros)
    {
        for (int i = 0; i < CantidadNumeros; ++i)
        {
            do
            {
                Console.Write("Introduce el entero del 1 al 4. Número: ");
                NumerosIntroducidos[i] = Convert.ToInt32(Console.ReadLine());

                if (NumerosIntroducidos[i] < 1 || NumerosIntroducidos[i] > 4)
                {
                    Console.WriteLine("¡Ups! Este número no es un número entre 1 y 4.");
                }
            } while (NumerosIntroducidos[i] < 1 || NumerosIntroducidos[i] > 4);
        }
    }

    // Función para contar el número de aciertos entre dos arreglos
    static int NumeroNumeroAcierto(int[] NumerosGenerados, int[] NumerosIntroducidos, int CantidadNumeros)
    {
        int NumerosAcertados = 0;
        for (int i = 0; i < CantidadNumeros; ++i)
        {
            if (NumerosGenerados[i] == NumerosIntroducidos[i])
            {
                NumerosAcertados++;
            }
        }
        return NumerosAcertados;
    }

    // Función para mostrar aciertos o fallos según la bandera mostrarAciertos
    static void AciertosFallos(int[] NumerosGenerados, int[] NumerosIntroducidos, int CantidadNumeros, bool mostrarAciertos)
    {
        Console.WriteLine(mostrarAciertos ? "Has acertado:" : "Has Fallado:");
        Console.WriteLine();
        for (int i = 0; i < CantidadNumeros; ++i)
        {
            if ((NumerosGenerados[i] == NumerosIntroducidos[i] && mostrarAciertos) ||
                (NumerosGenerados[i] != NumerosIntroducidos[i] && !mostrarAciertos))
            {
                Console.WriteLine($"Posición {i} has indicado un {NumerosIntroducidos[i]} y había un {NumerosGenerados[i]}");
                Console.WriteLine();
            }
        }
    }

    // Función para mostrar un resumen de las introducciones
    static void MuestraAciertosFallos(int[] NumerosGenerados, int[] NumerosIntroducidos, int CantidadNumeros)
    {
        Console.WriteLine("El resumen de las introducciones es el siguiente:");
        for (int i = 0; i < CantidadNumeros; ++i)
        {
            Console.WriteLine($"Posición {i}: Se había generado aleatoriamente un {NumerosGenerados[i]} y has indicado que podría haber un {NumerosIntroducidos[i]} por lo tanto has {(NumerosGenerados[i] == NumerosIntroducidos[i] ? "ACERTADO!" : "FALLADO!")}");
            Console.WriteLine();
        }
    }

    // Función principal
    static void Main()
    {
        // Crear objeto Random para generar números aleatorios
        Random aleatorio = new Random();

        // Generar cantidad aleatoria de números entre 5 y 10
        int CantidadNumeros = aleatorio.Next(5, 11);

        // Arreglos para almacenar números generados e introducidos por el usuario
        int[] NumerosGenerados = new int[10];
        int[] NumerosIntroducidos = new int[10];

        // Mensajes iniciales
        Console.WriteLine("++++++++++++++++++++++++++++++++++++++");
        Console.WriteLine($"Se generarán {CantidadNumeros} números aleatorios:");
        Console.WriteLine("++++++++++++++++++++++++++++++++++++++");

        // Llenar el arreglo de números generados de manera aleatoria
        AleatorioLlenaArray(NumerosGenerados, CantidadNumeros);

        // Llenar el arreglo de números introducidos por el jugador
        JugadorLlenaArray(NumerosIntroducidos, CantidadNumeros);

        // Contar el número de aciertos
        int NumerosAcertados = NumeroNumeroAcierto(NumerosGenerados, NumerosIntroducidos, CantidadNumeros);

        // Mostrar resultados
        Console.WriteLine("\n");
        Console.WriteLine("++++++++++++++++++++++++++++++++++++++");
        Console.WriteLine($"Has acertado {NumerosAcertados} números de {CantidadNumeros}");
        Console.WriteLine($"Lo que representa un {(float)NumerosAcertados / CantidadNumeros * 100} por ciento");
        Console.WriteLine("++++++++++++++++++++++++++++++++++++++");

        // Mostrar aciertos y fallos
        AciertosFallos(NumerosGenerados, NumerosIntroducidos, CantidadNumeros, true);
        AciertosFallos(NumerosGenerados, NumerosIntroducidos, CantidadNumeros, false);

        // Mostrar resumen de las introducciones
        MuestraAciertosFallos(NumerosGenerados, NumerosIntroducidos, CantidadNumeros);
    }
}
