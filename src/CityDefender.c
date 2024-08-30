#include <stdlib.h>
#include <stdio.h>

/* Partes principales */

// Control de cañones //
#include "Cartas.h"
// Mapa // 
#include "Tablero.h"



// Super controlador de cañones CITY DEFENDER 2.0
int main(int argc, char const *argv[]){
    (void)argc;
    (void)argv;
    int tamano = 21; // Definimos el tamaño del tablero, por ejemplo 5x5

    // Inicializar el tablero
    inicializarTablero(tamano);

    // Mostrar el tablero
    mostrarTablero();

    // Aquí podrías agregar más lógica relacionada con el juego

    // Liberar la memoria del tablero antes de finalizar
    liberarTablero();

    

    return 0;
}
