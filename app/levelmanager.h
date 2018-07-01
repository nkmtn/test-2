#ifndef LEVELMANAGER_H
#define LEVELMANAGER_H

#include <QObject>
#include <QVector2D>
#include <QVariantList>
#include <QRandomGenerator>

class LevelManager : public QObject
{
    Q_OBJECT
public:
    explicit LevelManager(QObject *parent = 0);
    Q_INVOKABLE QVector2D handleCollisions(QObject *hero, QVariantList arr);
signals:

public slots:
};

#endif // LEVELMANAGER_H
