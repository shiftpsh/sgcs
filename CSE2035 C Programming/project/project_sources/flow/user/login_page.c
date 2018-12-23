//
// Created by Suhyun Park on 02/12/2018.
//

#include <stdio.h>
#include <memory.h>
#include "../../language.h"
#include "../../types/member.h"
#include "../main_menu.h"
#include "login_page.h"
#include "user_page.h"

/// Login page flow.
void login_page() {
    MemberList *members = member_get_all();
    Language lang = lang_korean();

    char try_id[100], try_password[100];
    Member session;
    int flag = 0;

    printf(lang.login_title);

    for (int i = 3; i >= 0; i--) {
        if (i) {
            printf(lang.login_id);
            scanf("%s", try_id);
            printf(lang.login_password);
            scanf("%s", try_password);

            session = member_with_id(members, try_id);
            if (session._idx != -1) {
                if (strcmp(session.password, try_password) == 0
                    && session.state != Unregistered) {
                    flag = 1;
                    break;
                } else {
                    printf(lang.error_credentials_mismatch);
                }
            } else {
                printf(lang.error_credentials_mismatch);
            }
        } else {
            printf(lang.error_login_failed);
        }
    }

    list_free(members, MemberType);

    if (flag) {
        user_page(&session);
    } else {
        main_menu();
    }
}