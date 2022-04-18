#include<stdio.h>
#include<stdlib.h>
#include "heap.h"
#include "gc.h"

void push_Malloc_heap(struct Malloc_heap** head_ref, memory_node * new_ptr)
{
    struct Malloc_heap* new_node = (struct Malloc_heap*) malloc(sizeof(struct Malloc_heap));
    new_node->data_ptr = new_ptr;
    new_node->next = (*head_ref);
    (*head_ref)    = new_node;
}

void Malloc(memory_node * tree, int size, memory_node ** allocated, struct Malloc_heap** head_ref)
{
    push_Malloc_heap(head_ref, *allocated);
    allocate(tree, size, allocated);
}

void gc(struct Malloc_heap * head, memory_node * root)
{
    struct Malloc_heap * temp = head;
    printf("\nEntered !\n");
    while(temp != NULL)
    {
        temp->data_ptr->block.state = FREE;
        printf("\nMemory is getting freed !\n");
        temp->next = temp;
    }
    collapse(root);
}
void free_gc(struct Malloc_heap * head)
{
    struct Malloc_heap* next_node;
    while(head != NULL)
    {
        next_node = head->next;
        free(head);
        head = next_node;
    }
}

