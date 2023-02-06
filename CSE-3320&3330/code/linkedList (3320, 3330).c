typedef struct Node Node;
typedef struct LinkedList LinkedList;

struct Node {
    int data;
    Node* next;
};
Node* createNode(int data);

struct LinkedList {
    int size;
    Node* head;
    Node* tail;
};

#include <stdio.h>
#include <stdlib.h>

Node* createNode(int data) { // creates a new Node
    Node* node = malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    return node;
}

LinkedList* createLinkedList(int data) { // creates a new LinkedList
    LinkedList* list = malloc(sizeof(LinkedList));
    list->head = createNode(data);
    list->tail = list->head;
    list->size = 1;
    return list;
}
LinkedList* copyLinkedList(LinkedList* list) { // creates a new LinkedList with the same data as the original
    Node* indexNode = list->head;

    LinkedList* newList = createLinkedList(indexNode->data);

    indexNode = indexNode->next;

    for (int i = 1; i < list->size; i++) {
        append(newList, indexNode->data);
        indexNode = indexNode->next;
    }

    return newList;
}
void deleteLinkedList(LinkedList* list) { // deletes the LinkedList
    Node* indexNode = list->head;

    for (int i = 0; i < list->size; i++) {
        Node* deleted = indexNode;
        indexNode = indexNode->next;
        free(deleted);
    }

    free(list);
}

Node* selectNode(LinkedList* list, int index) { // gets the Node at that index
    // makes sure the index is not out of range
    if (index > list->size && index >= 0) {
        return NULL;
    }

    // Gets the Node at that index
    Node* indexNode = list->head;
    for (int i = 0; i < index; i++) {
        indexNode = indexNode->next;
    }

    return indexNode;
}
void append(LinkedList* list, int data) { // adds a new Node to the end of the list
    // get the last Node of the list
    Node* indexNode = list->head;
    for (int i = 0; i < list->size; i++) {
        indexNode = indexNode->next;
    }

    // create new Node based on the data
    Node* newNode = createNode(data);
    indexNode->next = newNode;

    // updates the list size
    list->size++;
}
void insertNode(LinkedList* list, int index, int data) { // inserts a new Node at that index
    // Makes sure the index is not out of range
    if (index > list->size && index >= 0) {
        return;
    }

    // gets the Node at that index
    Node* indexNode = list->head;
    for (int i = 0; i < index; i++) {
        indexNode = indexNode->next;
    }

    // creates a new Node nad inserts it t that location (index -> new -> next)
    Node* newNode = createNode(data);
    newNode->next = indexNode->next;
    indexNode->next = newNode;

    // updates the size of the list
    list->size++;
}
void deleteNode(LinkedList* list, int index) { // deletes the Node at that index
    // makes sure the index in not out of range
    if (index > list->size && index >= 0) {
        return;
    }

    // gets the Node at one under that index
    Node* indexNode = list->head;
    for (int i = 0; i < index - 1; i++) {
        indexNode = indexNode->next;
    }

    // saves the deleted node and resets the previous index's address to the proper address;
    Node* deleted = indexNode->next;
    indexNode->next = indexNode->next->next;

    // frees the deleted node
    free(deleted);

    // updates the size of the list
    list->size--;
}
void printList(LinkedList* list) { // prints the data of each Node in the list
    // gets the first Node
    Node* indexNode = list->head;

    // prints the data of each Node
    for (int i = 0; i < list->size; i++) {
        printf("%d->", indexNode->data);
        indexNode = indexNode->next;
    }
    printf("NULL\n");
}
