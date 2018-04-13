
#include "mbed.h"

// Lauflicht welches sich bei jedem Btn-Click um einen Schritt weiter bewegt
// Lösung2: Interrupts

// Alle 12-Leds des M0-Boards zu einer Bitgruppe zusammenfassen
//        LSB                                                      MSB
//        2^0   2^1   2^2                                          2^11
BusOut lb(P1_13,P1_12,P1_7,P1_6,P1_4,P1_3,P1_1,P1_0,LED4,LED3,LED2,LED1);
//        D20   D19   D18  D17  D16  D15  D14  D13  D4   D3   D2   D1


InterruptIn sw4(P1_16);	//InterruptIn = DigitalIn + Interruptfähigkeit

void OneRunLightStep();
void Sw4ISR();


int main(){
  lb = 1;
	sw4.rise(Sw4ISR); 	//Wir reagieren auf die steigende Flanke
  while(1){
	}
	
	return 0;
}

//Wird aufgerufen, wenn der Microcontroller eine steiogende Flanke auf SW4 erkannt hat.
//Diese Fähigkeit müssen wir allerdings zuerst im Programm definieren
void Sw4ISR(){
	if(sw4.read()){	//Das machen wir, da die Taster prellen. Das ist unsere Lösung, 
									//da die Peeks nur ganz Kurz sind, und der µC auch ein wenig Zeit braucht, um in die ISRzu gehen
		OneRunLightStep();
	}
}

void OneRunLightStep(){
  // if( lb==2048 )
  if( lb==0 ) // wenn finster LED1 wieder setzen
    lb = 1;
  else
    lb = lb << 1; // ansonsten schieben
}










