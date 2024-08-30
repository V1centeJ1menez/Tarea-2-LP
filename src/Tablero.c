#include <stdio.h>
#include <stdlib.h>
#include <time.h>
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
            // Inicializar la celda con ' '
            *(char *)(tablero[i][j]) = ' ';
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

void colocarBarcos(int tamano) {
    srand(time(NULL)); // Inicializa el generador de números aleatorios

    // Barcos y tamaños según la dificultad
    struct {
        int cantidad;
        int tamaño;
        char simbolo;
    } barcos[] = {
        {2, 2, '2'},  // 2 barcos de tamaño 1x2
        {1, 3, '3'},  // 1 barco de tamaño 1x3
        {1, 4, '4'},  // 1 barco de tamaño 1x4
        {1, 5, '5'}   // 1 barco de tamaño 1x5
    };

    // Ajustar los barcos según la dificultad
    if (tamano == 11) { // Facil
        barcos[0].cantidad = 2;
        barcos[1].cantidad = 1;
        barcos[2].cantidad = 1;
        barcos[3].cantidad = 1;
    } else if (tamano == 17) { // Medio
        barcos[0].cantidad = 3;
        barcos[1].cantidad = 2;
        barcos[2].cantidad = 1;
        barcos[3].cantidad = 1;
    } else if (tamano == 21) { // Dificil
        barcos[0].cantidad = 3;
        barcos[1].cantidad = 2;
        barcos[2].cantidad = 2;
        barcos[3].cantidad = 2;
    }

    int numBarcos = sizeof(barcos) / sizeof(barcos[0]);

    for (int b = 0; b < numBarcos; b++) {
        for (int k = 0; k < barcos[b].cantidad; k++) {
            int largo = barcos[b].tamaño;
            char simbolo = barcos[b].simbolo;
            int x, y;
            int orientacion = rand() % 2; // 0 = horizontal, 1 = vertical
            int colocado = 0;

            while (!colocado) {
                if (orientacion == 0) { // Horizontal
                    x = rand() % tamano;
                    y = rand() % (tamano - largo + 1);

                    // Verificar si hay espacio para colocar el barco
                    int espacioLibre = 1;
                    for (int l = 0; l < largo; l++) {
                        if (*(char *)(tablero[x][y + l]) != ' ') {
                            espacioLibre = 0;
                            break;
                        }
                    }

                    if (espacioLibre) {
                        // Colocar el barco
                        for (int l = 0; l < largo; l++) {
                            *(char *)(tablero[x][y + l]) = simbolo;
                        }
                        colocado = 1;
                    }
                } else { // Vertical
                    x = rand() % (tamano - largo + 1);
                    y = rand() % tamano;

                    // Verificar si hay espacio para colocar el barco
                    int espacioLibre = 1;
                    for (int l = 0; l < largo; l++) {
                        if (*(char *)(tablero[x + l][y]) != ' ') {
                            espacioLibre = 0;
                            break;
                        }
                    }

                    if (espacioLibre) {
                        // Colocar el barco
                        for (int l = 0; l < largo; l++) {
                            *(char *)(tablero[x + l][y]) = simbolo;
                        }
                        colocado = 1;
                    }
                }
            }
        }
    }
}
