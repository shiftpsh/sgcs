//
// Created by Suhyun Park on 13/11/2018.
//

#include <stdlib.h>
#include <memory.h>
#include <stdio.h>
#include "../util/util_string.h"
#include "../language.h"
#include "order.h"
#include "member.h"

/// Serialize an OrderHistory.
/// \param [out] str String to be appended the serialized order
/// \param orderHistory OrderHistory to serialize
void order_serialize(char *str, OrderHistory orderHistory) {
    char temp[20];
    str[0] = '\0';

    string_itoa(temp, orderHistory._idx);
    strcat(str, temp);
    strcat(str, ",");
    string_itoa(temp, orderHistory.product_idx);
    strcat(str, temp);
    strcat(str, ",");
    string_itoa(temp, orderHistory.member_idx);
    strcat(str, temp);
    strcat(str, ",");
    string_itoa(temp, orderHistory.state);
    strcat(str, temp);
}

/// Parse an order.
/// \param str String to be parsed
/// \return Parsed order
OrderHistory parse_order(char *str) {
    char *token;

    OrderHistory o;

    token = strtok(str, ",");
    o._idx = atoi(token);

    token = strtok(NULL, ",");
    o.product_idx = atoi(token);

    token = strtok(NULL, ",");
    o.member_idx = atoi(token);

    token = strtok(NULL, ",");
    o.state = atoi(token);

    return o;
}

/// Create a OrderList.
/// \return New OrderList
OrderList *order_list_create() {
    return list_create();
}

/// Append a OrderHistory to the OrderList.
/// \param [out] list OrderList to be appended
/// \param order OrderHistory to append
void order_list_append(OrderList *list, OrderHistory order) {
    OrderNode *node = (OrderNode *) malloc(sizeof(OrderNode));
    node->order = order;
    node->next_ptr = NULL;

    list_append(list, OrderType, node);
}

/// Remove last OrderHistory from a OrderList.
/// \param [out] list OrderList to remove last OrderHistory
void order_list_removelast(OrderList *list) {
    list_removelast(list, OrderType);
}

/// Get OrderHistory from OrderList at specific index.
/// \param list OrderList to find the OrderHistory
/// \param idx Index of the order to get
/// \return OrderHistory at index idx if exists, null_order otherwise
OrderHistory order_list_get(OrderList *list, int idx) {
    if (idx < 0) return null_order;
    if (list->size <= idx) return null_order;
    return ((OrderNode *) list_get(list, OrderType, idx))->order;
}

/// Get OrderHistory from OrderList with specific index.
/// \param list OrderList to find the OrderHistory
/// \param idx Index of the OrderHistory to get
/// \return OrderHistory with the specified index if exists, null_order otherwise
OrderHistory order_list_get_by_idx(OrderList *list, int idx) {
    if (list->size == 0) return null_order;

    OrderNode *x = list->head;
    do {
        if (x->order._idx == idx) return x->order;
        x = x->next_ptr;
    } while (x != NULL);

    return null_order;
}

/// Set order in OrderList at specific index.
/// \param [out] list OrderList to set the OrderHistory
/// \param order Updated OrderHistory
/// \param idx Index of the order to update
void order_list_set(OrderList *list, OrderHistory order, int idx) {
    list_set(list, OrderType, &order, idx);
}

/// Query orders from specific member.
/// \param list OrderList to query
/// \param member_id Member to find
/// \return Pointer of the OrderList that contains queried Orders
OrderList *order_query_by_member_id(OrderList *list, int member_id) {
    OrderList *result = order_list_create();

    if (list->size == 0) return result;

    OrderNode *x = list->head;
    do {
        if (x->order.member_idx == member_id) {
            order_list_append(result, x->order);
        }
        x = x->next_ptr;
    } while (x != NULL);

    return result;
}

/// Query orders from specific product id.
/// \param list OrderList to query
/// \param product_id Product to find
/// \return Pointer of the OrderList that contains queried Orders
OrderList *order_query_by_product_id(OrderList *list, int product_id) {
    OrderList *result = order_list_create();

    if (list->size == 0) return result;

    OrderNode *x = list->head;
    do {
        if (x->order.product_idx == product_id) {
            order_list_append(result, x->order);
        }
        x = x->next_ptr;
    } while (x != NULL);

    return result;
}

/// Query undelivered orders.
/// \param list OrderList to query
/// \return Pointer of the OrderList that contains queried Orders
OrderList *order_query_undelivered(OrderList *list) {
    OrderList *result = order_list_create();

    if (list->size == 0) return result;

    OrderNode *x = list->head;
    do {
        if (x->order.state == DeliverReady) {
            order_list_append(result, x->order);
        }
        x = x->next_ptr;
    } while (x != NULL);

    return result;
}

/// Get all orders in customer.csv.
/// \return All orders in customer.csv
OrderList *order_get_all() {
    char buffer[701];
    OrderList *list = order_list_create();
    FILE *fptr = fopen("history.csv", "r");

    fgets(buffer, 700, fptr); // Ignore first line

    while (fgets(buffer, 700, fptr) != NULL) {
        int l = (int) strlen(buffer);
        if (buffer[l] == '\n') buffer[l] = '\0';

        OrderHistory order = parse_order(buffer);
        order_list_append(list, order);
    }

    fclose(fptr);

    return list;
}

/// Print all orders in list.
/// \param list List to print all orders
/// \param lang Language to print
void order_print_all(OrderList *list, Language lang) {
    if (list->size == 0) {
        printf(lang.error_no_results);
        return;
    }

    OrderNode *x = list->head;
    do {
        printf(lang.order_template, x->order._idx, x->order.product_idx);
        x = x->next_ptr;
    } while (x != NULL);
}

/// Print specific order.
/// \param order Order to print
/// \param lang Language to print
void order_print(OrderHistory order, Language lang) {
    MemberList* members = member_get_all();
    Member member = member_list_get(members, order.member_idx);

    printf(lang.order_idx);
    printf("%d\n", order._idx);
    printf(lang.product_code);
    printf("%d\n", order.product_idx);
    printf(lang.member_idx);
    printf("%d\n", order.member_idx);
    printf(lang.member_id);
    printf("%s\n", member.id);
    printf(lang.member_name);
    printf("%s\n", member.name);
    printf(lang.member_address);
    printf("%s\n", member.address);

    printf(lang.parcel_status);
    switch(order.state) {
        case DeliverReady:
            printf("%s\n", lang.parcel_status_ready);
            break;
        case Delivering:
            printf("%s\n", lang.parcel_status_delivering);
            break;
        case Delivered:
            printf("%s\n", lang.parcel_status_delivered);
            break;
    }

    list_free(members, MemberType);
}

/// Save all orders in OrderList to customer.csv.
/// \param list OrderList to save
void order_put_all(OrderList *list) {
    if (list->size == 0) return;

    char buffer[701];
    FILE *fptr = fopen("history.csv", "w");
    fputs("주문번호,상품번호,회원번호,배송현황", fptr);
    fputs("\n", fptr);

    OrderNode *x = list->head;
    do {
        order_serialize(buffer, x->order);
        fputs(buffer, fptr);
        fputs("\n", fptr);
        x = x->next_ptr;
    } while (x != NULL);

    fclose(fptr);
}