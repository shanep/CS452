#include <lab.h>
#include <gtest/gtest.h>

TEST(VersionTest, PositiveNos)
{
    char *version = getVersion();
    ASSERT_STREQ("0.1", version);
    free(version);
}

TEST(AddTest, PositiveNos)
{
    int actual = add(1, 1);
    int expected = 2;
    ASSERT_EQ(expected, actual);
}

TEST(SegFaultTest, asan)
{
    ASSERT_DEATH(segfault(), ".*");
}

// This tests are disabled because they will fail they are used to make sure
// that the sanitizer is working correctly. You can run them with the
// --gtest_also_run_disabled_tests flag
// ./build/x86_x64-ASan/test-lab --gtest_filter=DISABLED_OutOfBoundsTest.fail --gtest_also_run_disabled_tests
// ./build/x86_x64-ASan/test-lab --gtest_filter=DISABLED_LeakTest.fail --gtest_also_run_disabled_tests

TEST(DISABLED_OutOfBoundsTest, fail)
{
    outOfBounds();
}

TEST(DISABLED_LeakTest, fail)
{
  int *actual = leak(2);
  ASSERT_EQ(2,*actual);
  free(actual);
}
