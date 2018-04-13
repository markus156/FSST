
#ifndef FuncGenFSST_h
#define FuncGenFSST_h

// Amplituden fix auf +/-1

class SignedRampGen {
	public:
		float val; // momentaner Ausgangswert
  private:
		float _inc; 
	public:
		SignedRampGen(); // Konstruktor
    
		void SetPointsPerPeriod(int aPoints);
	
	  // bezogen auf Fsample 0..0.5
	  void SetFrequ(float aFrequ);

    // Einen Abtastwert berechnen
	  // wird bei z.B. Fsample=100Hz  100x pro sec afgerufen
		void CalcOneStep();
};


class RectGen {
	public:
		float val; // momentaner Ausgangswert
	private:
		float _inc;
		float _phase;
	float _thrs;
	public:
		RectGen();
    
		void SetPointsPerPeriod(int aPoints);
	
		void SetFrequ(float aFrequ);

    // Dauer des ON-Pulses in Prozent ( 0..1 )
		void SetPulsWidth(float aPercent);

    // Einen Abtastwert berechnen
		void CalcOneStep();
};

#endif



















