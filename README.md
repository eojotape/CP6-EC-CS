# CP6-ED-CS
# Projeto de Porta Automatizada com ESP32, Servo Motor e Sensor Ultrassônico

Este é um projeto de uma porta que abre automaticamente quando detecta a presença de alguém usando um servo motor, um sensor ultrassônico e um ESP32.

## Materiais Necessários

- ESP32
- Servo Motor
- Sensor Ultrassônico HC-SR04 (ou similar)
- Placa de prototipagem
- Fonte de alimentação
- Jumpers e fios

## Montagem do Hardware

1. Conecte o servo motor à placa de prototipagem:
   - VCC do servo motor a uma saída de 5V do ESP32.
   - GND do servo motor a uma saída GND do ESP32.
   - Sinal (S) do servo motor ao pino GPIO do ESP32 escolhido.

2. Conecte o sensor ultrassônico à placa de prototipagem:
   - Conecte o pino VCC do sensor ultrassônico a uma saída de 5V do ESP32.
   - Conecte o pino GND do sensor ultrassônico a uma saída GND do ESP32.
   - Conecte o pino Echo do sensor ultrassônico ao pino GPIO do ESP32.
   - Conecte o pino Trigger do sensor ultrassônico a outro pino GPIO do ESP32.

3. Alimente o ESP32 com uma fonte de alimentação apropriada. No projeto foi utilizado um computador.

## Programação

1. Use a IDE Arduino ou sua plataforma de desenvolvimento preferida para programar o ESP32.

2. Escreva um código que:
   - Realize leituras do sensor ultrassônico para medir a distância entre o sensor e o objeto.
   - Quando o sensor detectar a presença de alguém a uma distância configurada, acione o servo motor para abrir a porta.
   - Calibre o servo motor para a abertura correta da porta e defina os ângulos corretos no código.

## Teste

- Realize testes para garantir que o sensor ultrassônico detecta corretamente a presença de alguém e que o servo motor abre e fecha a porta de acordo com os comandos do sensor.
- Ajuste o código conforme necessário para garantir um funcionamento suave e confiável.

## Integração
O projeto foi integrado via Tago.io utilizando assim a internet das coisas(IOT). Com ajuda dessa plataforma foi possivel verificar de qualquer lugar se o sensor estava aberto ou fechado.


