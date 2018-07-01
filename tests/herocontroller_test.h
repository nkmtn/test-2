#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

/* using namespace testing; */
//extern "C" {
#include "herocontroller.h"
#include "heromock.h"
//}

TEST(hero_controller, constructor)
{
    HeroController *hc = new HeroController();

    EXPECT_NE(qobject_cast<HeroController *>(hc), (void *) 0);
}

TEST(hero_controller, key_left)
{
    HeroController *hc = new HeroController();

    QObject *hero = new QObject();
    QObject *event = new QObject();

    QVector2D  direction;

    hero->setProperty("direction", QVariant(QVector2D(1, 0)));
    event->setProperty("key", QVariant(Qt::Key_Left));
    direction = hc->handle(hero, event);

    EXPECT_EQ(direction.x(), -1);
    EXPECT_EQ(direction.y(), 0);

    hero->setProperty("direction", QVariant(QVector2D(1, 0)));
    event->setProperty("key", QVariant(Qt::Key_A));
    direction = hc->handle(hero, event);

    EXPECT_EQ(direction.x(), -1);
    EXPECT_EQ(direction.y(), 0);
}

TEST(hero_controller, key_right)
{
    HeroController *hc = new HeroController();

    QObject *hero = new QObject();
    QObject *event = new QObject();

    QVector2D  direction;

    hero->setProperty("direction", QVariant(QVector2D(1, 0)));
    event->setProperty("key", QVariant(Qt::Key_Right));
    direction = hc->handle(hero, event);

    EXPECT_EQ(direction.x(), 1);
    EXPECT_EQ(direction.y(), 0);

    hero->setProperty("direction", QVariant(QVector2D(1, 0)));
    event->setProperty("key", QVariant(Qt::Key_D));
    direction = hc->handle(hero, event);

    EXPECT_EQ(direction.x(), 1);
    EXPECT_EQ(direction.y(), 0);
}

TEST(hero_controller, key_up)
{
    HeroController *hc = new HeroController();

    QObject *hero = new QObject();
    QObject *event = new QObject();

    QVector2D  direction;

    hero->setProperty("direction", QVariant(QVector2D(1, 0)));
    event->setProperty("key", QVariant(Qt::Key_Up));
    direction = hc->handle(hero, event);

    EXPECT_EQ(direction.x(), 0);
    EXPECT_EQ(direction.y(), -1);

    hero->setProperty("direction", QVariant(QVector2D(1, 0)));
    event->setProperty("key", QVariant(Qt::Key_W));
    direction = hc->handle(hero, event);

    EXPECT_EQ(direction.x(), 0);
    EXPECT_EQ(direction.y(), -1);
}

TEST(hero_controller, key_down)
{
    HeroController *hc = new HeroController();

    QObject *hero = new QObject();
    QObject *event = new QObject();

    QVector2D  direction;

    hero->setProperty("direction", QVariant(QVector2D(1, 0)));
    event->setProperty("key", QVariant(Qt::Key_Down));
    direction = hc->handle(hero, event);

    EXPECT_EQ(direction.x(), 0);
    EXPECT_EQ(direction.y(), 1);

    hero->setProperty("direction", QVariant(QVector2D(1, 0)));
    event->setProperty("key", QVariant(Qt::Key_S));
    direction = hc->handle(hero, event);

    EXPECT_EQ(direction.x(), 0);
    EXPECT_EQ(direction.y(), 1);
}

TEST(hero_controller, key_unknown)
{
    HeroController *hc = new HeroController();

    QObject *hero = new QObject();
    QObject *event = new QObject();

    QVector2D  direction;

    hero->setProperty("direction", QVariant(QVector2D(1, 0)));
    event->setProperty("key", QVariant(Qt::Key_Enter));
    direction = hc->handle(hero, event);

    EXPECT_EQ(direction.x(), 1);
    EXPECT_EQ(direction.y(), 0);

    hero->setProperty("direction", QVariant(QVector2D(0, -1)));
    event->setProperty("key", QVariant(Qt::Key_Y));
    direction = hc->handle(hero, event);

    EXPECT_EQ(direction.x(), 0);
    EXPECT_EQ(direction.y(), -1);
}

TEST(hero_controller, key_autorepeat)
{
    HeroController *hc = new HeroController();

    QObject *hero = new QObject();
    QObject *event = new QObject();

    QVector2D  direction;

    hero->setProperty("direction", QVariant(QVector2D(1, 0)));
    event->setProperty("isAutoRepeat", QVariant(true));
    direction = hc->handle(hero, event);

    EXPECT_EQ(direction.x(), 1);
    EXPECT_EQ(direction.y(), 0);

    hero->setProperty("direction", QVariant(QVector2D(0, -1)));
    event->setProperty("isAutoRepeat", QVariant(true));
    direction = hc->handle(hero, event);

    EXPECT_EQ(direction.x(), 0);
    EXPECT_EQ(direction.y(), -1);
}



TEST(hero_controller, exit)
{
    HeroController *hc = new HeroController();

    HeroMock *hero = new HeroMock(NULL);
    QObject *event = new QObject();

    QVector2D  direction;

    hero->setProperty("direction", QVariant(QVector2D(1, 0)));
    event->setProperty("key", QVariant(Qt::Key_Escape));
    direction = hc->handle(hero, event);

    EXPECT_EQ(hero->exited, true);
}
