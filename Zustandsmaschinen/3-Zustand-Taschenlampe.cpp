#include "mbed.h"
#include "BtnEventM0S.h"

//Die Leds, mit denen wir arbeiten werden
BusOut lb(P1_7,P1_6,P1_4,P1_3,P1_1,P1_0,LED4,LED3,LED2,LED1);

//Statusled
BusOut led_status(P1_13,P1_12);

BtnEventM0 sw4(P1_16), sw3(P0_23);
//SW4 = forwars
//SW3 = backwards

class Fahrradleuchte{
	public:
		void Init();
		void State1();
		void State2();
		void State3();
	
	private: 
		void State1Action();//Bit0 (LED) mit 10 Hz blinken
		void State2Action();//Bit2 (LED) mit 5 Hz blinken
		void State3Action();//Bit4 (LED) mit 1 Hz blinken
			
	
	public:
		int state;
	
	private:
		Timer t1;
};


Fahrradleuchte fl;

int main(){
	fl.Init();
	sw3.Init();
	sw4.Init();
	while(1)
	{
		if(fl.state==1){
			fl.State1();
		}
		if(fl.state==2){
			fl.State2();
		}
		if(fl.state==3){
			fl.State3();
		}
	}
}

void Fahrradleuchte::Init(){
		state= 1;
		t1.start();
}
void Fahrradleuchte::State1(){
	led_status=1;
	t1.reset();
	while(1){
		State1Action();
		if(sw4.CheckFlag()){	//Vorwärts auf Zustand 2
			state=2;
			return;
		}
		if(sw3.CheckFlag()){ //Rückwärts auf Zustand 3
			state=3;
			return;
		}
	}
}
void Fahrradleuchte::State1Action(){
	if(t1.read_ms()>100){
		t1.reset();
		if(lb==0){
			lb=0x1;
		}
		else{
			lb=0;
		}
	}
}

void Fahrradleuchte::State2(){
	led_status=2;
	t1.reset();
	while(1){
		State2Action();
		if(sw4.CheckFlag()){	//Vorwärts auf Zustand 3
			state=3;
			return;
		}
		if(sw3.CheckFlag()){ //Rückwärts auf Zustand 1
			state=1;
			return;
		}
	}
}
void Fahrradleuchte::State2Action(){
	if(t1.read_ms()>200){
		t1.reset();
		if(lb==0){
			lb=0x2;
		}
		else{
			lb=0;
		}
	}
}


void Fahrradleuchte::State3(){
	led_status=3;
	t1.reset();
	while(1){
		State3Action();
		if(sw4.CheckFlag()){	//Vorwärts auf Zustand 3
			state=1;
			return;
		}
		if(sw3.CheckFlag()){ //Rückwärts auf Zustand 1
			state=2;
			return;
		}
	}
}
void Fahrradleuchte::State3Action(){
	if(t1.read_ms()>500){
		t1.reset();
		if(lb==0){
			lb=0x4;
		}
		else{
			lb=0;
		}
	}
}