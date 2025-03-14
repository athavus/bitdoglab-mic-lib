#include <stdio.h>
#include "led_matrix.h"
#include "neopixel.h"

/**
 * Inicializa a matriz de LEDs.
 */
void led_matrix_init() {
    printf("Preparando NeoPixel...");
    npInit(LED_PIN, LED_COUNT);
    printf("NeoPixel inicializado!\n");
}

/**
 * Limpa todos os LEDs da matriz (desliga todos).
 */
void led_matrix_clear() {
    npClear();
}

/**
 * Atualiza a matriz de LEDs com base na intensidade do som.
 * @param intensity Intensidade do som (0 a 8)
 */
void led_matrix_update(uint8_t intensity) {
    // Limpa a matriz de LEDs.
    npClear();

    // A depender da intensidade do som, acende LEDs específicos.
    switch (intensity) {
        case 0: 
            break; // Se o som for muito baixo, não acende nada.
        
        case 1:
            break; // Acende apenas o centro.
        
        case 2:
            npSetLED(12, 0, 0, 120); // Acende o centro.

            // Primeiro anel.
            npSetLED(7, 0, 0, 80);
            npSetLED(11, 0, 0, 80);
            npSetLED(13, 0, 0, 80);
            npSetLED(17, 0, 0, 80);
            break;
        
        case 3:
            // Centro.
            npSetLED(12, 60, 60, 0);

            // Primeiro anel.
            npSetLED(7, 0, 0, 120);
            npSetLED(11, 0, 0, 120);
            npSetLED(13, 0, 0, 120);
            npSetLED(17, 0, 0, 120);

            // Segundo anel.
            npSetLED(2, 0, 0, 80);
            npSetLED(6, 0, 0, 80);
            npSetLED(8, 0, 0, 80);
            npSetLED(10, 0, 0, 80);
            npSetLED(14, 0, 0, 80);
            npSetLED(16, 0, 0, 80);
            npSetLED(18, 0, 0, 80);
            npSetLED(22, 0, 0, 80);
            break;
        
        case 4:
            // Centro.
            npSetLED(12, 80, 0, 0);

            // Primeiro anel.
            npSetLED(7, 60, 60, 0);
            npSetLED(11, 60, 60, 0);
            npSetLED(13, 60, 60, 0);
            npSetLED(17, 60, 60, 0);

            // Segundo anel.
            npSetLED(2, 0, 0, 120);
            npSetLED(6, 0, 0, 120);
            npSetLED(8, 0, 0, 120);
            npSetLED(10, 0, 0, 120);
            npSetLED(14, 0, 0, 120);
            npSetLED(16, 0, 0, 120);
            npSetLED(18, 0, 0, 120);
            npSetLED(22, 0, 0, 120);

            // Terceiro anel.
            npSetLED(1, 0, 0, 80);
            npSetLED(3, 0, 0, 80);
            npSetLED(5, 0, 0, 80);
            npSetLED(9, 0, 0, 80);
            npSetLED(15, 0, 0, 80);
            npSetLED(19, 0, 0, 80);
            npSetLED(21, 0, 0, 80);
            npSetLED(23, 0, 0, 80);
            break;
        
        case 8:
            // Centro.
            npSetLED(12, 255, 0, 0);

            // Primeiro anel.
            npSetLED(7, 255, 60, 0);
            npSetLED(11, 255, 60, 0);
            npSetLED(13, 255, 60, 0);
            npSetLED(17, 255, 60, 0);

            // Segundo anel.
            npSetLED(2, 255, 0, 120);
            npSetLED(6, 255, 0, 120);
            npSetLED(8, 255, 0, 120);
            npSetLED(10, 255, 0, 120);
            npSetLED(14, 255, 0, 120);
            npSetLED(16, 255, 0, 120);
            npSetLED(18, 255, 0, 120);
            npSetLED(22, 255, 0, 120);

            // Terceiro anel.
            npSetLED(1, 255, 0, 80);
            npSetLED(3, 255, 0, 80);
            npSetLED(5, 255, 0, 80);
            npSetLED(9, 255, 0, 80);
            npSetLED(15, 255, 0, 80);
            npSetLED(19, 255, 0, 80);
            npSetLED(21, 255, 0, 80);
            npSetLED(23, 255, 0, 80);
            break;
    }
}

/**
 * Aplica as mudanças na matriz de LEDs.
 */
void led_matrix_write() {
    npWrite();
}