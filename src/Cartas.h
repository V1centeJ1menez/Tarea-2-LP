#ifndef H_CARTAS
#define H_CARTAS


// Implementación de las cartas
/**
 * @brief Estructura que representa la mano del jugador.
 *
 * La estructura `Mano` almacena las cartas actuales del jugador y 
 * la cantidad de cartas disponibles para usar.
 */
typedef struct Mano 
{
    void ** carta;       /**< Array de punteros a cartas actuales en la mano. */
    int disponibles;    /**< Número de cartas disponibles para usar. */
} Mano;

/**
 * @brief Variable global que representa la mano del jugador.
 *
 * `Cartas` es una variable global que contiene la estructura `Mano`, 
 * la cual almacena las cartas actuales que tiene el jugador en su mano.
 */
extern Mano Cartas;

/**
 * @brief Inicializa la mano del jugador con cinco cartas de disparo simple.
 *
 * Esta función prepara la mano inicial del jugador, agregando cinco cartas 
 * de disparo simple.
 */
void inicializarMano();

/**
 * @brief Muestra en pantalla las cartas disponibles en la mano del jugador.
 *
 * Esta función imprime en la salida estándar una lista de las cartas 
 * actualmente disponibles en la mano del jugador.
 */
void mostrarMano();

/**
 * @brief Usa una carta de la mano disponible.
 *
 * Esta función permite al jugador usar una de las cartas disponibles en su mano,
 * eliminándola de la lista de cartas disponibles.
 */
void usarCarta();

void liberarMano();


/**
 * @brief Dispara un misil con un área de efecto de 1x1 celdas.
 *
 * La función dispara un misil en las coordenadas (x, y), afectando
 * únicamente esa celda específica.
 *
 * @param x Coordenada X del disparo.
 * @param y Coordenada Y del disparo.
 * @return Retorna una carta con las siguientes probabilidades:
 *         - disparoSimple: 65%
 *         - disparoGrande: 20%
 *         - disparoLineal: 5%
 *         - disparoRadar: 10%
 */

void * disparoSimple(int x, int y);

/**
 * @brief Dispara un gran misil con un área de efecto de 3x3 celdas.
 *
 * La función dispara un misil que afecta un área de 3x3 celdas,
 * centrada en las coordenadas (x, y).
 *
 * @param x Coordenada X del centro del área afectada.
 * @param y Coordenada Y del centro del área afectada.
 * @return Retorna una carta con las siguientes probabilidades:
 *         - disparoSimple: 80%
 *         - disparoGrande: 3%
 *         - disparoLineal: 10%
 *         - disparoRadar: 5%
 *         - disparo500KG: 2%
 */

void * disparoGrande(int x, int y);

/**
 * @brief Dispara múltiples misiles en un área de 1x5 o 5x1 celdas.
 *
 * La función dispara misiles que afectan un área de 1x5 celdas 
 * (en horizontal) o 5x1 celdas (en vertical), centrada en las 
 * coordenadas (x, y).
 *
 * @param x Coordenada X del centro del área afectada.
 * @param y Coordenada Y del centro del área afectada.
 * @return Retorna una carta con las siguientes probabilidades:
 *         - disparoSimple: 85%
 *         - disparoGrande: 5%
 *         - disparoLineal: 2%
 *         - disparoRadar: 6%
 *         - disparo500KG: 2%
 */

void * disparoLineal(int x, int y);

/**
 * @brief Dispara un misil radar que revela información sobre un área de 5x5 celdas.
 *
 * La función dispara un misil radar que no daña el área, pero revela
 * si hay presencia de barcos enemigos en un área de 5x5 celdas, 
 * centrada en las coordenadas (x, y).
 *
 * @param x Coordenada X del centro del área escaneada.
 * @param y Coordenada Y del centro del área escaneada.
 * @return Retorna una carta con las siguientes probabilidades:
 *         - disparoSimple: 75%
 *         - disparoGrande: 15%
 *         - disparoLineal: 5%
 *         - disparoRadar: 2%
 *         - disparo500KG: 3%
 */

void * disparoRadar(int x, int y);

/**
 * @brief Dispara un misil de 500KG que afecta un área de 11x11 celdas.
 *
 * Este misil es el más grande disponible y afecta un área de 11x11
 * celdas centrada en las coordenadas (x, y). Debido a su tamaño,
 * no retorna ninguna carta y deja incapacitado el cañón que lo disparó.
 *
 * @param x Coordenada X del centro del área afectada.
 * @param y Coordenada Y del centro del área afectada.
 * @return No retorna ninguna carta, el cañón queda incapacitado.
 */

void * disparo500KG(int x, int y);

void inicializarFunciones();


typedef void* (*func_ptr)(int, int); // Tipo para puntero a función

typedef enum {
    Simple,
    Grande,
    Lineal,
    Radar,
    _500KG,
    count
}Funciones;

extern func_ptr funciones[count];

int generarNumeroAleatorio(int max); 
void cambiarCarta(int indiceCarta, int tipoCarta); 

#endif