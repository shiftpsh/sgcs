//
// Created by Suhyun Park on 13/11/2018.
//

#include <memory.h>
#include <stdlib.h>
#include <stdio.h>
#include "../util/util_string.h"
#include "product.h"
#include "order.h"

/// Serialize a Product.
/// \param [out] str String to be appended the serialized product
/// \param product Product to serialize
void product_serialize(char *str, Product product) {
    char temp[20];
    str[0] = '\0';

    string_itoa(temp, product._idx);
    strcat(str, temp);
    strcat(str, ",");
    strcat(str, product.name);
    strcat(str, ",");
    strcat(str, product.category);
    strcat(str, ",");
    string_itoa(temp, product.price);
    strcat(str, temp);
    strcat(str, ",");
    string_itoa(temp, product.state);
    strcat(str, temp);
}

/// Parse a product.
/// \param str String to be parsed
/// \return Parsed product
Product parse_product(char *str) {
    char *token;

    Product p;

    token = strtok(str, ",");
    p._idx = atoi(token);

    token = strtok(NULL, ",");
    strcpy(p.name, token);

    token = strtok(NULL, ",");
    strcpy(p.category, token);

    token = strtok(NULL, ",");
    p.price = atoi(token);

    token = strtok(NULL, ",");
    p.state = atoi(token);

    return p;
}

/// Create a ProductList.
/// \return New ProductList
ProductList *product_list_create() {
    return list_create();
}

/// Append a Product to the ProductList.
/// \param [out] list ProductList to be appended
/// \param product Product to append
void product_list_append(ProductList *list, Product product) {
    ProductNode *node = (ProductNode *) malloc(sizeof(ProductNode));
    node->product = product;
    node->next_ptr = NULL;

    list_append(list, ProductType, node);
}

/// Remove last Product from a ProductList.
/// \param [out] list ProductList to remove last Product
void product_list_removelast(ProductList *list) {
    list_removelast(list, ProductType);
}

/// Get Product from ProductList at specific index.
/// \param list ProductList to find the Product
/// \param idx Index of the product to get
/// \return Product at index idx if exists, null_product otherwise
Product product_list_get(ProductList *list, int idx) {
    if (idx < 0) return null_product;
    if (list->size <= idx) return null_product;
    return ((ProductNode *) list_get(list, ProductType, idx))->product;
}

/// Set product in ProductList at specific index.
/// \param [out] list ProductList to set the Product
/// \param product Updated Product
/// \param idx Index of the product to update
void product_list_set(ProductList *list, Product product, int idx) {
    list_set(list, ProductType, &product, idx);
}

/// Get Product from ProductList with specific Product code.
/// \param list ProductList to find the Product
/// \param code Code of the product to get
/// \return Product with the specified code if exists, null_product otherwise
Product product_list_get_by_code(ProductList *list, int code) {
    if (list->size == 0) return null_product;

    ProductNode *x = list->head;
    do {
        if (x->product._idx == code) return x->product;
        x = x->next_ptr;
    } while (x != NULL);

    return null_product;
}

/// Query products which its name *contains* specific keyword.
/// \param list ProductList to query
/// \param keyword Keyword to find
/// \paran query_ready 1 to query currently not selling items as well; 0 otherwise
/// \return Pointer of the ProductList that contains queried Products
ProductList *product_query_by_name(ProductList *list, char *keyword, int query_ready) {
    ProductList *result = product_list_create();

    if (list->size == 0) return result;

    ProductNode *x = list->head;
    do {
        if (strstr(x->product.name, keyword) != NULL
            && ((!query_ready && x->product.state == Available) || (query_ready && x->product.state != Unavailable))) {
            product_list_append(result, x->product);
        }
        x = x->next_ptr;
    } while (x != NULL);

    return result;
}

/// Query products which its category *matches* specific keyword.
/// \param list ProductList to query
/// \param keyword Keyword to find
/// \paran query_ready 1 to query currently not selling items as well; 0 otherwise
/// \return Pointer of the ProductList that contains queried Products
ProductList *product_query_by_category(ProductList *list, char *keyword, int query_ready) {
    ProductList *result = product_list_create();

    if (list->size == 0) return result;

    ProductNode *x = list->head;
    do {
        if (strcmp(x->product.category, keyword) == 0
            && ((!query_ready && x->product.state == Available) || (query_ready && x->product.state != Unavailable))) {
            product_list_append(result, x->product);
        }
        x = x->next_ptr;
    } while (x != NULL);

    return result;
}

/// Query products which its price falls in specific range.
/// \param list ProductList to query
/// \param min minimum price
/// \param max maximum price
/// \paran query_ready 1 to query currently not selling items as well; 0 otherwise
/// \return Pointer of the ProductList that contains queried Products
ProductList *product_query_by_price(ProductList *list, int min, int max, int query_ready) {
    ProductList *result = product_list_create();

    if (list->size == 0) return result;

    ProductNode *x = list->head;
    do {
        if (min <= x->product.price && x->product.price <= max
            && ((!query_ready && x->product.state == Available) || (query_ready && x->product.state != Unavailable))) {
            product_list_append(result, x->product);
        }
        x = x->next_ptr;
    } while (x != NULL);

    return result;
}

/// Query all available products in list.
/// \param list ProductList to query
/// \paran query_ready 1 to query currently not selling items as well; 0 otherwise
/// \return Pointer of the ProductList that contains queried Products
ProductList *product_query_available(ProductList *list, int query_ready) {
    ProductList *result = product_list_create();

    if (list->size == 0) return result;

    ProductNode *x = list->head;
    do {
        if ((!query_ready && x->product.state == Available) || (query_ready && x->product.state != Unavailable)) {
            product_list_append(result, x->product);
        }
        x = x->next_ptr;
    } while (x != NULL);

    return result;
}

/// Get all products in product.csv.
/// \return All products in product.csv
ProductList *product_get_all() {
    char buffer[701];
    ProductList *list = product_list_create();
    FILE *fptr = fopen("product.csv", "r");

    fgets(buffer, 700, fptr); // Ignore first› line

    while (fgets(buffer, 700, fptr) != NULL) {
        int l = (int) strlen(buffer);
        if (buffer[l] == '\n') buffer[l] = '\0';

        Product product = parse_product(buffer);
        product_list_append(list, product);
    }

    fclose(fptr);

    return list;
}

/// Print all products in list.
/// \param list List to print all products
/// \param lang Language to print
void product_print_all(ProductList *list, Language lang) {
    if (list->size == 0) {
        printf(lang.error_no_results);
        return;
    }

    ProductNode *x = list->head;
    do {
        printf(lang.product_code);
        printf("%d\n", x->product._idx);

        printf(lang.product_name);
        printf("%s\n", x->product.name);

        printf(lang.product_category);
        printf("%s\n", x->product.category);

        printf(lang.product_price, x->product.price);

        printf(lang.message_separator);
        x = x->next_ptr;
    } while (x != NULL);
}

/// Print all products in list with product status.
/// \param list List to print all products
/// \param lang Language to print
void product_admin_print_all(ProductList *list, Language lang) {
    if (list->size == 0) {
        printf(lang.error_no_results);
        return;
    }

    ProductNode *x = list->head;
    do {
        printf(lang.product_code);
        printf("%d\n", x->product._idx);

        printf(lang.product_name);
        printf("%s\n", x->product.name);

        printf(lang.product_category);
        printf("%s\n", x->product.category);

        printf(lang.product_price, x->product.price);

        printf(lang.product_status);
        if (x->product.state == Available) {
            printf(lang.product_status_available);
        } else {
            printf(lang.product_status_ready);
        };
        printf("\n");

        printf(lang.message_separator);
        x = x->next_ptr;
    } while (x != NULL);
}

/// Save all products in ProductList to product.csv.
/// \param list ProductList to save
void product_put_all(ProductList *list) {
    if (list->size == 0) return;

    char buffer[701];
    FILE *fptr = fopen("product.csv", "w");
    fputs("상품번호,상품명,카테고리,가격,상태", fptr);
    fputs("\n", fptr);

    ProductNode *x = list->head;
    do {
        product_serialize(buffer, x->product);
        fputs(buffer, fptr);
        fputs("\n", fptr);
        x = x->next_ptr;
    } while (x != NULL);

    fclose(fptr);
}

/// Calculate purchased count of a product.
/// \param product Product to query
/// \return Purchased count
int product_sales(Product product) {
    OrderList *orders = order_get_all();
    int s = 0;

    OrderNode *x = orders->head;
    do {
        if (x->order.product_idx == product._idx) s++;
        x = x->next_ptr;
    } while (x != NULL);

    list_free(orders, OrderType);

    return s;
}