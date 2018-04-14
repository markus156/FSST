
#include "mbed.h"

// DigitalOut eine Variable für ein Bit
// BusOut eine Variable für eine ganze Bitgruppe

// Alle 12-Leds des M0-Boards zu einer Bitgruppe zusammenfassen

Serial pc(USBTX,USBRX);

int main(){
	int val =0;
	pc.baud(115200);
	
	while(1){
		pc.printf("Hello World\n");
		wait_ms(1000);
	}
}

