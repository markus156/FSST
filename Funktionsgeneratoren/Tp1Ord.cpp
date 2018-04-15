#include "Tp1Ord.h"

Tp1Ord::Tp1Ord(){
//Eine Vernünftige Grenzfrequenz setzen
SetAlpha(0.1);
     
}


void Tp1Ord::SetAlpha(float aAlpha){
    
    _alpha=aAlpha;
    _beta = 1 -_alpha; 
}

void Tp1Ord::calcOneStep(float aX)
{
    //im y steht der alte Y- Wert, das heißt wir brauchen hier keine Zwischenvariable
    y = (_alpha *aX)+(_beta*y);
}