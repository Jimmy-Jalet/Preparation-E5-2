#include "capot.h"
#define TEMPO_CAPOT 500

Capot::Capot(MccUldaq &_laCarte, int _numDio, QObject *parent):QObject(parent),laCarte(_laCarte),numDio(_numDio)
{
    laCarte.ulDConfigBit(numDio,DD_INPUT);
    laCarte.ulDBitIn(numDio,etatCapot);

    connect(&timerCapot,&QTimer::timeout,this,&Capot::onTimerCapot_timeout);
    timerCapot.start(TEMPO_CAPOT);
}

void Capot::onTimerCapot_timeout()
{
    bool etatCourant;
    laCarte.ulDBitIn(numDio,etatCourant);
    if(etatCapot!=etatCourant)
    {
        emit EtatCapotChange(etatCourant);
        etatCapot=etatCourant;
    }
}

bool Capot::getEtatCapot() const
{
    return etatCapot;
}
