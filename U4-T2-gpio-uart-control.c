#include <stdio.h>
#include <stdlib.h>
#include "pico/stdlib.h"
#include <pico/bootrom.h>

// Definição dos GPIOs
#define LED_GREEN 11
#define LED_BLUE 12
#define LED_RED 13
#define BUZZER 21

// Declaração de funções
void configurar();
void desligar_todos();
void ligar_led(uint led_pin);
void ligar_branco();
void aciona_buzzer(); //OK! - Emyle
void activate_buzzer_com_frequencia(int frequencia, int duracao_ms);
void processar_comando(char comando);

//Desenvolvido por Emyle
// Função para acionar o buzzer por 3 segundos
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
