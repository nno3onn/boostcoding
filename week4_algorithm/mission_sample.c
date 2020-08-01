#include <stdio.h>
/* <버블정렬 프로그램 작성>

0~9 사이 숫자 5개를 입력 받아 버블정렬을 이용하여 숫자를 오름차순으로 정렬하는 프로그램 작성하자.
숫자를 입력받는 부분은 따로 구현하지 않고 프로그램 안에서 배열로 선언하는 것으로 가정하고,
숫자에는 중복이 있을 수 있다.

예)
입력값: 32415 -> 출력값: 12345
입력값: 12791 -> 출력값: 11279 */


int main(void){
    int numbers[5] = {1,2,7,9,1};
    int temp;

    for(int i=0; i<5; i++){
        for(int j=0; j<4-i; j++){
            if(numbers[j] > numbers[j+1]){
                temp = numbers[j];
                numbers[j] = numbers[j+1];
                numbers[j+1] = temp;
            }
        }
    }

    for(int i=0; i<5; i++){
        printf("%d ",numbers[i]);
    }
    printf("\n");
    return 0;
}