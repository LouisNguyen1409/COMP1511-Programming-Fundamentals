#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

#define MAX_LEN 4096

struct card {
    int num;
    struct card *next;
};

struct card *deck_read(int player_num);
void print_deck(struct card *deck);

int main(void) {
    struct card *player1 = deck_read(1);
    struct card *player2 = deck_read(2);

    // TODO: Fill in your code here!
    struct card *pile = NULL;
    struct card *new_pile = NULL;
    int player_win = 0;
    int snap = 0;

    while (snap == 0 && player_win == 0) {
        new_pile = player1;
        player1 = player1->next;
        new_pile->next = pile;
        pile = new_pile;
        if (pile->next != NULL && pile->num == pile->next->num) {
            snap = 1;
            break;
        }
        if (player1 == NULL) {
            player_win = 2;
            break;
        }
        


        new_pile = player2;
        player2 = player2->next;
        new_pile->next = pile;
        pile = new_pile;
        if (pile->next != NULL && pile->num == pile->next->num) {
            snap = 1;
            break;
        }
        if (player2 == NULL) {
            player_win = 1;
            break;
        }

        if (pile->num == pile->next->num) {
            snap = 1;
        }
    }   

    if (snap == 1) {
        printf("Snap! Matched card %d\n", pile->num);
    } else if (player_win == 1) {
        printf("Player 1 has won!\n");
    } else if (player_win == 2) {
        printf("Player 2 has won!\n");
    }

    printf("Player 1's deck: ");
    print_deck(player1);
    printf("Player 2's deck: ");
    print_deck(player2);
    printf("Pile: ");
    print_deck(pile);




    return 0;
}

void print_deck(struct card *deck) {
    while (deck != NULL) {
        printf("%d -> ", deck->num);
        deck = deck->next;
    }
    printf("X\n");
}

// Function to create a deck for the specified player.
// Returns a pointer to the top card in the deck.
struct card *deck_read(int player_num) {
    int num;
    printf("Enter Player %d's deck values:\n", player_num);
    struct card *head = NULL;
    struct card *tail = NULL;
    while (scanf("%d", &num) == 1) {
        if (num == -1) break;
        struct card *new_card = malloc(sizeof(struct card));
        new_card->num = num;
        new_card->next = NULL;
        if (head == NULL) {
            head = tail = new_card;
        } else {
            tail = tail->next = new_card;
        }
    }
    return head;
}
