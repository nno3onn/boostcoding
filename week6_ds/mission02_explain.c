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
        exit(1);
    }
    node->data = data;
    node->next = NULL;
    return node;
}

int isEmpty(StackNode* root) {
    return !root;   //true, false (0,1) 값을 반환. root=NULL일 경우 !root=true(1)
}

void push(StackNode** root, int data) {
    StackNode* node = createStackNode(data);

    node->next = (*root);   //젤 첫 부분에 node가 와야하므로 node다음에 root를 가리킴
    *root = node;   //추가한 node가 젤 첫 부분이므로 root로 추가한 node를 가리킴

    printf("%d pushed to stack\n", data);
}

int pop(StackNode** root) {
    if (isEmpty(*root)) //root가 빈 경우 뺄게 없으므로 종료
        return -9999;
    int popped = (*root)->data; //뺄 값 = 젤 위의 값(=root의 값)

    StackNode *tmp = *root; //tmp: root를 변경하기 전에 root를 저장하여 메모리를 할당함
    *root = (*root)->next;  //root를 root 다음 노드로 변경
    free(tmp);  //tmp(=old root) 메모리 할당

    return popped;
}

int peek(StackNode** root) {
    if (isEmpty(*root)) //root=NULL이라면 최상위 값이 없음
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
