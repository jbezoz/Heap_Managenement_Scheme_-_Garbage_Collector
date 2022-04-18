#ifndef HEAP
#define HEAP
#define HEAP_SIZE 16*1024

char heap[HEAP_SIZE];
typedef struct memory_block {
    char* start;
    int size;
    enum {OCCUPIED, FREE, SPLIT} state;
} memory_block;

typedef struct memory_node {
    struct memory_block block;
    struct memory_node* left;
    struct memory_node* right;
} memory_node;

memory_block new_block(char* start_addr, int size);
void print_block(memory_block m);

int next_higher_power(int n);
char* get_state(memory_block b);
memory_node* init_tree();

void print_tree(memory_node* root);
void seperator();
void split(memory_node* parent);

// Caution: Use only on terminal nodes
void merge_children(memory_node* parent);

// collapses all free children of given node
void collapse(memory_node * tree);

int allocate(memory_node * tree, int size, memory_node ** allocated);
void free_node(memory_node * m);

#endif