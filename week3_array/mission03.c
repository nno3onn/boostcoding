#include <stdio.h>
#include <cs50.h>

#define MAX 10

int queue_array[MAX];
int rear = -1;
int front = -1;

void insert();
void delete();
void display();

int main(void){
     int num;

    while(1){
        num = get_int("원하는 기능을 숫자로 작성하시오.\n(1) add\n(2) pop\n(3) display\n(4) quit\n입력: ");

        switch(num) {
            case 1: //add
                insert();
                break;
            case 2: //pop
                delete();
                break;
            case 3: //display
                display();
                break;
            case 4: //quit
                return 1;
            default:
                printf("1 ~ 4 사이의 수를 입력하세요.");
        }
    }

    return 0;
}


void insert(){
    int add_item;

    //현재 꼬리의 위치 확인
    if(rear == MAX-1){
        printf("Queue가 꽉 찼습니다.\n");
    }else{
        if(front == -1) //초기값
            front++;

        printf("삽입할 값 : ");
        scanf("%d", &add_item);
        rear++;
        queue_array[rear] = add_item;   //꼬리에 값을 넣음
    }

}

void delete(){
    if(front == -1 || front > rear){
        printf("Queue가 비어있습니다.\n");
        return ;
    }else{
        printf("Queue에서 %d가 삭제되었습니다.\n", queue_array[front]);
        front++;
    }
}

void display(){
    int i;
    if(front == -1){
        printf("Queue가 비어있습니다.\n");
    }else{
        printf("Queue: ");

        for(i = front; i <= rear; i++)
            printf("%d ", queue_array[i]);

        printf("\n");
    }

}