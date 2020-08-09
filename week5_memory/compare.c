#include <stdio.h>
#include <cs50.h>

int main(void){
    int i = get_int("i: ");
    int j = get_int("j: ");

    if( i == j){
        printf("same\n");
    }else{
        printf("different\n");
    }



    string s = get_string("s: ");
    string t = get_string("t: ");

    if(s == t){
        printf("same\n");
    }else{
        printf("different\n");
    }
    /*같은 수를 입력하도 different라고 뜬다.
    왜냐하면 다른 주소에 저장되어 있기 때문이다.
    S와 T는 메모리에 두 덩어리를 얻지만 같은 곳에 저장하지 않기 때문에
    두 주소를 비교한 결과 값이 다르기 때문에 결과값도 differnet로 출력된다
    따라서 이전의 미션에서 비교 연산자 ==로 두 문자열을 비교할 수 없어서 strcmp를 사용하였다*/

    char* s = get_string("s: ");
    char* t = get_string("t: ");

    printf("%p\n", s);
    printf("%p\n", t);
    //두 문자열의 주소값이 서로 다르다.

}