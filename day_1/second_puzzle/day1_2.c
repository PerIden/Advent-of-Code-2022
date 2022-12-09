#include <stdio.h>
#include <stdlib.h>

int main()
{
    int sum = 0;
    int top_three[3] = {0};
    int MAX_LENGTH = 32;
    char food_item[MAX_LENGTH];
    int top_three_sum;
    FILE *fptr = fopen("input.txt", "r");

    if (fptr == NULL){
        printf("Error opening file");
        exit(1);
    }
    while(fgets(food_item, MAX_LENGTH, fptr)) {
        if(food_item[0] == '\n'){
            if(sum > top_three[2]){
                if(sum > top_three[1]){
                    if(sum > top_three[0]){
                        top_three[2] = top_three[1];
                        top_three[1] = top_three[0];
                        top_three[0] = sum;
                    }
                    else{
                        top_three[2] = top_three[1];
                        top_three[1] = sum;
                    }
                }
                else{
                    top_three[2] = sum;
                }
            }
            sum = 0; 
        }
        else{
            sum = sum + atoi(food_item);
        }
    top_three_sum = top_three[0] + top_three[1] + top_three[2];
    }
    fclose(fptr);
    printf("The top three elves have foods with a total of %d calories", top_three_sum);
}