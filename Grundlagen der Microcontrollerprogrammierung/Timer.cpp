#include "mbed.h"
#include "timer.h"

BusOut lb1(P1_13,P1_12,P1_7,P1_6);
BusOut lb2(P1_4,P1_3,P1_1,P1_0);
BusOut lb3(LED4,LED3,LED2,LED1);

void Led1_Blinker_Task();	//10 Hz
void Led2_Blinker_Task();	//5 Hz
void Led3_Blinker_Task();	//2 Hz

Timer t1,t2,t3;
int main(){
	
	lb1=lb2=lb3=0;
	
	t1.start();
	t2.start();
	t3.start();
	
	while(1){
		if(t1.read_ms()>100){
			t1.reset();
		Led1_Blinker_Task();
		}
		
		if(t2.read_ms()>200){
		t2.reset();
		Led2_Blinker_Task();
		}
		
		if(t3.read_ms()>500){
			t3.reset();
		Led3_Blinker_Task();
		}
			
	}
	
	return true;
}

void Led1_Blinker_Task(){
	if(lb1==0){lb1=0xF;}
	else{lb1=0;}
}

void Led2_Blinker_Task(){
	if(lb2==0){lb2=0xF;}
	else{lb2=0;}
}

void Led3_Blinker_Task(){
	if(lb3==0){lb3=0xF;}
	else{lb3=0;}
}





