//
// Created by Suhyun Park on 13/11/2018.
//

#ifndef PROJECT1_PRODUCT_H
#define PROJECT1_PRODUCT_H

#include "../language.h"
#include "linked_list.h"

typedef enum {
    Unavailable = -1, Ready, Available
} ProductState;

typedef struct {
    int _idx;
    char name[101];
    char category[101];
    int price;
    ProductState state;
} Product;

typedef struct __product_node {
    Product product;
    struct __product_node *next_ptr;
} ProductNode;

typedef LinkedList ProductList;

#define null_product (Product) {-1}

void product_serialize(char *str, Product product);

Product parse_product(char *str);

ProductList *product_list_create();

void product_list_append(ProductList *list, Product product);

void product_list_removelast(ProductList *list);

Product product_list_get(ProductList *list, int idx);

void product_list_set(ProductList *list, Product product, int idx);

Product product_list_get_by_code(ProductList *list, int code);

ProductList *product_query_by_name(ProductList *list, char *keyword, int query_ready);

ProductList *product_query_by_category(ProductList *list, char *keyword, int query_ready);

ProductList *product_query_by_price(ProductList *list, int min, int max, int query_ready);

ProductList *product_query_available(ProductList *list, int query_ready);

ProductList *product_get_all();

void product_print_all(ProductList *list, Language lang);

void product_admin_print_all(ProductList *list, Language lang);

void product_put_all(ProductList *list);

int product_sales(Product product);

#endif //PROJECT1_PRODUCT_H
