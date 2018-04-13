#include "mbed.h"
#include "BtnEventM0S.h" //AUfpassen,d ass es nicht M0s heißt

// DigitalOut eine Variable für ein Bit
// BusOut eine Variable für eine ganze Bitgruppe
//Die Leds, mit denen wir arbeiten werden
BusOut lb(P1_7,P1_6,P1_4,P1_3,P1_1,P1_0,LED4,LED3,LED2,LED1);

//Statusled
BusOut led_status(P1_13,P1_12);

BtnEventM0 sw4(P1_16), sw3(P0_23);
//SW4 = forwars
//SW3 = backwards

Serial pc(USBTX,USBRX);

const int ST_ROT=1;
const int ST_GELB=2;
const int ST_GRUEN=3;

class Ampel{
	public:
		void Init();
		void Rot();
		void Gelb();
		void Gruen();
	
	private:
		void ActionRot();		//Bit 0 mit 10 Herz blinken
		void ActionGelb();	//Bit 1 mit 5 Hz blinken
		void ActionGruen();	//Bit 2 mit 2 Hz blinken
	
	public:
		int state;
	private:
		//ALlt Timer sind von einem einzigen Hardwaretimer abgeleitet, man kann also unendlich viele Tiemrobjekte definieren
		Timer t1;	//Blinken
		Timer t2;	//Mit 10Hz Daten zur Anzeige schicken
		Timer t3;	//Zeit bis zum Umschalten
	
};

Ampel am;
int main(){
		pc.baud(115200);
		sw3.Init();sw4.Init();
		am.Init();
		while(1){
			if(am.state== ST_ROT){
				am.Rot();
			}
			else if(am.state==ST_GELB){
				am.Gelb();
			}
			else if(am.state==ST_GRUEN){
				am.Gruen();
			}
		}
}

void Ampel::Init(){
		state=ST_ROT;
		t1.start();
		t2.start();
		t3.start();
}

void Ampel::Rot(){
		//Einmalige Eintritsaktion
		// Zustand am Display in der ersten Zeile anzeigen
	
		pc.printf("ROT\n");
		t3.reset();
		while(1){
			ActionRot();
			//Zustandswechsel abfragen
			if(t3.read_ms()>3000){
				state=ST_GELB;
				return;
			}
		}
}
void Ampel::ActionRot(){
		//Blinken ist der T1
		if(t1.read_ms()>100){
			t1.reset();
			if(lb==0){
				lb=1;
			}
			else{
				lb=0;
			}
		}
		//ZEit 
		if(t2.read_ms()>100){
			t2.reset();	
			//Das 2 heißt zweite Zeile
			//2 ... Zweite Zeile des LCDs
			pc.printf("2 %d\n",t3.read_ms()/100);	//Durch 100 dividieren,da mit es lesbarer ist und weil wir anch Milisekunden abfragen
		}
}


void Ampel::Gelb(){
		//Einmalige Eintritsaktion
		// Zustand am Display in der ersten Zeile anzeigen
	
		pc.printf("Gelb\n");
		t3.reset();
		while(1){
			ActionGelb();
			//Zustandswechsel abfragen
			if(sw4.CheckFlag()){
				state=ST_ROT;
				return;
			}
			if(t3.read_ms()>4000){
				state=ST_GRUEN;
				return;
			}
		}
}
void Ampel::ActionGelb(){
		//Blinken ist der T1
		if(t1.read_ms()>200){
			t1.reset();
			if(lb==0){
				lb=2;
			}
			else{
				lb=0;
			}
		}
		//Zeit 
		if(t2.read_ms()>100){
			t2.reset();	
			//Das 2 heißt zweite Zeile
			//2 ... Zweite Zeile des LCDs
			pc.printf("2 %d\n",t3.read_ms()/100);	//Durch 100 dividieren,da mit es lesbarer ist und weil wir anch Milisekunden abfragen
		}
}


void Ampel::Gruen(){
		//Einmalige Eintritsaktion
		// Zustand am Display in der ersten Zeile anzeigen
	
		pc.printf("Gruen\n");
		t3.reset();
		while(1){
			ActionGruen();
			//Zustandswechsel abfragen
			if(sw4.CheckFlag()){
				state=ST_ROT;
				return;
			}
			if(t3.read_ms()>5000){
				state=ST_ROT;
				return;
			}
		}
}
void Ampel::ActionGruen(){
		//Blinken ist der T1
		if(t1.read_ms()>500){
			t1.reset();
			if(lb==0){
				lb=4;
			}
			else{
				lb=0;
			}
		}
		//Zeit 
		if(t2.read_ms()>100){
			t2.reset();	
			//Das 2 heißt zweite Zeile
			//2 ... Zweite Zeile des LCDs
			pc.printf("2 %d\n",t3.read_ms()/100);	//Durch 100 dividieren,da mit es lesbarer ist und weil wir anch Milisekunden abfragen
		}
}