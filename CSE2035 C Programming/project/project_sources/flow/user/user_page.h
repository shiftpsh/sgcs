//
// Created by Suhyun Park on 02/12/2018.
//

#ifndef CP_PROJECT_USER_PAGE_H
#define CP_PROJECT_USER_PAGE_H

#include "../../types/member.h"
#include "../../types/product.h"

void user_page(Member *session);

int user_edit_credentials(Member *session);

void user_edit_balance(Member *session);

void user_search_product(Member *session);

void user_product_list(Member *session, ProductList *products);

void user_lookup_product(Member *session, Product product);

void user_purchase_product(Member *session, Product product);

void user_search_orders(Member *session);

void user_search_parcels(Member *session);

#endif //CP_PROJECT_USER_PAGE_H
