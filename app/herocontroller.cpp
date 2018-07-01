#include "herocontroller.h"

HeroController::HeroController(QObject *parent) : QObject(parent)
{

}


QVector2D HeroController::handle(QObject *hero, QObject *event)
{
    if (event->property("isAutoRepeat").toBool()) {
        QVariant variant = hero->property("direction");
        return qvariant_cast<QVector2D>(variant);
    }

    int key = event->property("key").toInt();

    switch (key) {
    case Qt::Key_Left:
    case Qt::Key_A:
        return QVector2D(-1, 0);
        break;
    case Qt::Key_Right:
    case Qt::Key_D:
        return QVector2D(1, 0);
        break;
    case Qt::Key_Up:
    case Qt::Key_W:
        return QVector2D(0, -1);
        break;
    case Qt::Key_Down:
    case Qt::Key_S:
        return QVector2D(0, 1);
        break;
    case Qt::Key_Escape:
        QMetaObject::invokeMethod(hero, "exit");
    }

    QVariant variant = hero->property("direction");
    return qvariant_cast<QVector2D>(variant);
}
