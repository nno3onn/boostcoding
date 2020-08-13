// Implements a list of numbers with linked list
//1->2->3 add number

#include <stdio.h>
#include <stdlib.h>

// node 표현
typedef struct node {
    int number;
    struct node* next;
}node;

int main(void){

    //크기 0인 리스트 (초기화)
    node *list = NULL;

    // Add number to list
    node *n = malloc(sizeof(node));
    if (n == NULL){
        return 1;
    }
    n->number = 1;
    n->next = NULL;
    list = n;

    // Add number to list
    n = malloc(sizeof(node));   //같은 변수 n이지만 malloc을 사용해서 아까와 다른 주소가 들어옴
    if (n == NULL){
        return 1;
    }
    n->number = 2;
    n->next = NULL;
    list->next = n;

    // Add number to list
    n = malloc(sizeof(node));
    if(n == NULL){
        return 1;
    }
    n->number = 3;
    n->next = NULL;
    list->next->next = n;

    // Print list
    for (node *tmp = list; tmp != NULL; tmp = tmp->next){
        printf("%i\n", tmp->number);
    }

    // Free list
    while (list != NULL){
        node *tmp = list->next;
        free(list);
        list = tmp;
    }
}