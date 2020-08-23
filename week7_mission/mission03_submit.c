#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
    root->next = node;
}

int pop(StackNode* root) {
    if (isEmpty(root)){
        printf("queue is empty. can't pop\n");
        return -99;
    }
    int popped = root->next->data;

    StackNode *tmp = root->next;
    root->next = root->next->next;
    free(tmp);
    return popped;
}


int main(void){
    StackNode *stack = (StackNode*)malloc(sizeof(StackNode));
    char formula[MAX];
    char result[MAX];
    int j = -1;
    int check = 0;

    printf("<<중위 표기법을 후위 표기법으로 변환하는 프로그램>>\n\n");
    printf("계산식을 중위 표기법으로 입력하세요.\n=> ");
    scanf("%s", formula);

    for(int i = 0; i < strlen(formula); i++){


        if((int)formula[i] < 58 && (int)formula[i] >= 47){
            result[++j] = formula[i];


        }else{

            if (check > 0){
                if(formula[i] == ')'){
                    check--;
                    while(stack->next->data != '('){
                        result[++j] = pop(stack);
                    }
                    pop(stack);
                }else{
                     push(stack, formula[i]);
                }

            }else{
                if(formula[i] == '('){
                    check++;
                    push(stack, formula[i]);

                }else if(formula[i] == '-' || formula[i] == '+'){
                    while(stack->next != NULL){
                        result[++j] = pop(stack);
                    }
                    push(stack, formula[i]);


                }else if(formula[i] == '*' || formula[i] == '/' || formula[i] == '%'){
                    while(stack->data == '+' || stack->data == '-'){
                        result[++j] = pop(stack);
                    }
                    push(stack, formula[i]);
                }else{
                    printf("연산자가 아닌 것이 있습니다. 다시 실행해주세요.\n");
                    exit(1);
                }
            }
        }
    }
    while(stack->next != NULL){
        result[++j] = pop(stack);
    }

    printf("결과: %s\n\n", result);

}
