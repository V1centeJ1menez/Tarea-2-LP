#ifndef H_TABLERO
#define H_TABLERO


/**
 * @brief Matriz cuadrada que almacena la información de cada celda.
 *
 * `tablero` es un puntero triple que representa una matriz cuadrada dinámica.
 * Cada celda de esta matriz contiene información específica relacionada con 
 * el estado o contenido de una celda en particular del tablero.
 *
 * - **Dimensiones**: Es una matriz de `N x N` donde `N` representa el tamaño 
 *   del tablero.
 * - **Tipo de datos**: `void***` permite almacenar punteros a punteros a 
 *   cualquier tipo de dato, lo que proporciona flexibilidad para almacenar 
 *   diferentes tipos de estructuras en cada celda.
 *
 * @note Dado que es una variable global, debe asegurarse que está 
 *       correctamente inicializada antes de su uso.
 */

extern void *** tablero;


/**
 * @brief Inicializa el tablero cuadrado para un tamaño dado.
 *
 * Esta función se encarga de crear y configurar el tablero, reservando memoria 
 * para cada celda en una matriz cuadrada de tamaño `tamano x tamano`. 
 * Cada celda se inicializa a un estado por defecto que representa que no ha sido disparada.
 *
 * @param tamano Tamaño del lado del tablero (número de filas y columnas).
 * @return Un puntero triple (`void***`) que apunta al tablero inicializado. 
 *         Si la inicialización falla, retorna `NULL`.
 *
 * @note Es responsabilidad del usuario liberar la memoria asignada al tablero
 *       una vez que ya no sea necesaria.
 */
void inicializarTablero(int tamano);


/**
 * @brief Imprime el estado actual del tablero en la salida estándar.
 *
 * Esta función recorre cada celda del tablero y muestra su estado en la consola.
 * Los estados posibles de cada celda son:
 * - `'.'`: La celda no ha sido disparada.
 * - `'O'`: El disparo ha fallado.
 * - `'X'`: El disparo ha acertado.
 *
 * @param tablero Puntero triple (`void***`) que apunta al tablero a mostrar.
 * @param tamano Tamaño del lado del tablero (número de filas y columnas).
 *
 * @note Asegúrese de que el tablero ha sido inicializado antes de llamar a esta 
 *       función para evitar comportamientos indefinidos.
 */
void mostrarTablero();


/**
 * @brief Libera la memoria asignada para el tablero.
 *
 * Esta función recorre cada celda del tablero y libera la memoria asignada para cada 
 * celda y para las filas y columnas de la matriz.
 *
 * @note Es importante llamar a esta función una vez que el tablero ya no sea necesario
 *       para evitar fugas de memoria.
 */
void liberarTablero();

#endif