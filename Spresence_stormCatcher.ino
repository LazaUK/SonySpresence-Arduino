/*
     This is a Hackster.io project, demonstrating capabilities of Sony Spresence board
     to get sensor data on the light intensity and thunder sound, to detect proximity
     to the storm front

     Last updated on 5th of Jan, 2019
     by Laziz Turakulov
*/

int analogPin = A0;         // Analog pin on Spresence extension board
int lightIntensity = 1022;  // Light intensity values sent by LDR sensor
int lowestValue = 1022;     // The lowest value for light intensity;
int prevValue = 1022;       // Previous light intensity value for the loop run
int threshhold = 100;       // To verify sudden change of the light intensity

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
}

void loop() {
  prevValue = lightIntensity;
  lightIntensity = analogRead(analogPin); // Get the light intensity measure from LDR sensor
  Serial.print("Intensity value: ");      // Print telemetry to the System Monitor
  Serial.print(lightIntensity);           

  if (lowestValue > lightIntensity) {
    lowestValue = lightIntensity;
  }
  Serial.print(" , Lowest value: ");
  Serial.println(lowestValue);

  if (abs(lightIntensity - prevValue) > threshhold && (lightIntensity < 80)) {
    Serial.println("<----------------------------------------------->");
    Serial.println("<-    I've possibly sensed a lightning flash   ->");
    Serial.println("<----------------------------------------------->");
  }

  delayMicroseconds(20);
}
