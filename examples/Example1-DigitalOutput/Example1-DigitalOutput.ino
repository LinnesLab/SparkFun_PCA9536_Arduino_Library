/*
  Using the PCA9536 -- Digital Output
  By: Jim Lindblom
  SparkFun Electronics
  Date: May 4, 2018
  License: This code is public domain but you buy me a beer if you use this and we meet someday (Beerware license).
  Feel like supporting our work? Buy a board from SparkFun!
  https://www.sparkfun.com/products/TODO
  This example demonstrates how to use pinMode and digitalWrite/write to set output values of the PCA9536
  
  Hardware Connections:
  Attach the Qwiic Shield to your Arduino/Photon/ESP32 or other
  Plug the Qwiic RGB Sensor onto the shield
  Watch each LED turn on one-at-a-time
*/

#include <SparkFun_PCA9536_Arduino_Library.h>

PCA9536 io;

void setup() {
  io.begin();
  for (int i = 0; i < 4; i++)
  {
    io.pinMode(i, OUTPUT);
  }
}

void loop() {
  for (int i = 3; i >= 0; i--)
  {
    io.write((i+1)%4, HIGH); // Turn last pin HIGH
    io.write(i, LOW); // Turn this pin LOW
    delay(1000);
  }
}