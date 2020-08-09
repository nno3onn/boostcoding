#include <stdio.h>
#include <ctype.h> //toupper()
#include <cs50.h>
#include <string.h> //strlen()
#include <stdlib.h> //malloc()

int main(void){
    // char *s = get_string("s: ");

    // char *t = s;    //문자열을 복사하지 않고 주소를 복사하게 된다.

    // t[0] = toupper(t[0]);

    // printf("%s\n", s);
    // printf("%s\n", t);
    // /* 두 문자 모두 대문자고 바뀌게 된다. t만 바꿨는데 s는 왜 바뀌게 될까?
    // ==> t = s. t라는 변수에 s라는 주소를 저장하였기 때문에
    // s 혹은 t 둘 중 하나의 값을 바꾸게되면 s, t 두 값 모두 바뀌게 된다. 포인터이기 때문이다.*/



    //이와 같이 하지 않으려면 다른 공간을 만들고 글자를 복사한다. 이를 위해 malloc()을 사용한다.
    char *s = get_string("s: ");
    char *t = malloc(strlen(s) + 1);

    // for(int i = 0, n = strlen(s); i < n+1; i++){  //n을 추가하여 효율적으로 설계.\0도 같이 저장해야하기 때문에 n+1까지.
    //     t[i] = s[i];
    // }

    strcpy(t, s);

    t[0] = toupper(t[0]);

    printf("%s\n", s);
    printf("%s\n", t);

    free(t);    //할당된 메모리를 사용한 후에 해제해줌
}
