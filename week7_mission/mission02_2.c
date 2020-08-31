#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int *divisor;   //숫자N의 약수들이 담긴 int 배열

int compare(const void * a, const void * b)
{
    return (*(int*)a - *(int*)b);
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

    int answer = divisor[0] * divisor[N-1];
    printf("%d\n", answer);

    return 0;
}