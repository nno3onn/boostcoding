#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(void)
{
    string answer = get_string("오늘은 몇요일 인가요?\n");
    if(strcmp(answer, "월요일") == 0)
    {
        printf("월요일의 메뉴는 청국장 입니다.\n");
    }
    else if (strcmp(answer, "화요일") == 0)
    {
        printf("화요일의 메뉴는 비빔밥 입니다.\n");
    }
    else if (strcmp(answer, "수요일") == 0)
    {
        printf("수요일의 메뉴는 된장찌개 입니다.\n");
    }
    else if (strcmp(answer, "목요일") == 0)
    {
        printf("목요일의 메뉴는 칼국수 입니다.\n");
    }
    else if (strcmp(answer, "금요일") == 0)
    {
        printf("금요일의 메뉴는 냉면입니다.\n");
    }
    else if (strcmp(answer, "토요일") == 0)
    {
        printf("토요일의 메뉴는 소불고기 입니다.\n");
    }
    else if (strcmp(answer, "일요일") == 0)
    {
        printf("일요일의 메뉴는 오삼불고기 입니다.\n");
    }
    else{
         printf("요일을 잘못 입력하셨습니다. \n");
         int i = get_int("프로그램을 종료하시겠습니까? (YES=1 / NO=2) \n");
         if(i==1)
            {
                exit(0);
            }
         else{
               main();
          }
     }
}


// #include <stdio.h>
// #include <cs50.h>

// int main(void){
//     char a[] = "요요요";

//     printf("%s\n",a);
//     printf("%lu",sizeof(a));
    
//     printf("\n");
// }
