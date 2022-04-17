#include<stdio.h>
#include<stdlib.h>
#include "heap.h"
int main() 
{
    memory_node * root = init_tree();
    memory_node * A;
    memory_node * B;
    allocate(root, 128, &A);
    allocate(root, 8000, &B);
    print_tree(root);
    seperator();
    A->block.state = FREE;
    B->block.state = FREE;
    collapse(root);
    print_tree(root);
    return 0;
}