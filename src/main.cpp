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