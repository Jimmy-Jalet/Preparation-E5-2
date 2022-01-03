#ifndef CAPOT_H
#define CAPOT_H

#include <QObject>
#include <QTimer>
#include "mcculdaq.h"

class Capot : public QObject
{
    Q_OBJECT
public:
    explicit Capot(MccUldaq &_laCarte,int _numDio,QObject *parent = nullptr);
    void onTimerCapot_timeout();
    bool getEtatCapot() const;

private:
    MccUldaq &laCarte;
    bool etatCapot;
    int numDio;
    QTimer timerCapot;


signals:
    void EtatCapotChange(bool etat);

};

#endif // CAPOT_H
