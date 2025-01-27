# Controle de GPIO com LEDs e Buzzer - RP2040

![Image](https://github.com/user-attachments/assets/d50b85b8-d484-4839-93d8-4390087bf2cf)

## Descrição do Projeto
Este projeto utiliza o microcontrolador RP2040 presente na placa Raspberry Pi Pico W para controlar três LEDs (verde, azul e vermelho) e um buzzer. A interação com o sistema ocorre por meio de comandos UART, permitindo ligar, desligar e executar diferentes padrões de controle dos LEDs e do buzzer. O projeto foi desenvolvido e testado em simulação no Wokwi e é compatível com hardware físico.

## Funcionalidades
- Controle individual dos LEDs (verde, azul e vermelho).
- Ligação e desligamento simultâneo de todos os LEDs.
- Acionamento do buzzer por diferentes durações e frequências.
- Processamento de comandos UART para realizar as ações.

## Requisitos do Sistema
1. **Hardware Necessário:**
   - Placa de desenvolvimento Raspberry Pi Pico W.
   - LEDs (verde, azul, vermelho).
   - Buzzer passivo.

2. **Software e Ferramentas:**
   - Ambiente de desenvolvimento VS Code.
   - Pico SDK configurado para o RP2040.
   - Git para versionamento de código.

## Configuração do Ambiente
1. Clone este repositório:
   ```bash
   git clone <https://github.com/embarcatech-grupo3-subgrupo5/U4-T2-gpio-uart-control>
   ```
2. Configure o Pico SDK no seu ambiente de desenvolvimento.
3. Compile e carregue o código na Raspberry Pi Pico W.
4. Utilize um monitor serial (como o Putty ou a interface do VS Code) para enviar comandos UART e interagir com o sistema.

## Histórico de Contribuições
### **Equipe e Funções:**

1. **Geison:**
   - Desenvolvimento da função para ligar LEDs individualmente.
   - Implementação do acionamento do buzzer passivo com frequência e duração customizadas.
   - Colaboração na lógica de processamento de comandos UART.

2. **Julierme:**
   - Configuração inicial dos GPIOs para LEDs e buzzer.
   - Desenvolvimento da função para desligar todos os LEDs.

3. **Emyle:**
   - Configuração incial do projeto e base incial.
   - Implementação da função de configuração incial do buzzer.
   - Implementação da função para acionar o buzzer por 3 segundos.

4. **Gabriella:**
   - Desenvolvimento da função para ligar todos os LEDs.
   - Colaboração no processamento dos comandos UART e na integração geral do sistema.

## Instruções de Uso
1. Inicie o monitor serial com uma conexão UART para a Raspberry Pi Pico W.
2. Envie os seguintes comandos para controlar os LEDs e o buzzer:
   - **1**: Liga o LED verde.
   - **2**: Liga o LED azul.
   - **3**: Liga o LED vermelho.
   - **4**: Liga todos os LEDs.
   - **5**: Desliga todos os LEDs.
   - **6**: Aciona o buzzer por 2 segundos.
   - **7**: Habilita o modo de gravação.
3. Observe as ações no hardware ou na simulação.

## Vídeo Demonstrativo
Confira o funcionamento do projeto no vídeo [aqui](https://youtu.be/Q1Mv1HByov4).

## Licença
Este projeto é licenciado sob a MIT License.

