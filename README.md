# CityDefender 

### Autor: Vicente Andrés Jiménez Sepúlveda  
### Rol: 202373523-K

## Descripción

**CityDefender** es un juego basado en el clásico Battleship, donde los jugadores intentan destruir los barcos del enemigo. Utiliza un tablero representado por un puntero triple para almacenar la información de cada celda. El juego permite disparos de diferentes tipos, desde simples hasta ataques masivos que afectan áreas grandes del tablero. 

Este proyecto pone en práctica conceptos avanzados de manejo de punteros en C, como el uso de punteros triples para la gestión dinámica de matrices 2D.

## Estructura del Proyecto

El proyecto se organiza de la siguiente manera:

CityDefender/
├── src/
│   ├── main.c         # Archivo principal del programa
│   ├── Tablero.c      # Implementación de las funciones relacionadas con el tablero
│   ├── Tablero.h      # Declaraciones de las funciones y estructuras relacionadas con el tablero
│   ├── Cartas.c       # Implementación de las funciones relacionadas con las cartas
│   ├── Cartas.h       # Declaraciones de las funciones y estructuras relacionadas con las cartas
├── README.md          # Documentación del proyecto
├── Makefile           # Archivo para automatizar la compilación



## Compilación y Ejecución

Para compilar y ejecutar **CityDefender**, sigue estos pasos:

### Requisitos

- Un compilador de C (GCC recomendado).
- Sistema operativo Linux, macOS o Windows con un entorno de desarrollo compatible.
- `Make` para la automatización de la compilación.

### Instrucciones de Compilación

1. Clona el repositorio o descarga los archivos del proyecto.
2. Navega al directorio del proyecto:
   ```bash
   cd CityDefender
3. Compila el proyecto utilizando el Makefile proporcionado:
   ```bash
   make clean
   make 
4. Ejectura el juego:
   ```bash
   make run | make valgrind

### Ejemplos

Al iniciar el juego, se te presentará un menú para seleccionar la dificultad:

Selecciona la Dificultad:

1. Facil -> 11 X 11, 5 Barcos
2. Medio -> 17 X 17, 7 Barcos
3. Dificil -> 21 X 21, 9 Barcos
4. Salir Ingrese Numero:
Después de seleccionar la dificultad, el juego se inicializará y se te pedirá que uses cartas para atacar el tablero enemigo. Cada turno te mostrará el estado actual del tablero y el número de turnos restantes.

### Notas
* El uso de punteros triples permite una mayor flexibilidad en la gestión de la memoria del tablero, aunque también introduce una mayor complejidad en el manejo de los datos.
* Asegúrate de liberar toda la memoria dinámica asignada para evitar fugas de memoria.
* Este juego es un excelente ejemplo de cómo aplicar estructuras avanzadas de datos en C.
