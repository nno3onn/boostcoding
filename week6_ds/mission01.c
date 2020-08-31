// 배열로 Stack 만들기

#include <stdio.h>
#include <stdlib.h>

typedef struct stack{
    int top;
    int capacity;
    int* array;
} Stack;

Stack* createStack(int capacity) {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    if(!stack){
        printf("failed to create node\n");
        exit(1);
    }
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int*)malloc(stack->capacity*sizeof(int));
    if(!(stack->array)){
        exit();
    }
    return stack;
}

int isFull(Stack* stack) {
    return stack->top == stack->capacity-1;
}

int isEmpty(Stack* stack) {
    return stack->top == -1;
}

void push(Stack* stack, int item) {
    if (isFull(stack)){
        printf("stack is full\n");
        return;
    }
    stack->array[++stack->top] = item;
    printf("%d pushed to stack\n", item);
}

void pop(Stack* stack) {
    if (isEmpty(stack)){
        printf("stack is empty. can't pop\n");
    }else{
        printf("%d pop from the stack\n", stack->array[(stack->top)--]);
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

    free(stack);
    return 0;
}
