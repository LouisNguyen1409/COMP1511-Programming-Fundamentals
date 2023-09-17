// Program to do various linked list exercises
// <CLASS>, <MONTH YEAR>

#include <stdio.h>
#include <stdlib.h>

#include "list.h"

int main(void) {
    struct node *list1 = append_node(NULL, 3);
    append_node(list1, 1);
    append_node(list1, 4);
    struct node *list2 = append_node(NULL, 1);
    append_node(list2, 5);
    append_node(list2, 9);

    struct node *list1_copy = copy(list1);
    
    // Task 4: Use the append function to create a list containing the
    // nodes of list1 followed by the nodes of list2 and print the
    // list
    // The list should be
    // 3 -> 1 -> 4 -> 1 -> 5 -> 9 -> X
    // Print list1, list2 and the joined list using
    // print_list_with_addresses function to ensure that
    // they are different
    free_list(list1);
    free_list(list2);
    // Task 5: Deal with the final memory leak!
    return 0;
}

/** PRESCRIBED FUNCTIONS **/
struct node *append_node(struct node *head, int data) {
    struct node *new_node = create_node(data);
    if (head == NULL) {
        return new_node;
    }
    struct node *curr = head;
    while (curr->next != NULL) {
        curr = curr->next;
    }
    curr->next = new_node;
    return head;
}

// Task 2: Implement the copy function
// Returns a copy of the list
struct node *copy(struct node *list) {
    if (list == NULL) {
        return NULL;
    }

    struct node *list_copy = create_node(list->data);
    struct node *curr_copy = list_copy;
    struct noode *curr = list->next; 
    while (current != NULL) {

        current = current->next;
    }
    return NULL;
}

// Task 3: Implement the append function
// Returns a list containing a copy of list2 appended to a copy of
// list1. The original lists are NOT modified.
struct node *append(struct node *list1, struct node *list2) {
    struct node *new_node = create_node(data);
    if (head == NULL) {
        return new_node;
    }
    struct node *curr = head;
    while (curr->next != NULL) {
        curr = curr->next;
    }
    curr->next = new_node;
    return head;
}

void print_list(struct node *head) {
    struct node *curr = head;
    while (curr != NULL) {
        printf("%d -> ", curr->data);
        curr = curr->next;
    }
    printf("X\n");
}

void print_list_with_addresses(struct node *head) {
    struct node *curr = head;
    while (curr != NULL) {
        printf("%d (%p) -> ", curr->data, curr);
        curr = curr->next;
    }
    printf("X\n");
}

struct node *create_node(int data) {
    struct node *new_node = malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

// Frees all memory associated with list.
void free_list(struct node *head) {
    struct node *curr = head;
    while (curr != NULL) {
        struct node *del_node = curr;
        curr = curr->next;
        free(del_node);
    }
}