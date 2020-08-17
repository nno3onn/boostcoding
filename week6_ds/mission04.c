// 뒤에서 k번째 노트는 무엇일까요?

#include <stdio.h>
#include <stdlib.h> //malloc()

typedef struct node {
    int data;
    struct node* next;
} Node;

Node* createNode(int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    if(!node){
        printf("failed to create node\n");
        exit(1);
    }
    node->data = data;
    node->next = NULL;
    return node;
}

void append(Node* head, int data) {
    Node *node = createNode(data);
    Node *tmp = head;

    while(tmp->next != NULL) {
        tmp = tmp->next;
    }
    tmp->next = node;

    printf("%d is appended. \n", node->data);
}

int getLastNode (Node* head, int k) {
    Node* front = head;
    Node* rear = head;

    while(--k != 0)
        rear = rear->next;

    while(rear->next != NULL){
        front = front->next;
        rear = rear->next;
    }
    return front->data;
}

void printList(Node* head) {
    printf("printList: ");

    while(head->next != NULL){
        head = head->next;
        printf("%d ", head->data);
    }
    printf("\n");
}

int main() {
    Node* head = (Node*)malloc(sizeof(Node));
    append(head, 9);
    append(head, 8);
    append(head, 4);
    append(head, 14);
    append(head, 5);

    printList(head);

    printf("\n%dth last node is %d\n", 2, getLastNode(head, 2));
    while(head->next == NULL){
        Node* tmp = head;
        head = head->next;
        free(tmp);
    }
}
