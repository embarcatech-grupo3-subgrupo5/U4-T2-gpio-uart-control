#include <stdio.h>
#include "pico/stdlib.h"

#define BUZZER 21

void aciona_buzzer(){
    gpio_put(BUZZER, true);
    sleep_ms(3000);
    gpio_put(BUZZER, false);
    sleep_ms(3000);
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
#include <stdlib.h>
#include "pico/stdlib.h"

// Definições de pinos
#define PIN_LED_G 11
#define PIN_LED_B 12
#define PIN_LED_R 13

// Funções para controlar LEDs
void ativar_led(uint pino) {
    gpio_put(pino, 1);
}

void desativar_led(uint pino) {
    gpio_put(pino, 0);
}

// Função para controlar o Buzzer
void ativar_buzzer(void) {
    gpio_put(PIN_BUZZER, 1);
}

void desativar_buzzer(void) {
    gpio_put(PIN_BUZZER, 0);

    }

int main() {

    // Configuração dos LEDs 
    gpio_init(PIN_LED_R);
    gpio_set_dir(PIN_LED_R, GPIO_OUT);
    gpio_put(PIN_LED_R, 0);

    gpio_init(PIN_LED_G);
    gpio_set_dir(PIN_LED_G, GPIO_OUT);
    gpio_put(PIN_LED_G, 0);

    gpio_init(PIN_LED_B);
    gpio_set_dir(PIN_LED_B, GPIO_OUT);
    gpio_put(PIN_LED_B, 0);

     char tecla_pressionada;

    while (true) {
        tecla_pressionada = obter_tecla();  // Obtém a tecla pressionada

        // Controles de LEDs 
        switch (tecla_pressionada) {
            case 'A':
                ativar_led(PIN_LED_R); // Liga o LED vermelho
                break;
            case 'B':
                ativar_led(PIN_LED_B); // Liga o LED azul
                break;
            case 'C':
                ativar_led(PIN_LED_G); // Liga o LED verde
                break;
            case 'D':
                ativar_led(PIN_LED_R); // Liga todos os LEDs
                ativar_led(PIN_LED_B);
                ativar_led(PIN_LED_G);
                break;
            
            default:
                // Desliga os LEDs
                desativar_led(PIN_LED_R);
                desativar_led(PIN_LED_B);
                desativar_led(PIN_LED_G);
                
                break;
        }

        sleep_ms(50);  // Delay para evitar leituras rápidas demais
    }

    return 0;
}
