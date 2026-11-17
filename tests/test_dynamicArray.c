/*
[ ] Simular o razonar sobre un fallo de malloc.
*/
#include <stdlib.h>
#include "unity.h"
#include "dynamicArray.h"

void setUp(void){}
void tearDown(void){}

void test_init_creates_empty_array(void)
{
    dynarray_t array = {0};
    // Inicializar un vector de estructuras.
    TEST_ASSERT_TRUE(dynArray_init(&array,sizeof(int))== SUCCESS);
   
    dynArray_free(&array);
    // Destruir un vector correctamente inicializado.
    TEST_ASSERT_NULL(array.items);
    // Destruir un vector dos veces.
    TEST_ASSERT_TRUE(dynArray_free(&array)==SUCCESS);
}
void test_init_element_size_zero(void)
{
    dynarray_t array={0};
    // Intentar inicializar con element_size = 0.
    TEST_ASSERT_TRUE(dynArray_init(&array,0) == INVALID_ARGUMENT);
}
void test_call_destroy_null_pointer(void)
{
    // Llamar a destroy con un puntero NULL.
    TEST_ASSERT_FALSE(dynArray_free(NULL) == SUCCESS);
}
void test_init_null_pointer(void)
{
    // Intentar inicializar con un puntero al vector igual a NULL.
    TEST_ASSERT_TRUE(dynArray_init(NULL,sizeof(int))==INVALID_ARGUMENT);
}
void test_init_two_times_same_array(void)
{
    // Intentar inicializar dos veces el mismo vector.
    dynarray_t array = {0};
    dynArray_init(&array,sizeof(int));
    TEST_ASSERT_TRUE(dynArray_init(&array,sizeof(int)) == ALREADY_INIT);
    TEST_ASSERT_TRUE(dynArray_free(&array) == SUCCESS);
}
// pushback
void test_insert_item_empty_array(void)
{
    dynarray_t array={0};
    int item = 1;
    TEST_ASSERT_TRUE(dynArray_push_back(&array,&item) == INVALID_ARGUMENT);
    //Insertar un entero en un vector vacío.
    TEST_ASSERT_TRUE(dynArray_init(&array,sizeof(int))==SUCCESS);
    TEST_ASSERT_NOT_NULL(array.items);
    TEST_ASSERT_TRUE(dynArray_free(&array) == SUCCESS);
}
void test_insert_item_capacity(void)
{
    dynarray_t* array = calloc(1,sizeof(*array));
    TEST_ASSERT_NOT_NULL(array);
    TEST_ASSERT_TRUE(dynArray_init(array,sizeof(int))==SUCCESS);
    // Insertar cuatro enteros sin ampliar capacidad.
    for(int i = 0;i < 4;i++)
    {
        TEST_ASSERT_TRUE(dynArray_push_back(array,&i) == SUCCESS);
    }
    TEST_ASSERT_TRUE(array->capacity == 4);
    TEST_ASSERT_TRUE(dynArray_get_length(array) == 4);
    // Insertar un quinto entero y comprobar que capacity pasa a 8.
    int itemnew = 5;
    TEST_ASSERT_TRUE(dynArray_push_back(array,&itemnew) == SUCCESS);
    TEST_ASSERT_TRUE(array->capacity == 8);
    TEST_ASSERT_TRUE(dynArray_get_length(array) == 5);
    int* value = (int*) dynArray_get_item(array,4);
    TEST_ASSERT_TRUE(*value == itemnew);
    TEST_ASSERT_TRUE(dynArray_free(array) == SUCCESS);
    free(array);
}
void test_insert_float_type_array(void)
{
    dynarray_t array = {0};
    TEST_ASSERT_TRUE(dynArray_init(&array,sizeof(float))==SUCCESS);
    float item = 0.4;
    TEST_ASSERT_TRUE(dynArray_push_back(&array,&item) == SUCCESS);
    TEST_ASSERT_TRUE(dynArray_free(&array) == SUCCESS);
}
void test_insert_custom_structs_array(void)
{
    typedef struct
    {
        float x;
        float y;
        float z;
    }vector_t;

    dynarray_t array = {0};
    TEST_ASSERT_TRUE(dynArray_init(&array,sizeof(vector_t))==SUCCESS);
    vector_t vec = {3.2,1.4,1.0};
    TEST_ASSERT_TRUE(dynArray_push_back(&array,&vec) == SUCCESS);
    vector_t* value = (vector_t*)dynArray_get_item(&array,0);
    TEST_ASSERT_TRUE(value->x == vec.x);
    TEST_ASSERT_TRUE(value->y == vec.y);
    TEST_ASSERT_TRUE(value->z == vec.z);
    TEST_ASSERT_TRUE(dynArray_free(&array) == SUCCESS);
}
void test_get_length_empty_array(void)
{
    dynarray_t* array = calloc(1,sizeof(*array));
    TEST_ASSERT_FALSE(array == NULL);
    TEST_ASSERT_TRUE(dynArray_init(array,sizeof(float))==SUCCESS);
    TEST_ASSERT_TRUE(dynArray_get_length(array) == 0);
    TEST_ASSERT_TRUE(dynArray_free(array) == SUCCESS);
    TEST_ASSERT_NULL(array->items);
    free(array);
}
void test_clear_and_reuse_array(void)
{
    dynarray_t* array = calloc(1,sizeof(*array));
    TEST_ASSERT_FALSE(array == NULL);
    TEST_ASSERT_TRUE(dynArray_init(array,sizeof(float))==SUCCESS);
    float item = 0.4;
    TEST_ASSERT_TRUE(dynArray_push_back(array,&item) == SUCCESS);
    size_t prev_size = array->size;
    TEST_ASSERT_TRUE(dynArray_clear(array) == SUCCESS);
    TEST_ASSERT_TRUE(array->size != prev_size);
    free(array);
}
int main(void)
{
    UNITY_BEGIN();
    RUN_TEST(test_init_creates_empty_array);
    RUN_TEST(test_init_element_size_zero);
    RUN_TEST(test_call_destroy_null_pointer);
    RUN_TEST(test_init_null_pointer);
    RUN_TEST(test_init_two_times_same_array);
    RUN_TEST(test_insert_item_empty_array);
    RUN_TEST(test_insert_item_capacity);
    RUN_TEST(test_insert_float_type_array);
    RUN_TEST(test_insert_custom_structs_array);
    RUN_TEST(test_get_length_empty_array);
    RUN_TEST(test_clear_and_reuse_array);
    return UNITY_END();
}