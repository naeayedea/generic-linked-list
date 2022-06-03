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

void initIntList() {
    clear(list);
    int n = sizeof(iData) / sizeof(iData[0]) - 1;
    for (; n>=0; n--) {
        push(list, &iData[n], sizeof(iData[n]));
    }
    printList("Integer List", printInt);
}

void initFloatList() {
    clear(list);
    int n = sizeof(fData) / sizeof(fData[0]) - 1;
    for (; n>=0; n--) {
        push(list, &fData[n], sizeof(fData[n]));
    }
    printList("Float List", printFloat);
}

void initStringList() {
    clear(list);
    int n = sizeof(sData) / sizeof(sData[0]) - 1;
    for (; n>=0; n--) {
        push(list, sData[n], strlen(sData[n])+1);

    }
    printList("String List", printString);
}

void initLongLongList() {
    clear(list);
    int n = sizeof(llData) / sizeof(llData[0]) - 1;
    for (; n>=0; n--) {
        push(list, &llData[n], sizeof(llData[n]));
    }
    printList("LongLong List", printLLong);
}

void setup() {
    //create a new global list for testing
    list = newList();
}

void runTests() {
    //test ints
    initIntList();
    //print the result of the sumList consumer
    printf("\nSum: %d", sumList(list));

    //test floats
    initFloatList();

    //test strings
    initStringList();

    //test long longs
    initLongLongList();
}