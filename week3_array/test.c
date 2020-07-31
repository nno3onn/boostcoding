#include <stdio.h>
#include <cs50.h>

int main(void){
    printf("%lu\n",sizeof("A+"));
    printf("%lu\n\n",sizeof("A"));

    char* grade[2]={"A+","A"};
    printf("%lu\n",sizeof(grade[0]));
    printf("%lu\n\n",sizeof(grade[1]));
    return 0;
}
