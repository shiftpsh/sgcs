//
// Created by Suhyun Park on 02/12/2018.
//

#include <stdio.h>
#include <memory.h>
#include "../../util/util_string.h"
#include "../../util/util_io.h"
#include "../../types/member.h"
#include "register_page.h"
#include "user_page.h"

/// Register page flow.
void register_page() {
    MemberList *members = member_get_all();
    Member m;
    Language lang = lang_korean();
    char temp[1001];
    temp[0] = '\0';

    printf(lang.signup_title);

    // for some reason strcpy acts weird initially
    strcpy(m.name, "");

    CLEAR_INPUT_BUFFER;

    printf(lang.signup_name);
    scan_valid_string(m.name, lang.error_invalid_string, lang.signup_name);

    printf(lang.signup_id);
    do { // ID conflict check
        scan_valid_id(m.id, lang.error_invalid_string, lang.signup_id);
        if (member_id_exists(members, m.id)) {
            printf(lang.error_id_confilct);
            printf(lang.signup_id);
        }
    } while (member_id_exists(members, m.id));

    printf(lang.signup_password);
    scan_valid_string(m.password, lang.error_invalid_string, lang.signup_password);

    printf(lang.signup_re_password);
    do { // Password match check
        fgets(temp, 1000, stdin);
        temp[strlen(temp) - 1] = '\0';
        if (strcmp(temp, m.password) != 0) {
            printf(lang.error_password_mismatch);
            printf(lang.signup_re_password);
        }
    } while (strcmp(temp, m.password) != 0);

    printf(lang.signup_address);
    scan_valid_string(m.address, lang.error_invalid_string, lang.signup_address);

    m._idx = members->size + 1;
    m.balance = 0;
    m.state = Registered;

    member_list_append(members, m);
    member_put_all(members);

    list_free(members, MemberType);

    user_page(&m);
}
