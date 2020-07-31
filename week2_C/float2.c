#include <stdio.h>
#include <cs50.h>

int main(void)
{
    float price = get_float("What's your price?\n");
    printf("Your total is %.2f\n", price * 1.0625); 
    //메사추세츠의 부가세 6.25%
}
