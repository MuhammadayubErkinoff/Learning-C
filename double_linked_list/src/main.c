#include <stdio.h>
#include <assert.h>
#include <double_linked_list.h>

int main() {
    struct double_linked_list list = create_list();
    int val;

    printf("=== Running double linked list tests ===\n");

    // Initially empty
    assert(is_empty(&list) == 1);
    assert(size(&list) == 0);

    // Insert at head
    insert_at_head(&list, 10);
    insert_at_head(&list, 20);
    insert_at_head(&list, 30); // list = [30,20,10]
    assert(size(&list) == 3);
    assert(get_head(&list, &val) == 0 && val == 30);
    assert(get_tail(&list, &val) == 0 && val == 10);

    // Insert at tail
    insert_at_tail(&list, 40);
    insert_at_tail(&list, 50); // list = [30,20,10,40,50]
    assert(size(&list) == 5);
    assert(get_tail(&list, &val) == 0 && val == 50);

    // Insert at middle
    insert_at(&list, 2, 99); // list = [30,20,99,10,40,50]
    assert(size(&list) == 6);
    assert(get_at_pos(&list, 2, &val) == 0 && val == 99);

    // Delete head
    delete_head(&list); // list = [20,99,10,40,50]
    assert(size(&list) == 5);
    assert(get_head(&list, &val) == 0 && val == 20);

    // Delete tail
    delete_tail(&list); // list = [20,99,10,40]
    assert(size(&list) == 4);
    assert(get_tail(&list, &val) == 0 && val == 40);

    // Delete middle element
    delete_at(&list, 1); // removes 99 → list = [20,10,40]
    assert(size(&list) == 3);
    assert(get_at_pos(&list, 1, &val) == 0 && val == 10);

    // Delete by value
    delete_with_val(&list, 10); // list = [20,40]
    assert(size(&list) == 2);
    assert(get_at_pos(&list, 1, &val) == 0 && val == 40);

    // Clear list
    clear(&list);
    assert(is_empty(&list) == 1);
    assert(size(&list) == 0);

    printf("✅ All tests passed!\n");
    return 0;
}