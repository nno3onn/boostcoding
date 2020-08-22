#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int *divisor;   //숫자N의 약수들이 담긴 int 배열

int compare(const void * a, const void * b)
{
    return (*(int*)a - *(int*)b);
}

int result(int N){
    int Num = 4;    //답은 최소 4부터 가능.

    bool check = false;
    bool check2 = false;

    while(check == false){
        for(int i = 0; i < N; i++){
            if(Num % divisor[i] == 0 && Num != divisor[i]){
                check2 = true;
            }else{
                Num++;
                check2 = false;
                break;
            }
        }
        if(check2 == true){
            check = true;
        }
    }
    return Num;
}

int main() {
    int N;  //숫자N의 약수의 개수
    scanf("%d", &N);

    divisor = malloc(sizeof(int) * N);

    for(int i = 0; i < N; i++){
        int tmp;
        scanf("%d", &tmp);  //숫자N의 약수들을 모두 받아옴
        divisor[i] = tmp;
    }

    qsort(divisor, N, sizeof(int), compare);

    int answer = result(N);
    printf("%d\n", answer);

    return 0;
}