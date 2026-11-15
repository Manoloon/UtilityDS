#include "dynamicArray.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

uint8_t init(dynarray_t *array, size_t itemSize) {
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

uint8_t destroy(dynarray_t *array) {
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
