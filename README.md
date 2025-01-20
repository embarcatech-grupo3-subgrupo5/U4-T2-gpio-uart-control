# U4-T2-gpio-uart-control
## Tarefa 2 -Controle de pinos GPIO com o emprego de uma porta UART. 
## Descrição
Este projeto implementa o controle de pinos GPIO de um microcontrolador RP2040 utilizando:

Interface UART para comandos.

O objetivo é realizar o acionamento de LEDs RGB e um buzzer via comunicação serial.

Funcionalidades:

Recepção de comandos via UART para controlar LEDs e buzzer.

Mapeamento de comandos para ações:

LED_GREEN: Liga o LED verde.

LED_BLUE: Liga o LED azul.

LED_RED: Liga o LED vermelho.

LED_WHITE: Liga todos os LEDs.

LED_OFF: Desliga todos os LEDs.

BUZZER_ON: Aciona o buzzer por 2 segundos.

## Requisitos:

Microcontrolador Raspberry Pi Pico W.

Ferramenta educacional BitDogLab.

Terminal serial (como PuTTY).

## Execução:

Configure os LEDs nos GPIOs 11, 12 e 13 e o buzzer no GPIO 21.

Envie comandos via UART utilizando um terminal serial.

Observe os LEDs e o buzzer respondendo aos comandos.

## Configuração do Ambiente

Instale o Pico SDK seguindo a documentação oficial.

Configure o simulador Wokwi para a Atividade 1.

Configure o terminal serial (PuTTY) para a Atividade 2.

## Contribuição

Clone o repositório.

Crie um branch para suas alterações.

Faça commits claros e frequentes.

Envie um pull request para revisão.

# Vídeo Demonstrativo

Um vídeo mostrando o funcionamento do projeto está disponível no link: [Inserir Link Aqui]
