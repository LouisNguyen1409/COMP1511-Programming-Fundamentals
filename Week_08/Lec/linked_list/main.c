#include <stdio.h>
#include "link_list.h"



int main(void) {
    struct node *head;
    // Let's create a node!
    head = create_node(5, NULL);
    head = create_node(7, head);
    head = create_node(11, head);
    head = create_node(18, head);
    head = create_node(1, head);
    
    print_list(head);
    // when I exited this loop, my current = NULL

    // let's add a node to teh end of the list - lets do 9
    struct node *current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    // when I exit this loop, my current->next = NULL, 
    // which means that I am sitting on the last node

    struct node *new_node = create_node(9, NULL);
    
    current->next = new_node;
    // Inserting into a linked list by finding the middle of it 
    int size = size_linked_list(head);
    printf("The size of the linked list is %d\n", size);

    // mid_point = 2/2 = 1
    int mid_point = size/2;
    
    insert_middle(head, mid_point);

    print_list(head);

    head = delete_node(head, 13);
    print_list(head);

    // Let's do a function to print out all the values in a linked list 
    // that are even
    // Input: head
    // Output: void 
    printf("Even numbers are: ");
    print_even(head);

    // Let's do a function that increments every item in the list by 2
    // Input: head
    // Output: head/void
    increment_nodes(head);
    printf("New list is: ");
    print_list(head);
    
    return 0;

}