
#ifndef TP1Ord_V2_h
#define TP1Ord_V2_h


class TP1Ord {
  public:
		float y; // Ausgangswert des Filters
	private:
		float _alpha, _beta; // Koeffizienten für die Grenzfrequenz
  public:
    TP1Ord();

    void SetAlpha(float aAlpha);

    void CalcOneStep();
};

#endif


