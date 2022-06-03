#ifndef Node
#define Node struct NODE
#define List struct LIST
struct NODE {
    void *data;
    unsigned long size;
    struct NODE *next;
};
struct LIST {
    Node *head;
    unsigned long long size;
};
#endif

List *newList();
void push(List *list, void *data, unsigned long data_size);
void append(List *list, void *data, unsigned long data_size);
void iterate(List *list, void (*function)(void *));
int isEmpty(List *list);
unsigned long long size(List *list);
void clear(List *list);
void *rem(List *list);