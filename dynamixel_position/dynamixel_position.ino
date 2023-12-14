#include <AX12A.h>

#define DirectionPin  (10u)
#define BaudRate    (1000000ul) // Baud rate for serial comunication the AX-12A
#define ID    (17u) // AX-12A's current ID

int position_in_degrees = 0; // Angular position in degrees, goes from 0° to 300°
int position_in_bits = 0; // Angular position in bits, goes from 0 to 1023

void setup(){
  ax12a.begin(BaudRate, DirectionPin, &Serial); // Initialize AX-12A
  ax12a.setEndless(ID, OFF); // Set position control for AX-12A
}

void loop(){
  position_in_degrees = 150;
  position_in_bits = map(position_in_degrees, 0, 300, 0, 1023);
  ax12a.move(ID, position_in_bits);
  delay(500);
}   
