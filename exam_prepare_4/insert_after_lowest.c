#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

// Provided Functions
struct node *create_node(int data);
struct node *insert_at_head(struct node *head, int data);
void print_list(struct node *head);

// Your functions
struct node *insert_after_lowest(struct node *head, int data);


int main(void) {

    // Only your function is called during testing
    // Any changes in this main function will not
    // be used in testing

    struct node *head = insert_at_head(NULL, 6);
    head = insert_at_head(head, 2);
    head = insert_at_head(head, 4);
    
    print_list(head);
    head = insert_after_lowest(head, 99);
    print_list(head);
    
    return 0;
}

// Mallocs a new node and returns a pointer to it
struct node *create_node(int data) {
    struct node *new_node = malloc(sizeof(struct node));
    new_node->next = NULL;
    new_node->data = data;
    return new_node;
}

// Inserts at the head of a linked list
// Returns a pointer to the new head of the list
struct node *insert_at_head(struct node *head, int data) {
    struct node *new_node = create_node(data);
    new_node->next = head;
    return new_node;
}

// Prints a linked list
void print_list(struct node *head) {
    struct node *curr = head;
    while (curr != NULL) {
        printf("%d -> ", curr->data);
        curr = curr->next;
    }
    printf("X\n");
}

struct node *insert_after_lowest(struct node *head, int data) {

    // TODO: Insert a new node with the value, 'data' 
    // after the node with the lowest data.
    struct node *curr = head;

    if (curr == NULL) {
        return NULL;
    }

    int lowest = curr->data;
    while (curr != NULL) {
        if (curr->data < lowest) {
            lowest = curr->data;
        }
        curr = curr->next;
    }

    curr = head;
    while (curr != NULL) {
        if (curr->data == lowest) {
            struct node *new_node = create_node(data);
            new_node->next = curr->next;
            curr->next = new_node;
            return head;
        }
        curr = curr->next;
    }
    return head;
}
