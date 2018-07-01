#ifndef CALCULATE_PRIMES_H
#define CALCULATE_PRIMES_H

#include <gtest/gtest.h>

//extern "C" {
#include "levelmanager.h"
//}

TEST(level_manager, constructor)
{
    LevelManager *lm = new LevelManager();

    EXPECT_NE(qobject_cast<LevelManager *>(lm), (void *) 0);
}

TEST(level_manager, choose_outside_1)
{
    LevelManager *lm = new LevelManager();

    QObject *hero = new QObject();
    QList<QVariant> vlist = QList<QVariant>() << 3<< 8<< 8<< 8<< 8<< 8<< 13<< 7<< 12<< 8<< 8<< 8<< 8<< 8<< 0<<
                                                 9<< 7<< 7<< 7<< 7<< 7<< 7<< 7<< 7<< 7<< 7<< 7<< 7<< 7<< 9<<
                                                 9<< 7<< 14<< 7<< 12<< 8<< 8<< 10<< 8<< 8<< 13<< 7<< 14<< 7<< 9<<
                                                 9<< 7<< 9<< 7<< 7<< 7<< 7<< 9<< 7<< 7<< 7<< 7<< 9<< 7<< 9<<
                                                 9<< 7<< 2<< 13<< 7<< 14<< 7<< 15<< 7<< 14<< 7<< 12<< 1<< 7<< 9<<
                                                 9<< 7<< 7<< 7<< 7<< 9<< 7<< 7<< 7<< 9<< 7<< 7<< 7<< 7<< 9<<
                                                 15<< 7<< 14<< 7<< 12<< 11<< 13<< 7<< 12<< 11<< 13<< 7<< 14<< 7<< 15<<
                                                 7<< 7<< 9<< 7<< 7<< 7<< 7<< 7<< 7<< 7<< 7<< 7<< 9<< 7<< 7<<
                                                 14<< 7<< 15<< 7<< 12<< 10<< 13<< 7<< 12<< 10<< 13<< 7<< 15<< 7<< 14<<
                                                 9<< 7<< 7<< 7<< 7<< 9<< 7<< 7<< 7<< 9<< 7<< 7<< 7<< 7<< 9<<
                                                 9<< 7<< 3<< 13<< 7<< 15<< 7<< 14<< 7<< 15<< 7<< 12<< 0<< 7<< 9<<
                                                 9<< 7<< 9<< 7<< 7<< 7<< 7<< 9<< 7<< 7<< 7<< 7<< 9<< 7<< 9<<
                                                 9<< 7<< 15<< 7<< 12<< 8<< 8<< 11<< 8<< 8<< 13<< 7<< 15<< 7<< 9<<
                                                 9<< 7<< 7<< 7<< 7<< 7<< 7<< 7<< 7<< 7<< 7<< 7<< 7<< 7<< 9<<
                                                 2<< 8<< 8<< 8<< 8<< 8<< 13<< 7<< 12<< 8<< 8<< 8<< 8<< 8<< 1;

    QVector2D  direction;

    hero->setProperty("x", QVariant(0));
    hero->setProperty("y", QVariant(7 * 48));
    hero->setProperty("direction", QVariant(QVector2D(1, 0)));
    direction = lm->handleCollisions(hero, vlist);

    if (direction.x() == 1 && direction.y() == 0)
        SUCCEED();
    else
        FAIL();
}

TEST(level_manager, choose_outside_2)
{
    LevelManager *lm = new LevelManager();

    QObject *hero = new QObject();
    QList<QVariant> vlist = QList<QVariant>() << 3<< 8<< 8<< 8<< 8<< 8<< 13<< 7<< 12<< 8<< 8<< 8<< 8<< 8<< 0<<
                                                 9<< 7<< 7<< 7<< 7<< 7<< 7<< 7<< 7<< 7<< 7<< 7<< 7<< 7<< 9<<
                                                 9<< 7<< 14<< 7<< 12<< 8<< 8<< 10<< 8<< 8<< 13<< 7<< 14<< 7<< 9<<
                                                 9<< 7<< 9<< 7<< 7<< 7<< 7<< 9<< 7<< 7<< 7<< 7<< 9<< 7<< 9<<
                                                 9<< 7<< 2<< 13<< 7<< 14<< 7<< 15<< 7<< 14<< 7<< 12<< 1<< 7<< 9<<
                                                 9<< 7<< 7<< 7<< 7<< 9<< 7<< 7<< 7<< 9<< 7<< 7<< 7<< 7<< 9<<
                                                 15<< 7<< 14<< 7<< 12<< 11<< 13<< 7<< 12<< 11<< 13<< 7<< 14<< 7<< 15<<
                                                 7<< 7<< 9<< 7<< 7<< 7<< 7<< 7<< 7<< 7<< 7<< 7<< 9<< 7<< 7<<
                                                 14<< 7<< 15<< 7<< 12<< 10<< 13<< 7<< 12<< 10<< 13<< 7<< 15<< 7<< 14<<
                                                 9<< 7<< 7<< 7<< 7<< 9<< 7<< 7<< 7<< 9<< 7<< 7<< 7<< 7<< 9<<
                                                 9<< 7<< 3<< 13<< 7<< 15<< 7<< 14<< 7<< 15<< 7<< 12<< 0<< 7<< 9<<
                                                 9<< 7<< 9<< 7<< 7<< 7<< 7<< 9<< 7<< 7<< 7<< 7<< 9<< 7<< 9<<
                                                 9<< 7<< 15<< 7<< 12<< 8<< 8<< 11<< 8<< 8<< 13<< 7<< 15<< 7<< 9<<
                                                 9<< 7<< 7<< 7<< 7<< 7<< 7<< 7<< 7<< 7<< 7<< 7<< 7<< 7<< 9<<
                                                 2<< 8<< 8<< 8<< 8<< 8<< 13<< 7<< 12<< 8<< 8<< 8<< 8<< 8<< 1;

    QVector2D  direction;

    hero->setProperty("x", QVariant(15 * 48));
    hero->setProperty("y", QVariant(7 * 48));
    hero->setProperty("direction", QVariant(QVector2D(1, 0)));
    direction = lm->handleCollisions(hero, vlist);

    if (direction.x() == 1 && direction.y() == 0)
        SUCCEED();
    else
        FAIL();
}

TEST(level_manager, choose_free_1)
{
    LevelManager *lm = new LevelManager();

    QObject *hero = new QObject();
    QList<QVariant> vlist = QList<QVariant>() << 3<< 8<< 8<< 8<< 8<< 8<< 13<< 7<< 12<< 8<< 8<< 8<< 8<< 8<< 0<<
                                                 9<< 7<< 7<< 7<< 7<< 7<< 7<< 7<< 7<< 7<< 7<< 7<< 7<< 7<< 9<<
                                                 9<< 7<< 14<< 7<< 12<< 8<< 8<< 10<< 8<< 8<< 13<< 7<< 14<< 7<< 9<<
                                                 9<< 7<< 9<< 7<< 7<< 7<< 7<< 9<< 7<< 7<< 7<< 7<< 9<< 7<< 9<<
                                                 9<< 7<< 2<< 13<< 7<< 14<< 7<< 15<< 7<< 14<< 7<< 12<< 1<< 7<< 9<<
                                                 9<< 7<< 7<< 7<< 7<< 9<< 7<< 7<< 7<< 9<< 7<< 7<< 7<< 7<< 9<<
                                                 15<< 7<< 14<< 7<< 12<< 11<< 13<< 7<< 12<< 11<< 13<< 7<< 14<< 7<< 15<<
                                                 7<< 7<< 9<< 7<< 7<< 7<< 7<< 7<< 7<< 7<< 7<< 7<< 9<< 7<< 7<<
                                                 14<< 7<< 15<< 7<< 12<< 10<< 13<< 7<< 12<< 10<< 13<< 7<< 15<< 7<< 14<<
                                                 9<< 7<< 7<< 7<< 7<< 9<< 7<< 7<< 7<< 9<< 7<< 7<< 7<< 7<< 9<<
                                                 9<< 7<< 3<< 13<< 7<< 15<< 7<< 14<< 7<< 15<< 7<< 12<< 0<< 7<< 9<<
                                                 9<< 7<< 9<< 7<< 7<< 7<< 7<< 9<< 7<< 7<< 7<< 7<< 9<< 7<< 9<<
                                                 9<< 7<< 15<< 7<< 12<< 8<< 8<< 11<< 8<< 8<< 13<< 7<< 15<< 7<< 9<<
                                                 9<< 7<< 7<< 7<< 7<< 7<< 7<< 7<< 7<< 7<< 7<< 7<< 7<< 7<< 9<<
                                                 2<< 8<< 8<< 8<< 8<< 8<< 13<< 7<< 12<< 8<< 8<< 8<< 8<< 8<< 1;

    QVector2D  direction;

    hero->setProperty("x", QVariant(48));
    hero->setProperty("y", QVariant(7 * 48));
    hero->setProperty("direction", QVariant(QVector2D(1, 0)));
    direction = lm->handleCollisions(hero, vlist);

    if (direction.x() == 1 && direction.y() == 0)
        FAIL();
    else
        SUCCEED();
}

TEST(level_manager, choose_free_2)
{
    LevelManager *lm = new LevelManager();

    QObject *hero = new QObject();
    QList<QVariant> vlist = QList<QVariant>() << 3<< 8<< 8<< 8<< 8<< 8<< 13<< 7<< 12<< 8<< 8<< 8<< 8<< 8<< 0<<
                                                 9<< 7<< 7<< 7<< 7<< 7<< 7<< 7<< 7<< 7<< 7<< 7<< 7<< 7<< 9<<
                                                 9<< 7<< 14<< 7<< 12<< 8<< 8<< 10<< 8<< 8<< 13<< 7<< 14<< 7<< 9<<
                                                 9<< 7<< 9<< 7<< 7<< 7<< 7<< 9<< 7<< 7<< 7<< 7<< 9<< 7<< 9<<
                                                 9<< 7<< 2<< 13<< 7<< 14<< 7<< 15<< 7<< 14<< 7<< 12<< 1<< 7<< 9<<
                                                 9<< 7<< 7<< 7<< 7<< 9<< 7<< 7<< 7<< 9<< 7<< 7<< 7<< 7<< 9<<
                                                 15<< 7<< 14<< 7<< 12<< 11<< 13<< 7<< 12<< 11<< 13<< 7<< 14<< 7<< 15<<
                                                 7<< 7<< 9<< 7<< 7<< 7<< 7<< 7<< 7<< 7<< 7<< 7<< 9<< 7<< 7<<
                                                 14<< 7<< 15<< 7<< 12<< 10<< 13<< 7<< 12<< 10<< 13<< 7<< 15<< 7<< 14<<
                                                 9<< 7<< 7<< 7<< 7<< 9<< 7<< 7<< 7<< 9<< 7<< 7<< 7<< 7<< 9<<
                                                 9<< 7<< 3<< 13<< 7<< 15<< 7<< 14<< 7<< 15<< 7<< 12<< 0<< 7<< 9<<
                                                 9<< 7<< 9<< 7<< 7<< 7<< 7<< 9<< 7<< 7<< 7<< 7<< 9<< 7<< 9<<
                                                 9<< 7<< 15<< 7<< 12<< 8<< 8<< 11<< 8<< 8<< 13<< 7<< 15<< 7<< 9<<
                                                 9<< 7<< 7<< 7<< 7<< 7<< 7<< 7<< 7<< 7<< 7<< 7<< 7<< 7<< 9<<
                                                 2<< 8<< 8<< 8<< 8<< 8<< 13<< 7<< 12<< 8<< 8<< 8<< 8<< 8<< 1;

    QVector2D  direction;

    hero->setProperty("x", QVariant(8 * 48));
    hero->setProperty("y", QVariant(4 * 48));
    hero->setProperty("direction", QVariant(QVector2D(-1, 0)));
    direction = lm->handleCollisions(hero, vlist);

    if ((direction.x() == -1 && direction.y() == 0)
            || (direction.x() == 0 && direction.y() == -1))
        FAIL();
    else
        SUCCEED();
}

//TEST(calculate_primes_test, range) {
//    int nprimes[1001] = {};
//    ASSERT_EQ(calculate_primes(nprimes, 3), -1);
//    ASSERT_EQ(calculate_primes(nprimes, 0), -1);
//    ASSERT_EQ(calculate_primes(nprimes, -10), -1);
//    ASSERT_EQ(calculate_primes(nprimes, 1001), -1);
//}

//TEST(calculate_primes_test, primes) {
//    int nprimes[1001] = {};
//    ASSERT_EQ(calculate_primes(nprimes, 4), 2);
//    ASSERT_EQ(nprimes[0], 0);
//    ASSERT_EQ(nprimes[1], 0);
//    ASSERT_EQ(nprimes[2], 1);
//    ASSERT_EQ(nprimes[3], 1);
//    ASSERT_EQ(nprimes[4], 0);
//}

//TEST(calculate_primes_test, primes2) {
//    int nprimes[1001] = {};
//    ASSERT_EQ(calculate_primes(nprimes, 8), 4);
//    ASSERT_EQ(nprimes[0], 0);
//    ASSERT_EQ(nprimes[1], 0);
//    ASSERT_EQ(nprimes[2], 1);
//    ASSERT_EQ(nprimes[3], 1);
//    ASSERT_EQ(nprimes[4], 0);
//    ASSERT_EQ(nprimes[5], 1);
//    ASSERT_EQ(nprimes[6], 0);
//    ASSERT_EQ(nprimes[7], 1);
//}

//TEST(calculate_primes_test, primes3) {
//    int nprimes[1001] = {};
//    calculate_primes(nprimes, 1000);
//    ASSERT_EQ(nprimes[613], 1);
//    ASSERT_EQ(nprimes[614], 0);
//    ASSERT_EQ(nprimes[859], 1);
//    ASSERT_EQ(nprimes[861], 0);
//}

#endif
