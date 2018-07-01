#ifndef HEROMOCK_H
#define HEROMOCK_H

#include <QObject>

class HeroMock: public QObject
{
    Q_OBJECT
public:
    bool exited;

    HeroMock(QObject *parent) : QObject(parent) {
        exited = false;
    }

    Q_INVOKABLE void exit() {
        exited = true;
    }
};

#endif // HEROMOCK_H
