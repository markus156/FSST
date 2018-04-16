
// Der Bitschiebe-Befehl in C/C++

int  a;

a = B#0001;  // in a steht Bin�r 0001

a = a << 1;  // in a steht jetzt B#0010
a = a << 1;  // in a steht jetzt B#0100

a = a >> 2;  // in a steht jetzt B#0001
a = a >> 1;  // in a steht jetzt B#0000

// Bitwise OR
B#1001 | B#0010 = B#1011


// Bits in einem Byte mit Bitwise-And abfragen

B#1010 & B#0101 = B#0000

B#1010 & B#1000 = B#1000

// !!gezieltes!! abfragen ob ein Bit in einem Byte gesetzt ist

  2^3    2^2  2^1  2^0
B#  0    0    0    0;

int btn;

if( btn & 1 )  B#xxxx & B#0001
  printf("Bit0 ist gesetzt");

if( btn & 2 ) B#xxxx & B#0010
  printf("Bit1 ist gesetzt");

if( btn & 4 )
  printf("Bit2 ist gesetzt");

if( btn & 8 )
  printf("Bit3 ist gesetzt");


// Mit dem Bitwise-OR Bits in einem Byte setzen 
// ohne die schon gesetzen Bits zu zerst�ren

int leds;

leds = B#0001; // Bit0 ist gesetzt

leds = B#0010; // Bit1 ist gesetzt aber Bit0 ist leider wieder gel�scht

// Die L�sung ist, da� man Bits dazuverodert
leds = leds | B#0010; // leds ist jetzt B#0011;



// Bits nach links schieben und 1en nachschieben
a = 00001;
a = a << 1;  // 00010

// ich h�tte aber gerne das 1en nachgeschoben werden
// wie k�nnte man das machen ?
// Nach links schieben und 1 dazuverodern
a = (a << 1) | 00001; // 00011
a = (a << 1) | 00001; // 00111

a = (a << 1) | 1; // 01111

a = a << 1; // 0010
a = a | 1;  // 0011


~ bitwise not  ~0 = 1
               ~1 = 0


// �bungsbeispiele:
B#001011 & B#000101 = B#000001

B#001011 | ~(B#000101) = 111011
               111010

B#000110 << 2 = B#011000

(B#000110 << 3) | B#000011 = B#110011

2 << 2 = 8

// Logisches und und nicht bitwise und
B#0101 && B#1010 = true
B#0101 && B#0000 = false
B#0101 || B#0000 = true

//        Sw1    Sw2    Sw3    Sw4
//        Bit0   Bit1   Bit2   Bit3
BusIn btn(P0_10, P0_15, P0_23, P1_16);

//          Bit0           Bit3
BusOut leds(LED1,LED2,LED3,LED4);

// wenn sw2 gedr�ckt ist sollen LED1 u.LED3 leuchten
if( btn & 2 ) // B#0010
    leds = 5; // B#0101

// wenn sw1 und sw2 gedr�ckt sind sollen LED3 u. LED4 leuchten
if( (btn & 1) && (btn & 2) )
    leds = 12; // B#1100

// wenn sw3 oder sw4 gedr�ckt sind sollen LED1 u. LED2 leuchten
if( (btn & 4) || (btn & 8) )
    leds = 3; // B#0011

// Schreiben Sie f�r einen 12-Bit LED-Bar ein 4er Lauflicht nach links
int i;
leds = 0;
for(i=1; i<=4; i++) { // 4x 1en nachschieben
    leds = (leds << 1) | 1;
    wait_ms(200);
}
for(i=1; i<=12; i++) { // 12x 0en nachschieben
    leds = leds << 1;
    wait_ms(200);
}


