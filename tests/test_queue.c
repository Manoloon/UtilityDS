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
    int test = 10;
    bool result = enqueue(q,&test);
    TEST_ASSERT_FALSE(result);
    q = create_queue();
    TEST_ASSERT_NOT_NULL(q);
    enqueue(q,&test);
    TEST_ASSERT_TRUE(peek(q) == &test);
    int test2 = 20;
    enqueue(q,&test2);
    TEST_ASSERT_TRUE(peek(q) == &test);
    free(q);
}
void test_queue_peek(void)
{
    queue_t* q = create_queue();
    TEST_ASSERT_NOT_NULL(q);
    // empty queue
    TEST_ASSERT_TRUE(peek(q) == NULL);
    const float test = 3.3f;
    bool result = enqueue(q,&test);
    TEST_ASSERT_TRUE(result);
    TEST_ASSERT_TRUE(peek(q) == &test);
    free(q);
}
void test_queue_dequeue(void)
{
    queue_t* q =NULL;
    // NULL Queue
    TEST_ASSERT_TRUE(dequeue(q) ==NULL);
    q = create_queue();
    TEST_ASSERT_NOT_NULL(q);
    // Queue empty
    TEST_ASSERT_TRUE(dequeue(q) == NULL);
    enqueue(q,"AB");
    // dequeue item
    TEST_ASSERT_TRUE(dequeue(q) == "AB");
    TEST_ASSERT_TRUE(queue_is_empty(q));
    free(q);
}
int main(void)
{
    UNITY_BEGIN();
    RUN_TEST(test_create_queue_and_delete);
    RUN_TEST(test_queue_enqueue);
    RUN_TEST(test_queue_peek);
    RUN_TEST(test_queue_dequeue);
    return UNITY_END();
}