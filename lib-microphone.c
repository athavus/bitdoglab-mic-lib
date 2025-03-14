#include <stdio.h>
#include <math.h>
#include "pico/stdlib.h"
#include "mic.h"
#include "led_matrix.h"

int main() {
    stdio_init_all();

    // Delay para o usuário abrir o monitor serial...
    sleep_ms(5000);

    // Inicialização da matriz de LEDs
    led_matrix_init();
    
    // Inicialização do módulo de microfone
    uint dma_channel = mic_init();

    // Buffer de amostras do ADC.
    uint16_t adc_buffer[SAMPLES];

    // Amostragem de teste.
    printf("Amostragem de teste...\n");
    mic_sample(adc_buffer, dma_channel);

    printf("Configuracoes completas!\n");

    printf("\n----\nIniciando loop...\n----\n");
    while (true) {
        // Realiza uma amostragem do microfone.
        mic_sample(adc_buffer, dma_channel);
        
        // Pega a potência média da amostragem do microfone.
        float avg = mic_power(adc_buffer);
        avg = 2.f * abs(ADC_ADJUST(avg)); // Ajusta para intervalo de 0 a 3.3V. (apenas magnitude, sem sinal)

        // Calcula intensidade a ser mostrada na matriz de LEDs.
        uint intensity = mic_get_intensity(avg);

        // Atualiza a matriz de LEDs com base na intensidade
        led_matrix_update(intensity);
        
        // Aplica as mudanças na matriz
        led_matrix_write();

        // Envia a intensidade e a média das leituras do ADC por serial.
        printf("Intensidade: %d | Média: %.4f V\n", intensity, avg);
    }
}