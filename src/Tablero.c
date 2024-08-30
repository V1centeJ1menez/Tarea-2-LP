#include <stdio.h>
#include <stdlib.h>
#include "Tablero.h"

// Definir las variables globales del tablero y el tamaño
void ***tablero = NULL;
static int tamanoTablero = 0; // Variable global para almacenar el tamaño del tablero

void inicializarTablero(int tamano) {
    tamanoTablero = tamano; // Almacenar el tamaño en la variable global

    // Asignar memoria para el array de punteros a punteros (N filas)
    tablero = (void ***)malloc(tamano * sizeof(void **));
    if (tablero == NULL) {
        perror("Error al asignar memoria para las filas del tablero");
        return;
    }

    for (int i = 0; i < tamano; i++) {
        // Asignar memoria para cada fila de punteros (N columnas)
        tablero[i] = (void **)malloc(tamano * sizeof(void *));
        if (tablero[i] == NULL) {
            perror("Error al asignar memoria para las columnas del tablero");
            return;
        }

        for (int j = 0; j < tamano; j++) {
            // Asignar memoria para cada celda (almacenar un char que representa el estado de la celda)
            tablero[i][j] = malloc(sizeof(char));
            if (tablero[i][j] == NULL) {
                perror("Error al asignar memoria para la celda del tablero");
                return;
            }
            // Inicializar la celda con 'O'
            *(char *)(tablero[i][j]) = 'O';
        }
    }
}

void mostrarTablero() {
    // Imprimir la fila de números de columna
    printf("   ");
    for (int j = 0; j < tamanoTablero; j++) {
        printf("| %c ", ' '); // Espacio en blanco para la separación de celdas
    }
    printf("|\n");

    for (int i = 0; i < tamanoTablero; i++) {
        // Imprimir el número de fila al principio de cada fila, ajustado para ser 1-indexed
        printf("%2d ", i + 1);

        for (int j = 0; j < tamanoTablero; j++) {
            // Imprimir la celda enmarcada con '|' al principio y final
            printf("| %c ", *(char *)(tablero[i][j]));
        }
        // Imprimir la barra vertical al final de cada fila
        printf("|\n");

        // Imprimir una línea horizontal después de cada fila
        printf("   ");
        for (int j = 0; j < tamanoTablero; j++) {
            printf("|---"); // Separadores entre celdas
        }
        printf("|\n");
    }
}


void liberarTablero() {
    if (tablero != NULL) {
        // Liberar cada celda del tablero
        for (int i = 0; i < tamanoTablero; i++) {
            for (int j = 0; j < tamanoTablero; j++) {
                free(tablero[i][j]);
            }
            // Liberar cada fila del tablero
            free(tablero[i]);
        }
        // Liberar el array de filas del tablero
        free(tablero);
        tablero = NULL;
    }
}
