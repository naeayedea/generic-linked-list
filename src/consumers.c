#include "consumers.h"
#include "list.h"

void sumListConsumer(void *data);

void printString(void *data) {
    printf("\"%s\"  ", (char *)data);
}

void printInt(void *data) {
    printf("%d ", *(int *)data);
}

void printFloat(void *data) {
    printf("%.2f ", *(float *)data);
}

int result;
int sumList(List list) {
    result = 0;
    iterate(list, sumListConsumer);
    return result;
}
void sumListConsumer(void * data) {
    result+= *(int *)data;
}
