/*
    void mostrarTablero() {
    // Imprimir la fila de números de columna
    printf("   ");
    for (int j = 0; j < tamanoTablero; j++) {
        printf("+---"); // Separadores entre celdas
    }
    printf("+\n");

    printf("   ");
    for (int j = 0; j < tamanoTablero; j++) {
        printf("| %2d", j + 1); // Números de columna, ajustado para ser 1-indexed
    }
    printf(" |\n");

    printf("   ");
    for (int j = 0; j < tamanoTablero; j++) {
        printf("+---"); // Separadores entre celdas
    }
    printf("+\n");

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
            printf("+---"); // Separadores entre celdas
        }
        printf("+\n");
    }
}
*/