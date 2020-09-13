/*
 * CS 210: Machine Problem 5
 * Mad Libs
 * Author: Darwin Charles Yadav
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 100

/*Function Prototypes*/
void print_greeting();
void removeLastChar(char s[]);
int isvowel(char word[]);
int istoken(char word[]);
void replace(char word[], char replacement[]);
void token_to_english(char token[], char prompt[]);
void process_file(FILE* in, FILE* out);
FILE* open_file(char prompt[], char mode[]);

int main()
{
    char inp_name[MAX_LEN];
    char out_name[MAX_LEN];

    FILE* input_file;
    FILE* output_file;

    print_greeting();

    input_file = open_file(inp_name, "r");

    output_file = open_file(out_name, "w");

    process_file(input_file, output_file);

    printf("\n");
    printf("Processing finished. Enjoy your story.\n");

    return 0;
}

void print_greeting(){
    printf("MAD-LIBS Text Processor\n");
    printf("The program will open a mad-libs file, ask you to fill various words, and produce a funny story.\n");
}

FILE* open_file(char prompt[], char mode[]){

    FILE* in;
    FILE* out;

    if (mode[0] == 'r'){
        do{
            printf("Enter mad-lib file name:");
            fgets(prompt, MAX_LEN, stdin);
            removeLastChar(prompt);
            in = fopen(prompt, mode);

            if (in == NULL){
                printf("Unable to open file: %s. Try again!\n", prompt);
            }
        } while(in == NULL);

    } else {
    /*Output codes*/
        printf("Enter file name for resulting story:");
        fgets(prompt, MAX_LEN, stdin);
        removeLastChar(prompt);

        out = fopen(prompt, mode);
    }
}

void process_file(FILE* in, FILE* out){

    char input_data[MAX_LEN];
    char replacement[MAX_LEN];
    int a = 0;

    while(fscanf(in, "%s", &input_data) != EOF){

        replace(input_data, replacement);
        if (a == 0){
            fprintf(out, "%s", replacement);
            a = 1;
        }else{
            fprintf(out," %s", replacement);
        }
    }

    fclose(in);
    fclose(out);
}
void removeLastChar(char s[]){
    int nullInd = strlen(s);
    if (nullInd != 0){
        s[nullInd-1] = '\0';
    }
}
int istoken(char word[]){
    if (strcmp(word, "<adjective>") == 0 ||
        strcmp(word, "<plural-noun>") == 0 ||
        strcmp(word, "<noun>") == 0 ||
        strcmp(word, "<place>") == 0 ||
        strcmp(word, "<funny-noise>") == 0 ||
        strcmp(word, "<person's-name>") == 0){
        return 1;
    } else {
        return 0;
    }
}
int isvowel(char word[]){
    if (word[0] == 'a' ||
        word[0] == 'e' ||
        word[0] == 'i' ||
        word[0] == 'o' ||
        word[0] == 'u'){
        return 1;
    } else {
        return 0;
    }
}
void replace(char word[], char replacement[]){

    int x = istoken(word);
    if (x == 1){
        token_to_english(word, replacement);

        int is_vow = isvowel(replacement);

        if (is_vow == 1){
            printf("Please type an %s:", replacement);
            fgets(replacement, MAX_LEN, stdin);
            removeLastChar(replacement);
        }else{
            printf("Please type a %s:", replacement);
            fgets(replacement, MAX_LEN, stdin);
            removeLastChar(replacement);
        }
    } else {
        strcpy(replacement, word);
    }
}

void token_to_english(char token[], char prompt[]){
    for(int i = 0; token[i] != '\0'; i++){
        if (token[i] == '<'){
            prompt[i] = token[i+1];
        }else if(token[i] == '>'){
            prompt[i-1] = '\0';
        }else{
            prompt[i] = token[i+1];
        }
        if (prompt[i] == '-'){
            prompt[i] = ' ';
        }
    }
}
