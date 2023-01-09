#include <ChangeTracker.h>
#include <stdint.h>
#include <unity.h>

void test_changetracker()
{
    ChangeTracker<int> ct;
    TEST_ASSERT_EQUAL(ct.output(), false);
    ct.input(1);
    TEST_ASSERT_EQUAL(ct.output(), false);
    ct.input(1);
    TEST_ASSERT_EQUAL(ct.output(), false);
    ct.input(10);
    TEST_ASSERT_EQUAL(ct.output(false), true);
    ct.input(10);
    TEST_ASSERT_EQUAL(ct.output(), true);
    ct.input(10);
    TEST_ASSERT_EQUAL(ct.output(), false);
    ct.input(1);
    TEST_ASSERT_EQUAL(ct.output(), true);
    ct.input(1);
    TEST_ASSERT_EQUAL(ct.output(), false);
    ct.trigger();
    TEST_ASSERT_EQUAL(ct.output(), true);
    TEST_ASSERT_EQUAL(ct.output(), false);
}

void test_positive_flank()
{
    PositiveFlankTracker<float> ct;
    TEST_ASSERT_EQUAL(ct.output(), false);
    ct.input(1.5);
    TEST_ASSERT_EQUAL(ct.output(), false);
    ct.input(1.5);
    TEST_ASSERT_EQUAL(ct.output(), false);
    ct.input(10.5);
    TEST_ASSERT_EQUAL(ct.output(), true);
    ct.input(10.5);
    TEST_ASSERT_EQUAL(ct.output(), false);
    ct.input(1.5);
    TEST_ASSERT_EQUAL(ct.output(), false);
}

void test_negative_flank()
{
    NegativeFlankTracker<uint32_t> ct;
    TEST_ASSERT_EQUAL(ct.output(), false);
    ct.input(1);
    TEST_ASSERT_EQUAL(ct.output(), false);
    ct.input(1);
    TEST_ASSERT_EQUAL(ct.output(), false);
    ct.input(10);
    TEST_ASSERT_EQUAL(ct.output(), false);
    ct.input(10);
    TEST_ASSERT_EQUAL(ct.output(), false);
    ct.input(1);
    TEST_ASSERT_EQUAL(ct.output(false), true);
    ct.input(1);
    TEST_ASSERT_EQUAL(ct.output(), true);
    ct.input(1);
    TEST_ASSERT_EQUAL(ct.output(), false);
}

int main()
{
    UNITY_BEGIN();
    RUN_TEST(test_changetracker);
    RUN_TEST(test_positive_flank);
    RUN_TEST(test_negative_flank);
    return UNITY_END();
}
