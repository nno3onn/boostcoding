#include <stdio.h>
#include <unistd.h> //sleep함수 사용하는 라이브러리

int main(void)
{
    for (int i = 1; ; i *=2 )   //영원히 2를 곱함
    {
        printf("%i\n", i);
        sleep(1);   //1초간 쉼
    }
}
