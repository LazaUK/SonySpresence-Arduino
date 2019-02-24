/*
     This is a Hackster.io project, demonstrating capabilities of Sony Spresence board
     to get sensor data on the light intensity and thunder sound, to detect proximity
     to the storm front

     Last updated on 23rd of Feb, 2019
     by Laziz Turakulov
*/

// Imported audio frequency metere analyser module of Arturo Guadalupi
// and used it to detect sound at 100 Hz frequency
// ttp://arduino.cc/en/Tutorial/SimpleAudioFrequencyMeter
#include <AudioFrequencyMeter.h>
AudioFrequencyMeter meter;

unsigned int lightIntensity = 1000;    // Light intensity values sent by LDR sensor
float soundIntensity = 1000;           // Sound intensity values sent by MIC sensor
int safeDistance = 5000;               // 5 seconds count to detect if in a danger zone
int lowestValue = 1000;                // The lowest value for light intensity;
int prevValue = 1000;                  // Previous light intensity value for the loop run
int threshhold = 100;                  // To verify sudden change of the light intensity

void setup() {
  /*
      <<- Old style of LED config and blinking ->>
      pinMode(LED0, OUTPUT);
      digitalWrite(LED0, HIGH);
      digitalWrite(LED0, LOW);
  */

  ledOn(PIN_LED0);         // Switch on all the LEDs in a sequence
  delay(100);
  ledOn(PIN_LED1);
  delay(100);
  ledOn(PIN_LED2);
  delay(100);
  ledOn(PIN_LED3);
  delay(1000);

  ledOff(PIN_LED0);         // Switch off all the LEDs in a sequence
  delay(100);
  ledOff(PIN_LED1);
  delay(100);
  ledOff(PIN_LED2);
  delay(100);
  ledOff(PIN_LED3);
  delay(1000);

  Serial.begin(115200); // Set download speed for the Serial Monitor updates
  Serial.println("Spresence is ready");

  meter.setBandwidth(50.00, 200.00);    // Ignore frequency out of this range
  meter.begin(A2, 1000);                // Intialize A2 at sample rate of 1kHz
}

void loop() {
  prevValue = lightIntensity;
  lightIntensity = analogRead(A0);        // Get the light intensity measure from LDR sensor
  Serial.print("Intensity value: ");      // Print telemetry to the System Monitor
  Serial.print(lightIntensity);
  Serial.print("Previous value: ");
  Serial.print(prevValue);

  if (lowestValue > lightIntensity) {
    lowestValue = lightIntensity;
  }
  Serial.print(" , Lowest value: ");
  Serial.println(lowestValue);

  if (abs(lightIntensity - prevValue) > threshhold) {
    Serial.println("<----------------------------------------------->");
    Serial.println("<-    I've possibly sensed a lightning flash   ->");
    Serial.println("<----------------------------------------------->");

    // Start 5 seconds countdown
    unsigned long countDown = millis();
    while (millis() - countDown < safeDistance)
    {
      soundIntensity = meter.getFrequency();
      // Check if it's close to 100 Hz frequency
      if (frequency > 90 && frequency < 110)
      {
        // turn the LEDs on - DANGER ZONE !!
        ledOn(PIN_LED0);
        ledOn(PIN_LED1);
        ledOn(PIN_LED2);
        ledOn(PIN_LED3);
      } else {
        // turn the LEDs off
        ledOff(PIN_LED0);
        ledOff(PIN_LED1);
        ledOff(PIN_LED2);
        ledOff(PIN_LED3);
      }
    }
  }

  delayMicroseconds(20);
}
