#include <Arduino.h>
#include <Wire.h>

#define I2C_ADDRESS  0x08
#define ADC_PIN      A0
#define LED_PIN      13

volatile uint8_t temperature = 25;

void requestEvent();

void setup() {
    pinMode(LED_PIN, OUTPUT);
    Wire.begin(I2C_ADDRESS);
    Wire.onRequest(requestEvent);
    Serial.begin(9600);
}

void loop() {
    int adcValue = analogRead(ADC_PIN);
    temperature = map(adcValue, 0, 676, 25, 100);
    digitalWrite(LED_PIN, !digitalRead(LED_PIN));
    delay(100);
}

void requestEvent() {
    Wire.write(temperature);
}
