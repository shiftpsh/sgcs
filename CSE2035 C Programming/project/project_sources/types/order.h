//
// Created by Suhyun Park on 13/11/2018.
//

#ifndef PROJECT1_ORDER_H
#define PROJECT1_ORDER_H

#include "linked_list.h"

typedef enum {
    DeliverReady = 0, Delivering = 1, Delivered = 2
} ParcelState;

typedef struct {
    int _idx;
    int product_idx;
    int member_idx;
    ParcelState state;
} OrderHistory;

typedef struct __order_node {
    OrderHistory order;
    struct __order_node *next_ptr;
} OrderNode;

typedef LinkedList OrderList;

#define null_order (OrderHistory) {-1}

void order_serialize(char *str, OrderHistory orderHistory);

OrderHistory parse_order(char *str);

OrderList *order_list_create();

void order_list_append(OrderList *list, OrderHistory order);

void order_list_removelast(OrderList *list);

OrderHistory order_list_get(OrderList *list, int idx);

OrderHistory order_list_get_by_idx(OrderList *list, int idx);

void order_list_set(OrderList *list, OrderHistory order, int idx);

OrderList *order_query_by_member_id(OrderList *list, int member_id);

OrderList *order_query_by_product_id(OrderList *list, int product_id);

OrderList *order_query_undelivered(OrderList *list);

OrderList *order_get_all();

void order_print_all(OrderList *list, Language lang);

void order_print(OrderHistory order, Language lang);

void order_put_all(OrderList *list);

#endif //PROJECT1_ORDER_H
