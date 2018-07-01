#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

/* using namespace testing; */
extern "C" {
#include "utils.h"
}

TEST(expand, test4)
{
    int x1, y1;
    int nprimes[] = {0, 0, 1, 1, 0};
    EXPECT_EQ(expand(4, &x1, &y1, nprimes), 1);
    EXPECT_EQ(x1, 2);
    EXPECT_EQ(y1, 2);
}

TEST(expand, test6)
{
    int x1, y1;
    int nprimes[] = {0, 0, 1, 1, 0, 1, 0};
    EXPECT_EQ(expand(6, &x1, &y1, nprimes), 1);
    EXPECT_EQ(x1, 3);
    EXPECT_EQ(y1, 3);
}

TEST(expand, test8)
{
    int x1, y1;
    int nprimes[] = {0, 0, 1, 1, 0, 1, 0, 1, 0};
    EXPECT_EQ(expand(8, &x1, &y1, nprimes), 1);
    EXPECT_EQ(x1, 3);
    EXPECT_EQ(y1, 5);
}

TEST(expand, test10)
{
    int x1, y1;
    int nprimes[] = {0, 0, 1, 1, 0, 1, 0, 1, 0, 0, 0};
    EXPECT_EQ(expand(10, &x1, &y1, nprimes), 2);
    EXPECT_EQ(x1, 3);
    EXPECT_EQ(y1, 7);
}

