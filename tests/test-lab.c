#include <lab.h>
#include <unity.h>

void setUp(void) {
    // set stuff up here
}

void tearDown(void) {
    // clean stuff up here
}

void test_getVersion(void) {
    char *version = getVersion();
    TEST_ASSERT_EQUAL_STRING("0.1", version);
    free(version);
}

void test_add(void) {
    int actual = add(1, 1);
    int expected = 2;
    TEST_ASSERT_EQUAL(expected, actual);
}


int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_getVersion);
    RUN_TEST(test_add);
    return UNITY_END();
}