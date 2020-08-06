#include <stdio.h>

#define SIZE 50000

int main(int argc, char* argv[]){
    int n;

    //파일에서 첫 번째 N을 입력
    scanf("%d", &n);

    //1부터 N까지 숫자 중 K가 빠진 배열을 선언함
    int part_arr[SIZE];
    int length_of_part_arr = n-1;

    //파일에서 N-1개의 숫자를 입력
    for (int i = 0; i < length_of_part_arr; i++)
        scanf("%d", &part_arr[i]);

    int part_sum = 0;


    //N - 1 개의 숫자의 합을 구함
    for (int i = 0; i < length_of_part_arr; i++)
        part_sum += part_arr[i];

    //N개의 합을 구함
    int total_sum = n * (n+1) /2;

    //합의 차로 빠진 수인 k를 구함
    int k = total_sum - part_sum;

    printf("K = %d\n", k);

    return 0;
}
