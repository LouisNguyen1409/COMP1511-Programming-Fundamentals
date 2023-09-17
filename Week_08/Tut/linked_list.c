# include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *create_node(int data);
struct node *append(struct node *head, int data);

int main void() {
    struct node *head = create_node(0);
    printf("data: %d\n", head->data);
    head->data = 3;

    head->next = create_node(1);
    head->next->next = create_node(3);
    head->nextnext->next = create_node(4);

    




    return 0;
}

struct node *create_node(int data) {
    struct node *new_node = malloc(size(struct node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

struct node *append(struct node *head, int data) {
    struct node *new_node = create_node(data);
    if (head == NULL) {
        return new_node;
    }
    struct node *current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = new_node;
    return head;
}

