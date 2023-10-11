#include <lab.h>
#include <gtest/gtest.h>

TEST(VersionTest, PositiveNos) {
    char *version = getVersion();
    ASSERT_STREQ("0.1", version);
    free(version);
}

TEST(AddTest, PositiveNos) {
    int actual = add(1, 1);
    int expected = 2;
    ASSERT_EQ(expected, actual);
}
