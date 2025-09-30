#include <stdio.h>
#include <stdlib.h>
#include <double_linked_list.h>

struct double_linked_list create_list() {
    struct double_linked_list new_list = {NULL, NULL, 0};
    return new_list;
}

int is_empty(struct double_linked_list* list) {
    return list->size == 0;
}

int size(struct double_linked_list* list) {
    return list->size;
}

struct node* get_node_at(struct double_linked_list* list, int pos) {
    if (pos < 0 || pos >= list->size) return NULL;

    struct node* cur;
    if (pos < list->size / 2) {
        cur = list->head;
        for (int i = 0; i < pos; i++) cur = cur->next;
    } else {
        cur = list->tail;
        for (int i = list->size - 1; i > pos; i--) cur = cur->prev;
    }
    return cur;
}

struct node* get_first_node_with_val(struct double_linked_list* list, int val) {
    struct node* cur = list->head;
    while (cur) {
        if (cur->val == val) return cur;
        cur = cur->next;
    }
    return NULL;
}

int insert_at(struct double_linked_list* list, int pos, int val) {
    if (pos < 0 || pos > list->size) return -1;

    struct node* new_node = malloc(sizeof(struct node));
    if (!new_node) return -1;

    new_node->val = val;
    new_node->prev = new_node->next = NULL;

    if (list->size == 0) {
        list->head = list->tail = new_node;
    } else if (pos == 0) {
        new_node->next = list->head;
        list->head->prev = new_node;
        list->head = new_node;
    } else if (pos == list->size) {
        new_node->prev = list->tail;
        list->tail->next = new_node;
        list->tail = new_node;
    } else { // insert in middle
        struct node* node_at_pos = get_node_at(list, pos);
        new_node->prev = node_at_pos->prev;
        new_node->next = node_at_pos;
        node_at_pos->prev->next = new_node;
        node_at_pos->prev = new_node;
    }

    list->size++;
    return 0;
}

int insert_at_head(struct double_linked_list* list, int val) {
    return insert_at(list, 0, val);
}

int insert_at_tail(struct double_linked_list* list, int val) {
    return insert_at(list, list->size, val);
}

int get_at_pos(struct double_linked_list* list, int pos, int* out_val) {
    struct node* n = get_node_at(list, pos);
    if (!n) return -1;
    *out_val = n->val;
    return 0;
}

int get_head(struct double_linked_list* list, int* out_val) {
    if (is_empty(list)) return -1;
    *out_val = list->head->val;
    return 0;
}

int get_tail(struct double_linked_list* list, int* out_val) {
    if (is_empty(list)) return -1;
    *out_val = list->tail->val;
    return 0;
}

int delete_at(struct double_linked_list* list, int pos) {
    if (pos < 0 || pos >= list->size) return -1;

    struct node* to_delete = get_node_at(list, pos);

    if (list->size == 1) {
        list->head = list->tail = NULL;
    } else if (pos == 0) {
        list->head = list->head->next;
        list->head->prev = NULL;
    } else if (pos == list->size - 1) {
        list->tail = list->tail->prev;
        list->tail->next = NULL;
    } else {
        to_delete->prev->next = to_delete->next;
        to_delete->next->prev = to_delete->prev;
    }

    free(to_delete);
    list->size--;
    return 0;
}

int delete_head(struct double_linked_list* list) {
    return delete_at(list, 0);
}

int delete_tail(struct double_linked_list* list) {
    return delete_at(list, list->size - 1);
}

int delete_with_val(struct double_linked_list* list, int val) {
    struct node* n = get_first_node_with_val(list, val);
    if (!n) return -1;

    if (n == list->head) return delete_head(list);
    if (n == list->tail) return delete_tail(list);

    n->prev->next = n->next;
    n->next->prev = n->prev;
    free(n);
    list->size--;
    return 0;
}

void clear(struct double_linked_list* list) {
    struct node* cur = list->head;
    while (cur) {
        struct node* next = cur->next;
        free(cur);
        cur = next;
    }
    list->head = list->tail = NULL;
    list->size = 0;
}

void print_list(struct double_linked_list* list) {
    struct node* cur = list->head;
    printf("[");
    while (cur) {
        printf("%d", cur->val);
        if (cur->next) printf(" <-> ");
        cur = cur->next;
    }
    printf("]\n");
}