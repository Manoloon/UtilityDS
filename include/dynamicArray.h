#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H
#include <stdbool.h>
#include <stdint.h>
typedef enum 
{
    SUCCESS,
    INVALID_ARGUMENT,
    ALREADY_INIT,
    OVERFLOW,
    OUT_OF_MEMORY
} error_code_e;

typedef struct
{
    void* items;
    size_t size;
    size_t capacity;
    size_t item_size;
} dynarray_t;
// init size 0 , 
// capacity 4 , 
// items apunta a un bloque de memoria reservado
// element_size tiene el tamano del tipo que queremos almacenar
bool init(dynarray_t* array, size_t itemSize);
//size_t get_length(dynarray_t* array);
// copia superficial
//void push_back(dynarray_t* array,void* item);
// devuelve puntero del item en indice index;
// solo valido si no se realizo ninguna operacion que modifica el conjunto.
//void* get_item(dynarray_t* array,int index);
//void set_item(dynarray_t* array,int index,void* newData);
//void* pop_back(dynarray_t* array);
//void remove(dynarray_t* array,int index);
//void resize(dynarray_t* array,size_t new_size);
//void reserve(dynarray_t* array, size_t size);
//void clear(dynarray_t* array);
bool destroy(dynarray_t* array);

#endif