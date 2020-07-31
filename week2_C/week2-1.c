#include <stdio.h>
#include <cs50.h>

void list(int, int);

int main(void)
{
    list(5,3);   
}

void list(int now, int order)
{
     printf("주문건수 : %i 건\n", order);
    printf("기존 재고량 : %i개\n", now);
    now = now - order;
    printf("남은 재고량 : %i개\n", now);
    printf("매출액(부가세포함) : %.f원\n", now * 1.1 * 10000);
}

