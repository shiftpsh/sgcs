//
// Created by Suhyun Park on 13/11/2018.
//

#ifndef PROJECT1_MEMBER_H
#define PROJECT1_MEMBER_H

#include "../language.h"
#include "linked_list.h"

typedef enum {
    Unregistered = -1, Registered = 1
} MemberState;

typedef struct {
    int _idx;
    char id[101];
    char password[101];
    char name[101];
    char address[301];
    int balance;
    MemberState state;
} Member;

typedef struct __member_node {
    Member member;
    struct __member_node *next_ptr;
} MemberNode;

typedef LinkedList MemberList;

#define null_member (Member) {-1}

void member_serialize(char *str, Member member);

Member parse_member(char *str);

MemberList *member_list_create();

void member_list_append(MemberList *list, Member member);

void member_list_removelast(MemberList *list);

Member member_list_get(MemberList *list, int idx);

void member_list_set(MemberList *list, Member member, int idx);

int member_id_exists(MemberList *list, char *id);

Member member_with_id(MemberList *list, char *id);

MemberList *member_get_all();

void member_print_all(MemberList *list, Language lang);

void member_put_all(MemberList *list);

#endif //PROJECT1_MEMBER_H
