#include "dynamicArray.h"
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

uint8_t dynArray_init(dynarray_t *array, size_t itemSize) {
  if (array == NULL)
  {
    return INVALID_ARGUMENT;
  }
  if(array->items != NULL)
  {
    return ALREADY_INIT;
  }
  if(itemSize < 1)
  {
    return INVALID_ARGUMENT;
  }
  if(itemSize > SIZE_MAX/4)
  {
    return OVERFLOW;
  }
  array->item_size = itemSize;
  array->capacity = 4;
  array->size = 0;
  void* itemsTemp = malloc(itemSize * array->capacity);
  if(itemsTemp == NULL)
  {
    return OUT_OF_MEMORY;
}
  array->items = itemsTemp;
  return SUCCESS;
}

size_t dynArray_get_length(dynarray_t *array)
{
  if(array == NULL)
  {
    return 0;
  }
    return array->size;
}

uint8_t dynArray_push_back(dynarray_t *array,const void *item)
{
  bool bInvalidArg = array == NULL || item == NULL || array->items == NULL;
  if(bInvalidArg)
  {
    return INVALID_ARGUMENT;
  }
  if(array->size == array->capacity) // array is full
  {
    if(array->capacity / 2 + 1 == SIZE_MAX)
    {
      return OVERFLOW;
    }
    size_t new_capacity = array->capacity * 2;
    if(new_capacity > SIZE_MAX / array->item_size)
    {
      return OVERFLOW;
    }
    size_t new_size = array->item_size * new_capacity;
    void* items_temp = realloc(array->items,new_size);
    if(items_temp == NULL)
    {
      return OUT_OF_MEMORY;
    }
    array->items = items_temp;
    array->capacity = new_capacity;
  }
  // insert new item
  size_t offset = array->size * array->item_size;
  // unsigned char* para aritmetica de bytes
  memcpy((uint8_t*)array->items + offset,item,array->item_size);
  array->size++;
  return SUCCESS;
}

void *dynArray_get_item(dynarray_t *array, size_t index)
{
  if(array == NULL || array->size <= index)
  {
    return NULL;
  }
    return (uint8_t*)array->items + (index * array->item_size);
}

uint8_t dynArray_destroy(dynarray_t *array)
{
    if (array == NULL)
    {
        return INVALID_ARGUMENT;
    }
    if (array->items != NULL)
    {
        free(array->items);
    }

    array->item_size = 0;
    array->capacity = 0;
    array->size = 0;
    array->items = NULL;
    return SUCCESS;
}
