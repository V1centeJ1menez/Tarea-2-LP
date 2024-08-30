#include <stdio.h>
#include <stdlib.h>
#include "Cartas.h"

Mano Cartas;

// Declaración de las funciones
void * disparoSimple(int x, int y) {
    printf("Disparo Simple con (%d, %d)\n", x, y);
    return NULL;
}

void * disparoGrande(int x, int y) {
    printf("Disparo Grande con (%d, %d)\n", x, y);
    return NULL;
}

void * disparoLineal(int x, int y) {
    printf("Disparo Lineal con (%d, %d)\n", x, y);
    return NULL;
}

void * disparoRadar(int x, int y) {
    printf("Disparo Radar con (%d, %d)\n", x, y);
    return NULL;
}

void * disparo500KG(int x, int y) {
    printf("Disparo 500KG con (%d, %d)\n", x, y);
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

    // Ejecutar la función de la carta seleccionada
    cartaSeleccionada(0, 0); // Llamar la función con coordenadas arbitrarias

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
        if (random < 65) {
            Cartas.carta[indiceCarta] = (void *)funciones[Simple];
        } else if (random < 85) {
            Cartas.carta[indiceCarta] = (void *)funciones[Grande];
        } else if (random < 90) {
            Cartas.carta[indiceCarta] = (void *)funciones[Lineal];
        } else if (random < 100) {
            Cartas.carta[indiceCarta] = (void *)funciones[Radar];
        }
    } else if (tipoCarta == Grande) {
        if (random < 80) {
            Cartas.carta[indiceCarta] = (void *)funciones[Simple];
        } else if (random < 83) {
            Cartas.carta[indiceCarta] = (void *)funciones[Grande];
        } else if (random < 93) {
            Cartas.carta[indiceCarta] = (void *)funciones[Lineal];
        } else if (random < 98) {
            Cartas.carta[indiceCarta] = (void *)funciones[Radar];
        } else {
            Cartas.carta[indiceCarta] = (void *)funciones[_500KG];
        }
    } else if (tipoCarta == Lineal) {
        if (random < 85) {
            Cartas.carta[indiceCarta] = (void *)funciones[Simple];
        } else if (random < 90) {
            Cartas.carta[indiceCarta] = (void *)funciones[Grande];
        } else if (random < 92) {
            Cartas.carta[indiceCarta] = (void *)funciones[Lineal];
        } else if (random < 98) {
            Cartas.carta[indiceCarta] = (void *)funciones[Radar];
        } else {
            Cartas.carta[indiceCarta] = (void *)funciones[_500KG];
        }
    } else if (tipoCarta == Radar) {
        if (random < 75) {
            Cartas.carta[indiceCarta] = (void *)funciones[Simple];
        } else if (random < 90) {
            Cartas.carta[indiceCarta] = (void *)funciones[Grande];
        } else if (random < 95) {
            Cartas.carta[indiceCarta] = (void *)funciones[Lineal];
        } else if (random < 97) {
            Cartas.carta[indiceCarta] = (void *)funciones[Radar];
        } else {
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