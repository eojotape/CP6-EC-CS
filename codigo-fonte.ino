#include <ESP32Servo.h>
#include "ArduinoJson.h"
#include "EspMQTTClient.h"

#define echoPin 27
#define trigPin 14
#define servoPin 12

long duracao;
float dist;

Servo servo;

EspMQTTClient client{
    "!SEU WIFI!",                             // SSID do WiFi
    "!SUA SENHA!",                          // Senha do wifi
    "mqtt.tago.io",                         // Endereço do servidor
    "Default",                              // Usuario
    "c5749daf-1ca1-4c67-aa20-ac1b3059486d", // Token do device
    "esp",                                  // Nome do device
    1883                                    // Porta de comunicação
};

void setup()
{
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
    Serial.begin(9600);
    Serial.println("Conectando WiFi");
    while (!client.isWifiConnected())
    {
        Serial.print('.');
        client.loop();
        delay(1000);
    }
    Serial.println("WiFi Conectado");
    Serial.println("Conectando com Servidor MQTT");
    while (!client.isMqttConnected())
    {
        Serial.print('.');
        client.loop();
        delay(1000);
    }
    Serial.println("MQTT Conectado");
}

void onConnectionEstablished()
{
}
char bufferJson[100];

void loop()
{

    int statusPorta = 0;

    digitalWrite(trigPin, LOW);
    delayMicroseconds(5);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    delayMicroseconds(10);

    duracao = pulseIn(echoPin, HIGH);
   
    dist = (duracao * 0.034) / 2;

    servo.attach(12);
    if (dist <= 10)
    {
        servo.write(90);
        Serial.print(dist);
        Serial.print("cm = ");
        Serial.println(" aberto");
        statusPorta = 1;
        delay(2000);
    }
    else
    {
        servo.write(0);
        Serial.print(dist);
        Serial.print("cm = ");
        Serial.println(" fechado");
        statusPorta = 0;
    }
    StaticJsonDocument<300> documentoJson;
    documentoJson["variable"] = "Porta";
    documentoJson["value"] = statusPorta;
    serializeJson(documentoJson, bufferJson);
    Serial.println(bufferJson);
    client.publish("Status_Porta", bufferJson);
    delay(5000);
    client.loop();
}
