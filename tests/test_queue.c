#include <stdlib.h>
#include "unity.h"
#include "queue.h"

void setUp(void){}
void tearDown(void){}

void test_create_queue_and_delete(void)
{
    queue_t* q = create_queue();
    TEST_ASSERT_NOT_NULL(q);
    free(q);
    q = NULL;
    TEST_ASSERT_NULL(q);
}
void test_queue_enqueue(void)
{
    queue_t* q = NULL;
    bool result = enqueue(q,10);
    TEST_ASSERT_FALSE(result);
    q = create_queue();
    TEST_ASSERT_NOT_NULL(q);
    enqueue(q,10);
    TEST_ASSERT_TRUE(peek(q) == 10);
    enqueue(q,20);
    TEST_ASSERT_TRUE(peek(q) == 10);
    free(q);
}
void test_queue_peek(void)
{
    queue_t* q = create_queue();
    TEST_ASSERT_NOT_NULL(q);
    // empty queue
    TEST_ASSERT_TRUE(peek(q) == -1);
    enqueue(q,10);
    TEST_ASSERT_TRUE(peek(q) == 10);
    free(q);
}
int main(void)
{
    UNITY_BEGIN();
    RUN_TEST(test_create_queue_and_delete);
    RUN_TEST(test_queue_enqueue);
    RUN_TEST(test_queue_peek);
    return UNITY_END();
}