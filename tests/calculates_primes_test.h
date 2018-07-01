#ifndef CALCULATE_PRIMES_H
#define CALCULATE_PRIMES_H

#include <gtest/gtest.h>

extern "C" {
#include "utils.h"
}

TEST(calculate_primes_test, range) {
    int nprimes[1001] = {};
    ASSERT_EQ(calculate_primes(nprimes, 3), -1);
    ASSERT_EQ(calculate_primes(nprimes, 0), -1);
    ASSERT_EQ(calculate_primes(nprimes, -10), -1);
    ASSERT_EQ(calculate_primes(nprimes, 1001), -1);
}

TEST(calculate_primes_test, primes) {
    int nprimes[1001] = {};
    ASSERT_EQ(calculate_primes(nprimes, 4), 2);
    ASSERT_EQ(nprimes[0], 0);
    ASSERT_EQ(nprimes[1], 0);
    ASSERT_EQ(nprimes[2], 1);
    ASSERT_EQ(nprimes[3], 1);
    ASSERT_EQ(nprimes[4], 0);
}

TEST(calculate_primes_test, primes2) {
    int nprimes[1001] = {};
    ASSERT_EQ(calculate_primes(nprimes, 8), 4);
    ASSERT_EQ(nprimes[0], 0);
    ASSERT_EQ(nprimes[1], 0);
    ASSERT_EQ(nprimes[2], 1);
    ASSERT_EQ(nprimes[3], 1);
    ASSERT_EQ(nprimes[4], 0);
    ASSERT_EQ(nprimes[5], 1);
    ASSERT_EQ(nprimes[6], 0);
    ASSERT_EQ(nprimes[7], 1);
}

TEST(calculate_primes_test, primes3) {
    int nprimes[1001] = {};
    calculate_primes(nprimes, 1000);
    ASSERT_EQ(nprimes[613], 1);
    ASSERT_EQ(nprimes[614], 0);
    ASSERT_EQ(nprimes[859], 1);
    ASSERT_EQ(nprimes[861], 0);
}

#endif
