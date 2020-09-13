/*
 * CS 210:Machine problem 7 cards.h
 *
 * Author: Darwin Charles Yadav
 */

#ifndef CARDS_H_INCLUDED
#define CARDS_H_INCLUDED

#define MAX_SIZE 21

/*Function prototypes*/
/* Structured and Enumerated data types*/
typedef enum{
    Spades,
    Hearts,
    Diamonds,
    Clubs
}card_suits;

typedef enum{
    Ace = 1,
    Two = 2,
    Three = 3,
    Four = 4,
    Five = 5,
    Six = 6,
    Seven = 7,
    Eight = 8,
    Nine = 9,
    Ten = 10,
    Jack = 11,
    Queen = 12,
    King = 13
}card_value;

typedef struct{
    card_suits suit;
    card_value value;
} card_t;

typedef struct{
    card_t *card_ts;
    int num_of_decks;
    int track_card;
} shoe_t;

/*Function Prototypes*/
void print_card(card_t current_card);
int points(int card_value);
shoe_t initial_shoe(int num_of_decks);
shoe_t reshuffle(shoe_t cards_to_reshuffle);
int cards_left(shoe_t cards_left_for_reshuffle);
void free_shoe(shoe_t current_shoe);
card_t draw_card(shoe_t drawing_shoe);

/*Hand Functions */

typedef struct{
    card_t player_cards[MAX_SIZE];
    int num_of_cards;
} hand_t;

hand_t empty_hand(hand_t current_hand);

void print_hand(hand_t current_hand);
hand_t add_card_to_hand(hand_t current_hand, card_t new_card);
int blackjack_value(hand_t current_hand);


#endif // CARDS_H_INCLUDED
