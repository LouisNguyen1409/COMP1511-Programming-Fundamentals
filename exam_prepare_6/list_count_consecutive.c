#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct node {
    struct node *next;
    int          data;
};

int count_consecutive(struct node *head);
struct node *array_to_list(int len, int array[]);
void print_list(struct node *head);

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

    int n_consec = count_consecutive(head);
    printf("There are %d consecutive occurances.\n", n_consec);
    print_list(head);

    return 0;
}

// TODO: FIX THIS FUNCTION
// Counts the number of consecutive items in a list
// e.g. [2, 3, 2, 5, 4] has 3 consecutive occurances
int count_consecutive(struct node *head) {

    int n_consec = 0;

    struct node *curr = head;
    struct node *prev = NULL;
    while (curr != NULL) {
        // checking to see if previous and current and consecutive.
        if (prev - curr == 1 || prev - curr == -1) {
            n_consec++;
        }

        curr = curr->next;
        prev = prev->next;
    }
    return n_consec;
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

// DO NOT CHANGE THIS FUNCTION
// print linked list
void print_list(struct node *head) {
    printf("[");
    struct node *n = head;
    while (n != NULL) {
        // If you're getting an error here,
        // you have returned an invalid list
        printf("%d", n->data);
        if (n->next != NULL) {
            printf(", ");
        }
        n = n->next;
    }
    printf("]\n");
}

