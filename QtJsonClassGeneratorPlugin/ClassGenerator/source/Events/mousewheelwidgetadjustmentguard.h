#ifndef MOUSEWHEELWIDGETADJUSTMENTGUARD_H
#define MOUSEWHEELWIDGETADJUSTMENTGUARD_H

#include <QObject>

class MouseWheelWidgetAdjustmentGuard : public QObject
{
    Q_OBJECT
public:
    explicit MouseWheelWidgetAdjustmentGuard(QObject *parent);

protected:
    bool eventFilter(QObject* o, QEvent* e) override;

signals:

public slots:
};

#endif // MOUSEWHEELWIDGETADJUSTMENTGUARD_H
