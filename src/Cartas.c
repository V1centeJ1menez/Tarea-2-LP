#include <stdio.h>
#include <stdlib.h>
#include "Cartas.h"
#include "Tablero.h"


Mano Cartas;

// Variables globales para las coordenadas
int coordenadaX = 0;
int coordenadaY = 0;

void * disparoSimple(int x, int y) {
    // Verificar que las coordenadas estén dentro de los límites del tablero
    if (x < 0 || x > tamanoTablero || y < 0 || y > tamanoTablero) {
        printf("Coordenadas fuera de los límites del tablero.\n");
        return NULL;
    }

    // Mostrar el disparo
    printf("Disparo Simple con (%d, %d)\n", x , y ); // Para mostrar coordenadas 1-indexed

    // Verificar el estado del tablero en la coordenada especificada
    char *celda = (char *)tablero[x - 1][y - 1]; // Convertir el puntero a char
    if (*celda == ' ') {
        // Si está vacío, se considera un fallo
        printf("Falló el disparo en (%d, %d).\n", x, y );
        *celda = 'O'; // Marcamos el fallo en el tablero
    } else if (*celda == 'O'){
    
        printf("Has fallado de nuevo (%d, %d).\n", x, y );
    } else {
        // Si hay algo, se considera un acierto
        printf("Acierto en (%d, %d).\n", x , y );
        *celda = 'X'; // Marcamos el acierto en el tablero
    }

    return NULL;
}


void * disparoGrande(int x, int y) {
    // Verificar que las coordenadas estén dentro de los límites del tablero
    if (x < 1 || x > tamanoTablero || y < 1 || y > tamanoTablero) {
        printf("Coordenadas fuera de los límites del tablero.\n");
        return NULL;
    }

    // Ajustar las coordenadas para que el índice del arreglo sea 0-indexed
    int x0 = x - 1;
    int y0 = y - 1;

    printf("Disparo Grande con (%d, %d)\n", x, y);

    // Recorrer el área de efecto 3x3
    for (int i = x0 - 1; i <= x0 + 1; i++) {
        for (int j = y0 - 1; j <= y0 + 1; j++) {
            // Verificar que las coordenadas estén dentro de los límites del tablero
            if (i >= 0 && i < tamanoTablero && j >= 0 && j < tamanoTablero) {
                char *celda = (char *)tablero[i][j]; // Convertir el puntero a char
                if (*celda == ' ' || *celda == 'O') {
                    // Si está vacío, se considera un fallo
                    *celda = 'O'; // Marcamos el fallo en el tablero
    
                } else {
                    // Si hay algo, se considera un acierto
                    *celda = 'X'; // Marcamos el acierto en el tablero
                }
            }
        }
    }

    return NULL;
}


void * disparoLineal(int x, int y) {
    // Verificar que las coordenadas estén dentro de los límites del tablero
    if (x < 1 || x > tamanoTablero || y < 1 || y > tamanoTablero) {
        printf("Coordenadas fuera de los límites del tablero.\n");
        return NULL;
    }

    // Ajustar las coordenadas para que el índice del arreglo sea 0-indexed
    int x0 = x - 1;
    int y0 = y - 1;

    printf("Disparo Lineal con (%d, %d)\n", x, y);

    // Determinar la orientación (0 = horizontal, 1 = vertical)
    int orientacion = rand() % 2;

    // Área de efecto de 1x5 o 5x1 dependiendo de la orientación
    if (orientacion == 0) { // Horizontal
        for (int j = y0 - 2; j <= y0 + 2; j++) {
            // Verificar que la columna está dentro de los límites del tablero
            if (x0 >= 0 && x0 < tamanoTablero && j >= 0 && j < tamanoTablero) {
                char *celda = (char *)tablero[x0][j]; // Convertir el puntero a char
                if (*celda == ' ') {
                    // Si está vacío, se considera un fallo
                    *celda = 'O'; // Marcamos el fallo en el tablero
                } else if (*celda != 'O') {
                    // Si hay algo, se considera un acierto
                    *celda = 'X'; // Marcamos el acierto en el tablero
                }
            }
        }
    } else { // Vertical
        for (int i = x0 - 2; i <= x0 + 2; i++) {
            // Verificar que la fila está dentro de los límites del tablero
            if (i >= 0 && i < tamanoTablero && y0 >= 0 && y0 < tamanoTablero) {
                char *celda = (char *)tablero[i][y0]; // Convertir el puntero a char
                if (*celda == ' ') {
                    // Si está vacío, se considera un fallo
                    *celda = 'O'; // Marcamos el fallo en el tablero
                } else if (*celda != 'O') {
                    // Si hay algo, se considera un acierto
                    *celda = 'X'; // Marcamos el acierto en el tablero
                }
            }
        }
    }

    return NULL;
}


void *disparoRadar(int x, int y) {
    printf("Disparo Radar con (%d, %d)\n", x, y);

    // Ajustar las coordenadas para que el índice del arreglo sea 0-indexed
    int x0 = x - 1;
    int y0 = y - 1;

    // Recorrer el área de efecto 5x5
    for (int i = x0 - 2; i <= x0 + 2; i++) {
        for (int j = y0 - 2; j <= y0 + 2; j++) {
            // Verificar que las coordenadas estén dentro de los límites del tablero
            if (i >= 0 && i < tamanoTablero && j >= 0 && j < tamanoTablero) {
                char *celda = (char *)tablero[i][j]; // Convertir el puntero a char
                if (*celda == ' ' || *celda == 'O') {
                    // Si está vacío, se considera un fallo y se marca con '0'
                    *celda = '0';
                } else if (*celda != 'X') {
                    // Si hay un barco, se marca con 'X'
                    *celda = 'X';
                }
            }
        }
    }

    return NULL;
}


void *disparo500KG(int x, int y) {
    printf("Disparo 500KG con (%d, %d)\n", x, y);

    // Ajustar las coordenadas para que el índice del arreglo sea 0-indexed
    int x0 = x - 1;
    int y0 = y - 1;

    // Recorrer el área de efecto 11x11
    for (int i = x0 - 5; i <= x0 + 5; i++) {
        for (int j = y0 - 5; j <= y0 + 5; j++) {
            // Verificar que las coordenadas estén dentro de los límites del tablero
            if (i >= 0 && i < tamanoTablero && j >= 0 && j < tamanoTablero) {
                char *celda = (char *)tablero[i][j]; // Convertir el puntero a char
                if (*celda != 'X') {
                    // Marcar todas las celdas afectadas con '0' si no hay un acierto
                    *celda = '0';
                }
            }
        }
    }

    return NULL;
}



// Array de punteros a funciones
func_ptr funciones[count];

void inicializarFunciones() {
    funciones[Simple] = disparoSimple;
    funciones[Grande] = disparoGrande;
    funciones[Lineal] = disparoLineal;
    funciones[Radar] = disparoRadar;
    funciones[_500KG] = disparo500KG;
}


void inicializarMano() {
    Cartas.disponibles = 5;
    Cartas.carta = (void **)malloc(Cartas.disponibles * sizeof(void *));
    
    if (Cartas.carta == NULL) {
        perror("Failed to allocate memory");
        exit(EXIT_FAILURE);
    }

    // Inicializa el array de cartas con punteros a funcion Simple
    for (int i = 0; i < Cartas.disponibles; i++) {
        Cartas.carta[i] = (void *)funciones[0]; // Cast a void *
    }
}


void mostrarMano() {
    printf("Cartas:\n");
    for (int i = 0; i < Cartas.disponibles; i++) {
        func_ptr f = (func_ptr)Cartas.carta[i]; // Cast a func_ptr
        if (f == disparoSimple) {
            printf("Simple ");
        } else if (f == disparoGrande) {
            printf("Grande ");
        } else if (f == disparoLineal) {
            printf("Lineal ");
        } else if (f == disparoRadar) {
            printf("Radar ");
        } else if (f == disparo500KG) {
            printf("500KG ");
        }

        if (i != Cartas.disponibles - 1){
             printf("| ");
        }

    }
    printf("\n");
}

// Implementación de la función usarCarta
void usarCarta() {
    int seleccion = 0;

    mostrarMano();
    printf("Selecciona una Carta (1-%d): ", Cartas.disponibles);
    scanf("%d", &seleccion);
    seleccion--; // Ajustar a índice basado en 0

    if (seleccion < 0 || seleccion >= Cartas.disponibles) {
        printf("Selección inválida.\n");
        return;
    }

    func_ptr cartaSeleccionada = (func_ptr)Cartas.carta[seleccion];
    // Determinar el tipo de carta actual
    int tipoCarta;
    if (cartaSeleccionada == disparoSimple) {
        tipoCarta = Simple;
    } else if (cartaSeleccionada == disparoGrande) {
        tipoCarta = Grande;
    } else if (cartaSeleccionada == disparoLineal) {
        tipoCarta = Lineal;
    } else if (cartaSeleccionada == disparoRadar) {
        tipoCarta = Radar;
    } else if (cartaSeleccionada == disparo500KG) {
        tipoCarta = _500KG;
    } else {
        printf("Carta no válida.\n");
        return;
    }

    // Leer coordenadas para el disparo
    printf("Ingrese coordenada X (Fila): ");
    scanf("%d", &coordenadaX);
    printf("Ingrese coordenada Y (Columna): ");
    scanf("%d", &coordenadaY);
    // Ejecutar la función de la carta seleccionada
    cartaSeleccionada(coordenadaX, coordenadaY); // Llamar la función con coordenadas arbitrarias

    // Cambiar la carta según las probabilidades
    cambiarCarta(seleccion, tipoCarta);
}

void liberarMano() {
    free(Cartas.carta);
}


// Función para generar un número aleatorio entre 0 y max (incluido)
int generarNumeroAleatorio(int max) {
    return rand() % (max + 1);
}

// Función para cambiar la carta según las probabilidades
void cambiarCarta(int indiceCarta, int tipoCarta) {
    int random = generarNumeroAleatorio(99);

    // Probabilidades de cambio según el tipo de carta actual
    if (tipoCarta == Simple) {
        // disparoSimple: 65%
        if (random < 65) {
            Cartas.carta[indiceCarta] = (void *)funciones[Simple];
        }
        // disparoGrande: 20%
        else if (random < 85) {
            Cartas.carta[indiceCarta] = (void *)funciones[Grande];
        }
        // disparoLineal: 5%
        else if (random < 90) {
            Cartas.carta[indiceCarta] = (void *)funciones[Lineal];
        }
        // disparoRadar: 10%
        else if (random < 100) {
            Cartas.carta[indiceCarta] = (void *)funciones[Radar];
        }
    } else if (tipoCarta == Grande) {
        // disparoSimple: 80%
        if (random < 80) {
            Cartas.carta[indiceCarta] = (void *)funciones[Simple];
        }
        // disparoGrande: 3%
        else if (random < 83) {
            Cartas.carta[indiceCarta] = (void *)funciones[Grande];
        }
        // disparoLineal: 10%
        else if (random < 93) {
            Cartas.carta[indiceCarta] = (void *)funciones[Lineal];
        }
        // disparoRadar: 5%
        else if (random < 98) {
            Cartas.carta[indiceCarta] = (void *)funciones[Radar];
        }
        // disparo500KG: 2%
        else {
            Cartas.carta[indiceCarta] = (void *)funciones[_500KG];
        }
    } else if (tipoCarta == Lineal) {
        // disparoSimple: 85%
        if (random < 85) {
            Cartas.carta[indiceCarta] = (void *)funciones[Simple];
        }
        // disparoGrande: 5%
        else if (random < 90) {
            Cartas.carta[indiceCarta] = (void *)funciones[Grande];
        }
        // disparoLineal: 2%
        else if (random < 92) {
            Cartas.carta[indiceCarta] = (void *)funciones[Lineal];
        }
        // disparoRadar: 6%
        else if (random < 98) {
            Cartas.carta[indiceCarta] = (void *)funciones[Radar];
        }
        // disparo500KG: 2%
        else {
            Cartas.carta[indiceCarta] = (void *)funciones[_500KG];
        }
    } else if (tipoCarta == Radar) {
        // disparoSimple: 75%
        if (random < 75) {
            Cartas.carta[indiceCarta] = (void *)funciones[Simple];
        }
        // disparoGrande: 15%
        else if (random < 90) {
            Cartas.carta[indiceCarta] = (void *)funciones[Grande];
        }
        // disparoLineal: 5%
        else if (random < 95) {
            Cartas.carta[indiceCarta] = (void *)funciones[Lineal];
        }
        // disparoRadar: 2%
        else if (random < 97) {
            Cartas.carta[indiceCarta] = (void *)funciones[Radar];
        }
        // disparo500KG: 3%
        else {
            Cartas.carta[indiceCarta] = (void *)funciones[_500KG];
        }
    } else if (tipoCarta == _500KG) {
        // No se cambia la carta y se incapacita el cañón
        Cartas.disponibles--;
        if (Cartas.disponibles <= 0) {
            printf("No hay más cartas disponibles.\n");
            liberarMano();
            exit(EXIT_FAILURE);
        }
        for (int i = indiceCarta; i < Cartas.disponibles; i++) {
            Cartas.carta[i] = Cartas.carta[i + 1];
        }
        Cartas.carta = realloc(Cartas.carta, Cartas.disponibles * sizeof(void *));
        if (Cartas.carta == NULL) {
            perror("Failed to reallocate memory");
            exit(EXIT_FAILURE);
        }
    }
}
