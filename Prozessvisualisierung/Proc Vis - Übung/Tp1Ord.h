#ifndef Tp1Ord_h
#define Tp1Ord_h

class Tp1Ord{
    public:
        float y;
    private:
        //performancemäßig brauchen wir ein beta, das ist 1-Alpha
        //Das müssen wir nur einmal berechnen und rufen es dann von der Variale auf
        float _alpha,_beta; //Koeffizienten für die Grenzfrequenz
    public:
    Tp1Ord();

    void SetAlpha(float aAlpha);

    //Einen Abtastwert berechnen
    void calcOneStep(float aX);

};
#endif