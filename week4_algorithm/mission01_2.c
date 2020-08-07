#include <stdio.h>
//정렬 사용하지 않고 해결

/*0~9 나타내는 배열 생성
첫 번째 배열은 +1, 두 번째 배열은 -1
결과 배열이 모두 0이면 애너그램임*/

#define LENGTH 5

int main(void){
    int initial[LENGTH] = {1, 2, 3, 4, 5}; //초깃값
    int anagram[LENGTH] = {5, 4, 3, 2, 1}; //애너그램으로 변환한 값

    int compare_array[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}; //값을 0으로 초기화
    int number;

    for(size_t i=0; i < LENGTH; i++){
        //initial의 각 숫자를 배열의 인덱스로 설정하고 1씩 더함
        number = initial[i];
        compare_array[number] += 1;
    }

    for(size_t i = 0; i < LENGTH; i++){
        //anagram(애너그램으로 변환한 값)의 각 숫자를 배열의 인덱스로 설정하고 1씩 뺌
        number = anagram[i];
        compare_array[number] -= 1;
    }

    for(int i = 0; i < 10; i++){
        //배열의 값이 0이 아닌 게 하나라도 있다면 false 반환함
        if(compare_array[i] != 0){
            printf("false\n");
            return 0;
        }
    }
    printf("true\n");
    return 0;
}