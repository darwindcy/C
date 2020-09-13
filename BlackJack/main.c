/*
 * CS 210: Machine problem 7
 *  Main.c file
 * Author: Darwin Charles Yadav
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

#include "cards.h"

int main()
{
    shoe_t current_shoe;
    int player_stake = 1000;
    int player_bet;
    int dealer_score = 0;
    int player_score = 0;
    char choice;

    printf("Welcome to Blackjack!\n\n");

    do{
        printf("How many decks do you wish to play with (1-10)?");
        scanf("%d", &current_shoe.num_of_decks);
        if (current_shoe.num_of_decks<1 || current_shoe.num_of_decks> 10){
            printf("Invalid Number of decks; Enter valid number of decks\n");
        }
    }while(current_shoe.num_of_decks < 1 || current_shoe.num_of_decks >10);

    printf("SHUFFLING!\n");

    current_shoe = initial_shoe(current_shoe.num_of_decks);
    do{
        printf("Your stake: $%d\n", player_stake);
        printf("Cards left in the Shoe:%d\n\n",cards_left(current_shoe));

        do{
            printf("Enter your bet (negative to quit):");
            scanf("%d", &player_bet);
            if(player_bet < 0){
                return 0;
            }
            if(player_bet > player_stake){
                printf("Bet cannot be higher than stake\n");
            }
        }while(player_bet > player_stake);

        hand_t dealer_hand = empty_hand(dealer_hand);
        hand_t player_hand = empty_hand(player_hand);

        dealer_hand = add_card_to_hand(dealer_hand, draw_card(current_shoe));

        printf("The Dealer is showing");
        print_hand(dealer_hand);
        printf("\n\n");

        player_hand = add_card_to_hand(dealer_hand, draw_card(current_shoe));

        do{
            printf("Your cards:");
            print_hand(player_hand);

            for(int i = 0; i < player_hand.num_of_cards; i++){
                player_score = player_score + points(player_hand.player_cards[i].value);
            }

            printf("Score = %d", player_score);

            if (player_score < 21){
                printf("Do you want to (H)it or (S)tand?");
                scanf(" %c", &choice);
                choice = tolower(choice);
                if (choice == 'h'){
                    add_card_to_hand(player_hand, draw_card(current_shoe));
                } else{
                    for(int i = 0; i<dealer_hand.num_of_cards;i++){
                        dealer_score = dealer_score + points(dealer_hand.player_cards[i].value);
                    }
                    while(dealer_score > 17 || dealer_score < 21){
                        add_card_to_hand(player_hand,draw_card(current_shoe));
                    }
                    printf("Dealer cards:\n");
                    print_hand(dealer_hand);
                    if (dealer_score > 21){
                        printf("Dealer Busts. You Win $d\n", player_bet);
                        player_stake = player_stake + player_bet;
                    }else if (dealer_score > player_score){
                        printf("Dealer wins with a score of %d. You Lost!\n", dealer_score);
                        player_stake = player_stake - player_bet;
                    }else if (dealer_score < player_score){
                        printf("Player wins with a score of %d. You Win!\n", player_score);
                        player_stake = player_stake + player_bet;
                    }else if(dealer_score == player_score){
                        printf("Game ends with a draw");
                        player_stake = player_stake;
                    }
                }
                printf("You Busted. You lose.\n");
                if (player_stake == 0){
                    printf("You're busted! It's time to rethink your career choices.");
                    free_shoe(current_shoe);
                }
            }
        } while (player_score < 21);

    } while(1);


    return 0;
}

