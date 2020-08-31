// 연결 리스트로 Stack 만들기

#include <stdio.h>
#include <stdlib.h>

typedef struct stackNode {
    int data;
    struct stackNode* next;
} StackNode;

StackNode* createStackNode(int data) {
    StackNode* node = (StackNode*)malloc(sizeof(StackNode));
    if(!node){
        printf("failed to create node\n");
        exit(1);
    }
    node->data = data;
    node->next = NULL;
    return node;
}

int isEmpty(StackNode* root) {
    return !root;
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
    printf("%d pop from stack\n", pop(&root));
    printf("%d pop from stack\n", pop(&root));
    return 0;

    while(root->next == NULL){
        StackNode* tmp = root;
        root = root->next;
        free(tmp);
    }
}