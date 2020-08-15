// 배열로 Stack 만들기

#include <stdio.h>
#include <stdlib.h>

typedef struct stack{
    int top;
    int capacity;
    int* array;
} Stack;

Stack* createStack(int capacity) {
    // malloc 사용 후 stack이 잘 생성되었는지 확인
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    if(!stack){
        printf("failed to create node\n");
        exit(0);    //생성되지 않았다면 프로그램 종료
    }
    stack->capacity = capacity;
    stack->top = -1;     // 배열을 [0]부터 시작하기 위해 -1(empty)로 지정
    stack->array = (int*)malloc(stack->capacity*sizeof(int));
    // malloc 사용 후 배열이 잘 생성되었는지 확인
    if(!(stack->array)){
        exit(0);
    }
    return stack;
}

int isFull(Stack* stack) {  // 조건(0,1)으로 반환
    return stack->top == stack->capacity-1;
}

int isEmpty(Stack* stack) { // 조건(0,1)으로 반환
    return stack->top == -1;
}

void push(Stack* stack, int item) {
    if (isFull(stack)){ // stack이 가득차면 값을 추가할 수 없으므로 중단함
        printf("stack is full\n");
        return;
    }
    stack->array[++stack->top] = item;  // stack의 최상단에 있는 배열(top+1)에 item(추가할 값)을 넣음
    printf("%d pushed to stack\n", item);
}

void pop(Stack* stack) {
    if (isEmpty(stack)){    //stack이 비어있으면 pop할 값이 없음
        printf("stack is empty. can't pop\n");
    }else{
        printf("%d pop from the stack\n", stack->array[(stack->top)--]);    //stack의 최상단(top)을 가리키는 값을
    }
}

void peek(Stack* stack) {
    if (isEmpty(stack)){
        printf("stack is empty. No peek\n");
    }else{
    printf("%d is peek\n", stack->array[stack->top]);
    }
}

int main() {
    Stack* stack = createStack(100);

    push(stack, 10);
    peek(stack);
    push(stack, 20);
    peek(stack);
    push(stack, 30);
    peek(stack);
    push(stack, 40);

    pop(stack);
    peek(stack);
    pop(stack);
    peek(stack);

    push(stack, 50);
    peek(stack);
    pop(stack);
    peek(stack);
    pop(stack);
    peek(stack);
    pop(stack);
    peek(stack);
    pop(stack);

    free(stack);    //할당받은 메모리를 해제함
    return 0;
}
