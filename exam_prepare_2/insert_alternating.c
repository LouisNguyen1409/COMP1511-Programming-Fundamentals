#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

// Provided Functions
struct node *create_node(int data);
void print_list(struct node *head);

int main(void) {

    struct node *head = NULL;
    struct node *new_node = NULL;
    // TODO: Read integers until EOF
    // For each integer, alternate inserting at tail 
    //      and inserting at head
    int data;
    int counter = 1;
    while (scanf("%d", &data) == 1) {
        new_node = create_node(data);
        struct node *curr = head;
        if (counter % 2 != 0) {
            new_node->next = head;
            head = new_node; 
        } else if (counter % 2 == 0) {
            while (curr->next != NULL) {
                curr = curr->next;
            }
            curr->next = new_node;
        }
        counter ++;
    }
    

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

// Prints a linked list
void print_list(struct node *head) {
    struct node *curr = head;
    while (curr != NULL) {
        printf("%d -> ", curr->data);
        curr = curr->next;
    }
    printf("X\n");
}

