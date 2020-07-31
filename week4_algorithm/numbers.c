#include <stdio.h>
#include <cs50.h>

//선형 검색

int main(void){
    int numbers[6] = {4, 8, 16, 23, 42};    //숫자 5개의 배열을 선언하고 각 값을 초기화함

    for(int i = 0; i < 6; i++){
        if(numbers[i] == 50){
            printf("Found\n");
        }
    }
    printf("Not found\n");
}