
# Biblioteca para Controle de Microfone e Matriz de LEDs na **BitdogLab** com **Raspberry Pi Pico W**

Esta biblioteca foi desenvolvida para a plataforma **BitdogLab** que utiliza a **Raspberry Pi Pico W (RP2040)**. Ela permite a captura de áudio via microfone, processa as amostras de áudio e controla uma matriz de LEDs **NeoPixel** para exibir visualmente a intensidade do som detectado.

## Estrutura do Projeto

O projeto é composto por três módulos principais e um script para armazenamento dos logs:

1. **[lib-microphone.c](./lib-microphone.c)** - Responsável pela captura de áudio do microfone e pelo controle do fluxo de dados.
2. **[mic.c](./mic.c)** - Contém funções para configurar o ADC, o DMA e realizar as leituras do microfone.
3. **[led_matrix.c](./led_matrix.c)** - Controla a matriz de LEDs **NeoPixel**, exibindo a intensidade do som de acordo com a amostragem do microfone.
4. **[logs.py](./logs.py)** - Script Python para capturar os logs via comunicação serial, permitindo registrar os valores de intensidade e média de áudio para posterior análise.


## Dependências

- **Raspberry Pi Pico W (RP2040)**
- **NeoPixel Library** para controle dos LEDs

## Funcionalidades

### 1. Inicialização da Biblioteca

A biblioteca deve ser inicializada antes de utilizar as funcionalidades, com a seguinte sequência de funções:

```c
void init_microphone();
void init_led_matrix();
```

### 2. Captura de Áudio

A captura do áudio é feita utilizando o ADC da **Raspberry Pi Pico W** com leitura contínua do microfone. A função `read_audio_sample()` realiza a amostragem dos dados.

```c
uint32_t read_audio_sample();
```

### 3. Processamento de Áudio

Os dados do áudio capturado são processados para calcular a intensidade do som. A função `process_audio_sample()` converte a amostra de áudio em um valor adequado para controlar a matriz de LEDs.

```c
void process_audio_sample(uint32_t sample);
```

### 4. Controle da Matriz de LEDs

A matriz de LEDs **NeoPixel** exibe a intensidade do áudio. A função `update_led_matrix()` recebe o valor da intensidade e atualiza a exibição dos LEDs.

```c
void update_led_matrix(uint32_t intensity);
```

### 5. Script de Logs em Python

O script **logs.py** permite capturar os logs de dados do microfone via comunicação serial. Ele registra as amostras de áudio, bem como a média de intensidade ao longo do tempo. Abaixo está o código básico que pode ser necessário alterar para utilizar o script:

```python
# CONFIGURAÇÕES
PORTA = 'COM7'           # Porta onde sua placa aparece no Windows
BAUD = 115200            # Velocidade de comunicação (deve bater com o código C)
ARQUIVO_LOG = 'logs_microphone.txt'  # Nome do arquivo onde os logs serão salvos
```