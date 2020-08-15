// 연결리스트로 Stack 만들기

#include <stdio.h>
#include <stdlib.h>

typedef struct stackNode {
    int data;
    struct stackNode* next;
} StackNode;

StackNode* createStackNode(int data) {
    StackNode* node = (StackNode*)malloc(sizeof(StackNode));
    // malloc사용 후 node가 만들어졌는지 확인
    if(!node){
        printf("failed to create node\n");
        exit(0);
    }
    node->data = data;
    node->next = NULL;
    return node;
}

int isEmpty(StackNode* root) {
    return !root;   //true, false (0,1) 값을 반환
}

void push(StackNode** root, int data) {
    StackNode* node = createStackNode(data);

    node->next = (*root);
    *root = node;

    printf("%d pushed to stack\n", data);
}

int pop(StackNode** root) {
    if (isEmpty(*root))
        return -9999;
    int popped = (*root)->data;

    StackNode *tmp = *root;
    *root = (*root)->next;
    free(tmp);

    return popped;
}

int peek(StackNode** root) {
    if (isEmpty(*root))
        return -9999;
    return (*root)->data;
}

int main() {
    StackNode* root = NULL;

    push(&root, 10);
    push(&root, 20);
    push(&root, 30);
    push(&root, 40);

    printf("%d pop from stack\n", pop(&root));
    printf("%d pop from stack\n", pop(&root));

    push(&root, 50);
    printf("%d peeked from stack\n", peek(&root));
    printf("%d pop from stack\n", pop(&root));
    printf("%d pop from stack\n", pop(&root));
    printf("%d pop from stack\n", pop(&root));
    return 0;

    //할당받은 메모리 해제
    while(root->next == NULL){
        StackNode* tmp = root;
        root = root->next;
        free(tmp);
    }
}
