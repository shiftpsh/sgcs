//
// Created by Suhyun Park on 13/11/2018.
//

#include <memory.h>
#include <stdlib.h>
#include <stdio.h>
#include "../util/util_string.h"
#include "member.h"

// TODO implement sorting

/// Serialize a member.
/// \param [out] str String to be appended the serialized member
/// \param member Member to serialize
void member_serialize(char *str, Member member) {
    char temp[20];
    str[0] = '\0';

    string_itoa(temp, member._idx);
    strcat(str, temp);
    strcat(str, ",");
    strcat(str, member.id);
    strcat(str, ",");
    strcat(str, member.password);
    strcat(str, ",");
    strcat(str, member.name);
    strcat(str, ",");
    strcat(str, member.address);
    strcat(str, ",");
    string_itoa(temp, member.balance);
    strcat(str, temp);
    strcat(str, ",");
    string_itoa(temp, member.state);
    strcat(str, temp);
}

/// Parse a member.
/// \param str String to be parsed
/// \return Parsed member
Member parse_member(char *str) {
    char *token;

    Member m;

    token = strtok(str, ",");
    m._idx = atoi(token);

    token = strtok(NULL, ",");
    strcpy(m.id, token);

    token = strtok(NULL, ",");
    strcpy(m.password, token);

    token = strtok(NULL, ",");
    strcpy(m.name, token);

    token = strtok(NULL, ",");
    strcpy(m.address, token);

    token = strtok(NULL, ",");
    m.balance = atoi(token);

    token = strtok(NULL, ",");
    m.state = atoi(token);

    return m;
}

/// Create a MemberList.
/// \return New MemberList
MemberList *member_list_create() {
    return list_create();
}

/// Append a Member to the MemberList.
/// \param [out] list MemberList to be appended
/// \param member Member to append
void member_list_append(MemberList *list, Member member) {
    MemberNode *node = (MemberNode *) malloc(sizeof(MemberNode));
    node->member = member;
    node->next_ptr = NULL;

    list_append(list, MemberType, node);
}

/// Remove last Member from a MemberList.
/// \param [out] list MemberList to remove last Member
void member_list_removelast(MemberList *list) {
    list_removelast(list, MemberType);
}

/// Get Member from MemberList at specific index.
/// \param list MemberList to find the Member
/// \param idx Index of the member to get
/// \return Member at index idx if exists, null_member otherwise
Member member_list_get(MemberList *list, int idx) {
    if (idx < 0) return null_member;
    if (list->size <= idx) return null_member;
    return ((MemberNode *) list_get(list, MemberType, idx))->member;
}

/// Set member in MemberList at specific index.
/// \param [out] list MemberList to set the Member
/// \param member Updated Member
/// \param idx Index of the member to update
void member_list_set(MemberList *list, Member member, int idx) {
    list_set(list, MemberType, &member, idx);
}

/// Find if a Member exists in MemberList by specific ID.
/// \param list MemberList to find the Member
/// \param id ID of the member to find
/// \return 1 if such member exists; 0 otherwise
int member_id_exists(MemberList *list, char *id) {
    if (list->size == 0) return 0;

    MemberNode *x = list->head;
    do {
        if (strcmp(x->member.id, id) == 0) return 1;
        x = x->next_ptr;
    } while (x != NULL);

    return 0;
}

/// Find a Member by its ID.
/// \param list MemberList to find the Member
/// \param id ID of the member to find
/// \return Member with ID id if exists; null_member otherwise
Member member_with_id(MemberList *list, char *id) {
    if (list->size == 0) return null_member;

    MemberNode *x = list->head;
    do {
        if (strcmp(x->member.id, id) == 0) return x->member;
        x = x->next_ptr;
    } while (x != NULL);

    return null_member;
}

/// Get all members in customer.csv.
/// \return All members in customer.csv
MemberList *member_get_all() {
    char buffer[701];
    MemberList *list = member_list_create();
    FILE *fptr = fopen("customer.csv", "r");

    fgets(buffer, 700, fptr); // Ignore first line

    while (fgets(buffer, 700, fptr) != NULL) {
        int l = (int) strlen(buffer);
        if (buffer[l] == '\n') buffer[l] = '\0';

        Member member = parse_member(buffer);
        member_list_append(list, member);
    }

    fclose(fptr);

    return list;
}

void member_print_all(MemberList *list, Language lang) {
    if (list->size == 0) {
        printf(lang.error_no_results);
        return;
    }

    MemberNode *x = list->head;
    do {
        printf(lang.member_idx);
        printf("%d\n", x->member._idx);

        printf(lang.member_id);
        printf("%s\n", x->member.id);

        printf(lang.member_name);
        printf("%s\n", x->member.name);

        printf(lang.member_address);
        printf("%s\n", x->member.address);

        printf(lang.message_separator);
        x = x->next_ptr;
    } while (x != NULL);
}

/// Save all members in MemberList to customer.csv.
/// \param list MemberList to save
void member_put_all(MemberList *list) {
    if (list->size == 0) return;

    char buffer[701];
    FILE *fptr = fopen("customer.csv", "w");
    fputs("회원번호,아이디,비밀번호,이름,주소,잔액,상태", fptr);
    fputs("\n", fptr);

    MemberNode *x = list->head;
    do {
        member_serialize(buffer, x->member);
        fputs(buffer, fptr);
        fputs("\n", fptr);
        x = x->next_ptr;
    } while (x != NULL);

    fclose(fptr);
}