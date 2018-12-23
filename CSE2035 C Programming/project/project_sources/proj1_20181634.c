#define _CRT_SECURE_NO_WARNINGS

#include "util/util_file.h"
#include "flow/main_menu.h"
#include "proj1_20181634.h"

/// Setup the program.
int main() {
    initialize();
    main_menu();

    return 0;
}

/// Initializes the database needed to run the program.
void initialize() {
    if (!file_exists("customer.csv")) {
        file_writeln("customer.csv", "회원번호,아이디,비밀번호,이름,주소,잔액,상태");
    }
    if (!file_exists("product.csv")) {
        file_writeln("product.csv", "상품번호,상품명,카테고리,가격,상태");
    }
    if (!file_exists("history.csv")) {
        file_writeln("history.csv", "주문번호,상품번호,회원번호,배송현황");
    }
}
