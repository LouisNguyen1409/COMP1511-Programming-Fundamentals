/*Problem 1: 

find_range takes one parameter: a pointer to the head of
the list to search through. find_range should return a single integer: 
the difference between the smallest value and the largest value in the list.

For example, if the list contained:
3->4->5->6->X

find_range should return 3, as 6 - 3 = 3

As another example, if the list contained:
1->X

find_range should return 1, as it is the only value in the list.

Testing
list_find_range.c</b> also contains a <b>main</b> function which
allows you to test your <b>find_range</b> function.

This main function:

converts the command-line arguments to a linked list
assigns a pointer to the first node in the linked list to head
calls find_range(head)
prints the result.

Do not change this main function.  If you want to change it, you have
misread the question.

Your find_range function will be called directly in marking.
The main function is only to let you test your find_range function

Here is how the main function allows you to test find_range:

dcc list_find_range.c -o list_find_range
./list_find_range 3 4 5
The range is: 2

./list_find_range 10 9 8 7 6 5 4 3 2 1
The range is: 9

./list_find_range 1
The range is: 1

./list_find_range
The list is empty!


Assumptions/Restrictions/Clarifications.
find_range should return only a single integer: the range of the list.
find_range should not change the linked list it is given.
find_range should not change the next or data fields of list nodes.
find_range should not use arrays.
find_range should not call malloc.
find_range should not call scanf (or getchar or fgets).
find_range should not print anything. It should not call printf.
Do not change the definition of struct node.
Do not change the supplied main function. It will not be tested or marked.
*/

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

// Do not change these #defines, or your program will fail the autotests!
#define EMPTY_LIST -42

struct node {
    struct node *next;
    int          data;
};

// find_range should return the range of the list, or
// EMPTY_LIST if the list is empty.
int find_range(struct node *head) {
    if (head == NULL) {
        return EMPTY_LIST;
    }


    int min = head->data;
    int max = head->data;
    struct node *current = head;

    while (current != NULL) {
        if (current->data < min) {
            min = current->data;
        } else if (current->data) {
            max = current->data;
        }
        current = current->next;
    }
    return max - min;
}


////////////////////////////////////////////////////////////////////////
//               DO NOT CHANGE THE CODE BELOW                         //
////////////////////////////////////////////////////////////////////////

int find_range(struct node *head);
struct node *strings_to_list(int len, char *strings[]);

// DO NOT CHANGE THIS MAIN FUNCTION
int main(int argc, char *argv[]) {
    // create linked list from command line arguments
    struct node *head = strings_to_list(argc - 1, &argv[1]);

    // If you're getting an error here,
    // you have returned an uninitialized value
    int range = find_range(head);
    if (range == EMPTY_LIST) {
        printf("The list is empty!\n");
    } else {
        printf("The range is: %d\n", range);
    }

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