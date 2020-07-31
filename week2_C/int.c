#include <cs50.h> //get_string
#include <stdio.h> //printf

int main(void){
    printf("Your are at least %i days old.\n", 
        get_int("What's your age?\n") * 365);
}
