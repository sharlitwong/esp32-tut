/*
ESP32 Tutorial with HC-SR04 Ultrasonic Sensor
Last Edited: 8/21/2026 by Charlotte Wong

A basic program that configures pins, then uses a distance sensor to print the 
distance to the closest object from the sensor in cm. 
*/ 

#include <Arduino.h>

const int TRIG_PIN = 10;
const int ECHO_PIN = 1;

void setup() {
    pinMode(TRIG_PIN, OUTPUT); // gpio 10 esp --> sensor
    pinMode(ECHO_PIN, INPUT);

    Serial.begin(115200);
}

void loop() {
    // Make sure TRIG starts LOW
    digitalWrite(TRIG_PIN, LOW);
    delayMicroseconds(2);

    // Send a 10 microsecond pulse
    digitalWrite(TRIG_PIN, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIG_PIN, LOW);

    // Measure how long ECHO stays HIGH
    long duration = pulseIn(ECHO_PIN, HIGH);

    // Convert time to distance in centimeters
    float distance = duration / 58.0;

    Serial.print("Distance: ");
    Serial.print(distance);
    Serial.println(" cm");

    delay(100);
}