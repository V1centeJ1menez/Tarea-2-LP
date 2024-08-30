#include <stdlib.h>
#include <stdio.h>

/* Partes principales */
#include "Cartas.h"
#include "Tablero.h"

int main(int argc, char const *argv[]) {
    (void)argc;
    (void)argv;
    
    int tamano = 0; // Tamaño del tablero
    int opcion = 0; // Opción seleccionada por el usuario

    while (1) {
        // Mostrar el menú de selección de dificultad
        printf("Selecciona la Dificultad:\n");
        printf("1. Facil -> 11 X 11, 5 Barcos\n");
        printf("2. Medio -> 17 X 17, 7 Barcos\n");
        printf("3. Dificil -> 21 X 21, 9 Barcos\n");
        printf("4. Salir\n");
        
        // Leer la opción del usuario
        printf("Ingrese Numero: ");
        scanf("%d", &opcion);
        
        // Procesar la opción del usuario
        switch (opcion) {
            case 1:
                tamano = 11;
                break;
            case 2:
                tamano = 17;
                break;
            case 3:
                tamano = 21;
                break;
            case 4:
                printf("Saliendo...\n");
                liberarTablero(); // Asegúrate de liberar el tablero antes de salir
                return 0; // Salir del programa
            default:
                printf("Opción no válida. Inténtelo de nuevo.\n");
                continue;
        }

        // Liberar el tablero antes de inicializar uno nuevo
        liberarTablero();
        
        // Inicializar el tablero
        inicializarTablero(tamano);
        
        // Mostrar el tablero
        mostrarTablero();
    
        // Esperar la entrada del usuario para continuar o salir
        printf("Presione Enter para continuar...");
        getchar(); // Para consumir el '\n' pendiente del scanf
        getchar(); // Para esperar la entrada del usuario
    }
}
