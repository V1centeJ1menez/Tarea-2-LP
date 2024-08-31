#include <stdio.h>
#include <stdlib.h>
#include "Tablero.h"
#include "Cartas.h"

int main(int argc, char const *argv[]) {
    (void)argc;
    (void)argv;
    
    int tamano = 0; // Tamaño del tablero
    int opcion = 0; // Opción seleccionada por el usuario
    int turnosRestantes = 0; // Número de turnos restantes
    int turnoActual = 1; // Contador de turnos
    
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
                turnosRestantes = 30; // Límite de turnos para Fácil
                break;
            case 2:
                tamano = 17;
                turnosRestantes = 35; // Límite de turnos para Medio
                break;
            case 3:
                tamano = 21;
                turnosRestantes = 15; // Límite de turnos para Difícil
                break;
            case 4:
                printf("Saliendo...\n");
                // Liberar ultimo tablero
                return 0; // Salir del programa
            default:
                printf("Opción no válida. Inténtelo de nuevo.\n");
                continue;
        }

        
        // Inicializar el tablero - Colocar los barcos en el tablero - Mostrar tablero
        printf("\nTurnos restantes: %d\n", turnosRestantes);
        inicializarTablero(tamano);
        colocarBarcos(tamano);

        inicializarFunciones();
        inicializarMano();

        // Bucle de turnos
        while (turnosRestantes > 0) {
            printf("\n--- Turno %d ---\n", turnoActual);
            mostrarTablero(); // Mostrar el tablero en el turno actual

            usarCarta(); // Permite usar una carta
            
            turnosRestantes--; // Disminuir el número de turnos restantes
            turnoActual++;      // Incrementar el contador de turnos

            printf("\nTurnos restantes: %d\n", turnosRestantes);

            if (turnosRestantes == 0) {
                printf("Se han agotado los turnos. Fin del juego.\n");
                liberarTablero();
                liberarMano();
                break; // Salir del bucle de turnos
            }
        }
        
        turnoActual = 0;
        
        // Esperar la entrada del usuario para continuar o salir
        printf("Presione Enter para continuar...");
        getchar(); // Para consumir el '\n' pendiente del scanf
        getchar(); // Para esperar la entrada del usuario
    }
}
