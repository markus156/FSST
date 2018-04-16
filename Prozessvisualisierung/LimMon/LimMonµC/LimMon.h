#ifndef LimMon_h
#define LimMon_h


class LimitMonitor {
    static const int S_NORMAL = 0;
    static const int S_UPPER  = 1;
    static const int S_LOWER  = -1;
  public:
    float upper, lower;
    int state;
    float y;
  public:
    LimitMonitor()
			{ lower=-0.5; upper=0.5; state=S_NORMAL; y=0; }
    
    void CalcOneStep(float aVal);

    void SwitchToNormal();
    void SwitchToUpper();
    void SwitchToLower();
};

void LimitMonitor::SwitchToNormal()
{
  state=S_NORMAL; y=0;
  if( ua0.acqON ) {
    ua0.SvMessage("Normal!!");
    // bei Verwendung von LimMonDlg aktivieren
    // bei Verwendung von SvVis3 auskommentieren
    // ua0.WriteSvI32(250, 0); 
  }
}
void LimitMonitor::SwitchToUpper(){
	state=S_UPPER; y=1;
  if( ua0.acqON ) {
    ua0.SvMessage("Upper!!");
    // bei Verwendung von LimMonDlg aktivieren
    // bei Verwendung von SvVis3 auskommentieren
    // ua0.WriteSvI32(250, 0); 
  }
}

void LimitMonitor::SwitchToLower(){
	state=S_LOWER; y=-1;
  if( ua0.acqON ) {
    ua0.SvMessage("Lower!!");
    // bei Verwendung von LimMonDlg aktivieren
    // bei Verwendung von SvVis3 auskommentieren
    // ua0.WriteSvI32(250, 0); 
  }
}
void LimitMonitor::CalcOneStep(float aVal){
	
	//Untere Grenze unterschritten
	if(state==S_NORMAL && aVal < lower){
		SwitchToLower();
	}
	//Obere Grenze überschreiten
	if(state==S_NORMAL && aVal > upper){
		SwitchToUpper();
	}
	//Untere Grenze überschreiten
	if(state==S_LOWER && aVal > lower){
		SwitchToNormal();
	}
	//Obere Grenze unterschreiten
	if(state==S_UPPER && aVal < upper){
		SwitchToNormal();
	}
}
#endif
