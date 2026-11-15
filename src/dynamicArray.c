#include "dynamicArray.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

bool init(dynarray_t *array, size_t itemSize) {
  if (array == NULL) {
    fprintf(stderr, "DynArray Init : Failed to init an invalid array");
    return false;
  }
  if(array->items != NULL)
  {
    fprintf(stderr, "DynArray Init : Failed to init an array already initialized");
    return false;
  }
  array->item_size = itemSize;
  array->capacity = 4;
  array->size = 0;
  array->items = malloc(itemSize * array->capacity);
  if(array->items == NULL)
  {
    fprintf(stderr,"DynArray Init: failed to allocate memory for items\n");
    return false;
}
  return true;
}

bool destroy(dynarray_t *array) {
  if (array == NULL || array->items == NULL) {
    fprintf(stderr, "DynArray Destroy : failed. Array is NULL\n");
    return false;
  }
  free(array->items);
  array->item_size = 0;
  array->capacity = 0;
  array->size = 0;
  array->items = NULL;
  return true;
}
