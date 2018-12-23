#include "language.h"

/// Get Korean locale strings.
/// \return Korean locale strings
Language lang_korean() {
    Language lang;

    lang.message_select = "선택: ";
    lang.message_search = "검색: ";
    lang.message_minimum_price = "최소 가격: ";
    lang.message_maximum_price = "최대 가격: ";
    lang.message_separator = "----------------------------------------\n";

    lang.error_too_long = "입력한 값이 너무 깁니다.\n";
    lang.error_out_of_range = "입력 범위를 벗어났습니다.\n";
    lang.error_invalid_string = "잘못된 입력입니다.\n";
    lang.error_credentials_mismatch = "회원 아이디 또는 비밀번호가 일치하지 않습니다.\n";
    lang.error_login_failed = "확인 후 다시 로그인을 시도하여 주세요.\n";
    lang.error_password_mismatch = "비밀번호가 일치하지 않습니다.\n";
    lang.error_id_confilct = "이미 사용 중인 아이디입니다.\n";
    lang.error_insufficient_funds = "잔액이 부족합니다.\n";
    lang.error_no_results = "일치하는 결과가 없습니다.\n";

    lang.member_idx = "회원번호: ";
    lang.member_id = "아이디: ";
    lang.member_name = "이름: ";
    lang.member_address = "주소: ";

    lang.product_code = "상품코드: ";
    lang.product_name = "상품명: ";
    lang.product_category = "카테고리: ";
    lang.product_price = "가격: %d원\n";
    lang.product_price_input = "가격: ";
    lang.product_status = "상품 상태: ";
    lang.product_status_ready = "판매 준비 중";
    lang.product_status_available = "판매 중";
    lang.product_sales = "판매량: ";

    lang.order_template = "주문번호: %d / 상품번호: %d\n";
    lang.order_idx = "주문번호: ";
    lang.parcel_status = "배송 상태: ";
    lang.parcel_status_ready = "배송 준비";
    lang.parcel_status_delivering = "배송 중";
    lang.parcel_status_delivered = "배송 완료";

    lang.main_menu_title = "\n====== SG-MALL에 오신 것을 환영합니다. ======\n";
    lang.main_menu_1_login = "1. 회원 로그인\n";
    lang.main_menu_2_signup = "2. 회원 가입\n";
    lang.main_menu_3_search = "3. 상품 검색\n";
    lang.main_menu_4_admin_login = "4. 관리자 로그인\n";
    lang.main_menu_5_quit = "5. 종료\n";

    lang.signup_title = "\n====== 회원 가입 ======\n";
    lang.signup_name = "이름: ";
    lang.signup_id = "아이디: ";
    lang.signup_password = "비밀번호: ";
    lang.signup_re_password = "비밀번호 확인: ";
    lang.signup_address = "주소: ";

    lang.login_title = "\n====== 회원 로그인 ======\n";
    lang.login_id = "아이디: ";
    lang.login_password = "비밀번호: ";

    lang.user_menu_title = "\n====== %s님, SG-MALL에 오신 것을 환영합니다. ======\n";
    lang.user_menu_1_edit = "1. 회원 정보 수정\n";
    lang.user_menu_2_bank = "2. 가상계좌 입금 및 출금\n";
    lang.user_menu_3_search = "3. 상품 검색\n";
    lang.user_menu_4_orders = "4. 구매 내역 조회\n";
    lang.user_menu_5_parcels = "5. 배송 내역 조회\n";
    lang.user_menu_6_logout = "6. 로그아웃 및 종료\n";

    lang.user_info_edit_title = "\n====== 회원 정보 수정 ======\n";
    lang.user_info_1_name = "1. 이름: %s\n";
    lang.user_info_2_password = "2. 비밀번호: %s\n";
    lang.user_info_3_address = "3. 주소: %s\n";
    lang.user_info_4_delete = "4. 회원 탈퇴\n";
    lang.user_info_5_exit = "5. 이전 화면으로 돌아가기\n";
    lang.user_new_name = "새 이름: ";
    lang.user_current_password = "현재 비밀번호: ";
    lang.user_new_password = "새 비밀번호: ";
    lang.user_new_password_confirm = "새 비밀번호 확인: ";
    lang.user_new_address = "새 주소: ";
    lang.user_info_delete_confirm = "정말 탈퇴하시겠습니까? (Y/n): ";
    lang.user_new_name_saved = "새 이름이 저장되었습니다.\n";
    lang.user_new_password_saved = "새 비밀번호가 저장되었습니다.\n";
    lang.user_new_address_saved = "새 주소가 저장되었습니다.\n";
    lang.user_info_deleted = "탈퇴가 완료되었습니다.\n";

    lang.user_balance_title = "\n====== 가상계좌 입금 및 출금 ======\n";
    lang.user_balance_message = "내 가상계좌 잔액: %d원\n";
    lang.user_balance_1_deposit = "1. 입금하기\n";
    lang.user_balance_2_withdraw = "2. 출금하기\n";
    lang.user_balance_3_exit = "3. 이전 화면으로 돌아가기\n";
    lang.user_balance_deposit_message = "입금 금액: ";
    lang.user_balance_deposit_complete = "입금이 완료되었습니다.\n";
    lang.user_balance_withdrawal_message = "출금 금액: ";
    lang.user_balance_withdrawal_complete = "출금이 완료되었습니다.\n";

    lang.product_search_title = "\n====== 상품 검색 ======\n";
    lang.product_search_1_by_name = "1. 이름으로 검색하기\n";
    lang.product_search_2_by_category = "2. 카테고리로 검색하기\n";
    lang.product_search_3_by_price = "3. 가격으로 검색하기\n";
    lang.product_search_4_all = "4. 전체 상품 보기\n";
    lang.product_search_5_exit = "5. 이전 화면으로 돌아가기\n";
    lang.product_list_0_exit = "0. 이전 화면으로 돌아가기\n";
    lang.product_purchase1_1_purchase = "1. 구매하기\n";
    lang.product_purchase1_2_exit = "2. 이전 화면으로 돌아가기\n";
    lang.product_purchase2_price = "상품 가격: %d원\n";
    lang.product_purchase2_needed_funds = "필요 금액: %d원\n";
    lang.product_purchase2_after_funds = "구매 후 잔액: %d원\n";
    lang.product_purchase2_1_deposit = "1. 가상계좌 입금하고 구매하기\n";
    lang.product_purchase2_1_purchase = "1. 구매하기\n";
    lang.product_purchase2_2_exit = "2. 이전 화면으로 돌아가기\n";
    lang.product_purchase_complete = "구매가 완료되었습니다.\n";

    lang.order_status_title = "\n====== 구매 내역 ======\n";
    lang.parcel_status_title = "\n====== 배송 내역 ======\n";

    lang.admin_login_title = "\n====== 관리자 로그인 ======\n";
    lang.admin_page_title = "\n====== SG-MALL 관리자 페이지 ======\n";
    lang.admin_page_1_lookup_customers = "1. 회원 정보 조회\n";
    lang.admin_page_2_add_or_remove_products = "2. 상품 등록 및 삭제\n";
    lang.admin_page_3_edit_products = "3. 상품 정보 수정\n";
    lang.admin_page_4_product_statistics = "4. 상품 조회 및 통계 보기\n";
    lang.admin_page_5_order_statistics = "5. 구매 내역 및 통계 보기\n";
    lang.admin_page_6_edit_parcel_status = "6. 배송 내역 수정\n";
    lang.admin_page_7_exit = "7. 로그아웃 및 종료\n";

    lang.admin_add_or_delete_products_title = "\n====== 상품 등록 및 삭제 ======\n";
    lang.admin_add_or_delete_products_1_add = "1. 상품 추가\n";
    lang.admin_add_or_delete_products_2_remove = "2. 상품 삭제\n";
    lang.admin_add_or_delete_products_3_back = "3. 이전 화면으로 돌아가기\n";
    lang.admin_add_product_title = "\n====== 상품 등록 ======\n";
    lang.admin_product_added = "상품이 등록되어 현재 판매 준비 중입니다.\n";
    lang.admin_product_enable = "상품을 즉시 판매 상태로 설정할까요? (Y/n): ";
    lang.admin_product_add_continue = "다른 상품을 계속 등록할까요? (Y/n): ";
    lang.admin_remove_product_title = "\n====== 상품 삭제 ======\n";
    lang.admin_product_removed = "상품이 삭제되었습니다.\n";
    lang.admin_product_remove_continue = "다른 상품을 계속 삭제할까요? (Y/n): ";

    lang.admin_edit_products_title = "\n====== 상품 수정 ======\n";
    lang.admin_edit_products_1_name = "1. 이름 수정\n";
    lang.admin_edit_products_2_category = "2. 카테고리 수정\n";
    lang.admin_edit_products_3_price = "3. 가격 수정\n";
    lang.admin_edit_products_4_state = "4. 상품 판매 상태 수정\n";
    lang.admin_edit_products_5_exit = "5. 이전 화면으로 돌아가기\n";
    lang.admin_product_new_name = "새 이름: ";
    lang.admin_product_new_category = "새 카테고리: ";
    lang.admin_product_new_price = "새 가격: ";
    lang.admin_product_new_state = "새 판매 상태 (Y/n): ";
    lang.admin_product_edited = "상품이 수정되었습니다.\n";
    lang.admin_product_edit_continue = "다른 상품을 계속 수정할까요? (Y/n): ";

    lang.admin_lookup_orders_title = "\n====== 구매 내역 및 통계 ======\n";
    lang.admin_lookup_orders_1_by_user_id = "1. 구매자 ID로 조회\n";
    lang.admin_lookup_orders_2_by_product_code = "2. 상품 코드로 조회\n";
    lang.admin_lookup_orders_3_undelivered = "3. 미배송된 주문 조회\n";
    lang.admin_lookup_orders_4_all = "4. 전체 주문 조회\n";
    lang.admin_lookup_orders_5_exit = "5. 이전 화면으로 돌아가기\n";
    lang.admin_lookup_orders_user_id = "구매자 ID: ";
    lang.admin_lookup_orders_product_code = "상품 코드: ";

    lang.admin_edit_parcel_status_title = "\n====== 배송 상태 수정 ======\n";
    lang.admin_edit_parcel_status_desc = "새 배송 상태:\n";
    lang.admin_edit_parcel_status_new_1_ready = "1. 배송 준비\n";
    lang.admin_edit_parcel_status_new_2_delivering = "2. 배송 중\n";
    lang.admin_edit_parcel_status_new_3_delivered = "3. 배송 완료\n";
    lang.admin_edit_parcel_status_new_4_exit = "4. 이전 화면으로 돌아가기\n";
    lang.admin_edit_parcel_complete = "배송 상태가 수정되었습니다.\n";

    return lang;
}