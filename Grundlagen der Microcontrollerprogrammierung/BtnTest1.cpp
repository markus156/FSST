#include "mbed.h"

//        LSB                                                      MSB
//        2^0   2^1   2^2                                          2^11
BusOut lb(P1_13,P1_12,P1_7,P1_6,P1_4,P1_3,P1_1,P1_0,LED4,LED3,LED2,LED1);
//        D20   D19   D18  D17  D16  D15  D14  D13  D4   D3   D2   D1

// DigitalIn sw4(P1_16);

//        Sw1    Sw2    Sw3    Sw4
//        Bit0   Bit1   Bit2   Bit3
BusIn btn(P0_10, P0_15, P0_23, P1_16);

void BtnBlinker1();
// Sw1 => D18 blinken
// Sw2 => D17 blinken ...usw...usw..
// Sw3 => D16 
// Sw4 => D15

void BtnBlinker2();

void BtnBlinker3();
// wenn Sw1 und Sw2 gedrückt sollen D20 und D19 leuchten

// wenn Sw3 oder Sw4 gedrückt sollen D18 und D17 leuchten

// ansonsten finster


// Ein paar Lauflichter
// zum üben
void LeftRunLight();
void RightRunLight();

// für das Plus
void LeftSnake();

// Einsen nachschieben
a = (a << 1) | 1; // 00011
a = (a << 1) | 1; // 00111


int main(){
  lb = 0; // alle leds aus
    
    while(1){
    LeftRunLight();
  }
}

void LeftRunLight(){
    lb = 1;
    for(int i=1; i<=12; i++){
        lb = lb << 1;
        wait_ms(300);
    }
}

void LeftSnake(){
    lb = 1;
    for(int i=1; i<=12; i++){ // 12x 1en nachschieben
        lb = (lb << 1) | 1;
        wait_ms(300);
    }
  for(int i=1; i<=12; i++){ // 11x 0en nachschieben
        lb = lb << 1;
        wait_ms(300);
    }
}



void BtnBlinker3(){
    if( (btn & 1) && (btn & 2) )
        lb = 3;
    else if( (btn & 4) || (btn & 8) )
        lb = 12;
    else
        lb = 0;
}

void BtnBlinker1(){
    if( btn & 1 ) // Sw1
        lb = 4;     // D18
    if( btn & 2 ) // Sw2
        lb = 8;     // D17
    if( btn & 4 ) // Sw3
        lb = 16;    // D16
    // ......
    wait_ms(300);
    lb = 0;
    wait_ms(300);
}

// Wenn mehrere Btns gedrück sind sollen auch mehrere Leds blinken 
void BtnBlinker2(){
    lb = 0;
    if( btn & 1 ) // Sw1
        lb = lb | 4;  // Bit2 durch dazuverodern setzen
    if( btn & 2 ) // Sw2
        lb = lb | 8;  // Bit3 durch dazuverodern setzen
    if( btn & 4 ) // Sw3
        lb = lb | 16;    // D16
    // ......
    wait_ms(300);
    lb = 0;
    wait_ms(300);
}