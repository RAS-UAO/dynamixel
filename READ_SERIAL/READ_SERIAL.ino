


#include <AX12A.h>

char option;
int led = 13;
int reg = 0;


#define DirectionPin  (12u)
#define BaudRate    (1000000ul)
#define ID    (254u)
#define switchCom(DirPin,Mode)		(digitalWrite(DirPin,Mode)) 
#define setDPin(DirPin,Mode)   		(pinMode(DirPin,Mode))  

void setup(){
  //Serial.begin(1000000);

  pinMode(led, OUTPUT); 
  setDPin(12u,OUTPUT);
  ax12a.begin(BaudRate,DirectionPin, &Serial);
  ax12a.setEndless(ID, OFF);
  //pinMode(8u, OUTPUT); 
 // setDPin(8u,OUTPUT);
  //digitalWrite(8u, HIGH);
  //setDPin(10,OUTPUT);
  switchCom(12u, TX_MODE); 
  Serial.println("------------------------------------------------------------------------");
  Serial.println("Menu ");
  Serial.println("------------------------------------------------------------------------");
  Serial.println("a -> Brocast 0 ");
  Serial.println("b -> Brocast 512 ");
  Serial.println("c -> Brocast 1023 ");
  Serial.println("d -> Leer posicion  d #ID ");
  Serial.println("e -> Config ID e #IDnew ");
  Serial.println("f -> mover servo  f #ID #POS ");
  Serial.println("g -> velocidad servo g #ID #dir(0-left 1-right) #vel ");  
  Serial.println("------------------------------------------------------------------------");
}

void loop(){

  //si existe datos disponibles los leemos
  if (Serial.available()>0){
    //leemos la opcion enviada
   
    option=Serial.read();
    Serial.println(option);
    if(option=='a') {
      //Mover broadcast a 0
    //  switchCom(12u, TX_MODE); 
      ax12a.setEndless(ID, OFF);
      ax12a.move(ID, 0);
      digitalWrite(led, LOW);
      Serial.println("ON");
      delay(500);
      switchCom(12u, TX_MODE); 
    }
    if(option=='b') {
          //Mover broadcast a 512
    //  switchCom(12u, TX_MODE); 
      ax12a.setEndless(ID, OFF);
      ax12a.move(ID, 512);
      digitalWrite(led, LOW);
      Serial.println("OFF");
      delay(500);
      switchCom(12u, TX_MODE); 
    }
    if(option=='d') {
      //Leer posicion  d #
    
      Serial.println("Ingresa ID a leer: ");
      while(Serial.available()<0){};
      int IDnew= Serial.parseInt();
      Serial.println(IDnew);
      switchCom(12u, RX_MODE); 
      reg = ax12a.readPosition(IDnew);
      Serial.println(reg);
      delay(1000);
      switchCom(12u, TX_MODE); 
    }
    if(option=='c') {
    //Mover broadcast a 1023
    //  switchCom(12u, TX_MODE); 
      ax12a.setEndless(ID, OFF);
      ax12a.move(ID, 1023);
      digitalWrite(led, LOW);
      Serial.println("OFF");
      delay(500);
      switchCom(12u, TX_MODE); 
    }
    if(option=='e') {
      //set ID e #
      Serial.println("Ingresa nueva ID: ");
      while(Serial.available()<0);
      int IDnow = Serial.parseInt();
      Serial.println(IDnow);
      ax12a.ledStatus(ID, ON);
      delay(500);
      ax12a.reset(254u);
      ax12a.ledStatus(ID, OFF); 
      delay(500);
      //
      ax12a.ledStatus(1u, ON);
      delay(500);
      ax12a.setID(1u, unsigned (IDnow)); 
      ax12a.ledStatus(IDnow, OFF); 
      switchCom(12u, TX_MODE); 

    }
      if(option=='f') {
      //mover especifico posicion f #ID #POS
      Serial.println("Ingresa nuevo ID y nueva posicion: ");
      while(Serial.available()<0);
      int IDNew = Serial.parseInt();
      Serial.println(IDNew);
      while(Serial.available()<0);
      int PosNew = Serial.parseInt();
      Serial.println(PosNew);
      ax12a.setEndless(ID, OFF);
      ax12a.move(IDNew, PosNew);
      delay(500);
      switchCom(12u, TX_MODE); 

    }
      if(option=='g') {
      //mover especifico velocidad sin fin g #ID #dir(0-left 1-right) #vel
      
      Serial.println("Ingresa nuevo ID, nueva direccion y velocidad: ");
      while(Serial.available()<0);
      int IDNew = Serial.parseInt();
      Serial.println(IDNew);
      while(Serial.available()<0);
      int DirNew = Serial.parseInt();
      Serial.println(DirNew);
      while(Serial.available()<0);
      int VelNew = Serial.parseInt();
      Serial.println(VelNew);
      ax12a.setEndless(ID, ON);
      ax12a.turn(IDNew, DirNew, VelNew);
      delay(500);
      switchCom(12u, TX_MODE); 

    }
    if(option == 'z'){
  Serial.println("------------------------------------------------------------------------");
  Serial.println("Menu ");
  Serial.println("------------------------------------------------------------------------");
  Serial.println("a -> Brocast 0 ");
  Serial.println("b -> Brocast 512 ");
  Serial.println("c -> Brocast 1023 ");
  Serial.println("d -> Leer posicion  d #ID ");
  Serial.println("e -> Config ID e #IDnew ");
  Serial.println("f -> mover servo  f #ID #POS ");
  Serial.println("g -> velocidad servo g #ID #dir(0-left 1-right) #vel ");  
  Serial.println("------------------------------------------------------------------------");
    }
  }
  option = "";
   
}