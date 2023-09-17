// This program introduces the linked list data structure
// YAY Linked Lists 
// Sasha 22T3 Week 7: Lecture 12

#include <stdio.h>
#include <stdlib.h> // this allows me to have malloc and free at my disposal

// Let's build up a node
struct node {
    int data;
    // pointer to a node, called next
    // int *number_ptr = pointer to an int
    // struct node *ptr = pointer to a struct
    struct node *next; 
};

// Let's have some functions!
// Create a node: this function will make us a new node
struct node *create_node(int data, struct node *next);
// Insert at the end of the list 
struct node *insert_at_end(struct node *head);
// Print list: This function will traverse through and print out the ll
void print_linked_list(struct node *head);
int size_linked_list(struct node *head);


int main(void) {

    struct node *head;

    head = create_node(3, NULL);
    head = create_node(4, head); 
    head = create_node(5, head);

    print_linked_list(head);

    insert_at_end(head);
    
    print_linked_list(head);

    printf("Linked list is %d items\n", size_linked_list(head));

    return 0;
}

// This function creates a new node
// Output: our new node
// Input: int data, struct node *next (which are the two members of the node that you need to 
// make a node!)
struct node *create_node(int data, struct node *next) {
    struct node *new_node = malloc(sizeof(struct node));

    new_node->data = data;
    new_node->next = next;

    return new_node;

}



// This function inserts a node at the end of the list!
// Output: struct node * 
// Input: struct node *head  
struct node *insert_at_end(struct node *head) {
    struct node *current = head;
    
    while(current->next != NULL) {
        current = current->next;
    }
    // Come out of the while loop current->next = NULL, and you are 
    // standing/sitting at the last node of the list
    struct node *new_node = create_node(13, NULL);
    current->next = new_node;

    return head;
} 



// This function traverses the list and prints out the data stored in the nodes
// Output: void
// Input: head
void print_linked_list(struct node *head) {

    struct node *current = head;

    while(current != NULL) {
        printf("%d\n", current->data);
        current = current->next;
    }
    // When I come out of the while loop, current = NULL
    printf("NULL\n");
}

// This function will calculate the size of a linked list
// Input: head (struct node *)
// Output: int size
int size_linked_list(struct node *head) {
    int counter = 0;
    struct node *current = head;

    while(current != NULL) {
        counter = counter + 1;
        current = current->next;
    }
    // When we exit out of the while loop, current = NULL, and we have gone through
    // all the nodes of the list
    return counter;
}