#include <stdio.h>

int main(void){
    int arr[10] = {0,};
    int number1[5] = {1, 4, 2, 5, 8};
    int number2[5] = {2, 5, 4, 3, 1};

    for(int i = 0; i < 5; i++){
        arr[number1[i]]++;
        arr[number2[i]]--;
    }

    for(int i = 0; i < 10; i++){
        if(arr[i] != 0){
            printf("false\n");
            return 0;
        }
    }
    printf("true\n");
    return 0;
}