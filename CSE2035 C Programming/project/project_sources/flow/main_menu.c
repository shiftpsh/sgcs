//
// Created by Suhyun Park on 02/12/2018.
//

#include <stdio.h>
#include "../language.h"
#include "../util/util_io.h"
#include "admin/admin_login_page.h"
#include "user/register_page.h"
#include "user/login_page.h"
#include "main_menu.h"
#include "search_product_page.h"

/// Main menu flow.
void main_menu() {
    Language lang = lang_korean();

    printf(lang.main_menu_title);
    printf(lang.main_menu_1_login);
    printf(lang.main_menu_2_signup);
    printf(lang.main_menu_3_search);
    printf(lang.main_menu_4_admin_login);
    printf(lang.main_menu_5_quit);
    printf(lang.message_select);

    int menu = scan_valid_int(1, 5, lang.error_out_of_range, lang.message_select);

    switch (menu) {
        case 1:
            login_page();
            break;
        case 2:
            register_page();
            break;
        case 3:
            search_product_page();
            break;
        case 4:
            admin_login_page();
            break;
        case 5:
            return;
    }
}