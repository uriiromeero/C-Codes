using System;

class Programa
{
    static void Main()
    {
        // Crear objeto Random para generar números aleatorios
        Random aleatorio = new();

        // Generar cantidad aleatoria de números entre 5 y 10
        int CantidadNumeros = aleatorio.Next(5, 11);

        // Arreglos para almacenar números generados e introducidos por el usuario
        int[] NumerosGenerados = new int[10];
        int[] NumerosIntroducidos = new int[10];

        // Mensajes iniciales
        Console.WriteLine("++++++++++++++++++++++++++++++++++++++");
        Console.WriteLine($"Se generarán {CantidadNumeros} números aleatorios:");
        Console.WriteLine("++++++++++++++++++++++++++++++++++++++");

        // Generar números aleatorios y almacenar en el arreglo NumerosGenerados
        for (int i = 0; i < CantidadNumeros; ++i)
        {
            NumerosGenerados[i] = aleatorio.Next(1, 5);
        }

        // Mensajes para el jugador
        Console.WriteLine("Es tu turno, jugador. Introduce un número:");
        Console.WriteLine("Recuerda que solo puedes usar números del 1 al 4!");
        Console.WriteLine("++++++++++++++++++++++++++++++++++++++");

        // Inicializar contador de números acertados
        int NumerosAcertados = 0;

        // Pedir al jugador que introduzca números y comparar con los generados
        for (int i = 0; i < CantidadNumeros; ++i)
        {
            int NumeroIntroducido;

            // Validar que el número introducido esté en el rango correcto
            do
            {
                Console.Write("Introduce el entero del 1 al 4. Número: ");
                NumeroIntroducido = int.Parse(Console.ReadLine());

                if (NumeroIntroducido < 1 || NumeroIntroducido > 4)
                {
                    Console.WriteLine("¡Ups! Este número no está entre 1 y 4.");
                }
            } while (NumeroIntroducido < 1 || NumeroIntroducido > 4);

            // Almacenar el número introducido en el arreglo
            NumerosIntroducidos[i] = NumeroIntroducido;

            // Comparar con el número generado y actualizar el contador
            if (NumerosIntroducidos[i] == NumerosGenerados[i])
            {
                NumerosAcertados++;
            }
        }

        // Mostrar resultados
        Console.WriteLine("\n");
        Console.WriteLine("++++++++++++++++++++++++++++++++++++++");
        Console.WriteLine($"Has acertado {NumerosAcertados} números de {CantidadNumeros}");
        Console.WriteLine($"Lo que representa un {(float)NumerosAcertados / CantidadNumeros * 100} por ciento");
        Console.WriteLine("++++++++++++++++++++++++++++++++++++++");

        // Mostrar aciertos y fallos
        Console.WriteLine("Has acertado los siguientes:");
        Console.WriteLine("++++++++++++++++++++++++++++++++++++++\n");
        for (int i = 0; i < CantidadNumeros; ++i)
        {
            if (NumerosIntroducidos[i] == NumerosGenerados[i])
            {
                Console.WriteLine($"Posición {i} has indicado un {NumerosIntroducidos[i]} y había un {NumerosGenerados[i]}");
            }
        }

        Console.WriteLine("\n");
        Console.WriteLine("++++++++++++++++++++++++++++++++++++++");
        Console.WriteLine("Has fallado los siguientes:");
        Console.WriteLine("++++++++++++++++++++++++++++++++++++++\n");
        for (int i = 0; i < CantidadNumeros; ++i)
        {
            if (NumerosIntroducidos[i] != NumerosGenerados[i])
            {
                Console.WriteLine($"Posición {i} has indicado un {NumerosIntroducidos[i]} y había un {NumerosGenerados[i]}");
            }
        }

        // Resumen de las introducciones
        Console.WriteLine("++++++++++++++++++++++++++++++++++++++");
        Console.WriteLine("El resumen de las introducciones es el siguiente:");
        Console.WriteLine("++++++++++++++++++++++++++++++++++++++\n");
        for (int i = 0; i < CantidadNumeros; ++i)
        {
            Console.WriteLine($"Posición {i}: Se había generado aleatoriamente un {NumerosGenerados[i]} y has indicado que podría haber un {NumerosIntroducidos[i]} por lo tanto has... {(NumerosGenerados[i] == NumerosIntroducidos[i] ? "ACERTADO!" : "FALLADO!")}\n");
        }
    }
}
