#include <stdio.h>

int main(){
    int temp = 91203;
    int i;

    void *vptemp = &temp;
    char *cptemp = vptemp;
    short *sptemp = vptemp;
    int *iptemp = vptemp;


    printf("temp address: %p\n\n", vptemp);

    for(i = 0; i < 4; i++){
        printf("cptemp+%d : %p\n", i, cptemp+i);
    }

    for(i = 0; i < 4; i++){
        printf("*(cptemp+%d) : %d\n", i, *(cptemp+i));
    }

    for(i = 0; i < 2; i++){
        printf("*(sptemp+%d) : %d\n", i, *(sptemp+i));
    }

    printf("*(iptemp+0) : %d\n", *(iptemp+0));
}
