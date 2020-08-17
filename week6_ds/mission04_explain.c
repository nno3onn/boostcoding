// 뒤에서 k번째 노트는 무엇일까요?

#include <stdio.h>
#include <stdlib.h> //malloc()

typedef struct node {
    int data;
    struct node* next;
} Node;

Node* createNode(int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    if(!node){  //메모리 문제로 node가 만들어지지 않았는지 확인
        printf("failed to create node\n");
        exit(1);    //node가 만들어지지 않았다면 종료
    }
    node->data = data;
    node->next = NULL;
    return node;
}

void append(Node* head, int data) {
    Node *node = createNode(data);  //입력된 data를 가진 노드 생성
    Node *tmp = head;   //마지막 노드인지 확인할 노드

    while(tmp->next != NULL) {  //tmp를 head에서부터 한 칸씩 전진시켜 마지막 노드에서 멈춤
        tmp = tmp->next;
    }
    tmp->next = node;   //마지막 노드인 tmp 뒤에 새로운 node를 이음

    printf("%d is appended. \n", node->data);
}

int getLastNode (Node* head, int k) {
    // front와 rear는 거리가 k만큼 띄워진 노드. front --(+k)--> rear
    // 두 노드는 head에서부터 시작
    Node* front = head;
    Node* rear = head;

    while(--k != 0)    //k-1부터 ~ 1까지 (k-1)번 반복함
        rear = rear->next;  // k-1만큼 rear를 뒤로 이동

    //rear이 마지막 노드가 될 때까지 front와 rear이 함께 한 칸씩 뒤로 이동
    while(rear->next != NULL){
        front = front->next;
        rear = rear->next;
    }
    //rear가 마지막 노드일 때 front가 뒤에서 k 번째 노드가 됨.
    return front->data;
}

void printList(Node* head) {
    printf("printList: ");

    while(head->next != NULL){  // 마지막 노드가 될 때까지 계속 한 칸씩 뒤로 이동하여 해당 노드 속 값을 출력
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

    //할당받은 메모리를 해제함
    while(head->next == NULL){
        Node* tmp = head;
        head = head->next;
        free(tmp);
    }
}
