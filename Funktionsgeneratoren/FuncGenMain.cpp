#include "mbed.h"
#include "Serial_HL.h"
#include "FuncGenFSST.h"
#include "Tp1Ord.h"

// 2 Generatoren mit switch umschalten

//100 Punkte pro Periode 0,01

//Commando 2 0 Frewuenz
//Commando 3 = Amplitude
//Switchvariable switcht die Generatiren
//Commando 4


SerialBLK pc(USBTX, USBRX);
SvProtocol ua0(&pc);
void CommandHandler();
void ExecSignalChain();

//Funktionsgeneratoren
Triangle fg1;
Rectangle fg2;
SignedRampGen sig1;
Sinus fg3;
Cos cosinus;


//Cos fg4;
float amp1 = 1.0;
float v1; // Ausgangswert mit amp1 multipliziert
//float v2;
Tp1Ord tp;

int swt=2; // 1..v1 auf fg1 geschaltet    2..v1 auf fg2 geschaltet
//Umschaltvariable, mit der wir zwischen den Generatoren umschalten können
//Testbeispiel kann eventuell einSinus etc sein

int main(void){
    pc.format(8,SerialBLK::None,1);
    pc.baud(500000); // Baudrate

    ua0.SvMessage("FuncGenMain3"); // Meldung zum PC senden

    Timer stw;
    stw.start();

     //  while(1)-Loop der mit dem PC kommuniziert
    while(1) {
        CommandHandler();
        if( (stw.read_ms()>10) ) { // 100Hz

            // dieser Teil wird mit 100Hz aufgerufen
            //Timer resetten
            stw.reset();

            // Funktionsgeneratoren rechnen
            ExecSignalChain(); 
            if( ua0.acqON ) {
                ua0.WriteSV(1, v1);
				ua0.WriteSV(2,tp.y);
							
				//ua0.WriteSV(2, v2);
                //ua0.WriteSV(2, tp.y);
            }
        }
    }
    return 1;
}

void ExecSignalChain(){
	
	fg3.CalcOneStep();
	v1= fg3.val*amp1;
	tp.calcOneStep(v1);
}

void CommandHandler(){
    uint8_t cmd;

    if( !pc.IsDataAvail() )
        return;
    cmd = ua0.GetCommand();

    // mithilfe von Kommandos vom PC Frequenz und Amplitude verstellen

    if( cmd==2 ) { // Frequenz
        float frequ = ua0.ReadF();
        cosinus.SetFrequ(frequ);
        ua0.SvMessage("Set Frequ");
    }

    // Amplitute
    if( cmd==3 ) { 
        amp1 = ua0.ReadF();
        ua0.SvMessage("Set Frequ");
    }

    // Funktionsgeneratoren umschalten
    if( cmd==4 ) { 
        swt = ua0.ReadI16();
        ua0.SvMessage("Switch FG");
    }

    // Grenzfrequenz umstellen umschalten
    if( cmd==5 ) { 
        tp.SetAlpha(ua0.ReadI16());
        ua0.SvMessage("Set Alpha");
    }
}