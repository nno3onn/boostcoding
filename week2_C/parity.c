#include <stdio.h>  //printf, scanf ... 함수 포함하는 라이브러리
#include <cs50.h>   //get_int 함수 포함하는 라이브러리

int main(void){
    int n = get_int("n: "); //사용자에게 하나의 정수값을 받음

    if(n % 2 == 0)  //짝수인 경우  (% : 나머지)
    {
        printf("even\n");   //even 출력
    }
    else    //홀수인 경우
    {
        printf("odd\n");    //odd 출력
    }
}
