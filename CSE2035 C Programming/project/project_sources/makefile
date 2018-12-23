CC = gcc
CFAGS = -W -Wall
TARGET = proj1_20181634
OBJECTS = language.o \
		types/linked_list.o \
		types/product.o \
		types/member.o \
		types/order.o \
		util/util_io.o \
		util/util_string.o \
		util/util_file.o \
		flow/admin/admin_login_page.o \
		flow/admin/admin_page.o \
		flow/user/login_page.o \
		flow/user/register_page.o \
		flow/user/user_page.o \
		flow/search_product_page.o \
		flow/main_menu.o \
		proj1_20181634.o

all: $(TARGET)

$(TARGET): $(OBJECTS)
		$(CC) $(CFLAGS) -o $@ $^

clean : rm *.o cp_project_20181634