#include "widgetusb202.h"
#include "ui_widgetusb202.h"

WidgetUSB202::WidgetUSB202(QWidget *parent,MccUldaq _lacarte)
    : QWidget(parent)
    , ui(new Ui::WidgetUSB202),MccUldaq(_lacarte)
{
    ui->setupUi(this);
    UlError erreur;
      erreur = laCarte.ulDConfigBit(LED1,DD_OUTPUT);
      if(erreur != ERR_NO_ERROR)
            qDebug() << "Config " << LED1 << " Code Erreur : " << erreur
}

WidgetUSB202::~WidgetUSB202()
{
    delete ui;
}

