#include "heap.h"
#ifndef GC
#define GC
struct Malloc_heap {
    memory_node * data_ptr;
    struct Malloc_heap * next;
};

void free_gc(struct Malloc_heap * head);
void gc(struct Malloc_heap * head, memory_node * root);
void push_Malloc_heap(struct Malloc_heap** head_ref, memory_node * new_ptr);
void Malloc(memory_node * tree, int size, memory_node ** allocated, struct Malloc_heap** head_ref);

#endif