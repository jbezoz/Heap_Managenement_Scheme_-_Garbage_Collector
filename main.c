#include<stdio.h>
#include<stdlib.h>
#include "heap.h"
#include "gc.h"

int main() 
{
    memory_node * root = init_tree();
    memory_node * A;
    memory_node * B;
    allocate(root, 8000, &A);
    allocate(root, 8000, &B);
    print_tree(root);
    seperator();
    A->block.state = FREE;
    B->block.state = FREE;
    collapse(root);
    print_tree(root);

    // struct Malloc_heap * head = NULL;
    // memory_node * root = init_tree();
    // memory_node * A;
    // memory_node * B;
    // if(1)
    // {
    //     Malloc(root, 4000, &A, &head);
    //     Malloc(root, 4000, &B, &head);
    //     print_tree(root);
    //     gc(head, root);
    // }
    // collapse(root);
    // free_gc(head);
    // seperator();
    // print_tree(root);

    return 0;
}