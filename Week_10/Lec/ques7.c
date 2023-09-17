#include <stdio.h>
#include <assert.h>
#include <stdlib.h>


struct node {
    struct node *next;
    int          data;
};

// delete_div_six should delete the first node that is divisible by 6 
// If there are no nodes that are divisible by 6, it should return
// the list unchanged.
struct node *delete_div_six(struct node *head) {
    struct node *current = head;
    struct node *pre_current = NULL;
    if (head == NULL) {
        return NULL;
    }   
    
    if (current->data % 6 == 0 && pre_current == NULL) {
        head = current->next;
        free(current);
        return head;
    }

    while (current != NULL) {
        if (current->data % 6 == 0) {
            pre_current->next = current->next;
            free(current);
            return head;
        }
        pre_current = current;
        current = current->next;
    }
    return head;
}



////////////////////////////////////////////////////////////////////////
//               DO NOT CHANGE THE CODE BELOW                         //
////////////////////////////////////////////////////////////////////////
void print_list(struct node *head);
struct node *strings_to_list(int len, char *strings[]);

// DO NOT CHANGE THIS MAIN FUNCTION
int main(int argc, char *argv[]) {
    // create linked list from command line arguments
    struct node *head = strings_to_list(argc - 1, &argv[1]);

    // If you're getting an error here,
    // you have returned an uninitialized value
    struct node *new_head = delete_div_six(head);
    print_list(new_head);

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

// print linked list
void print_list(struct node *head) {
    printf("[");

    for (struct node *n = head; n != NULL; n = n->next) {
        // If you're getting an error here,
        // you have returned an invalid list
        printf("%d", n->data);
        if (n->next != NULL) {
            printf(", ");
        }
    }
    printf("]\n");
}