#include <stdio.h>  //#기호를 10번 출력하는 프로그램
                    //그러나 실제 출력은 11개가 나온다.
                    //이는 문법적인 버그가 아닌, 논리적 오류이다.
                    //이때, printf를 사용한다.

int main(void)
{
    for (int i = 0; i < 10; i++)
    {
        // printf("i is now %i: ", i+1);
        printf("#\n");
    }
}
