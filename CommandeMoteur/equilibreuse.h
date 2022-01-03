#ifndef EQUILIBREUSE_H
#define EQUILIBREUSE_H
#include <QLabel>
#include "capot.h"
#include <QMainWindow>
QT_BEGIN_NAMESPACE
namespace Ui { class Equilibreuse; }
QT_END_NAMESPACE

class Equilibreuse : public QMainWindow
{
    Q_OBJECT

public:
    Equilibreuse(QWidget *parent = nullptr);
    ~Equilibreuse();
    void onCapot_EtatCapotChange(bool etat);

    Capot *getLeCapot() const;

private slots:
    void on_pushButton_Arreter_clicked();

    void on_pushButton_Lancer_clicked();

private:
    Ui::Equilibreuse *ui;
    //Moteur *leMoteur;
    MccUldaq laCarte;
    Capot *leCapot;
    QLabel labelEtatCapot;
};
#endif // EQUILIBREUSE_H
