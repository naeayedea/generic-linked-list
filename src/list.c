#include <stdlib.h>
#include <string.h>
#include "list.h"

#ifdef debug
#include <stdio.h>
#endif

void delete_node(Node *node){
    free(node->data);
    free(node);
    node = NULL;
}

Node * createNode(void *data, size_t data_size) {
    //allocate memory for new node
    Node *node = malloc(sizeof(Node));
    //add space for the data to the node
    node->data = malloc(data_size);
    //copy data to the node
    memcpy(node->data, data, data_size);
    return node;
}

//pushes data onto list
void push(List list, void *data, size_t data_size) {
#ifdef debug
    printf("data: %s, size: %ud\n", data, (unsigned) data_size);
#endif
    Node *node = createNode(data, data_size);
    //push data to head of list
    node->next = *list;
    //set list header to be new node
    *list = node;
}

//appends data to end of list
void append(List list, void *data, size_t data_size) {
#ifdef debug
    printf("data: %s, size: %ud\n", data, (unsigned) data_size);
#endif
    Node *node = createNode(data, data_size);
    if (isEmpty(list)) {
        node->next = *list;
        *list = node;
    } else {
        Node *tail = *list;
        //find the tail of the list
        while (tail->next != NULL) {
            tail = tail->next;
        }
        //explicitly set to null
        node->next = NULL;
        tail->next = node;
    }
}

//iterates over list by passing each node to function given as parameter
void iterate(List list, void (*consumer)(void *)) {
    Node *head = *list;
    while (head != NULL) {
        consumer(head->data);
        head = head->next;
    }
}

//determine if list is empty, returns 1 if empty, 0 otherwise.
int isEmpty(List list) {
    if (*list == NULL) {
        return 1;
    } else {
        return 0;
    }
}

//returns number of elements in the list
int size(List list) {
    int size = 0;
    Node *current = *list;
    while (current != NULL) {
        size++;
        current = current->next;
    }
    return size;
}

//clear all elements in the list
void clear(List list) {
    while(!isEmpty(list)) {
        rem(list);
    }
}

//removes the first node in the list, returns NULL if empty or the data at the node otherwise
void *rem(List list) {
    if(isEmpty(list)) {
        return NULL;
    } else {
        void *result = (*list)->data;
        Node *next = (*list) -> next;
        delete_node(*list);
        *list = next;
        return result;
    }
}