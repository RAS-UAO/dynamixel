#include <AX12A.h>
#define DirectionPin  (10u)
#define BaudRate    (1000000ul) // Baud rate for serial comunication the AX-12A
#define ID    (16u) // AX-12A's current ID

int velocity_in_bits = 0; // Angular velocity in bits, goes from 0 to 1023

void setup(){
  ax12a.begin(BaudRate, DirectionPin, &Serial); // Initialize AX-12A
  ax12a.setEndless(ID, ON); // Set velocity control for AX-12A
}

void loop(){
  velocity_in_bits = 100;
  
  ax12a.turn(ID, LEFT, velocity_in_bits);
  delay(1000);
  
  ax12a.turn(ID, RIGHT, velocity_in_bits);
  delay(1000);
}
