#ifndef DOUBLE_LINKED_LIST_H
#define DOUBLE_LINKED_LIST_H

struct node {
    int val;
    struct node* prev;
    struct node* next;
};

struct double_linked_list {
    struct node* head;
    struct node* tail;
    int size;
};

struct double_linked_list create_list();

int is_empty(struct double_linked_list* list);

int size(struct double_linked_list* list);

int insert_at(struct double_linked_list* list, int pos, int val);

int insert_at_head(struct double_linked_list* list, int val);

int insert_at_tail(struct double_linked_list* list, int val);

int get_at_pos(struct double_linked_list* list, int pos, int* out_val);

int get_head(struct double_linked_list* list, int* out_val);

int get_tail(struct double_linked_list* list, int* out_val);

int delete_at(struct double_linked_list* list, int pos);

int delete_head(struct double_linked_list* list);

int delete_tail(struct double_linked_list* list);

int delete_with_val(struct double_linked_list* list, int val);

void clear(struct double_linked_list* list);

void print_list(struct double_linked_list* list);

#endif