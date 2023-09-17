#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

struct node {
    struct node *next;
    int          data;
};


// if I have a 
// list1: 4 5 6
// list2: 7 8 9
// list: 4 5 6 7 8 9
struct node *concatenate(struct node *head1, struct node *head2) {
    while (head1 == NULL) {
        return head2;
    }

    struct node *current1 = head1;
    struct node *current2 = head2;
    while (current1->next != NULL) {
        current1 = current1->next;
    }
    current1->next = current2;

    return head1;

}


struct node *strings_to_list(int len, char *strings[]);

// DO NOT CHANGE THIS MAIN FUNCTION
int main(int argc, char *argv[]) {
    // create two linked lists from command line arguments
    int dash_arg = argc - 1;
    while (dash_arg > 0 && strcmp(argv[dash_arg], "-") != 0) {
        dash_arg = dash_arg - 1;
    }
    struct node *head1 = strings_to_list(dash_arg - 1, &argv[1]);
    struct node *head2 = strings_to_list(argc - dash_arg - 1, &argv[dash_arg + 1]);

    struct node *new_head = concatenate(head1, head2);
    while (new_head != NULL) {
        printf("%d->", new_head->data);
        new_head = new_head->next;
    }
    printf("X\n");

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