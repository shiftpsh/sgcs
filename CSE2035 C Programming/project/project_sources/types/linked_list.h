//
// Created by Suhyun Park on 30/11/2018.
//

#ifndef PROJECT1_LINKED_LIST_H
#define PROJECT1_LINKED_LIST_H

typedef struct {
    void *head;
    void *tail;
    int size;
} LinkedList;

enum GenericType {
    MemberType, OrderType, ProductType
};

LinkedList *list_create();

void list_append(LinkedList *list, enum GenericType type, void *node);

void list_removelast(LinkedList *list, enum GenericType type);

void *list_get(LinkedList *list, enum GenericType type, int idx);

void list_set(LinkedList *list, enum GenericType type, void *value, int idx);

void list_free(LinkedList *list, enum GenericType type);

#endif //PROJECT1_LINKED_LIST_H
