#ifndef Node
#define Node struct NODE
#define List Node **
struct NODE {
    void *data;
    struct NODE *next;
};
#endif

void printString(void *data);
void printInt(void *data);
void printFloat(void *data);
int sumList(List *list);