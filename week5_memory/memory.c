#include <stdlib.h>

void f(void){
    int *x = malloc(10 * sizeof(int));
    // x[10] = 0;  //ERROR! 10번째 없음. 0~9임. 버퍼 오버플로우 발생.
    // x[1000] = 0; //ERROR! 할당한 메모리를 벗어남
    //valgrind를 이용하면 에러 발생한 것을 볼 수 있음.
    //help50 valgrind ./memory

    x[9] = 0;
    free(x);
}

int main(void){
    f();
    return 0;
}
