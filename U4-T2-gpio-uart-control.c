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
void desligar_todos_leds(); // TODO - JULIERME E MARIO
void ligar_led(uint led_pin); //OK - GEISON
void ligar_branco(); //TODO - JULIERME E MARIO
void aciona_buzzer(); //OK! - Emyle
void activate_buzzer_com_frequencia(int frequencia, int duracao_ms); //TODO - ALEXANDRE
void processar_comandos(char comando); //OK - GEISON - TODO - GABRIELLA

// Desenvolvido por Geison
// Função para ligar um LED específico
void ligar_led(uint led_pin) {
    desligar_todos();
    gpio_put(led_pin, 1);
}

// Desenvolvido por Emyle
// Função para acionar o buzzer por 3 segundos
void aciona_buzzer(){
    gpio_put(BUZZER, true);
    sleep_ms(3000);
    gpio_put(BUZZER, false);
    sleep_ms(3000);
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
        /*TODO - Funções 4 ao 8 - (Os proximos cases devem chamar)
        
        - Função para ligar todos os LEDs
        - Função para desligar todos os LEDs
        - Função para acionar o buzzer
        - Função para acionar o buzzer com frequência
        - Função para habilitar o modo de gravacao [A funcao é (reset_usb_boot(0, 0);]
)
        - Default case
        */
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
