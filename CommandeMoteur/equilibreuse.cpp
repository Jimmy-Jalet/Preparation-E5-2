#include "equilibreuse.h"
#include "ui_equilibreuse.h"

Equilibreuse::Equilibreuse(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Equilibreuse)
{
    ui->setupUi(this);
    leCapot = new Capot(laCarte,0,this);
    connect(leCapot,&Capot::EtatCapotChange,this,&Equilibreuse::onCapot_EtatCapotChange);
    ui->statusbar->addPermanentWidget(&labelEtatCapot);
    onCapot_EtatCapotChange(leCapot->getEtatCapot());


Equilibreuse::~Equilibreuse()
{
    delete ui;
}

void Equilibreuse::onCapot_EtatCapotChange(bool etat)
{
    QPalette palette;
        labelEtatCapot.setAutoFillBackground(true);
        if(etat)
        {
            palette.setColor(QPalette::WindowText,Qt::black);
            labelEtatCapot.setPalette(palette);
            labelEtatCapot.setText("| Capot Fermé |");
        }
        else
        {
            palette.setColor(QPalette::WindowText,Qt::red);
            labelEtatCapot.setPalette(palette);
            labelEtatCapot.setText("| Capot ouvert |");
        }
}


void Equilibreuse::on_pushButton_Lancer_clicked()
{
    // si le capot est fermé
    if(leCapot)
    ui->pushButton_Lancer->setText("Fixer Consigne");
}

Capot *Equilibreuse::getLeCapot() const
{
    return leCapot;
}


