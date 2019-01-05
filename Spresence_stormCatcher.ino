/*
     This is a Hackster.io project, demonstrating capabilities of Sony Spresence board
     to get sensor data on the light intensity and thunder sound, to detect proximity
     to the storm front

     Last updated on 4th of Jan, 2019
     by Laziz Turakulov
*/

int analogPin = A0;     // Analog pin on Spresence extension board
int lightIntensity = 0; // Light intensity values sent by LDR sensor

void setup() {
  
  pinMode(LED0, OUTPUT);  // Set output mode for on-boards LEDs
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);

  digitalWrite(LED0, HIGH); // Switch on all the LEDs in a sequence
  delay(100);
  digitalWrite(LED1, HIGH);
  delay(100);
  digitalWrite(LED2, HIGH);
  delay(100);
  digitalWrite(LED3, HIGH);
  delay(1000);

  digitalWrite(LED0, LOW);  // Switch off all the LEDs in a sequence
  delay(100);
  digitalWrite(LED1, LOW);
  delay(100);
  digitalWrite(LED2, LOW);
  delay(100);
  digitalWrite(LED3, LOW);
  
  Serial.begin(115200); // Set download speed for the Serial Monitor updates
  Serial.println("Spresence is ready");
}

void loop() {

  lightIntensity = analogRead(analogPin); // Get the light intensity measure from LDR sensor
  Serial.print("Intensity value: ");
  Serial.println(lightIntensity);         // Print the values on the System Monitor screen

  if(lightIntensity < 80) {
    Serial.println("<----------------------->");
    Serial.println("I've sensed a light flash");
    Serial.println("<----------------------->");
  }

  delay(100);

}
