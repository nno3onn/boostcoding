#include <stdio.h>
#include <stdlib.h>     //rand()함수
#include <time.h>       //time()함수

/* 숫자 애너그램 찾기*/
//오름차순 정리 후, 두 배열이 같은지 확인

const int LENGTH = 5;

int num1[LENGTH] = {};
int num2[LENGTH] = {};

void random_sort(int arr[], int length);
void bubble_sort(int arr[], int length);
void print(int arr[]);
char* anagram(int arr1[], int arr2[], int length);

int main(void){
    srand(time(0)); //time(): 프로그램을 실행할 때마다 난수가 변경됨(1초 단위로 변경)

    printf("입력값: ");
    random_sort(num1, LENGTH);
    printf(", ");
    random_sort(num2, LENGTH);

    printf(" -> 출력값: ");
    print(num1);
    printf(", ");
    print(num2);
    printf(" (%s)\n", anagram(num1, num2, LENGTH));

    return 0;
}

void random_sort(int arr[], int length){
    for(int i = 0; i < length; i++){
        // printf("num1: ");
        // print(num1);
        // printf(", num2: ");
        // print(num2);
        // printf("\n");
        arr[i] = rand()%9+1;    //1~9의 랜덤 숫자 지정
    }
    print(arr);

    bubble_sort(arr, length);
}


void bubble_sort(int arr[], int length){
    int temp;

    for (int i=0; i<length; i++){
        for (int j=0; j<length-i-1; j++){
            if (arr[j] > arr[j+1]){
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void print(int arr[]){
    for(int i=0; i<5; i++){
        printf("%d", arr[i]);
    }
}

char* anagram(int arr1[], int arr2[], int length){
    for(int i=0; i<length; i++){
        if(arr1[i] != arr2[i]){
            return "False";
        }
    }
    return "True";
}
