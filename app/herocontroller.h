#ifndef HEROCONTROLLER_H
#define HEROCONTROLLER_H

#include <QObject>
#include <QKeyEvent>

class HeroController : public QObject
{
    Q_OBJECT
public:
    explicit HeroController(QObject *parent = nullptr);
    Q_INVOKABLE QVector2D handle(QObject *hero, QObject *event);
signals:

public slots:
};

#endif // HEROCONTROLLER_H
