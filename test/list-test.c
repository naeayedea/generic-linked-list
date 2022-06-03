#include <list.h>
#include <stdio.h>
#include <limits.h>
#include <consumers.h>
#include <string.h>

List *list;

//define arrays of data for usage in testing
float fData[] = {-1451515.41414f, 1.2f, 2.3f, 3.4f, 4.5f, 5.6f, 41414515490.57851f};
char *sData[] = {"", "Hello, World!", "\"\"", "Generic Linked List", "An exceedingly long string of word filler, trying to hit the word count; etc. etc. etc."};
int iData[] = {-INT_MIN, 2, 3, 4, 5, 6, 7, INT_MAX};
long long llData[] = {LLONG_MIN, -1, 0, 1, LLONG_MAX};

void setup();
void runTests();

int main(void) {
    setup();
    runTests();
    return 0;
}

void printList(char * title, void (*consumer)(void *)) {
    printf("\n----------------\n");
    printf("%s\n", title);
    iterate(list, consumer);
    printf("\n----------------\n");
}

unsigned long initIntList() {
    clear(list);
    int n = sizeof(iData) / sizeof(iData[0]);
    for (; n > 0; n--) {
        push(list, &iData[n - 1], sizeof(iData[n - 1]));
    }
    printList("Integer List", printInt);
    return n;
}

unsigned long initFloatList() {
    clear(list);
    int n = sizeof(fData) / sizeof(fData[0]);
    for (; n > 0; n--) {
        push(list, &fData[n], sizeof(fData[n]));
    }
    printList("Float List", printFloat);
    return n;
}

unsigned long initStringList() {
    clear(list);
    int n = sizeof(sData) / sizeof(sData[0]);
    for (; n > 0; n--) {
        push(list, sData[n], strlen(sData[n])+1);

    }
    printList("String List", printString);
    return n;
}

unsigned long initLongLongList() {
    clear(list);
    int n = sizeof(llData) / sizeof(llData[0]);
    for (; n > 0; n--) {
        push(list, &llData[n], sizeof(llData[n]));
    }
    printList("LongLong List", printLLong);
    return n;
}

void setup() {
    //create a new global list for testing
    list = newList();
}

void runTests() {
    size_t count;
    //test ints
    count = initIntList();
    //print the result of the sumList consumer
    printf("\nSum: %d", sumList(list));

    //test floats
    count = initFloatList();

    //test strings
    count = initStringList();

    //test long longs
    count = initLongLongList();
}