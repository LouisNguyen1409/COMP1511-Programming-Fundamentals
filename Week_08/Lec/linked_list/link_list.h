// This is my header file where I will define all the functions I am going
// to use with my linked lists


//Let's build a node... 
struct node {
    int data;
    struct node *next;  //created a pointer called next that points to 
                        //the address of another node
};
// This function prints out a linked list
void print_list(struct node *head);
// This function creates a new node
struct node *create_node(int data, struct node *next);
// This function gets the size of a linked list
int size_linked_list(struct node *head);
// This messy function inserts in the middle of a linked list
void insert_middle(struct node *head, int position);
// This function deletes a node
struct node *delete_node(struct node *head, int value);
// This function will print out all the even numbers inside a linked list
void print_even(struct node *head);

void increment_nodes(struct node *head);