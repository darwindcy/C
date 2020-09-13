/*
 * CS 210: Machine Problem-2
 * Program to play Rock,Paper,Scissors
 * Author: Darwin Charles Yadav
 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/*Function prototypes*/

void print_greeting();
void print_score(int human_score, int computer_score,int ties);
char get_pick();
double compute_result(int human_pick, int comp_pick);
char compute_next_pick(int human_pick, int comp_pick);

int main()
{
    int human_wins = 0;
    int computer_wins = 0;
    int ties = 0;
    int result;
    char human_pick;
    char computer_pick = 'r';

    print_greeting();
    while (1){
        print_score(human_wins, computer_wins, ties);
        human_pick = get_pick();
        if (human_pick == 'g'){
            break;
        }
        result = compute_result(human_pick, computer_pick);

        if (result < 0){
            printf("You Win!\n");
            human_wins++;
        }else if (result > 0){
            printf("I Win!\n");
            computer_wins++;
        }else{
            printf("Tie!\n");
            ties++;
        }
        computer_pick = compute_next_pick(human_pick, computer_pick);
    }
    return 0;
}

/*Function Definitions*/

/*Function that prints the greeting*/
void print_greeting(){
    printf("Welcome to the RPS AI\n");
    printf("I will dominate your puny human brain!\n");
}

/*Function that calculates the score */

void print_score(int human_score,int computer_score,int ties){

    printf("The current score is:\n");
    printf("Human: %d\n", human_score);
    printf("AI   : %d\n", computer_score);
    printf("Ties : %d\n", ties);
}

/*Function that gets choice from user*/

char get_pick(){

    char ch;
    int bad = 1;

    while (bad){
        printf("Pick (R)ock, (P)aper, (S)cissors, or (G)ive up:");
        scanf(" %c", &ch);
        ch = tolower(ch);   /*Converts alphabet into lowercase*/

        if (ch == 'r' || ch == 'p' || ch == 's' || ch == 'g'){
            bad = 0;
        } else {
            bad = 1;
        }

        if (bad == 1){
            printf("Bad input! Try again.\n");
        }
    }
        return ch;
}

/*Computes the result and prints the choices*/

double compute_result(int human_pick, int comp_pick){
    if (human_pick == 'p' && comp_pick == 's'){
        printf("You chose paper\n");
        printf("I chose scissors\n");
        return 1;
    }else if (human_pick == 's' && comp_pick == 'r'){
        printf("You chose scissors\n");
        printf("I chose rock\n");
        return 1;
    }else if (human_pick == 'r' && comp_pick == 'p'){
        printf("You chose rock\n");
        printf("I chose paper\n");
        return 1;
    }else if (comp_pick == 'p' && human_pick == 's'){
        printf("You chose scissors\n");
        printf("I chose paper\n");
        return -1;
    }else if (comp_pick == 's' && human_pick == 'r'){
        printf("You chose rock\n");
        printf("I chose scissors\n");
        return -1;
    }else if (comp_pick == 'r' && human_pick == 'p'){
        printf("You chose paper\n");
        printf("I chose rock\n");
        return -1;
    }else if (comp_pick == 'r' && human_pick == 'r'){
        printf("You chose rock\n");
        printf("I chose rock\n");
        return 0;
    }else if (comp_pick == 'p' && human_pick == 'p'){
        printf("You chose paper\n");
        printf("I chose paper\n");
        return 0;
    }else if (comp_pick == 's' && human_pick == 's'){
        printf("You chose scissors\n");
        printf("I chose scissors\n");
        return 0;
    }else{
        return 0;
    }
}

/*Function that decides what the computer picks next*/

char compute_next_pick(int human_pick, int comp_pick){
    if ((human_pick == 'r' && comp_pick == 'r') ||
        (human_pick == 'r' && comp_pick == 'p') ||
        (human_pick == 'p' && comp_pick == 'r')){
            return 's';
        }else if ((human_pick == 'p' && comp_pick == 'p') ||
        (human_pick == 'p' && comp_pick == 's') ||
        (human_pick == 's' && comp_pick == 'p')){
            return 'r';
        }else if ((human_pick == 'r' && comp_pick == 's') ||
        (human_pick == 's' && comp_pick == 'r') ||
        (human_pick == 's' && comp_pick == 's')){
            return 'p';
        }
        return 'r';
}
