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
void configurar_leds(); // OK - JULIERME
void ligar_todos_leds(); // OK - GABRIELLA
void desligar_todos_leds(); // OK - JULIERME
void ligar_led(uint led_pin); //OK - GEISON
void acionar_buzzer(); //OK! - Emyle
void acionar_buzzer_com_frequencia(int frequencia, int duracao_ms); //OK - GEISON
void processar_comandos(char comando); //OK - GEISON - GABRIELLA

// Desenvolvido por Geison
// Função para ligar um LED específico
void ligar_led(uint led_pin) {
    desligar_todos_leds();
    gpio_put(led_pin, 1);
}

// Desenvolvido por Julierme
// Configuração inicial dos GPIOs
void configurar_leds() {
    gpio_init(LED_VERDE);
    gpio_set_dir(LED_VERDE, GPIO_OUT);
    gpio_init(LED_AZUL);
    gpio_set_dir(LED_AZUL, GPIO_OUT);
    gpio_init(LED_VERMELHO);
    gpio_set_dir(LED_VERMELHO, GPIO_OUT);
    gpio_init(BUZZER);
    gpio_set_dir(BUZZER, GPIO_OUT);
}

// Desenvolvido por Julierme
// Função para desligar todos os LEDs
void desligar_todos_leds() {
    gpio_put(LED_VERDE, 0);
    gpio_put(LED_AZUL, 0);
    gpio_put(LED_VERMELHO, 0);
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

// Desenvolvido por Geison
// Função para acionar o buzzer com uma frequência específica
void acionar_buzzer_com_frequencia(int frequencia, int duracao_ms) {
    int atraso = 1000000 / (2 * frequencia); // Meio-período em microsegundos
    for (int i = 0; i < (duracao_ms * 1000) / (2 * atraso); i++) {
        gpio_put(BUZZER, 1);
        sleep_us(atraso);
        gpio_put(BUZZER, 0);
        sleep_us(atraso);
    }
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
            printf("Todos os LEDs ligados.\n");
            break;
        case '5': // Desligar todos os LEDs
            desligar_todos_leds();
            printf("Todos os LEDs desligados.\n");
            break;
        case '6': // Acionar buzzer por 3 segundos
            acionar_buzzer();
            printf("Buzzer acionado por 3 segundos.\n");
            break;
        case '7': // Acionar buzzer com frequência
            acionar_buzzer_com_frequencia(2, 3000); // Frequência de 2 Hz por 3 segundos
            printf("Buzzer acionado com frequência de 2 Hz por 3 segundos.\n");
            break;
        case '8': // Habilitar modo de gravação
            reset_usb_boot(0, 0);
            printf("Modo de gravação habilitado.\n");
            break;
        default:
            printf("Comando desconhecido. Tente novamente.\n");
            break;
    }
}

int main() {
    stdio_init_all();
    configurar_leds();

    while (true) {
        char comando;
        printf("Digite um comando (1-7): ");
        comando = getchar(); // Recebe comando via UART
        processar_comandos(comando); // Processa o comando recebido
    }

    return 0;
}
