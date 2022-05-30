#include <stdio.h>
#include <string.h>
#include "list.h"
#include "consumers.h"


int main (void) {
    Node *head = NULL;
    List list = &head;
    int i;

    //create list of integers
    int iData[] = {5, 4, 3, 2, 1, 6};
    for (i = 0; i < 5; i++) {
        push(list, &iData[i], sizeof(int));
    }
    //append list element of list so should be 1,2,3,4,5,6
    append(list, &iData[5] , sizeof(int));
    //print the list using printInt consumer
    printf("Integer List:\n");
    iterate(list, printInt);
    //print the result of the sumList consumer
    printf("\nSum: %d", sumList(list));

    //clear the list
    clear(list);
    //create list of floats
    float fData[] = {500.5f, 400.4f, 300.3f, 200.2f, 100.1f};
    for (i = 0; i < 5; i++) {
        push(list, &fData[i], sizeof(float));
    }
    //print the list using printFloat consumer
    printf("\n\nFloat List:\n");
    iterate(list, printFloat);

    //clear list
    clear(list);
    //create list of strings
    char * sData[] = {"hello", "goodbye", "hi", "test", "very long string"};
    for (i = 0; i < 5; i++) {
        push(list, sData[i], strlen(sData[i])+1);
    }
    //print the list using printString consumer
    printf("\n\nString List:\n");
    iterate(list, printString);
    return 0;
}

