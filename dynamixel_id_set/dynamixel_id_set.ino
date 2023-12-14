#include <AX12A.h>
#define DirectionPin     (10u)  
#define BaudRate      (1000000ul) // Baud rate for serial comunication the AX-12A
#define ID        (1u) // AX-12A's current ID

void setup(){¿
  ax12a.begin(BaudRate, DirectionPin, &Serial); // Initialize AX-12A
  delay(500);
  ax12a.setID(ID, 17); // ID = AX-12A's current ID; 17 = AX-12A's new ID
}

void loop(){
}
