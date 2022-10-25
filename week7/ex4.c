#include <malloc.h>
#include <string.h>


void* __realloc(void *ptr, int new_size) {
    if (new_size == 0) {
        free(ptr);
        return NULL;
    }

    void *new_ptr = malloc(new_size * sizeof(void *));
    size_t old_size = malloc_usable_size(ptr);

    if (old_size == 0) return new_ptr;

    size_t copy_size = old_size < new_size ? old_size : new_size;
    memcpy(new_ptr, ptr, copy_size);

    return new_ptr;
}
