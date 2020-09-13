/*
 * CS 210: Machine problem 7
 *  cards.c
 * Author: Darwin Charles Yadav
 */

#include "cards.h"

/*Function definitions*/

void print_card(card_t current_card){
    char current_suit[10];

    if (current_card.suit == Clubs){
        strcpy(current_suit, "Clubs");
    }else if(current_card.suit == Diamonds){
        strcpy(current_suit, "Diamonds");
    }else if(current_card.suit == Hearts){
        strcpy(current_suit, "Hearts");
    }else{
        strcpy(current_suit, "Spades");
    }

    if (current_card.value == Ace){
        printf("Ace of %s\n", current_suit);
    }else if(current_card.value == Jack){
        printf("Jack of %s\n", current_suit);
    }else if(current_card.value == Queen){
        printf("Queen of %s\n", current_suit);
    }else if(current_card.value == King){
        printf("King of %s\n", current_suit);
    }else{
        printf("%d of %s\n", current_card.value, current_suit);
    }
}

int points(int card_value){
    if (card_value > 10){
        return 10;
    }else{
        return card_value;
    }
}
shoe_t initial_shoe(int num_of_decks){

    shoe_t current_shoe;


    current_shoe.num_of_decks = num_of_decks;

    current_shoe.card_ts = (malloc(sizeof(card_t)* 52 * current_shoe.num_of_decks));

    /* Stores the cards in the designated array */
    int i = 0;
        for (int n = 1; n <= current_shoe.num_of_decks; n++){
            for (card_suits s = Spades; s <= Clubs; s++){
                for (card_value v = Ace; v <= King; v++){
                    current_shoe.card_ts[i].suit = s;
                    current_shoe.card_ts[i].value = v;
                    i++;
                }
            }
        }
    /*shuffle's the card and returns the shuffled cards*/
    return reshuffle(current_shoe);
}

card_t draw_card(shoe_t drawing_shoe){
    drawing_shoe.track_card++;
    return drawing_shoe.card_ts[drawing_shoe.track_card -1 ];
}
int cards_left(shoe_t cards_left_for_reshuffle){
    int left_cards;
    left_cards = ((cards_left_for_reshuffle.num_of_decks*52) - cards_left_for_reshuffle.track_card);
    return left_cards;
}

shoe_t reshuffle(shoe_t cards_to_reshuffle){
    card_t temp_card;

    srand(time(0));
    for(int i=0; i < cards_to_reshuffle.num_of_decks*52; i++){

        int random_position = i + rand()%(52 - i);

        temp_card.suit = cards_to_reshuffle.card_ts[i].suit;
        temp_card.value = cards_to_reshuffle.card_ts[i].value;

        cards_to_reshuffle.card_ts[i].suit = cards_to_reshuffle.card_ts[random_position].suit;
        cards_to_reshuffle.card_ts[i].value =  cards_to_reshuffle.card_ts[random_position].value;

        cards_to_reshuffle.card_ts[random_position].suit = temp_card.suit;
        cards_to_reshuffle.card_ts[random_position].value = temp_card.value;
    }
    cards_to_reshuffle.track_card = 0;
    return cards_to_reshuffle;
}
void free_shoe(shoe_t current_shoe){
    free(current_shoe.card_ts);
}

hand_t empty_hand(hand_t current_hand){
    hand_t new_hand;

    new_hand.num_of_cards = 0;
    return new_hand;
}
void print_hand(hand_t current_hand){

    for (int i = 0; i < current_hand.num_of_cards; i++){
        print_card(current_hand.player_cards[i]);
    }
}
hand_t add_card_to_hand(hand_t current_hand, card_t new_card){

    current_hand.num_of_cards = current_hand.num_of_cards + 1;
    current_hand.player_cards[current_hand.num_of_cards - 1].suit = new_card.suit;
    current_hand.player_cards[current_hand.num_of_cards - 1].value = new_card.value;

    return current_hand;
}
int blackjack_value(hand_t current_hand){
    int total_value = 0;
    for(int i = 0; i < current_hand.num_of_cards; i++){
        total_value = total_value + points(current_hand.player_cards[i].value);
    }
    return total_value;
}
