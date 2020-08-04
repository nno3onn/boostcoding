#include <stdio.h>
#include <cs50.h>

/* 최단 시간에 다리건너기*/

int main(void){

    const int LENGTH = get_int("입력값: ");
    int arr[LENGTH];

    if(LENGTH > 100){
        printf("입력값은 100명을 넘기지 않아야 합니다.\n");
        return 1;
    }

    for(int i = 0; i < LENGTH; i++){
        arr[i] = get_int("");
    }

    // for(int i = 0; i < LENGTH; i++){
    //     printf("%d",arr[i]);
    // }


    int sum;


    for(int i = 0; i < LENGTH ; i+2){
        printf("%d %d", a[i], a[i+1]);
        sum += a[i+1];
    }

    printf("출력값: ");


    return 0;
}
