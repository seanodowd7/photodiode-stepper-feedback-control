#include <Stepper.h>

const int stepsPerRevolution = 2048;
Stepper motor(stepsPerRevolution, 8, 10, 9, 11);

const int photodiodePin = A0;

const float resistor = 4700.0;
const float referenceVoltage = 5.0;

const float rateThreshold = 1040.0;

float previousCurrent = 0.0;
unsigned long previousTime = 0;

void setup() {
  Serial.begin(9600);

  motor.setSpeed(10);

  int startingReading = analogRead(photodiodePin);

  float startingVoltage =
      startingReading * (referenceVoltage / 1023.0);

  previousCurrent =
      (startingVoltage / resistor) * 1000000.0;

  previousTime = millis();
}

void loop() {

  int adcReading = analogRead(photodiodePin);

  float voltage =
      adcReading * (referenceVoltage / 1023.0);

  float current =
      (voltage / resistor) * 1000000.0;

  unsigned long currentTime = millis();

  float dt =
      (currentTime - previousTime) / 1000.0;

  if (dt > 0) {

    float currentRate =
        (current - previousCurrent) / dt;

    Serial.print("Current: ");
    Serial.print(current, 2);
    Serial.print(" uA   Rate: ");
    Serial.print(currentRate, 2);
    Serial.println(" uA/s");

    if (currentRate > rateThreshold) {
      motor.step(50);
    }

    previousCurrent = current;
    previousTime = currentTime;
  }

  delay(50);
}