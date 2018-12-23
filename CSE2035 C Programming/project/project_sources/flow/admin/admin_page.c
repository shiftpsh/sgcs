//
// Created by Suhyun Park on 2018-12-04.
//

#include <stdio.h>
#include <memory.h>
#include "../../language.h"
#include "../../util/util_io.h"
#include "../../types/member.h"
#include "../../types/product.h"
#include "../../util/util_string.h"
#include "../../types/order.h"
#include "admin_page.h"

/// Admin page flow.
void admin_page() {
    int exit_flag = 0;
    Language lang = lang_korean();

    while (!exit_flag) {
        printf(lang.admin_page_title);
        printf(lang.admin_page_1_lookup_customers);
        printf(lang.admin_page_2_add_or_remove_products);
        printf(lang.admin_page_3_edit_products);
        printf(lang.admin_page_4_product_statistics);
        printf(lang.admin_page_5_order_statistics);
        printf(lang.admin_page_6_edit_parcel_status);
        printf(lang.admin_page_7_exit);
        printf(lang.message_select);

        int menu = scan_valid_int(1, 7, lang.error_out_of_range, lang.message_select);

        switch (menu) {
            case 1:
                admin_lookup_customers();
                break;
            case 2:
                admin_add_or_delete_products();
                break;
            case 3:
                admin_edit_products();
                break;
            case 4:
                admin_search_product();
                break;
            case 5:
                admin_lookup_orders();
                break;
            case 6:
                admin_lookup_parcel_status();
                break;
            case 7:
                exit_flag = 1;
                break;
        }
    }
}

/// Lookup all registered customers.
void admin_lookup_customers() {
    Language lang = lang_korean();
    MemberList *members = member_get_all();
    member_print_all(members, lang);
    list_free(members, MemberType);
}

/// Adds or deletes products.
void admin_add_or_delete_products() {
    int exit_flag = 0;
    Language lang = lang_korean();

    while (!exit_flag) {
        printf(lang.admin_add_or_delete_products_title);
        printf(lang.admin_add_or_delete_products_1_add);
        printf(lang.admin_add_or_delete_products_2_remove);
        printf(lang.admin_add_or_delete_products_3_back);
        printf(lang.message_select);

        int menu = scan_valid_int(1, 3, lang.error_out_of_range, lang.message_select);

        switch (menu) {
            case 1:
                admin_add_product();
                break;
            case 2:
                admin_remove_product();
                break;
            case 3:
                exit_flag = 1;
                break;
        }
    }
}


/// Add new product.
void admin_add_product() {
    Language lang = lang_korean();
    printf(lang.admin_add_product_title);

    CLEAR_INPUT_BUFFER

    Product product;

    printf(lang.product_name);
    scan_valid_string(product.name, lang.error_invalid_string, lang.product_name);

    printf(lang.product_category);
    scan_valid_string(product.category, lang.error_invalid_string, lang.product_name);

    printf(lang.product_price_input);
    product.price = scan_valid_int(1, 2000000000, lang.error_out_of_range, lang.product_price_input);

    product.state = Ready;

    printf(lang.admin_product_added);
    printf(lang.admin_product_enable);

    if (scan_valid_boolean(lang.error_invalid_string, lang.admin_product_enable)) {
        product.state = Available;
    }

    ProductList *products = product_get_all();
    product._idx = products->size + 1;
    product_list_append(products, product);
    product_put_all(products);
    list_free(products, ProductType);

    printf(lang.admin_product_add_continue);
    if (scan_valid_boolean(lang.error_invalid_string, lang.admin_product_add_continue)) {
        admin_add_product();
    }
}

/// Delete existing product.
void admin_remove_product() {
    Language lang = lang_korean();
    int code;

    ProductList *products = product_get_all();
    ProductList *not_deleted_products = product_query_available(products, 1);

    printf(lang.admin_remove_product_title);

    product_admin_print_all(not_deleted_products, lang);

    Product selected = null_product;

    printf(lang.product_list_0_exit);
    printf(lang.message_select);

    do {
        scanf("%d", &code);

        if (code == 0) {
            break;
        }

        selected = product_list_get_by_code(products, code);
        if (selected._idx == -1) {
            printf(lang.error_out_of_range);
            printf(lang.message_select);
        }
    } while (selected._idx == -1);

    if (code) {
        selected.state = Unavailable;
        product_list_set(products, selected, code);
        product_put_all(products);

        printf(lang.admin_product_removed);
    }

    list_free(products, ProductType);
    list_free(not_deleted_products, ProductType);

    if (code) {
        printf(lang.admin_product_remove_continue);
        if (scan_valid_boolean(lang.error_invalid_string, lang.admin_product_remove_continue)) {
            admin_remove_product();
        }
    }
}

/// Edit products.
void admin_edit_products() {
    Language lang = lang_korean();
    int code;

    ProductList *products = product_get_all();
    ProductList *not_deleted_products = product_query_available(products, 1);

    printf(lang.admin_edit_products_title);

    product_admin_print_all(not_deleted_products, lang);

    Product selected = null_product;

    printf(lang.product_list_0_exit);
    printf(lang.message_select);

    do {
        scanf("%d", &code);

        if (code == 0) {
            break;
        }

        selected = product_list_get_by_code(products, code);
        if (selected._idx == -1) {
            printf(lang.error_out_of_range);
            printf(lang.message_select);
        }
    } while (selected._idx == -1);

    if (code) {
        admin_edit_product(selected);
    }

    list_free(products, ProductType);
    list_free(not_deleted_products, ProductType);

    if (code) {
        printf(lang.admin_product_edit_continue);
        if (scan_valid_boolean(lang.error_invalid_string, lang.admin_product_edit_continue)) {
            admin_edit_products();
        }
    }
}

/// Edit specific product.
/// \param product Product to edit
void admin_edit_product(Product product) {
    Language lang = lang_korean();
    ProductList *products = product_get_all();

    printf(lang.admin_edit_products_1_name);
    printf(lang.admin_edit_products_2_category);
    printf(lang.admin_edit_products_3_price);
    printf(lang.admin_edit_products_4_state);
    printf(lang.admin_edit_products_5_exit);
    printf(lang.message_select);

    int menu = scan_valid_int(1, 5, lang.error_out_of_range, lang.message_select);

    CLEAR_INPUT_BUFFER

    switch (menu) {
        case 1:
            printf(lang.admin_product_new_name);
            scan_valid_string(product.name, lang.error_invalid_string, lang.admin_product_new_name);
            break;
        case 2:
            printf(lang.admin_product_new_category);
            scan_valid_string(product.category, lang.error_invalid_string, lang.admin_product_new_category);
            break;
        case 3:
            printf(lang.admin_product_new_price);
            product.price = scan_valid_int(1, 2000000000, lang.error_out_of_range, lang.admin_product_new_price);
            break;
        case 4:
            printf(lang.admin_product_new_state);
            product.state = scan_valid_boolean(lang.error_invalid_string, lang.admin_product_new_state);
            break;
    }

    if (menu != 5) {
        product_list_set(products, product, product._idx);
        product_put_all(products);
        printf(lang.admin_product_edited);
    }

    list_free(products, ProductType);
}

/// Search products.
void admin_search_product() {
    ProductList *products = product_get_all(), *queried;
    char query[101];
    int min, max;

    int exit_flag = 0;
    Language lang = lang_korean();

    while (!exit_flag) {
        printf(lang.product_search_title);
        printf(lang.product_search_1_by_name);
        printf(lang.product_search_2_by_category);
        printf(lang.product_search_3_by_price);
        printf(lang.product_search_4_all);
        printf(lang.product_search_5_exit);

        printf(lang.message_select);

        int menu = scan_valid_int(1, 5, lang.error_out_of_range, lang.message_select);

        CLEAR_INPUT_BUFFER

        switch (menu) {
            case 1:
                printf(lang.message_search);
                fgets(query, 100, stdin);
                queried = product_query_by_name(products, string_trim(query), 1);
                break;
            case 2:
                printf(lang.message_search);
                fgets(query, 100, stdin);
                queried = product_query_by_category(products, string_trim(query), 1);
                break;
            case 3:
                printf(lang.message_minimum_price);
                min = scan_valid_int(0, 2000000000, lang.error_out_of_range, lang.message_minimum_price);
                printf(lang.message_maximum_price);
                max = scan_valid_int(min, 2000000000, lang.error_out_of_range, lang.message_minimum_price);
                queried = product_query_by_price(products, min, max, 1);
                break;
            case 4:
                queried = product_query_available(products, 1);
                break;
            case 5:
                exit_flag = 1;
                break;
        }

        if (menu != 5) {
            admin_product_list(queried);
            list_free(queried, ProductType);
        }
    }

    list_free(products, ProductType);
}

/// View searched products.
/// \param products Queried products
void admin_product_list(ProductList *products) {
    Language lang = lang_korean();
    int code = 0, exit_flag = 0;

    while (1) {
        Product selected = null_product;

        product_admin_print_all(products, lang);
        printf(lang.product_list_0_exit);
        printf(lang.message_select);

        do {
            scanf("%d", &code);

            if (code == 0) {
                exit_flag = 1;
                break;
            }

            selected = product_list_get_by_code(products, code);
            if (selected._idx == -1) {
                printf(lang.error_out_of_range);
                printf(lang.message_select);
            }
        } while (selected._idx == -1);

        if (exit_flag) break;

        admin_lookup_product(selected);
    }
}

/// Lookup specific product.
/// \param product Producy to lookup
void admin_lookup_product(Product product) {
    Language lang = lang_korean();

    printf(lang.product_code);
    printf("%d\n", product._idx);

    printf(lang.product_name);
    printf("%s\n", product.name);

    printf(lang.product_category);
    printf("%s\n", product.category);

    printf(lang.product_status);
    if (product.state == Available) {
        printf(lang.product_status_available);
    } else {
        printf(lang.product_status_ready);
    };
    printf("\n");

    printf(lang.product_price, product.price);

    printf(lang.product_sales);
    printf("%d\n", product_sales(product));

    printf(lang.message_separator);
    printf(lang.product_list_0_exit);
    printf(lang.message_select);

    scan_valid_int(0, 0, lang.error_invalid_string, lang.message_select);
}

/// Lookup orders.
void admin_lookup_orders() {
    Language lang = lang_korean();

    MemberList *members = member_get_all();
    OrderList *orders = order_get_all(), *queried;
    char query[101];
    Member member;
    int temp;

    printf(lang.admin_lookup_orders_title);
    printf(lang.admin_lookup_orders_1_by_user_id);
    printf(lang.admin_lookup_orders_2_by_product_code);
    printf(lang.admin_lookup_orders_3_undelivered);
    printf(lang.admin_lookup_orders_4_all);
    printf(lang.admin_lookup_orders_5_exit);

    printf(lang.message_select);

    int menu = scan_valid_int(1, 5, lang.error_out_of_range, lang.message_select);

    CLEAR_INPUT_BUFFER

    switch (menu) {
        case 1:
            do {
                printf(lang.admin_lookup_orders_user_id);
                fgets(query, 100, stdin);

                query[strlen(query) - 1] = '\0';
                member = member_with_id(members, query);
                if (member._idx == -1) {
                    printf(lang.error_invalid_string);
                }
            } while (member._idx == -1);

            queried = order_query_by_member_id(orders, member._idx);
            break;
        case 2:
            printf(lang.admin_lookup_orders_product_code);
            scanf("%d", &temp);
            queried = order_query_by_product_id(orders, temp);
            break;
        case 3:
            queried = order_query_undelivered(orders);
            break;
        case 4:
            queried = order_get_all();
            break;
    }

    if (menu != 5) {
        admin_order_list(queried);
        list_free(queried, OrderType);
    }

    list_free(orders, OrderType);
    list_free(members, MemberType);
}

/// View searched orders.
/// \param orders Queried orders
void admin_order_list(OrderList *orders) {
    Language lang = lang_korean();
    order_print_all(orders, lang);
}

/// Edit parcel status.
void admin_lookup_parcel_status() {
    Language lang = lang_korean();

    MemberList *members = member_get_all();
    OrderList *orders, *queried;
    char query[101];
    Member member;
    int temp;

    int exit_flag = 0;

    while (!exit_flag) {
        orders = order_get_all();

        printf(lang.admin_edit_parcel_status_title);
        printf(lang.admin_lookup_orders_1_by_user_id);
        printf(lang.admin_lookup_orders_2_by_product_code);
        printf(lang.admin_lookup_orders_3_undelivered);
        printf(lang.admin_lookup_orders_4_all);
        printf(lang.admin_lookup_orders_5_exit);

        printf(lang.message_select);

        int menu = scan_valid_int(1, 5, lang.error_out_of_range, lang.message_select);

        CLEAR_INPUT_BUFFER

        switch (menu) {
            case 1:
                do {
                    printf(lang.admin_lookup_orders_user_id);
                    fgets(query, 100, stdin);

                    query[strlen(query) - 1] = '\0';
                    member = member_with_id(members, query);
                    if (member._idx == -1) {
                        printf(lang.error_invalid_string);
                    }
                } while (member._idx == -1);

                queried = order_query_by_member_id(orders, member._idx);
                break;
            case 2:
                printf(lang.admin_lookup_orders_product_code);
                scanf("%d", &temp);
                queried = order_query_by_product_id(orders, temp);
                break;
            case 3:
                queried = order_query_undelivered(orders);
                break;
            case 4:
                queried = order_get_all();
                break;
            case 5:
                exit_flag = 1;
                break;
        }

        if (menu != 5) {
            admin_order_list_select_to_edit(queried);
            list_free(queried, OrderType);
        }

        list_free(orders, OrderType);
    }

    list_free(members, MemberType);
}

/// View searched orders and edit parcel status.
/// \param orders Queried orders
void admin_order_list_select_to_edit(OrderList *orders) {
    Language lang = lang_korean();
    order_print_all(orders, lang);
    OrderHistory order;
    int x;

    if (orders->size == 0) return;

    printf(lang.message_separator);
    printf(lang.product_list_0_exit);
    printf(lang.message_select);

    do {
        scanf("%d", &x);
        if (!x) break;
        order = order_list_get_by_idx(orders, x);

        if (order._idx == -1) {
            printf(lang.error_out_of_range);
            printf(lang.message_select);
        }
    } while (order._idx == -1);

    if (x) {
        admin_edit_parcel_status(order);
    }
}

/// Edit parcel status of specific product.
/// \param order OrderHistory to edit parcel status
void admin_edit_parcel_status(OrderHistory order) {
    Language lang = lang_korean();
    OrderList *orders = order_get_all();

    order_print(order, lang);

    printf(lang.message_separator);

    printf(lang.admin_edit_parcel_status_desc);
    printf(lang.admin_edit_parcel_status_new_1_ready);
    printf(lang.admin_edit_parcel_status_new_2_delivering);
    printf(lang.admin_edit_parcel_status_new_3_delivered);
    printf(lang.admin_edit_parcel_status_new_4_exit);
    printf(lang.message_select);

    int menu = scan_valid_int(1, 4, lang.error_out_of_range, lang.message_select);

    switch (menu) {
        case 1:
            order.state = DeliverReady;
            break;
        case 2:
            order.state = Delivering;
            break;
        case 3:
            order.state = Delivered;
            break;
    }

    if (menu != 4) {
        printf(lang.admin_edit_parcel_complete);
    }

    order_list_set(orders, order, order._idx);
    order_put_all(orders);
    list_free(orders, OrderType);
}