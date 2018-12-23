//
// Created by Suhyun Park on 02/12/2018.
//

#include <stdio.h>
#include <memory.h>
#include "../../util/util_io.h"
#include "../../util/util_string.h"
#include "../../types/member.h"
#include "../../types/product.h"
#include "../../types/order.h"
#include "user_page.h"

/// User page flow.
void user_page(Member *session) {
    int exit_flag = 0;
    Language lang = lang_korean();

    while (!exit_flag) {
        printf(lang.user_menu_title, session->name);
        printf(lang.user_menu_1_edit);
        printf(lang.user_menu_2_bank);
        printf(lang.user_menu_3_search);
        printf(lang.user_menu_4_orders);
        printf(lang.user_menu_5_parcels);
        printf(lang.user_menu_6_logout);
        printf(lang.message_select);

        int menu = scan_valid_int(1, 6, lang.error_out_of_range, lang.message_select);

        switch (menu) {
            case 1:
                if (user_edit_credentials(session) == 1) {
                    exit_flag = 1;
                }
                break;
            case 2:
                user_edit_balance(session);
                break;
            case 3:
                user_search_product(session);
                break;
            case 4:
                user_search_orders(session);
                break;
            case 5:
                user_search_parcels(session);
                break;
            case 6:
                exit_flag = 1;
                break;
        }
    }
}

/// Edit current logged in user's credentials.
/// \param session Current user session
/// \return -1 if the user deleted its account; otherwise 0.
int user_edit_credentials(Member *session) {
    MemberList *members = member_get_all();

    int menu = 0, exit_flag = 0;
    Language lang = lang_korean();

    while (!exit_flag) {
        char masked_password[101], temp_password[101], temp_password_re[101];
        strcpy(masked_password, session->password);
        string_mask(masked_password, '*');

        printf(lang.user_info_edit_title);
        printf(lang.user_info_1_name, session->name);
        printf(lang.user_info_2_password, masked_password);
        printf(lang.user_info_3_address, session->address);
        printf(lang.user_info_4_delete);
        printf(lang.user_info_5_exit);
        printf(lang.message_select);

        menu = scan_valid_int(1, 5, lang.error_out_of_range, lang.message_select);

        CLEAR_INPUT_BUFFER;

        switch (menu) {
            case 1: // New name
                printf(lang.user_new_name);
                scan_valid_string(session->name, lang.error_invalid_string, lang.user_new_name);
                printf(lang.user_new_name_saved);
                break;
            case 2: // New password
                // Check current password
                printf(lang.user_current_password);
                do { // Password match check
                    fgets(temp_password, 1000, stdin);
                    temp_password[strlen(temp_password) - 1] = '\0';
                    if (strcmp(temp_password, session->password) != 0) {
                        printf(lang.error_password_mismatch);
                        printf(lang.user_current_password);
                    }
                } while (strcmp(temp_password, session->password) != 0);

                // Input new password
                printf(lang.user_new_password);
                scan_valid_string(temp_password, lang.error_invalid_string, lang.user_new_password);

                // Reinput new password
                printf(lang.user_new_password_confirm);
                do { // Password match check
                    fgets(temp_password_re, 1000, stdin);
                    temp_password_re[strlen(temp_password_re) - 1] = '\0';
                    if (strcmp(temp_password_re, temp_password) != 0) {
                        printf(lang.error_password_mismatch);
                        printf(lang.user_new_password_confirm);
                    }
                } while (strcmp(temp_password_re, temp_password) != 0);

                strcpy(session->password, temp_password);
                printf(lang.user_new_password_saved);
                break;
            case 3: // New address
                printf(lang.user_new_address);
                scan_valid_string(session->address, lang.error_invalid_string, lang.user_new_address);
                printf(lang.user_new_address_saved);
                break;
            case 4: // Delete account
                printf(lang.user_info_delete_confirm);
                if (scan_valid_boolean(lang.error_invalid_string, lang.user_info_delete_confirm)) {
                    session->state = Unregistered;
                    printf(lang.user_info_deleted);
                }
                break;
            case 5:
                exit_flag = 1;
                break;
        }

        // Save member to list
        member_list_set(members, *session, session->_idx);
        member_put_all(members);

        if (menu == 4 && session->state == Unregistered) {
            list_free(members, MemberType);
            return 1;
        }

    }

    list_free(members, MemberType);
    return 0;
}

/// Modify current logged in user's account balance.
/// \param session Current user session
void user_edit_balance(Member *session) {
    MemberList *members = member_get_all();

    int exit_flag = 0, temp = 0;
    Language lang = lang_korean();

    while (!exit_flag) {
        printf(lang.user_balance_title);
        printf(lang.user_balance_message, session->balance);
        printf(lang.message_separator);
        printf(lang.user_balance_1_deposit);
        printf(lang.user_balance_2_withdraw);
        printf(lang.user_balance_3_exit);
        printf(lang.message_select);

        int menu = scan_valid_int(1, 3, lang.error_out_of_range, lang.message_select);

        switch (menu) {
            case 1:
                printf(lang.user_balance_deposit_message);
                temp = scan_valid_int(0, 2000000000 - session->balance, lang.error_out_of_range, lang.user_balance_deposit_message);
                session->balance += temp;
                printf(lang.user_balance_deposit_complete);
                break;
            case 2:
                printf(lang.user_balance_withdrawal_message);
                do {
                    temp = scan_valid_int(0, 2000000000, lang.error_out_of_range, lang.user_balance_withdrawal_message);
                    if (temp > session->balance) {
                        printf(lang.error_insufficient_funds);
                        printf(lang.user_balance_withdrawal_message);
                    }
                } while (temp > session->balance);
                session->balance -= temp;
                printf(lang.user_balance_withdrawal_complete);
                break;
            case 3:
                exit_flag = 1;
                break;
        }

        // Save member to list
        member_list_set(members, *session, session->_idx);
        member_put_all(members);
    }

    list_free(members, MemberType);
}

/// Search products to purchase.
/// \param session Current user session
void user_search_product(Member *session) {
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
                queried = product_query_by_name(products, string_trim(query), 0);
                break;
            case 2:
                printf(lang.message_search);
                fgets(query, 100, stdin);
                queried = product_query_by_category(products, string_trim(query), 0);
                break;
            case 3:
                printf(lang.message_minimum_price);
                min = scan_valid_int(0, 2000000000, lang.error_out_of_range, lang.message_minimum_price);
                printf(lang.message_maximum_price);
                max = scan_valid_int(min, 2000000000, lang.error_out_of_range, lang.message_minimum_price);
                queried = product_query_by_price(products, min, max, 0);
                break;
            case 4:
                queried = product_query_available(products, 0);
                break;
            case 5:
                exit_flag = 1;
                break;
        }

        if (menu != 5) {
            user_product_list(session, queried);
            list_free(queried, ProductType);
        }
    }

    list_free(products, ProductType);
}

/// Show queried product list by user.
/// \param session Current user session
/// \param products Queried products
void user_product_list(Member *session, ProductList *products) {
    Language lang = lang_korean();
    int code = 0, exit_flag = 0;

    while (1) {
        Product selected = null_product;

        product_print_all(products, lang);
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

        user_lookup_product(session, selected);
    }
}

/// Show selected product by user.
/// \param session Current user session
/// \param product Selected product
void user_lookup_product(Member *session, Product product) {
    Language lang = lang_korean();
    int menu = 0, exit_flag = 0;

    while (!exit_flag) {
        printf(lang.product_code);
        printf("%d\n", product._idx);

        printf(lang.product_name);
        printf("%s\n", product.name);

        printf(lang.product_category);
        printf("%s\n", product.category);

        printf(lang.product_price, product.price);

        printf(lang.message_separator);

        printf(lang.product_purchase1_1_purchase);
        printf(lang.product_purchase1_2_exit);
        printf(lang.message_select);

        menu = scan_valid_int(1, 2, lang.error_out_of_range, lang.message_select);

        if (menu == 1) {
            user_purchase_product(session, product);
        } else {
            exit_flag = 1;
        }
    }
}

/// Begin purchase flow.
/// \param session Current user session
/// \param product Product to buy
void user_purchase_product(Member *session, Product product) {
    Language lang = lang_korean();
    int menu = 0, exit_flag = 0;

    while (!exit_flag) {
        printf(lang.user_balance_message, session->balance);
        printf(lang.product_purchase2_price, product.price);

        if (product.price > session->balance) {
            printf(lang.product_purchase2_needed_funds, product.price - session->balance);
            printf(lang.message_separator);
            printf(lang.product_purchase2_1_deposit);
        } else {
            printf(lang.product_purchase2_after_funds, session->balance - product.price);
            printf(lang.message_separator);
            printf(lang.product_purchase2_1_purchase);
        }
        printf(lang.product_purchase2_2_exit);
        printf(lang.message_select);

        menu = scan_valid_int(1, 2, lang.error_out_of_range, lang.message_select);

        if (menu == 1) {
            if (product.price > session->balance) {
                user_edit_balance(session);
            } else {
                MemberList *members = member_get_all();
                session->balance -= product.price;
                member_list_set(members, *session, session->_idx);
                member_put_all(members);
                list_free(members, MemberType);

                OrderList *orders = order_get_all();
                OrderHistory current_order;
                current_order._idx = orders->size + 1;
                current_order.product_idx = product._idx;
                current_order.member_idx = session->_idx;
                current_order.state = DeliverReady;

                order_list_append(orders, current_order);
                order_put_all(orders);
                list_free(orders, OrderType);

                printf(lang.product_purchase_complete);
                exit_flag = 1;
            }
        } else {
            exit_flag = 1;
        }
    }
}

/// Search orders.
/// \param session Current user session
void user_search_orders(Member *session) {
    Language lang = lang_korean();
    ProductList *products = product_get_all();
    OrderList *orders = order_get_all();
    OrderList *my_orders = order_query_by_member_id(orders, session->_idx);

    printf(lang.order_status_title);

    if (my_orders->size == 0) {
        printf(lang.error_no_results);
        return;
    }

    OrderNode *x = my_orders->head;
    do {
        printf(lang.order_idx);
        printf("%d\n", x->order._idx);

        printf(lang.product_code);
        printf("%d\n", x->order.product_idx);

        Product product = product_list_get_by_code(products, x->order.product_idx);

        printf(lang.product_name);
        printf("%s\n", product.name);

        printf(lang.product_category);
        printf("%s\n", product.category);

        printf(lang.product_price, product.price);

        printf(lang.message_separator);
        x = x->next_ptr;
    } while (x != NULL);

    list_free(orders, OrderType);
    list_free(my_orders, OrderType);
    list_free(products, ProductType);
}

/// Search parcels.
/// \param session Current user session
void user_search_parcels(Member *session) {
    Language lang = lang_korean();
    ProductList *products = product_get_all();
    OrderList *orders = order_get_all();
    OrderList *my_orders = order_query_by_member_id(orders, session->_idx);

    printf(lang.parcel_status_title);

    if (my_orders->size == 0) {
        printf(lang.error_no_results);
        return;
    }

    OrderNode *x = my_orders->head;
    do {
        printf(lang.order_idx);
        printf("%d\n", x->order._idx);

        printf(lang.product_code);
        printf("%d\n", x->order.product_idx);

        Product product = product_list_get_by_code(products, x->order.product_idx);

        printf(lang.product_name);
        printf("%s\n", product.name);

        printf(lang.parcel_status);
        switch (x->order.state) {
            case DeliverReady:
                printf(lang.parcel_status_ready);
                break;
            case Delivering:
                printf(lang.parcel_status_delivering);
                break;
            case Delivered:
                printf(lang.parcel_status_delivered);
                break;
        }
        printf("\n");

        printf(lang.message_separator);
        x = x->next_ptr;
    } while (x != NULL);

    list_free(orders, OrderType);
    list_free(my_orders, OrderType);
    list_free(products, ProductType);
}