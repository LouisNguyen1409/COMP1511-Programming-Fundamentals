#include "link_list.h"
#include <stdlib.h>
#include <stdio.h>




struct node *delete_node(struct node *head, int value) {
    struct node *current = head;
    struct node *previous = NULL;

    //1. Empty list?
    if (current == NULL) {
        return head;
    }

    //2. Delete the head of the list?
    if (current->data == value) {
        head = current->next;
        free(current);
        return head;
    }

    // Perfect case?
    while (current != NULL && current->data != value) {
        previous = current;
        current = current->next;
    }
    // When I exit this loop either current = NULL (so I have)
    // reached the end of the list or current->data = value 
    if (current == NULL) {
        return head;
    } else if (current->data == value) {
        previous->next = current->next;
        free(current);
    }

    return head;
}

// This function inserts in the middle of a linked list
// Input: head, position
// Output: ....
void insert_middle(struct node *head, int position) {
    
    struct node *new_node = create_node(13, NULL);
    int counter = 1;

    struct node *current = head;

    while (current != NULL && counter != position) {
        counter++;
        current = current->next;
    }
    // When I exit the loop, either current = NULL OR 
    // counter = position;
    if (counter == position) {
        new_node->next = current->next;
        current->next = new_node;
    }

}

// This function inserts at the end of a linked list
// Input
// Output

//struct node *insert_end_of_list(struct node *head, )

// This function calculates the size of a linked list
// Input: head of the list 
// Output: size of the linked list (int)
int size_linked_list(struct node *head) {
    int counter = 0;
    struct node *current = head;
    // traverse through that linked list
    while (current != NULL) {
        counter++;
        current = current->next;
    } 
    return counter;
}


// This function will create a new node by mallocing some memory
// Input: data, address next
// Output: pointer to that node that I've just created
struct node *create_node(int data, struct node *next) {
    struct node *new_node = malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = next;
    return new_node;
}

// This function will print out a linked list
// Input: the head of the list 
// Output: void (nothing)

void print_list(struct node *head) {
    struct node *current = head;
    
    while (current != NULL) {
        printf("%d\n", current->data);
        current = current->next;
    } 
}

// Let's do a function to print out all the values in a linked list 
// that are even
// Input: head
// Output: void 

void print_even(struct node *head) {
    struct node *current = head;
    while (current != NULL) {
        if (current->data % 2 == 0) {
            printf("%d\n", current->data);
        }
        current = current->next;
    }
}

void increment_nodes(struct node *head) {
    struct node *current = head;    
    while (current != NULL) {
        current->data += 2;
        current = current->next;
    }
}