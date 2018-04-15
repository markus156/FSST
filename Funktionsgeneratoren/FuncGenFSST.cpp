
#include "FuncGenFSST.h"
//-------------------------------------------------------------------------------------------------
//Rampengenerator
//-------------------------------------------------------------------------------------------------
SignedRampGen::SignedRampGen(){
    val = 0;
    SetPointsPerPeriod(10); // Default ist 10Pts/Periode
}

void SignedRampGen::SetPointsPerPeriod(float aPoints){
    _inc = 2.0/aPoints;
}

void SignedRampGen::SetFrequ(float aFrequ){
    SetPointsPerPeriod(1.0/aFrequ);
}

void SignedRampGen::CalcOneStep(){
    val = val + _inc;
    if( val>1.0 ){
        val = -1 + (val - 1.0); 
    }
}

//-------------------------------------------------------------------------------------------------
//Dreieck Generator
//-------------------------------------------------------------------------------------------------
Triangle::Triangle(){
    val = _phase = 0;
    SetPointsPerPeriod(10);
    _status= 1;
}
void Triangle::SetPointsPerPeriod(float aPoints){
    _inc=2.0/aPoints;
}

void Triangle::SetFrequ(float aFrequ){
    SetPointsPerPeriod(1.0/aFrequ);
}

void Triangle::CalcOneStep(){
    _phase = _phase+_inc;

    if(_phase > 1.0){
            
        _phase = -1+(_phase-1.0);
        
        if(_status == 1){
            _status = 2;
        }
        else if ( _status == 2){
            _status = 1;
        }
    }
    
    if(_status == 1){
        val = _phase;
    }
    else{
        val = -_phase;
    }
}
//-------------------------------------------------------------------------------------------------
//Rechteck Generator
//-------------------------------------------------------------------------------------------------
Rectangle::Rectangle(){
    val = _phase = 0;
    SetPointsPerPeriod(10);
    _thrs= 0;
}
void Rectangle::SetPointsPerPeriod(float aPoints){
    _inc=2.0/aPoints;
}

void Rectangle::SetFrequ(float aFrequ){
    SetPointsPerPeriod(1.0/aFrequ);
}
void Rectangle::SetPulsWidth(float aPercent){
    _thrs = 1.0-aPercent;
}
void Rectangle::CalcOneStep(){
    _phase = _phase+_inc;

    if(_phase > 1.0){
        _phase = -1+(_phase-1.0);
        
    
    }
    
    if(_phase > _thrs){
        val = 1.0;
    }
    else{
        val = -1.0;
    }
}
//-------------------------------------------------------------------------------------------------
//Sinus Generator (mit Datatable, ohne complexe Rechnung)
//-------------------------------------------------------------------------------------------------
Sinus::Sinus(){
    val = 0;
    SetPointsPerPeriod(20);
    
    table[0]= 0;
    table[1]= 0.6;
    table[2]= 0.85;
    table[3]= 0.85;
    table[4]= 0.6;
    table[5]= 0;
    table[6]= -0.6;
    table[7]= -0.85;
    table[8]= -0.85;
    table[9]= -0.6;
}
void Sinus::SetPointsPerPeriod(float aPoints){
    _N= 10;
    _inc= _N/aPoints;
}

void Sinus::SetFrequ(float aFrequ){
    SetPointsPerPeriod(1.0/aFrequ);
}

void Sinus::CalcOneStep(){
    _pos += _inc;
    if(_pos >= _N){
        _pos -= _N;
    }
    
    int i = Floor(_pos);
    double frac = _pos-i;
    
    int ii = i+1;
    if(ii>= _N){
        ii=0;
    }
    
    val = table[i]+((table[ii]-table[i])*frac);
}

int Sinus::Floor(float aFloor){
    return aFloor;
}
//-------------------------------------------------------------------------------------------------
//Cos Generator (mit Datatable, ohne complexe Rechnung)
//-------------------------------------------------------------------------------------------------
Cos::Cos(){
    val = 0;
    SetPointsPerPeriod(10);
    
    table[0]= 1;
    table[1]= 0.6;
    table[2]= 0;
    table[3]= -0.6;
    table[4]= -1;
    table[5]= -1;
    table[6]= -0.6;
    table[7]= 0;
    table[8]= 0.6;
    table[9]= 1;
    
}
void Cos::SetPointsPerPeriod(float aPoints){
    _N= 10;
    _inc= _N/aPoints;
}

void Cos::SetFrequ(float aFrequ){
    SetPointsPerPeriod(1.0/aFrequ);
}

void Cos::CalcOneStep(){
    _pos += _inc;
    if(_pos >= _N){
        _pos -= _N;
    }
    
    int i = Floor(_pos);
    double frac = _pos-i;
    
    int ii = i+1;
    if(ii>= _N){
        ii=0;
    }
    
    val = table[i]+((table[ii]-table[i])*frac);
}
int Cos::Floor(float aFloor){
    return aFloor;
}
