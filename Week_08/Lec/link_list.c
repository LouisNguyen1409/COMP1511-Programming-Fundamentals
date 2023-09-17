// This program introduces linked_lists - let's try this again :)
// Remember that it takes time - you may not get it straight away
// but it will happen!

#include <stdio.h>
#include <stdlib.h>

//Let's build a node... 
struct node {
    int data;
    struct node *next;  //created a pointer called next that points to 
                        //the address of another node
};

void print_list(struct node *head);
struct node *create_node(int data, struct node *next);
int size_linked_list(struct node *head);
void insert_middle(struct node *head, int position);

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

    return 0;

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