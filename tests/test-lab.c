#include <lab.h>
#include <unity.h>

void setUp(void) {
    // set stuff up here
}

void tearDown(void) {
    // clean stuff up here
}

void test_leak(void) {
    printf("LEAK TEST\n");
}

void test_segFault(void) {
    printf("SEGFAULT TEST\n");
}


int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_leak);
    RUN_TEST(test_segFault);
    return UNITY_END();
}