#include "dynamicArray.h"
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct dynarray_s
{
    void* items;
    size_t size;
    size_t capacity;
    size_t item_size;
}dynarray_t;

dynarray_t *dynArray_create(size_t itemSize)
{
  //printf("create itemSize %zu\n",itemSize);
  dynarray_t* array;
  if(itemSize < 1 || itemSize > SIZE_MAX / 4)
  {
    return NULL;
  }

  array = malloc(sizeof(dynarray_t));
  if(array == NULL)
  {
    return NULL;
  }
  array->item_size = itemSize;
  array->capacity = 4;
  array->size = 0;
  void *itemsTemp = malloc(itemSize * array->capacity);
  if (itemsTemp == NULL)
  {
    free(array);
    return NULL;
  }
  array->items = itemsTemp;
  return array;
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
  //printf("%zu : %zu\n",array->item_size,sizeof(item));
  bool bInvalidArg = array == NULL || item == NULL || array->items == NULL || 
                    array == item;
  if(bInvalidArg)
  {
    return INVALID_ARGUMENT;
  }
  if(array->size == array->capacity) // array is full
  {
    if(array->capacity / 2 + 1 == SIZE_MAX)
    {
      return MEM_OVERFLOW;
    }
    size_t new_capacity = array->capacity * 2;
    if(new_capacity > SIZE_MAX / array->item_size)
    {
      return MEM_OVERFLOW;
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

size_t dynArray_get_capacity(dynarray_t *array)
{
  if(array == NULL)
  {
    return 0;
  }
    return array->capacity;
}

void *dynArray_get_items(dynarray_t *array)
{
  if(array == NULL)
  {
    return NULL;
  }
    return array->items;
}

void *dynArray_get_item(dynarray_t *array, size_t index)
{
  if(array == NULL || array->size <= index)
  {
    return NULL;
  }
    return (uint8_t*)array->items + (index * array->item_size);
}

uint8_t dynArray_clear(dynarray_t *array)
{
    if (array == NULL)
    {
        return INVALID_ARGUMENT;
    }
    if (array->items != NULL)
    {
        free(array->items);
    }
    array->items = NULL;
    array->size = 0;
    return SUCCESS;
}

uint8_t dynArray_free(dynarray_t **array)
{
  if (array == NULL || *array == NULL)
  {
    return INVALID_ARGUMENT;
  }
  void *localItems = dynArray_get_items(*array);
  if (localItems != NULL)
  {
    free(dynArray_get_items(*array));
  }
  localItems = NULL;
  free(*array);
  *array = NULL;
  return SUCCESS;
}
