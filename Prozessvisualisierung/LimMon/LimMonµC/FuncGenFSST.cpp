
#include "FuncGenFSST.h"

SignedRampGen::SignedRampGen()
{
  val = 0;
  SetPointsPerPeriod(100); // Default ist 10Pts/Periode
}

void SignedRampGen::SetPointsPerPeriod(int aPoints)
{
  _inc = 2.0/aPoints;
}

void SignedRampGen::SetFrequ(float aFrequ)
{
  SetPointsPerPeriod(1.0/aFrequ);
}

void SignedRampGen::CalcOneStep()
{
  val = val + _inc;
  if( val>1.0 )
    val = -1 + (val - 1.0); 
}


RectGen::RectGen()
{
  val=0; _phase=0; _thrs=0;
  SetPointsPerPeriod(100); // Default ist 10Pts/Periode
}

void RectGen::SetPointsPerPeriod(int aPoints)
{
  _inc = 2.0/aPoints;
}

void RectGen::SetFrequ(float aFrequ)
{
  SetPointsPerPeriod(1.0/aFrequ);
}

void RectGen::SetPulsWidth(float aPercent)
{
  _thrs = 1.0-aPercent;
}

void RectGen::CalcOneStep()
{
  _phase = _phase + _inc;
  if( _phase>1.0 )
    _phase = -1 + (_phase - 1.0); 
  
  if( _phase>_thrs )
    val = 1.0;
  else
    val = -1.0;
}














