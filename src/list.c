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

List *newList() {
    List *list = malloc(sizeof(List));
    list->size = 0;
    list->head = NULL;
    return list;
}

Node * createNode(void *data, size_t data_size) {
    //allocate memory for new node
    Node *node = malloc(sizeof(Node));
    //let node know its size inherently
    node->size = data_size;
    //add space for the data to the node
    node->data = malloc(data_size);
    //copy data to the node
    memcpy(node->data, data, data_size);
    return node;
}

//pushes data onto list
void push(List *list, void *data, size_t data_size) {
#ifdef debug
    printf("data: %s, size: %ud\n", data, (unsigned) data_size);
#endif
    Node *node = createNode(data, data_size);
    //push data to head of list
    node->next = list->head;
    //set list header to be new node
    list->head = node;
    //increment size counter
    list->size++;
}

//appends data to end of list
void append(List *list, void *data, size_t data_size) {
#ifdef debug
    printf("data: %s, size: %ud\n", data, (unsigned) data_size);
#endif
    Node *node = createNode(data, data_size);
    if (isEmpty(list)) {
        node->next = list->head;
        list->head = node;
    } else {
        Node *tail = list->head;
        //find the tail of the list
        while (tail->next != NULL) {
            tail = tail->next;
        }
        //explicitly set to null
        node->next = NULL;
        tail->next = node;
    }
    //increment size counter
    list->size++;
}

//iterates over list by passing each node to function given as parameter
void iterate(List *list, void (*consumer)(void *)) {
    Node *head = list->head;
    while (head != NULL) {
        consumer(head->data);
        head = head->next;
    }
}

//determine if list is empty, returns 1 if empty, 0 otherwise.
int isEmpty(List *list) {
    if (list->head == NULL) {
        return 1;
    } else {
        return 0;
    }
}

//returns number of elements in the list
int size(List *list) {
    int size = 0;
    Node *current = list->head;
    while (current != NULL) {
        size++;
        current = current->next;
    }
    return size;
}

//clear all elements in the list
void clear(List *list) {
    while(!isEmpty(list)) {
        rem(list);
    }
}

//removes the first node in the list, returns NULL if empty or the data at the node otherwise
void *rem(List *list) {
    if(isEmpty(list)) {
        return NULL;
    } else {
        void *result = list->head->data;
        Node *next = list->head-> next;
        delete_node(list->head);
        list->head = next;
        list->size--;
        return result;
    }
}