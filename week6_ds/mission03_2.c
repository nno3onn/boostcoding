// 연결 리스트로 Queue 만들기

#include <stdio.h>
#include <stdlib.h> //malloc()

typedef struct node{
    struct node* next;
    int data;
}NODE;

NODE* createNode (int data){
    NODE* node = (NODE*)malloc(sizeof(NODE));
    if(!node){
        printf("failed to create node\n");
        exit(1);
    }
    node->next = NULL;
    node->data = data;
    return node;
}

int isEmpty(NODE* root){
    return !(root->next);
}

void push(NODE* root, int data){
    NODE *node = createNode(data);
    NODE *tmp = root;

    if(root == NULL){
        root->next = node;
    }else{
        while(tmp-> next != NULL){
            tmp = tmp->next;
        }
        tmp->next = node;
    }
    printf("%d pushed to queue\n", data);
}

void pop(NODE* root){
    if(isEmpty(root)){
        printf("queue is empty. can't pop\n");
        return;
    }
    NODE* tmp = root->next;
    root->next = root->next->next;
    printf("%d pop from queue\n", tmp->data);
    free(tmp);
}

void printList(NODE* head) {
    if(isEmpty(head)){
        printf("queue is empty. there's nothing\n");
        return;
    }
    printf("printList: ");

    while(head->next != NULL){
        head = head->next;
        printf("%d ", head->data);
    }
    printf("\n");
}

int main(){
    NODE *root = (NODE*)malloc(sizeof(NODE));

    push(root, 2);
    push(root, 2);
    push(root, 2);
    push(root, 2);
    printList(root);
    pop(root);
    printList(root);
    pop(root);
    printList(root);
    pop(root);
    printList(root);
    pop(root);
    printList(root);
    pop(root);
    printList(root);

    return 0;
}