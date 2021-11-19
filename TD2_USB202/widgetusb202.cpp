#include "widgetusb202.h"
#include "ui_widgetusb202.h"

WidgetUSB202::WidgetUSB202(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::WidgetUSB202)
{
    ui->setupUi(this);
}

WidgetUSB202::~WidgetUSB202()
{
    delete ui;
}

