#ifndef NEOPIXEL_H
#define NEOPIXEL_H

#include <stdlib.h>
#include <stdint.h>
#include "pico/stdlib.h"

/**
 * Inicializa o controlador de LEDs NeoPixel.
 * 
 * @param pin Pino GPIO conectado ao primeiro LED da cadeia
 * @param length Total de LEDs na cadeia
 */
void npInit(uint pin, uint amount);

/**
 * Define a cor de um LED específico.
 * 
 * @param i Índice do LED (começa em 0)
 * @param r Componente vermelho (0-255)
 * @param g Componente verde (0-255)
 * @param b Componente azul (0-255)
 */
void npSetLED(const uint index, const uint8_t r, const uint8_t g, const uint8_t b);

/**
 * Limpa todos os LEDs (desliga todos).
 */
void npClear();

/**
 * Envia os dados de cor para os LEDs.
 * Deve ser chamado após modificações para aplicar as alterações.
 */
void npWrite();

#endif // NEOPIXEL_H