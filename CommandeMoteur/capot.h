#ifndef CAPOT_H
#define CAPOT_H

#include <QObject>

class Capot : public QObject
{
    Q_OBJECT
public:
    explicit Capot(MccUldaq & laCarte,QObject *parent = nullptr);
private:
    bool etatCapot;
    int numDio;

signals:
    void EtatCapotChange(bool etat);

};

#endif // CAPOT_H
