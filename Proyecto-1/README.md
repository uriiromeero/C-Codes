# Proyecto 1

Este se divide en 2: 

   - Programa en C++ que realiza un analisis estadistico de un supermercado. [Estadísticas de Compras]
   - Programa en C y C++ que realiza un cálculo de repostaje en gasolinera. [Calculadora de Combustible]

# Estadísticas de Compras

Este programa en C++ realiza un análisis estadístico de una serie de productos comprados, calculando el importe total de la compra, la media en importe de los productos, el código del producto más caro, el precio del producto más caro, el precio del producto más barato y los puntos acumulados por la compra.

## Instrucciones de Uso

1. **Ejecución:**
   - Compilar el programa en un entorno que admita C++.
   - Ejecutar el programa resultante.

2. **Entrada de Datos:**
   - Introduce el código del producto cuando se solicite.
   - Proporciona el precio del producto en euros y la cantidad comprada.

3. **Resultados:**
   - El programa mostrará el importe total de la compra, la media en importe, el código y precio del producto más caro, el precio del producto más barato y los puntos acumulados.

## Notas

- El programa utiliza un bucle de entrada de datos que continuará hasta que se introduzca un código de producto no positivo.
- Se verifica la entrada positiva antes de procesar los datos para evitar cálculos innecesarios.
- La tasa de conversión de puntos por euro está fijada en 0.25, ajustable según sea necesario.
- La pausa antes de cerrar la consola (`system("pause");`) es específica para entornos Windows y puede eliminarse o ajustarse según el entorno de ejecución.

---

# Calculadora de Combustible

Este programa en C++ y/o C calcula el precio por galón y por litro de combustible, considerando descuentos por vales de 1 dólar. Además, determina la cantidad de nuevos vales de descuento obtenidos.

## Instrucciones de Uso

1. **Ejecución:**
   - Compilar el programa en un entorno que admita C++ o C.
   - Ejecutar el programa resultante.

2. **Entrada de Datos:**
   - Introduce el importe pagado, el número de galones repostados y el número de vales de descuento de 1 dólar utilizados.

3. **Resultados:**
   - El programa mostrará el precio en dólares por galón y por litro, así como la cantidad de nuevos vales de descuento obtenidos.

## Notas

- El programa realiza conversiones de tipos para facilitar los cálculos.
- Se considera un límite de descuento basado en el importe pagado.
- La pausa antes de cerrar la consola (`system("pause");`) es específica para entornos Windows y puede eliminarse o ajustarse según el entorno de ejecución.

---

*Nota: Estos README proporcionan descripciones básicas de los programas y las instrucciones para su uso. Asegúrate de tener un entorno de desarrollo adecuado para compilar y ejecutar programas en C++.*
