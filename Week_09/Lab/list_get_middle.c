// list_get_middle
// list_get_middle.c
//
// This program was written by Dinh Minh Nhat Nguyen z5428797
// on 10/04/2023
//
// Get the middle element from a Linked List

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct node {
    struct node *next;
    int          data;
};

int get_middle(struct node *head);
struct node *array_to_list(int len, int array[]);

// DO NOT CHANGE THIS MAIN FUNCTION
#define MAX_INIT_LIST_LEN 100
int main(void) {
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

    int result = get_middle(head);
    printf("%d\n", result);

    return 0;
}


// Return middle element of a linked list
// if list contains [6,7,8,9,10]  8 is returned
// if a list has even number of elements, first of middle two elements returned
// if list contains [1,2,3,4] 2 is returned
// list can not be empty
int get_middle(struct node *head) {

    // PUT YOUR CODE HERE (change the next line!)
    struct node *current = head;
    int total_length = 0;
    int middle_pos = 0;
    while (current != NULL) {
        total_length += 1;
        current = current->next;
    }

    if (total_length % 2 == 0) {
        middle_pos = (total_length / 2) - 1;
    } else {
        middle_pos = total_length / 2;
    }

    current = head;
    for (int i = 0; i < middle_pos; i++) {
        current = current->next;
    }
    int middle_data = current->data;
    return middle_data;

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
