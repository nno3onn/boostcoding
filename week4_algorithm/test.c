#include <stdio.h>

int num1[] = {1};
int num2[] = {2};

void print(int arr[]){
    for(int i=0; i<5; i++){
        printf("%d", arr[i]);
    }
}


int main(void){

    printf("num1: ");
    print(num1);
    printf("\n");

    printf("num2: ");
    print(num2);
    printf("\n");

}

