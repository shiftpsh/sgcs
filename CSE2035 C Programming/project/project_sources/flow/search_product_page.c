//
// Created by Suhyun Park on 2018-12-08.
//

#include <stdio.h>
#include "../util/util_io.h"
#include "../util/util_string.h"
#include "../types/product.h"
#include "main_menu.h"
#include "search_product_page.h"

/// Search products. Does not require login.
void search_product_page() {
    ProductList *products = product_get_all(), *queried = NULL;
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
            product_print_all(products, lang);
            list_free(queried, ProductType);
        }
    }

    list_free(products, ProductType);

    main_menu();
}