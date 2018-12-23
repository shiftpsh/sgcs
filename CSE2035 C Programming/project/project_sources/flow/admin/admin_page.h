//
// Created by Suhyun Park on 2018-12-04.
//

#ifndef CP_PROJECT_ADMIN_PAGE_H
#define CP_PROJECT_ADMIN_PAGE_H

#include "../../types/product.h"
#include "../../types/order.h"

void admin_page();

void admin_lookup_customers();

void admin_add_or_delete_products();

void admin_add_product();

void admin_remove_product();

void admin_edit_products();

void admin_edit_product(Product product);

void admin_search_product();

void admin_product_list(ProductList *products);

void admin_lookup_product(Product product);

void admin_lookup_orders();

void admin_order_list(OrderList* orders);

void admin_lookup_parcel_status();

void admin_order_list_select_to_edit(OrderList* orders);

void admin_edit_parcel_status(OrderHistory order);

#endif //CP_PROJECT_ADMIN_PAGE_H
