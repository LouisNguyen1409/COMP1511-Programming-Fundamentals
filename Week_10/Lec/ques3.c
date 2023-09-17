#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

struct node {
    struct node *next;
    int          data;
};

// list 1: 3 4 5 6 7 (5 nodes)
// list 2: 1 2 3 (3 nodes)
// return 2 as the difference 

int difference(struct node *head1, struct node *head2) {
    int length1 = 0;
    int length2 = 0;
    
    struct node *current1 = head1;
    struct node *current2 = head2;
    
    while (current1 != NULL) {
        length1 += 1;
        current1 = current1->next;   
    }

    while (current2 != NULL) {
        length2 += 1;
        current2 = current2->next;
    }

    int diff = 0;
    if (length1 > length2) {
        diff = length1 - length2;
    } else if (length2 > length1) {
        diff = length2 - length1; 
    }
    return diff;
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

    int diff = difference(head1, head2);
    printf("%d\n", diff);

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