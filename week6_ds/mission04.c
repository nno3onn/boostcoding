// 뒤에서 k번째 노트는 무엇일까요?

#include <stdio.h>
#include <stdlib.h> //malloc()

typedef struct node{
    int data;
    struct node* next;
} Node;

void append(Node* head, int data) {
    // 이 부분을 작성해 주세요!
    Node* node = malloc(sizeof(Node));
    if (!node){
        exit(0);
    }
    node->data = data;
    node->next = NULL;

    if (head->next == NULL){
        node->next = head;
        head = node;
    }


    printf("head: %d \n", head->data);
}

int getLastNode (Node* head, int k) {
    // 이 부분을 작성해 주세요!
    return 1;
}

void printList(Node* head) {
    // 이 부분을 작성해 주세요!
    printf("printList: %d ", head->data);

    // while(head->next != NULL){
    //     head = head->next;
    //     printf("%d ", head->data);
    // }
    printf("\n");
}

int main() {
    Node* head = (Node*)malloc(sizeof(Node));
    append(head, 9);
    printf("head: %d \n", head->data);
    append(head, 8);
    append(head, 4);
    append(head, 14);
    append(head, 5);

    printList(head);

    // printf("\n%dth last node is %d\n", 2, getLastNode(head, 2));
}