#include <stdio.h>
#include <stdlib.h>

int main()
{
    int sum = 0;
    int max = 0;
    int MAX_LENGTH = 32;
    char food_item[MAX_LENGTH];
    FILE *fptr = fopen("input.txt", "r");

    if (fptr == NULL){
        printf("Error opening file");
        exit(1);
    }
    while(fgets(food_item, MAX_LENGTH, fptr)) {
        if(food_item[0] == '\n'){
            max = (sum>max) ? sum : max;
            sum = 0; 
        }
        else{
            sum = sum + atoi(food_item);
        }
    }
    fclose(fptr);
    printf("The elf with the most calories has foods with a total of %d calories", max);
}