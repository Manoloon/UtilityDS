/*
[ ] Simular o razonar sobre un fallo de malloc.
*/
#include <stdlib.h>
#include "unity.h"
#include "dynamicArray.h"

void setUp(void){}
void tearDown(void){}

void test_creates_empty_array(void)
{
    dynarray_t* array = dynArray_create(sizeof(int));
    // Inicializar un vector de estructuras.
    TEST_ASSERT_NOT_NULL(array);
   
    dynArray_free(&array);
    // Destruir un vector correctamente inicializado.
    TEST_ASSERT_NULL(array);
    // Destruir un vector dos veces.
    TEST_ASSERT_TRUE(dynArray_free(&array)==INVALID_ARGUMENT);
}
void test_call_destroy_null_pointer(void)
{
    // Llamar a destroy con un puntero NULL.
    TEST_ASSERT_FALSE(dynArray_free(NULL) == SUCCESS);
}
// pushback
void test_insert_item_empty_array(void)
{
    dynarray_t* array = dynArray_create(sizeof(int));
    TEST_ASSERT_NOT_NULL(array);
    int item = 1;
    TEST_ASSERT_TRUE(dynArray_push_back(array,&item) == SUCCESS);
    //Insertar un entero en un vector vacío.
    TEST_ASSERT_NOT_NULL(dynArray_get_items(array));
    TEST_ASSERT_TRUE(dynArray_free(&array) == SUCCESS);
}
void test_insert_item_capacity(void)
{
    dynarray_t* array = dynArray_create(sizeof(int));
    TEST_ASSERT_NOT_NULL(array);
    // Insertar cuatro enteros sin ampliar capacidad.
    for(int i = 0;i < 4;i++)
    {
        TEST_ASSERT_TRUE(dynArray_push_back(array,&i) == SUCCESS);
    }
    TEST_ASSERT_TRUE(dynArray_get_capacity(array) == 4);
    TEST_ASSERT_TRUE(dynArray_get_length(array) == 4);
    // Insertar un quinto entero y comprobar que capacity pasa a 8.
    int itemnew = 5;
    TEST_ASSERT_TRUE(dynArray_push_back(array,&itemnew) == SUCCESS);
    TEST_ASSERT_TRUE(dynArray_get_capacity(array) == 8);
    TEST_ASSERT_TRUE(dynArray_get_length(array) == 5);
    int* value = (int*) dynArray_get_item(array,4);
    TEST_ASSERT_TRUE(*value == itemnew);
    TEST_ASSERT_TRUE(dynArray_free(&array) == SUCCESS);
}
void test_insert_float_type_array(void)
{
    dynarray_t* array = dynArray_create(sizeof(float));
    TEST_ASSERT_NOT_NULL(array);
    float item = 0.4;
    TEST_ASSERT_TRUE(dynArray_push_back(array,&item) == SUCCESS);
    TEST_ASSERT_TRUE(dynArray_free(&array) == SUCCESS);
}
// void test_insert_type_mismatch_array(void)
// {
//     dynarray_t* array = dynArray_create(sizeof(int));
//     TEST_ASSERT_NOT_NULL(array);
//     float item = 0.4;
//     TEST_ASSERT_TRUE(dynArray_push_back(array,&item) == INVALID_ARGUMENT);
//     TEST_ASSERT_TRUE(dynArray_free(&array) == SUCCESS);
// }
void test_insert_custom_structs_array(void)
{
    typedef struct
    {
        float x;
        float y;
        float z;
    }vector_t;

    dynarray_t* array = dynArray_create(sizeof(vector_t));
    TEST_ASSERT_NOT_NULL(array);
    vector_t vec = {3.2,1.4,1.0};
    TEST_ASSERT_TRUE(dynArray_push_back(array,&vec) == SUCCESS);
    vector_t* value = (vector_t*)dynArray_get_item(array,0);
    TEST_ASSERT_TRUE(value->x == vec.x);
    TEST_ASSERT_TRUE(value->y == vec.y);
    TEST_ASSERT_TRUE(value->z == vec.z);
    TEST_ASSERT_TRUE(dynArray_free(&array) == SUCCESS);
}
void test_get_length_empty_array(void)
{
    dynarray_t* array = dynArray_create(sizeof(float));
    TEST_ASSERT_NOT_NULL(array);
    TEST_ASSERT_TRUE(dynArray_get_length(array) == 0);
    TEST_ASSERT_TRUE(dynArray_free(&array) == SUCCESS);
    TEST_ASSERT_NULL(array);
}
void test_clear_and_reuse_array(void)
{
    dynarray_t* array = dynArray_create(sizeof(float));
    TEST_ASSERT_NOT_NULL(array);

    float item = 0.4;
    TEST_ASSERT_TRUE(dynArray_push_back(array,&item) == SUCCESS);
    size_t prev_size = dynArray_get_length(array);
    TEST_ASSERT_TRUE(dynArray_clear(array) == SUCCESS);
    TEST_ASSERT_TRUE(dynArray_get_length(array) != prev_size);
    TEST_ASSERT_TRUE(dynArray_free(&array) == SUCCESS);
}
int main(void)
{
    UNITY_BEGIN();
    RUN_TEST(test_creates_empty_array);
    RUN_TEST(test_call_destroy_null_pointer);
    RUN_TEST(test_insert_item_empty_array);
    RUN_TEST(test_insert_item_capacity);
    RUN_TEST(test_insert_float_type_array);
    //RUN_TEST(test_insert_type_mismatch_array);
    RUN_TEST(test_insert_custom_structs_array);
    RUN_TEST(test_get_length_empty_array);
    RUN_TEST(test_clear_and_reuse_array);
    return UNITY_END();
}