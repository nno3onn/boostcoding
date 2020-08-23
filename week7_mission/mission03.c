//중위표기법->후위표기법 변환 프로그램

#include <stdio.h>
#include <stdlib.h> //exit(), free(), malloc()
#include <string.h> //strlen()
#define MAX 1000

typedef struct StackNode{
    char data;
    struct StackNode* next;
}StackNode;

StackNode* createStackNode(char data) {
    StackNode* node = (StackNode*)malloc(sizeof(StackNode));
    if(!node){
        printf("failed to create node\n");
        exit(1);
    }
    node->data = data;
    node->next = NULL;
    return node;
}

int isEmpty(StackNode* root){
    return !(root->next);
}

void push(StackNode* root, char data) {
    StackNode *node = createStackNode(data);

    node->next = root->next;
    printf("%c pushed to stack\n", node->data);
    root->next = node;
    printf("    %c \n", root->next->data);
}

int pop(StackNode* root) {
    if (isEmpty(root)){
        printf("queue is empty. can't pop\n");
        return -99;
    }
    int popped = root->next->data;

    StackNode *tmp = root->next;
    root->next = root->next->next;
    printf("%d pop from stack\n", tmp->data);
    free(tmp);
    return popped;
}

void printStack(StackNode* stack){
    if(isEmpty(stack)){
        printf("queue is empty. there's nothing\n");
        return;
    }
    printf("stack print: ");

    StackNode* tmp = stack->next;
    printf("%c ", tmp->data);
    while(tmp->next != NULL){
        printf("%c ", tmp->data);
        tmp = tmp->next;
    }
    printf("\n");
}


int main(void){
    StackNode *stack = (StackNode*)malloc(sizeof(StackNode));    //연산자,(,)를 담을 스택 (made by 연결 리스트)
    char formula[MAX];  //사용자에게 입력받는 문자열
    char result[MAX];   //후위 표기법 문자열
    int j = 0;  //result에 값 추가
    int check = 0;

    printf("<<중위 표기법을 후위 표기법으로 변환하는 프로그램>>\n");
    printf("계산식을 중위 표기법으로 입력하세요.\n=>");
    scanf("%s", formula);

    for(int i = 0; i < strlen(formula); i++){   //중위 표기법을 왼->오 차례대로 읽음
        printf("%d. ",i+1);

        //숫자일 때
        if((int)formula[i] < 58 && (int)formula[i] >= 47){
            printf(" 숫자:  %d ",(int)formula[i]);
            result[j++] = formula[i];
        //연산자일 때
        }else{
            printf(" 연산자");
            //(1) '(' 속에 있는 경우
            if (check > 0){
                //(1)-1. ')'인 경우
                if(formula[i] == ')'){
                    check--;    //'('속에서 나오므로 check감소
                    while(stack->next->data != '('){    //'(' 전까지 스택을 pop함
                        result[j++] = pop(stack);   //pop한 것을 result에 저장
                    }
                    pop(stack); //'('는 버린다.
                //(1)-2. 닫는 괄호가 나오기 전까지 모든 연산자를 push한다.
                }else{
                     push(stack, formula[i]);    //무조건 push
                }
            //(2) 괄호 바깥에 있는 경우
            }else{
                //(2)-1. (인 경우
                if(formula[i] == '('){  //check+1하여 '('속에 있음 알림
                    check++;
                    push(stack, formula[i]);    //자신('(')을 push
                //(2)-2. -,+인 경우
                }else if(formula[i] == '-' || formula[i] == '+'){
                    printf("(-,+인지 확인)formula[i]: %c ",formula[i]);
                    //stack의 값을 모두 pop
                    while(stack->next != NULL){
                        result[j++] = pop(stack);   //result에 pop한 값을 저장
                    }
                    //자신을 push
                    push(stack, formula[i]);

                //(2)-3. 우선 연산자(*,/,%)인 경우
                }else if(formula[i] == '*' || formula[i] == '/' || formula[i] == '%'){
                    while(stack->data == '+' || stack->data == '-'){    //+나-나올 때까지
                        //result에 pop한 값을 저장
                        result[j++] = pop(stack);
                    }
                    push(stack, formula[i]);    //자신을 push
                }else{
                    printf("연산자가 아닌 것이 있습니다. 다시 실행해주세요.\n");
                    exit(1);
                }
            }
        }
        printf("\n");
        printStack(stack);
    }
    while(stack->next != NULL){
        result[j++] = pop(stack);
    }
    printf("result: %s\n", result);
}
