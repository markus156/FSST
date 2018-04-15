
#ifndef FuncGenFSST_h
#define FuncGenFSST_h

// Amplituden fix auf +/-1
//--------------------------
//Rampengenerator Generator
//--------------------------
class SignedRampGen {
    public:
        float val; // momentaner Ausgangswert
  private:
        float _inc; 
    public:
        SignedRampGen(); // Konstruktor
    
        void SetPointsPerPeriod(float aPoints);
    
        // bezogen auf Fsample 0..0.5
        void SetFrequ(float aFrequ);

        // Einen Abtastwert berechnen
        // wird bei z.B. Fsample=100Hz  100x pro sec afgerufen
        void CalcOneStep();
};
//------------------
//Dreieck Generator
//------------------
    public:
        float val; // momentaner Ausgangswert
  private:
        float _inc; 
        int _status;
        float _phase;
    public:
        Triangle(); // Konstruktor
    
        void SetPointsPerPeriod(float aPoints);
    
        // bezogen auf Fsample 0..0.5
        void SetFrequ(float aFrequ);

        // Einen Abtastwert berechnen
        // wird bei z.B. Fsample=100Hz  100x pro sec afgerufen
        void CalcOneStep();
};
//-------------------
//Rechteck Generator
//-------------------
class Rectangle {
    public:
        float val; // momentaner Ausgangswert
  private:
        float _inc; 
        float _thrs;
        float _phase;
    public:
        Rectangle(); // Konstruktor
    
        void SetPointsPerPeriod(float aPoints);
    
        // bezogen auf Fsample 0..0.5
        void SetFrequ(float aFrequ);
        void SetPulsWidth(float aPercent);
        // Einen Abtastwert berechnen
        // wird bei z.B. Fsample=100Hz  100x pro sec afgerufen
        void CalcOneStep();
};
//---------------
//Sinus Generator
//---------------
class Sinus {
    public:
        float val; // momentaner Ausgangswert
  private:
        float _inc; 
        float table[10];
        float _pos;
        int _N;
    public:
        Sinus(); // Konstruktor
    
        int Floor(float aFloor);
        void SetPointsPerPeriod(float aPoints);
    
        // bezogen auf Fsample 0..0.5
        void SetFrequ(float aFrequ);
        // Einen Abtastwert berechnen
    
        // wird bei z.B. Fsample=100Hz  100x pro sec afgerufen
        void CalcOneStep();
};
//---------------
//Cos Generator
//---------------
class Cos {
    public:
        float val; // momentaner Ausgangswert
  private:
        float _inc; 
        float _pos;
        float table[10];
        int _N;
    public:
        Cos(); // Konstruktor
    
        void SetPointsPerPeriod(float aPoints);
    
        // bezogen auf Fsample 0..0.5
        void SetFrequ(float aFrequ);

        // Einen Abtastwert berechnen
        // wird bei z.B. Fsample=100Hz  100x pro sec afgerufen
        void CalcOneStep();

        int Floor(float aFloor);
};
#endif



















