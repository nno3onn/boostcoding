#include <stdio.h>

int main(void){
    int n = 50;
    printf("%i\n", n);
    printf("%p\n", &n);
    printf("%i\n\n", *&n);

    int *p = &n;
    printf("%p\n", p);
    printf("%i\n\n", *p);

    char *s = "EMMA";
    printf("%p\n",s);
    printf("%c\n",*s);
    printf("%c\n",*(s+1));
    printf("%c\n",*(s+2));
    printf("%c\n",*(s+3));
    printf("%c\n",*(s+4));


}