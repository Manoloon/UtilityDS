# Utility DataStructures 
## Dynamic Array Datastructure
* Dynamic array Contract
* | Propiedad         | Decisión |
* | Capacidad inicial | 4 elementos |
* | Crecimiento       | Duplicar capacidad |
* | Almacenamiento    | Memoria contigua |
* | Tipo de datos     | Genérico mediante void * |
* | Inserción         | Copia de bytes |
* | Acceso            | Puntero al elemento |
* | Propiedad de memoria | El vector administra su bloque interno |
* | Destrucción       | Libera el bloque completo |

## API
* dynarray_t* dynArray_create(size_t itemSize);
* size_t dynArray_get_length(dynarray_t* array);
* uint8_t dynArray_push_back(dynarray_t* array,const void* item);
* size_t dynArray_get_capacity(dynarray_t* array);
* void* dynArray_get_items(dynarray_t* array);
* void* dynArray_get_item(dynarray_t* array,size_t index);
* uint8_t dynArray_clear(dynarray_t* array);
* uint8_t dynArray_free(dynarray_t** array);