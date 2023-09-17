#include <stdio.h>
#include <assert.h>
#include <stdlib.h>


struct node {
    struct node *next;
    int          data;
};

// duplicate should duplicate every node in the list, inserting the new
// node after the original node
struct node *duplicate(struct node *head) {
    if (head == NULL) {
        return NULL;
    }
    struct node *current = head;

    while (current != NULL) {
        struct node *duplicate = malloc(sizeof(struct node));
        duplicate->data = current->data;
        duplicate->next = current->next;
        
        current->next = duplicate;
        current = duplicate->next;
    }
    return head;
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
    struct node *new_head = duplicate(head);
    print_list(new_head);

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