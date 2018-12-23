//
// Created by Suhyun Park on 2018-12-04.
//

#include <stdio.h>
#include <memory.h>
#include "../../language.h"
#include "../main_menu.h"
#include "admin_login_page.h"
#include "admin_page.h"

void admin_login_page() {
    Language lang = lang_korean();

    char try_id[100], try_password[100];
    int flag = 0;

    printf(lang.admin_login_title);

    for (int i = 3; i >= 0; i--) {
        if (i) {
            printf(lang.login_id);
            scanf("%s", try_id);
            printf(lang.login_password);
            scanf("%s", try_password);

            // Because who cares about security?
            if (strcmp(try_id, "admin") || strcmp(try_password, "password")) {
                printf(lang.error_credentials_mismatch);
            } else {
                flag = 1;
                break;
            }
        } else {
            printf(lang.error_login_failed);
        }
    }

    if (flag) {
        admin_page();
    } else {
        main_menu();
    }
}