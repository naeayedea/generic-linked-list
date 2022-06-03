#include <list.h>
#include <stdio.h>
#include <limits.h>
#include <consumers.h>
#include <string.h>
#include "test-framework.h"

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
#ifndef SIMPLE_REPORT
    printf(LINEBREAK);
    printf("%s\n", title);
    iterate(list, consumer);
    printf(LINEBREAK);
#endif
}

unsigned long initIntList() {
    clear(list);
    int n = sizeof(iData) / sizeof(iData[0]);
    for (int i = 0; i < n; i++) {
        push(list, &iData[i], sizeof(iData[i]));
    }
    return n;
}

unsigned long initFloatList() {
    clear(list);
    int n = sizeof(fData) / sizeof(fData[0]);
    for (int i = 0; i < n; i++) {
        push(list, &fData[i], sizeof(fData[i]));
    }
    return n;
}

unsigned long initStringList() {
    clear(list);
    int n = sizeof(sData) / sizeof(sData[0]);
    for (int i = 0; i < n; i++) {
        push(list, sData[i], strlen(sData[i])+1);

    }
    return n;
}

unsigned long initLongLongList() {
    clear(list);
    int n = sizeof(llData) / sizeof(llData[0]);
    for (int i = 0; i < n; i++) {
        push(list, &llData[i], sizeof(llData[i]));
    }
    return n;
}

void setup() {
    //create a new global list for testing
    list = newList();
}

//initialise several different data types using the same list (which is cleared at each function call) to
//demonstrate that the list is generic
int testMultipleDataTypes() {
#ifndef SIMPLE_REPORT
    printf("TEST DATA:\n");
    initIntList();
    printList("Integer List", printInt);
    initFloatList();
    printList("Float List", printFloat);
    initStringList();
    printList("String List", printString);
    initLongLongList();
    printList("LongLong List", printLLong);
#endif
    return 1;
}

int testSize() {
    int result;
    beginTest("size");
    //check each list and ensure that the reported size is the number of elements added by the init function
    result = assertTrue(initIntList() == size(list), "intList");
    result = assertTrue(initFloatList() == size(list), "floatList") && result;
    result = assertTrue(initStringList() == size(list), "stringList") && result;
    result = assertTrue(initLongLongList() == size(list), "longlongList") && result;
    size_t initialSize = initLongLongList();
    //remove value from list and check that size is properly decremented
    rem(list);
    result = assertTrue(initialSize - 1 == size(list), "checkRemoval") && result;
    //clear list and check that size is 0 after
    clear(list);
    result = assertTrue(size(list) == 0, "checkClear") && result;
    //re-add entry to list and check size is 1
    push(list, &iData[0], sizeof(sData[0]));
    result = assertTrue(size(list) == 1, "checkPush") && result;

    endTest("size");
    return result;
}

int testIsEmpty() {
    int result;
    beginTest("isEmpty");
    //ensure list is empty for test
    clear(list);
    //ensure that isEmpty returns true
    result = assertTrue(isEmpty(list), "emptyList");
    //populate the list and check isn't empty
    initLongLongList();
    result = assertFalse(isEmpty(list), "filledList") && result;
    //clear list again and ensure is empty
    clear(list);
    result = assertTrue(isEmpty(list), "clearedList") && result;
    //finally, add an entry and ensure isn't empty
    push(list, &iData[0], sizeof(sData[0]));
    result = assertFalse(isEmpty(list), "singleElementList") && result;

    endTest("isEmpty");
    return result;
}

void runTests() {
    printf(LINEBREAK);
    printf("BEGINNING TESTS");
    printf(LINEBREAK);
    int result;
    testMultipleDataTypes();
    result = assertTrue(testSize(), "Size");
    result = assertTrue(testIsEmpty(), "isEmpty") && result;
    if (result) {
        printf(LINEBREAK);
        printf("ALL TESTS PASSED");
        printf(LINEBREAK);
    } else {
        printf(LINEBREAK);
        printf("TESTS FAILED (SEE ABOVE)");
        printf(LINEBREAK);
    }
}