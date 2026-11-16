#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H

#include <stddef.h>
#include <stdint.h>

typedef enum dynArr_Code_e
{
    SUCCESS,
    INVALID_ARGUMENT,
    ALREADY_INIT,
    OVERFLOW,
    OUT_OF_MEMORY
}dynArr_Code_e;

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
uint8_t dynArray_init(dynarray_t* array, size_t itemSize);
//size_t get_length(dynarray_t* array);
// copia superficial : offset = size * item_size -> destino = items + offset : 

// casos de borde : 
/*
    1 - el vector esta lleno : duplicar capacidad y luego insertar
    2 - falla realloc : el vector debe conservar su estado anterior
    3 - elemento de origen pertenece al propio vector : por el momento no permitir esto .
    4 - 
*/
uint8_t dynArray_push_back(dynarray_t* array,const void* item);
// devuelve puntero del item en indice index;
// solo valido si no se realizo ninguna operacion que modifica el conjunto.
void* dynArray_get_item(dynarray_t* array,size_t index);
//void set_item(dynarray_t* array,int index,void* newData);
//void* pop_back(dynarray_t* array);
//void remove(dynarray_t* array,int index);
//void resize(dynarray_t* array,size_t new_size);
//void reserve(dynarray_t* array, size_t size);
//void clear(dynarray_t* array);
uint8_t dynArray_destroy(dynarray_t* array);

#endif