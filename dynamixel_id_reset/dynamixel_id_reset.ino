#include <AX12A.h>
#define DirectionPin     (10u)
#define BaudRate      (1000000ul) // Baud rate for serial comunication the AX-12A
#define ID        (17u)  // AX-12A's current ID

void setup(){
  ax12a.begin(BaudRate, DirectionPin, &Serial);  // Initialize AX-12A
  delay(500);
  // Set AX-12A in default setup
  ax12a.reset(ID); // AX12-A's ID is 1 again
}

void loop(){
}
