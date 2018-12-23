//
// Created by Suhyun Park on 30/11/2018.
//

#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"
#include "member.h"
#include "order.h"
#include "product.h"

/// Create an empty LinkedList.
/// \return Empty LinkedList
LinkedList *list_create() {
    LinkedList *list = (LinkedList *) malloc(sizeof(LinkedList));
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;

    return list;
}

/// Append a node to a LinkedList.
/// \param [out] list LinkedList to be appended
/// \param type Type of the node to append
/// \param node Node to append
void list_append(LinkedList *list, enum GenericType type, void *node) {
    if (list->head == NULL && list->tail == NULL) {
        list->head = node;
        list->tail = node;
    } else {
        switch (type) {
            case MemberType:
                ((MemberNode *) list->tail)->next_ptr = node;
                break;
            case OrderType:
                ((OrderNode *) list->tail)->next_ptr = node;
                break;
            case ProductType:
                ((ProductNode *) list->tail)->next_ptr = node;
                break;
        }
        list->tail = node;
    }

    list->size++;
}

/// Remove last node of a LinkedList.
/// \param [out] list LinkedList to be removed its last node
/// \param type Type of the node to be removed
void list_removelast(LinkedList *list, enum GenericType type) {
    if (list->size == 0) return;

    if (type == MemberType) {
        MemberNode *x = list->head;
        while (x->next_ptr->next_ptr != NULL) {
            x = x->next_ptr;
        }
        free(x->next_ptr);
        x->next_ptr = NULL;
        list->tail = x;
    } else if (type == OrderType) {
        OrderNode *x = list->head;
        while (x->next_ptr->next_ptr != NULL) {
            x = x->next_ptr;
        }
        free(x->next_ptr);
        x->next_ptr = NULL;
        list->tail = x;
    } else if (type == ProductType) {
        ProductNode *x = list->head;
        while (x->next_ptr->next_ptr != NULL) {
            x = x->next_ptr;
        }
        free(x->next_ptr);
        x->next_ptr = NULL;
        list->tail = x;
    }

    list->size--;
}

/// Get node from LinkedList at specific index. Index is *1-based*.
/// \param list LinkedList to get the node
/// \param type Type of the node to get
/// \param idx Index of the node to get
/// \return Node at index idx if exists, NULL otherwise
void *list_get(LinkedList *list, enum GenericType type, int idx) {
    int i;
    if (idx < 1) return NULL;
    if (list->size < idx) return NULL;

    if (type == MemberType) {
        MemberNode *x = list->head;

        for (i = 0; i < idx - 1; i++) x = x->next_ptr;
        return x;
    } else if (type == OrderType) {
        OrderNode *x = list->head;

        for (i = 0; i < idx - 1; i++) x = x->next_ptr;
        return x;
    } else if (type == ProductType) {
        ProductNode *x = list->head;

        for (i = 0; i < idx - 1; i++) x = x->next_ptr;
        return x;
    }
}

/// Set node value in LinkedList at specific index. Index is *1-based*.
/// \param [out] list LinkedList to set the node value
/// \param type Type of the node to set
/// \param value New value of the node to update
/// \param idx Index of the node to update
void list_set(LinkedList *list, enum GenericType type, void *value, int idx) {
    int i;
    if (idx < 1) return;
    if (list->size < idx) return;

    if (type == MemberType) {
        MemberNode *x = list->head;
        for (i = 0; i < idx - 1; i++) x = x->next_ptr;

        x->member = *(Member *) value;
    } else if (type == OrderType) {
        OrderNode *x = list->head;
        for (i = 0; i < idx - 1; i++) x = x->next_ptr;

        x->order = *(OrderHistory *) value;
    } else if (type == ProductType) {
        ProductNode *x = list->head;
        for (i = 0; i < idx - 1; i++) x = x->next_ptr;

        x->product = *(Product *) value;
    }
}

/// Free a LinkedList from memory.
/// \param [out] list LinkedList to free
/// \param type Type of the nodes in the LinkedList
void list_free(LinkedList *list, enum GenericType type) {
    if (list->size == 0) return;

    if (type == MemberType) {
        MemberNode *curr = list->head;
        MemberNode *prev;
        if (curr == NULL) return;
        while (curr != NULL) {
            prev = curr;
            curr = curr->next_ptr;
            free(prev);
        }
    } else if (type == OrderType) {
        OrderNode *curr = list->head;
        OrderNode *prev;
        if (curr == NULL) return;
        while (curr != NULL) {
            prev = curr;
            curr = curr->next_ptr;
            free(prev);
        }
    } else if (type == ProductType) {
        ProductNode *curr = list->head;
        ProductNode *prev;
        if (curr == NULL) return;
        while (curr != NULL) {
            prev = curr;
            curr = curr->next_ptr;
            free(prev);
        }
    }

    free(list);
}