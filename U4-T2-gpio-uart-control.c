#include <stdio.h>
#include <stdlib.h>
#include "pico/stdlib.h"
#include <pico/bootrom.h>

// Definição dos GPIOs
#define LED_VERDE 11
#define LED_AZUL 12
#define LED_VERMELHO 13
#define BUZZER 21

// Declaração de funções
void configurar();
void desligar_todos();
void ligar_led(uint led_pin);
void ligar_branco();
void aciona_buzzer(); //OK! - Emyle
void activate_buzzer_com_frequencia(int frequencia, int duracao_ms);
void processar_comandos(char comando);

//Desenvolvido por Emyle
// Função para acionar o buzzer por 3 segundos
void aciona_buzzer(){
    gpio_put(BUZZER, true);
    sleep_ms(3000);
    gpio_put(BUZZER, false);
    sleep_ms(3000);
}

// Função para ativar o buzzer com uma frequência específica e duração
void activate_buzzer_com_frequencia(int frequencia, int duracao_ms) {
    int intervalo = 1000 / frequencia; // Calcula o intervalo de tempo entre os "bips"
    for (int i = 0; i < duracao_ms / intervalo; i++) {
        gpio_put(BUZZER, true);
        sleep_ms(intervalo / 2); // Meio do intervalo
        gpio_put(BUZZER, false);
        sleep_ms(intervalo / 2); // Meio do intervalo
    }
}

// Função para desligar todos os LEDs
void desligar_todos() {
    gpio_put(LED_VERDE, false);
    gpio_put(LED_AZUL, false);
    gpio_put(LED_VERMELHO, false);
    printf("Todos os LEDs desligados.\n");
}

// Função para ligar todos os LEDs
void ligar_todos() {
    gpio_put(LED_VERDE, true);
    gpio_put(LED_AZUL, true);
    gpio_put(LED_VERMELHO, true);
    printf("Todos os LEDs ligados.\n");
}

// Função para processar comandos UART
void processar_comandos(char comando) {
    switch (comando) {
        case '1': // Ligar LED verde
            ligar_led(LED_VERDE);
            printf("LED verde ligado.\n");
            break;
        case '2': // Ligar LED azul
            ligar_led(LED_AZUL);
            printf("LED azul ligado.\n");
            break;
        case '3': // Ligar LED vermelho
            ligar_led(LED_VERMELHO);
            printf("LED vermelho ligado.\n");
            break;
        case '4': // Ligar todos os LEDs
            ligar_todos();
            break;
        case '5': // Desligar todos os LEDs
            desligar_todos();
            break;
        case '6': // Acionar buzzer por 3 segundos
            aciona_buzzer();
        case '7': // Acionar buzzer com frequência
            activate_buzzer_com_frequencia(2, 3000); // Frequência de 2 Hz por 3 segundos
            break;
        case '8': // Habilitar modo de gravação
            reset_usb_boot(0, 0);
            break;
        default:
            printf("Comando desconhecido.\n");
            break;
    }
}

int main()
{
    stdio_init_all();
    gpio_init(BUZZER);
    gpio_set_dir(BUZZER, GPIO_OUT);

    while (true) {
        aciona_buzzer();
    }
}
