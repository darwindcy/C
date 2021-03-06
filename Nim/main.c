/*
 * CS 210: Machine Problem 3
 * Program to play the game of Nim
 * Author: Darwin Charles Yadav
 */

#define bool int
#define TRUE 1
#define FALSE 0
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/* Function Prototypes*/

void print_greeting();
void print_scoreboard(int human_score, int computer_score);
void play_nim(int starting_player, int *winner);
void get_human_move(int heap_a, int heap_b, int heap_c,
                    char *choosen_heap, int *number_removed);
void get_computer_move(int heap_a, int heap_b, int heap_c,
                       char *choosen_heap, int *number_removed);
bool user_wishes_to_continue();
void heaps(int heap_a, int heap_b, int heap_c);

int main()
{
    int human_score = 0, computer_score = 0;
    int starting_player = 1;
    int winner;

    print_greeting();
    do{
        play_nim(starting_player, &winner);
        if (winner == 1){
            printf("Player 1 wins!\n");
            printf("* * * * * * * * * * *\n");
            human_score ++;
            starting_player = 2;
        } else if (winner == 2){
            printf("Player 2 wins!\n");
            printf("* * * * * * * * * * *\n");
            computer_score ++;
            starting_player = 1;
        }
        print_scoreboard(human_score, computer_score);
    } while(user_wishes_to_continue());

    return 0;
}

/*Function definitions*/

/*Prints in-game greeting*/
void print_greeting(){
    printf("Welcome to the Ancient Game of Nim\n\n");
    printf("Player 1 is you (the human)\n");
    printf("Player 2 is me (the computer)\n");
}
/*Prints in-game scoreboard*/
void print_scoreboard(int human_score, int computer_score){
printf("Current Score:\n");
printf("Player 1 (Human):    %d\n", human_score);
printf("Player 2 (Computer): %d\n", computer_score);
}

/*Plays the game of Nim*/
void play_nim(int starting_player, int *winner){

    int heap_a = 0;
    int heap_b = 0;
    int heap_c = 1;
    char choosen_heap;
    int number_removed;
    int track_turn = 1;

    if (starting_player == 1){
        printf("Player 1 goes first this time!\n");
    } else {
        printf("Player 2 goes first this time!\n");
        track_turn = 2;
    }

    while (heap_a != 0 || heap_b != 0 || heap_c != 0){

        if (track_turn == 1){
            get_human_move(heap_a, heap_b, heap_c, &choosen_heap, &number_removed);
            track_turn = 2;
        } else {
            printf("Player 2\n");
            heaps(heap_a, heap_b, heap_c);
            get_computer_move(heap_a, heap_b, heap_c, &choosen_heap, &number_removed);
            printf("COMPUTER moves %c%d\n", choosen_heap, number_removed);
            track_turn = 1;
        }
        if (choosen_heap == 'a'){
            heap_a = heap_a - number_removed;
        } else if (choosen_heap == 'b'){
            heap_b = heap_b - number_removed;
        } else if (choosen_heap == 'c'){
            heap_c = heap_c - number_removed;
        }
    }
    if (track_turn == 2){
        *winner = 1;
    } else if (track_turn == 1){
        *winner = 2;
    }
}

/*Gets computer's next move from a series of calculations*/
void get_computer_move(int heap_a, int heap_b, int heap_c,
                       char *choosen_heap, int *number_removed){

    int nim_number;
    nim_number = heap_a ^ heap_b ^ heap_c;

    if (nim_number == 0 && heap_a != 0){
        *choosen_heap = 'a';
        *number_removed = 1;
    } else if (nim_number == 0 && heap_b != 0){
        *choosen_heap = 'b';
        *number_removed = 1;
    } else if (nim_number == 0 && heap_c != 0){
        *choosen_heap = 'c';
        *number_removed = 1;

    } else {

        if ((heap_a ^ nim_number) < heap_a){
            *choosen_heap = 'a';
            *number_removed = heap_a - (heap_a ^ nim_number);
        } else if ((heap_b ^ nim_number) < heap_b){
            *choosen_heap = 'b';
            *number_removed = heap_b - (heap_b ^ nim_number);
        } else if ((heap_c ^ nim_number) < heap_c){
            *choosen_heap = 'c';
            *number_removed = heap_c - (heap_c ^ nim_number);
        }
    }
}
/*Gets human move*/
void get_human_move(int heap_a, int heap_b, int heap_c,
                    char *choosen_heap, int *number_removed){
    char pile_choosen;
    int stone_count;
    bool repeat;

        do{
            printf("Player 1\n");
            heaps(heap_a, heap_b, heap_c);

            printf("Enter the letter of the heap and number of objects to remove:");
            scanf(" %c%d", &pile_choosen, &stone_count);
            pile_choosen = tolower(pile_choosen);

            if ((pile_choosen == 'a') && (stone_count > 0 && stone_count <= heap_a)){
            //heap_a = heap_a - stone_count;
                repeat = FALSE;
            } else if ((pile_choosen == 'b') && (stone_count > 0 && stone_count <= heap_b)){
            //heap_b = heap_b - stone_count;
                repeat = FALSE;
            } else if ((pile_choosen == 'c') && (stone_count > 0 && stone_count <= heap_c)){
            //heap_c = heap_c - stone_count;
                repeat = FALSE;
            } else {
                printf("Illegal move! Try again.\n");
                repeat = TRUE;
            }
        } while (repeat);
    *choosen_heap = pile_choosen;
    *number_removed = stone_count;
}
/*Prints Heaps*/
void heaps(int heap_a, int heap_b, int heap_c){
    printf("Heaps:\n");
    printf("A: %d\n", heap_a);
    printf("B: %d\n", heap_b);
    printf("C: %d\n", heap_c);
}
/*Prompts if user wishes to continue*/
bool user_wishes_to_continue(){
    char ch;
    bool bad = TRUE;

    do {
        printf("Do you wish to play again? (y/n)");
        scanf(" %c", &ch);
        ch = tolower(ch);

        if (ch == 'y'){
            return TRUE;
        } else if (ch == 'n'){
            return FALSE;
        }else {
            printf("Bad input! Try again.\n");
        }
    } while(bad);

    if (ch == 'y'){
        return TRUE;
    } else {
        return FALSE;
    }
}
