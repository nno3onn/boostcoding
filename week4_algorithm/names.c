// #include <cs50.h>
// #include <stdio.h>
// #include <string.h> //strcmp

// int main(void){
//     string names[4] = {"EMMA", "RODRIGO", "BRIAN", "DAVID"};

//     for(int i = 0; i < 4;  i++){
//         if (names[i] == "EMMA"){
//             printf("Found\n");
//         }
//     }
//     printf("Not found\n");
// }
/*위의 코드는 작동하지 않는다. 자료형이 다르기 때문이다.
관계연산자 == 는 문자열에 사용할 수 없다. 문자열은 문자, 부울, 소수 혹ㄷ은 정수와는 다르다.
문자열 자체가 배열로 여러 개의 문자로 구성된다. 두 문자열을 비교하고 싶으면 문자열 속에 문자를 하나씩 ㅣㅂ교해야많 ㅏㄴ다. 전체를 한꺼번에 비교할 수 없다.
하지만 파이썬이나 자바 같은 다른 프로그래밍 언어에서는 다음과 같이 한 줄로 비교가 가능하다.
하지만 C는 모든 것이 low레벨로 진행이 된다. 문자열을 비교하기 위해 등호를 사용할 수 없다.
아래와 같은 방법으로 문자열을 비교할 수 있다.*/

#include <cs50.h>
#include <stdio.h>
#include <string.h> //strcmp

int main(void){
    string names[4] = {"EMMA", "RODRIGO", "BRIAN", "DAVID"};

    for(int i = 0; i < 4;  i++){
        if(strcmp(names[i], "EMMA") == 0){
            printf("Found\n");
            return 0;
        }
    }
    printf("Not found\n");
    return 1;
}

/* 문자열을 비교하는 함수 strcmp에 첫 번째 비교 대상으로 names[i]를
두 번째 비교 대상으로 "EMMA"를 적는다.
strcmp함수는 두 문자열이 같다면 0을 반환한다. 양수를 반환하면 첫 번째 문자열이 알파벳 기준으로 큰 경우이고, 음수면 반대의 경우이다.
하지만 오늘은 두 문자열이 같은지만 확인하겠다.
strcmp는 <string.h>에 있으므로 추가해야 한다

하지만 결과로
Found
Not found
가 출력됨을 확인할 수 있다. 배열에서 EMMA를 찾은 걸까 못찾은 걸까?
그녀는 분명 여기 있는데 없다고 한다. 무엇이 잘못되었을까?
마지막에 적어둔 not found가 무조건 출력된다는 것이다.
그럼 found를 출력한 후 바로 어떻게 해주어야 할까? return해주어야 한다. 결과가 성공적이라는 것을 알려주기 위해 일반적으로는 0을 반환하고, ㅅㅓㅇ공적이지 않았을 경우 1을ㅇ 반환한다.
숫자 자체에는 큰 의미가 없지만 관습이라고 하자.


자, 이제 됐다.*/