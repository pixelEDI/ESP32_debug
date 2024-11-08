
/*
        _          _ ______ _____ _____
       (_)        | |  ____|  __ \_   _|
  _ __  ___  _____| | |__  | |  | || |
 | '_ \| \ \/ / _ \ |  __| | |  | || |
 | |_) | |>  <  __/ | |____| |__| || |_
 | .__/|_/_/\_\___|_|______|_____/_____|
 | |
 |_|

https://links.pixeledi.eu
Arduino Uno Debugging | V1.0 | 07.2024

*/

#include <Arduino.h>

const byte led1 = 26;

byte ledstate = LOW;
byte cnt = 0;

void toggleLED() {
  digitalWrite(led1, ledstate);
  delay(300);
}

void setup() {
  Serial.begin(11200);
  pinMode(led1, OUTPUT);
}

void loop() {

  cnt++;
  if (cnt % 2 == 0)
    ledstate = HIGH;
  else
    ledstate = LOW;

  toggleLED();
}
