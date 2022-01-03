#ifndef WIDGETUSB202_H
#define WIDGETUSB202_H

#include <QWidget>
#include <QtGlobal>
#include "../includes/uldaq.h"
#include "../includes/UlDaqDeviceManager.h"
#include "../includes/UlException.h"
#include "../includes/DioDevice.h"
#include "../includes/AoDevice.h"
#include "../includes/AiDevice.h"
#include "../includes/CtrDevice.h"
#include "mcculdaq.h"

QT_BEGIN_NAMESPACE
namespace Ui { class WidgetUSB202; }
QT_END_NAMESPACE

class WidgetUSB202 : public QWidget
{
    Q_OBJECT

public:
    WidgetUSB202(QWidget *parent = nullptr,MccUldaq &lacarte);
    ~WidgetUSB202();

private:
    Ui::WidgetUSB202 *ui;
    enum LED{LED1 =4,LED2=5,LED3=6,LED4=7};
    MccUldaq lacarte;
};
#endif // WIDGETUSB202_H
