#include <stdio.h>
#include <stdlib.h>

enum Shape{
    ROCK = 1,
    PAPER = 2,
    SCISSORS = 3,
};

static const int translate_shape[] = {
        ['A'] = ROCK,
        ['B'] = PAPER,
        ['C'] = SCISSORS,

        ['X'] = ROCK,
        ['Y'] = PAPER,
        ['Z'] = SCISSORS,
};

int calculatePoints(enum Shape elf, enum Shape me){
    // draw
    if(elf == me){
        return me + 3;
    }
    // loss
    else if(elf == ROCK && me == SCISSORS || elf == SCISSORS && me == PAPER || elf == PAPER && me == ROCK){
        return me;
    }
    // win
    return me + 6;
}

int main(void){
    FILE *fptr = fopen("input.txt", "r");
    if(fptr == NULL){
        printf("Error! File not found.");
        exit(1);
    }
    int elf, me;
    int SIZE = 32;
    char buff[SIZE];
    int points = 0;
    while(fgets(buff, SIZE, fptr)){
        elf = (int)buff[0];
        me = (int)buff[2];
        points += calculatePoints(translate_shape[elf],translate_shape[me]);
    }
    fclose(fptr); 
    printf("My total score is %d", points);
}