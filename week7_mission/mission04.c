#include <stdio.h>
#define MAX 10000

int main(void){
    int *number[MAX];

    printf("오름차순 할 숫자들을 입력해주세요. -1를 입력하면 숫자를 그만 입력합니다.\n");
    int i = 0;
    while(1){
        scanf("%d", number[i++]);
        if(*number[i-1] == -1){
            break;
        }
    }
}
