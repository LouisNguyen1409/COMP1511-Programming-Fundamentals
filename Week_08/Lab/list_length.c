// list_length
// list_list_length.c
//
// This program was written by Dinh Minh Nhat Nguyen z5428797
// on 03/04/2023
//
// Find the length of a Linked List

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct node {
    struct node *next;
    int          data;
};

int length(struct node *head);

// Return the length of the linked list pointed by head
int length(struct node *head) {

    // PUT YOUR CODE HERE (change the next line!)
    int counter = 0;
    struct node *current = head;

    while (current != NULL) {
        counter += 1;
        current = current->next;
    }

    return counter;

}

// DO NOT CHANGE THIS FUNCTION
// create linked list from array of strings
struct node *array_to_list(int len, int array[]) {
    struct node *head = NULL;
    int i = len - 1;
    while (i >= 0) {
        struct node *n = malloc(sizeof (struct node));
        assert(n != NULL);
        n->next = head;
        n->data = array[i];
        head = n;
        i -= 1;
    }
    return head;
}


// DO NOT CHANGE THIS MAIN FUNCTION
#define MAX_INIT_LIST_LEN 100
int main() {
    // Need to read in a number of ints into an array
    printf("How many numbers in initial list?: ");
    int list_size = 0;
    scanf("%d", &list_size);
    int initial_elems[MAX_INIT_LIST_LEN] = {0};
    int n_read = 0;
    while (n_read < list_size && scanf("%d", &initial_elems[n_read])) {
        n_read++;
    }

    // create linked list from first set of inputs
    struct node *head = NULL;
    if (n_read > 0) {
        // list has elements
        head = array_to_list(n_read, initial_elems);
    }

    printf("Counted %d elements in linked list.\n", length(head));

    return 0;
}

