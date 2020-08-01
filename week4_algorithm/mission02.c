#include <stdio.h>
#include <math.h>   //pow() : 제곱근구하기. pow(base, 제곱)
#include <cs50.h>   //get_int

/*친구들과 최단거리에 있는 집 구하기*/

/*입력값 중 중앙값 찾는 프로그램.
먼저 오름차순으로 정리한 후, 중앙값을 출력한다

개수가 홀수인 경우, 중앙값 출력
개수가 짝수인 경우, 중앙의 두 값중에서 평균에 더 가까운 값을 출력*/

int* bubble_sort(int a[], int length);
int midnum(int a[], int length);
float average(int a[], int length);
float pow_num(float avg, int num);

int main(void){
    const int LENGTH = get_int("친구들이 몇 명인가요?\n");

    printf("%i명 친구들의 집을 숫자로 나타내 주세요.\n", LENGTH);

    int num[5];

    for(int i = 0; i < LENGTH; i++){
        get_int("%d", &num[i]);
    }


    return 0;
}

int* bubble_sort(int a[], int length){
    int temp;

    for(int i = 0; i < length; i++){
        for(int j = 0; j < length - 1 - i; j++){
            if(a[j] > a[j+1]){
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
    return a;
}

int midnum(int a[], int length){
    int mid;
    float avg = average(a, length);

    if(length%2 == 0){ //짝수개인 경우
        if(pow_num(avg, a[length/2]) > pow_num(avg, a[length/2 + 1])){
            mid = a[length/2 + 1];
        }else{
            mid = a[length/2];
        }
    }else{ //홀수개인 경우
        mid = a[length/2 + 1];
    }
    return mid;
}

float average(int a[], int length){
    int sum;
    float avg;

    for(int i = 0; i < length; i++){
        sum = sum + a[i];
    }
    avg = (float)sum/(float)length;
    return avg;
}

float pow_num(float avg, int num){
    return pow(avg - num, 2);
}
