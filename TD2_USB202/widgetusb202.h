#ifndef WIDGETUSB202_H
#define WIDGETUSB202_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class WidgetUSB202; }
QT_END_NAMESPACE

class WidgetUSB202 : public QWidget
{
    Q_OBJECT

public:
    WidgetUSB202(QWidget *parent = nullptr);
    ~WidgetUSB202();

private:
    Ui::WidgetUSB202 *ui;
};
#endif // WIDGETUSB202_H
