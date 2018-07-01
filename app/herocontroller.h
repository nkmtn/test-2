#ifndef HEROCONTROLLER_H
#define HEROCONTROLLER_H

#include <QObject>
#include <QKeyEvent>
#include <QVector2D>
#include <Qt>

class HeroController : public QObject
{
    Q_OBJECT
public:
    explicit HeroController(QObject *parent = 0);
    Q_INVOKABLE QVector2D handle(QObject *hero, QObject *event);
signals:

public slots:
};

#endif // HEROCONTROLLER_H
