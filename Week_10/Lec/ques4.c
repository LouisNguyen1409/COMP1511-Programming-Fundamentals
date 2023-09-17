#include <stdio.h>
#include <assert.h>
#include <stdlib.h>


struct node {
    struct node *next;
    int          data;
};

// find_divisible by 6 should return the number of items in the list
// divisible by 6
int delete_divisible(struct node *head) {
    int counter = 0;
    struct node *current = head;

    if (head == NULL) {
        return 0;
    }

    while (current != NULL) {
        if (current->data % 6 == 0) {
            counter += 1;
        }
        current = current->next;
    }
    return counter;
}



////////////////////////////////////////////////////////////////////////
//               DO NOT CHANGE THE CODE BELOW                         //
////////////////////////////////////////////////////////////////////////
void print_list(struct node *head);
struct node *strings_to_list(int len, char *strings[]);

// DO NOT CHANGE THIS MAIN FUNCTION
int main(int argc, char *argv[]) {
    // create linked list from command line arguments
    struct node *head = strings_to_list(argc - 1, &argv[1]);

    // If you're getting an error here,
    // you have returned an uninitialized value
    // struct node *new_head = delete_divisible(head);
    // print_list(new_head);
    printf("%d\n", delete_divisible(head));
    return 0;
}

// DO NOT CHANGE THIS FUNCTION
// create linked list from array of strings
struct node *strings_to_list(int len, char *strings[]) {
    struct node *head = NULL;
    for (int i = len - 1; i >= 0; i = i - 1) {
        struct node *n = malloc(sizeof (struct node));
        assert(n != NULL);
        n->next = head;
        n->data = atoi(strings[i]);
        head = n;
    }
    return head;
}

// print linked list
void print_list(struct node *head) {
    printf("[");

    for (struct node *n = head; n != NULL; n = n->next) {
        // If you're getting an error here,
        // you have returned an invalid list
        printf("%d", n->data);
        if (n->next != NULL) {
            printf(", ");
        }
    }
    printf("]\n");
}