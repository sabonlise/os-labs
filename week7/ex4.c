#include <malloc.h>
#include <string.h>


void* __realloc(void *ptr, int new_size) {
    void *new_ptr;

    if (new_size == 0) {
        free(ptr);
        return NULL;
    }

    if (ptr == NULL) {
        new_ptr = malloc(new_size);
    } else  {
        new_ptr = malloc(new_size * sizeof(ptr));
        size_t old_size = malloc_usable_size(ptr);
        
        size_t copy_size = old_size < new_size ? old_size : new_size;
        memcpy(new_ptr, ptr, copy_size);
    }

    return new_ptr;
}
