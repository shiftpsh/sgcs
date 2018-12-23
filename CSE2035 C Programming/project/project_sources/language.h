#ifndef LANGUAGE_H
#define LANGUAGE_H

typedef struct {
    char *message_select;
    char *message_search;
    char *message_minimum_price;
    char *message_maximum_price;
    char *message_separator;
    char *error_too_long;
    char *error_out_of_range;
    char *error_invalid_string;
    char *error_credentials_mismatch;
    char *error_login_failed;
    char *error_password_mismatch;
    char *error_id_confilct;
    char *error_insufficient_funds;
    char *error_no_results;

    // Customer
    char *member_idx;
    char *member_id;
    char *member_name;
    char *member_address;

    // Product
    char *product_code;
    char *product_name;
    char *product_category;
    char *product_price;
    char *product_price_input;
    char *product_status;
    char *product_status_ready;
    char *product_status_available;
    char *product_sales;

    // Order
    char *order_template;
    char *order_idx;
    char *parcel_status;
    char *parcel_status_ready;
    char *parcel_status_delivering;
    char *parcel_status_delivered;

    // Main menu
    char *main_menu_title;
    char *main_menu_1_login;
    char *main_menu_2_signup;
    char *main_menu_3_search;
    char *main_menu_4_admin_login;
    char *main_menu_5_quit;

    // Signup page
    char *signup_title;
    char *signup_id;
    char *signup_name;
    char *signup_password;
    char *signup_re_password;
    char *signup_address;

    // Login page
    char *login_title;
    char *login_id;
    char *login_password;

    // User page
    char *user_menu_title;
    char *user_menu_1_edit;
    char *user_menu_2_bank;
    char *user_menu_3_search;
    char *user_menu_4_orders;
    char *user_menu_5_parcels;
    char *user_menu_6_logout;

    // User info edit
    char *user_info_edit_title;
    char *user_info_1_name;
    char *user_info_2_password;
    char *user_info_3_address;
    char *user_info_4_delete;
    char *user_info_5_exit;
    char *user_current_password;
    char *user_new_name;
    char *user_new_password;
    char *user_new_password_confirm;
    char *user_new_address;
    char *user_info_delete_confirm;
    char *user_new_name_saved;
    char *user_new_password_saved;
    char *user_new_address_saved;
    char *user_info_deleted;

    // User account balance
    char *user_balance_title;
    char *user_balance_message;
    char *user_balance_1_deposit;
    char *user_balance_2_withdraw;
    char *user_balance_3_exit;
    char *user_balance_deposit_message;
    char *user_balance_deposit_complete;
    char *user_balance_withdrawal_message;
    char *user_balance_withdrawal_complete;

    // Find products, purchase products
    char *product_search_title;
    char *product_search_1_by_name;
    char *product_search_2_by_category;
    char *product_search_3_by_price;
    char *product_search_4_all;
    char *product_search_5_exit;
    char *product_list_0_exit;
    char *product_purchase1_1_purchase;
    char *product_purchase1_2_exit;
    char *product_purchase2_price;
    char *product_purchase2_needed_funds;
    char *product_purchase2_after_funds;
    char *product_purchase2_1_deposit;
    char *product_purchase2_1_purchase;
    char *product_purchase2_2_exit;
    char *product_purchase_complete;

    // view order and parcel status
    char *order_status_title;
    char *parcel_status_title;

    // Admin-related
    char *admin_login_title;
    char *admin_page_title;
    char *admin_page_1_lookup_customers;
    char *admin_page_2_add_or_remove_products;
    char *admin_page_3_edit_products;
    char *admin_page_4_product_statistics;
    char *admin_page_5_order_statistics;
    char *admin_page_6_edit_parcel_status;
    char *admin_page_7_exit;

    // Add/delete products
    char *admin_add_or_delete_products_title;
    char *admin_add_or_delete_products_1_add;
    char *admin_add_or_delete_products_2_remove;
    char *admin_add_or_delete_products_3_back;
    char *admin_add_product_title;
    char *admin_product_added;
    char *admin_product_enable;
    char *admin_product_add_continue;
    char *admin_remove_product_title;
    char *admin_product_removed;
    char *admin_product_remove_continue;

    // Edit products
    char *admin_edit_products_title;
    char *admin_edit_products_1_name;
    char *admin_edit_products_2_category;
    char *admin_edit_products_3_price;
    char *admin_edit_products_4_state;
    char *admin_edit_products_5_exit;
    char *admin_product_new_name;
    char *admin_product_new_category;
    char *admin_product_new_price;
    char *admin_product_new_state;
    char *admin_product_edited;
    char *admin_product_edit_continue;

    // Lookup orders
    char *admin_lookup_orders_title;
    char *admin_lookup_orders_1_by_user_id;
    char *admin_lookup_orders_2_by_product_code;
    char *admin_lookup_orders_3_undelivered;
    char *admin_lookup_orders_4_all;
    char *admin_lookup_orders_5_exit;
    char *admin_lookup_orders_user_id;
    char *admin_lookup_orders_product_code;

    // Edit parcel status
    char *admin_edit_parcel_status_title;
    char *admin_edit_parcel_status_desc;
    char *admin_edit_parcel_status_new_1_ready;
    char *admin_edit_parcel_status_new_2_delivering;
    char *admin_edit_parcel_status_new_3_delivered;
    char *admin_edit_parcel_status_new_4_exit;
    char *admin_edit_parcel_complete;
} Language;

Language lang_korean();

#endif