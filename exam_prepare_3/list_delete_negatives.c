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
struct node *delete_negatives(struct node *head);

int main(void) {

    struct node *head = insert_at_head(NULL, 6);
    head = insert_at_head(head, -2);
    head = insert_at_head(head, 4);
    
    print_list(head);
    head = delete_negatives(head);
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


struct node *delete_negatives(struct node *head) {

    // TODO: Delete any nodes in the linked list 
    // with a data value < 0
    struct node *curr = head;
    struct node *pre = NULL;
    if (curr == NULL) {
        return head;
    }

    while (curr != NULL) {
        if (curr->data < 0 && pre == NULL) {
            head = curr->next;
            free(curr);
            curr = head;
        } else if (curr->data < 0 && pre != NULL) {
            pre->next = curr->next;
            free(curr);
            curr = pre->next;
        } else {
            pre = curr;
            curr = curr->next;
        }
        
    }
    return head;
}

