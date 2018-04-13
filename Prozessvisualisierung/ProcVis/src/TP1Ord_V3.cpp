
#include "TP1Ord_V3.h"

TP1Ord::TP1Ord()
{
  // vernünftige Grenzfrequenz setzen
  SetAlpha(0.1);
}


void TP1Ord::SetAlpha(float aAlpha)
{
  _alpha=aAlpha;
  _beta = 1.0-aAlpha;
}




