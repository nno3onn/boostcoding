#include <stdio.h>
#include <cs50.h> //string, get_string 함수 사용 가능

int main(void)
{
    string answer = get_string("What's your name?\n");
    printf("hello, %s\n", answer);
}
