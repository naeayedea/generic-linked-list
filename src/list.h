#ifndef Node
#define Node struct NODE
#define List Node **
struct NODE {
    void *data;
    struct NODE *next;
};
#endif

void push(List list, void *data, size_t data_size);
void append(List list, void *data, size_t data_size);
void iterate(List list, void (*function)(void *));
int isEmpty(List list);
int size(List list);
void clear(List list);

void *rem(List list);