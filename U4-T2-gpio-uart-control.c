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
void configurar_leds(); //Configuracao inicial dos GPIOS - TODO - JULIERME E MARIO
void ligar_todos_leds(); // GABRIELLA
void desligar_todos_leds(); // TODO - JULIERME E MARIO
void ligar_led(uint led_pin); //OK - GEISON
void ligar_branco(); //TODO - JULIERME E MARIO
void acionar_buzzer(); //OK! - Emyle
void acionar_buzzer_com_frequencia(int frequencia, int duracao_ms); //TODO - ALEXANDRE
void processar_comandos(char comando); //OK - GEISON - TODO - GABRIELLA

// Desenvolvido por Geison
// Função para ligar um LED específico
void ligar_led(uint led_pin) {
    desligar_todos_leds();
    gpio_put(led_pin, 1);
}

// Desenvolvido por Emyle
// Função para acionar o buzzer por 3 segundos
void acionar_buzzer(){
    gpio_put(BUZZER, true);
    sleep_ms(3000);
    gpio_put(BUZZER, false);
    sleep_ms(3000);
}

// Desenvolvido por Gabriella
// Função para ligar todos os LEDs
void ligar_todos_leds() {
    gpio_put(LED_VERDE, true);
    gpio_put(LED_AZUL, true);
    gpio_put(LED_VERMELHO, true);
    printf("Todos os LEDs ligados.\n");
}

// Função para processar comandos UART
// Desenvolvido por Gabriella e Geison
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
            ligar_todos_leds();
            break;
        case '5': // Desligar todos os LEDs
            desligar_todos_leds();
            break;
        case '6': // Acionar buzzer por 3 segundos
            acionar_buzzer();
        case '7': // Acionar buzzer com frequência
            acionar_buzzer_com_frequencia(2, 3000); // Frequência de 2 Hz por 3 segundos
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
        acionar_buzzer();
    }
}
