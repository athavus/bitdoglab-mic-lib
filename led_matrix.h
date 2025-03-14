#ifndef LED_MATRIX_H
#define LED_MATRIX_H

#include <stdint.h>

// Pino e número de LEDs da matriz de LEDs.
#define LED_PIN 7
#define LED_COUNT 25

/**
 * Inicializa a matriz de LEDs.
 */
void led_matrix_init();

/**
 * Limpa todos os LEDs da matriz (desliga todos).
 */
void led_matrix_clear();

/**
 * Atualiza a matriz de LEDs com base na intensidade do som.
 * @param intensity Intensidade do som (0 a 4)
 */
void led_matrix_update(uint8_t intensity);

/**
 * Aplica as mudanças na matriz de LEDs.
 */
void led_matrix_write();

#endif // LED_MATRIX_H