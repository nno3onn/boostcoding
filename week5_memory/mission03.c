//정렬을 해보자

//간단한 버블 정렬 코드를 배열이 아닌 포인터를 활용하여 완성해보세요.

#include <stdio.h>

void sort(int n, int arr[]);

int main(){
    int n = 7;
    int arr[7] = {0, 25, 10, 17, 6, 12, 9};
    sort(n, arr);

    for(int i = 0; i < n; i++){
        printf("%d ",*(arr+i));
    }
    printf("\n");

    return 0;
}

void sort(int n, int arr[]){
    int temp;

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n-i-1; j++){
            if (*(arr+j) > *(arr+j+1)){
                temp = *(arr+j);
                *(arr+j) = *(arr+j+1);
                *(arr+j+1) = temp;
            }
        }
    }
}
