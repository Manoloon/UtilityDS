/*
Inicializar un vector de enteros.
[ ] Inicializar un vector de estructuras.
[ ] Intentar inicializar con element_size = 0.
[ ] Intentar inicializar con un puntero al vector igual a NULL.
[ ] Intentar inicializar dos veces el mismo vector.
[ ] Simular o razonar sobre un fallo de malloc.
[ ] Destruir un vector correctamente inicializado.
[ ] Destruir un vector dos veces.
[ ] Llamar a destroy con un puntero NULL.
*/
#include "unity.h"
#include "dynamicArray.h"

void setUp(void){}
void tearDown(void){}
void test_init_creates_empty_array(void)
{
    dynarray_t array = {0};
    TEST_ASSERT_TRUE(init(&array,sizeof(int)));

    destroy(&array);
    TEST_ASSERT_NULL(array.items);
}

int main(void)
{
    UNITY_BEGIN();
    RUN_TEST(test_init_creates_empty_array);
    return UNITY_END();
}