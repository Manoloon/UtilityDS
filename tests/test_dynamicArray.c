/*
[ ] Simular o razonar sobre un fallo de malloc.
*/
#include "unity.h"
#include "dynamicArray.h"

void setUp(void){}
void tearDown(void){}

void test_init_creates_empty_array(void)
{
    dynarray_t array = {0};
    // Inicializar un vector de estructuras.
    TEST_ASSERT_TRUE(init(&array,sizeof(int))== SUCCESS);
   
    destroy(&array);
    // Destruir un vector correctamente inicializado.
    TEST_ASSERT_NULL(array.items);
    // Destruir un vector dos veces.
    TEST_ASSERT_TRUE(destroy(&array)==SUCCESS);
}
void test_init_element_size_zero(void)
{
     dynarray_t array;
    // Intentar inicializar con element_size = 0.
    TEST_ASSERT_TRUE(init(&array,0) == INVALID_ARGUMENT);
}
void test_call_destroy_null_pointer(void)
{
    // Llamar a destroy con un puntero NULL.
    TEST_ASSERT_FALSE(destroy(NULL) == SUCCESS);
}
void test_init_null_pointer(void)
{
    // Intentar inicializar con un puntero al vector igual a NULL.
    TEST_ASSERT_TRUE(init(NULL,sizeof(int))==INVALID_ARGUMENT);
}
void test_init_two_times_same_array(void)
{
    // Intentar inicializar dos veces el mismo vector.
    dynarray_t array = {0};
    init(&array,sizeof(int));
    TEST_ASSERT_TRUE(init(&array,sizeof(int)) == ALREADY_INIT);
}
int main(void)
{
    UNITY_BEGIN();
    RUN_TEST(test_init_creates_empty_array);
    RUN_TEST(test_init_element_size_zero);
    RUN_TEST(test_call_destroy_null_pointer);
    RUN_TEST(test_init_null_pointer);
    RUN_TEST(test_init_two_times_same_array);
    return UNITY_END();
}