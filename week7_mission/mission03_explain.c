//중위표기법->후위표기법 변환 프로그램

#include <stdio.h>
#include <stdlib.h> //exit(), free(), malloc()
#include <string.h> //strlen()
#define MAX 1000

typedef struct StackNode{   // 연결 리스트로 스택을 구현
    char data;  // 스택에 연산자,(,)가 들어가므로 자료형은 char임
    struct StackNode* next;
}StackNode;

StackNode* createStackNode(char data) {
    StackNode* node = (StackNode*)malloc(sizeof(StackNode));
    // malloc 사용 후, stack이 잘 생성되었는지 확인
    if(!node){
        printf("failed to create node\n");
        exit(1);    // 생성되지 않았다면 프로그램 종료 (node를 다룰 수 없기 때문)
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
    // stack이 비어있는지 확인
    if (isEmpty(root)){
        printf("queue is empty. can't pop\n");
        return -99; // 비어있으면 함수를 빠져나온다
    }
    int popped = root->next->data;  // popped에 pop될 값을 넣음

    StackNode *tmp = root->next;
    root->next = root->next->next;  // 스택 업데이트
    free(tmp);  // pop한 노드를 메모리 해제함

    return popped;
}


int main(void){
    StackNode *stack = (StackNode*)malloc(sizeof(StackNode));    //연산자,(,)를 담을 스택 (made by 연결 리스트)
    char formula[MAX];  // 사용자에게 입력받는 문자열
    char result[MAX];   // 후위 표기법 문자열
    int j = -1;  // result에 값이 추가될 떄마다 +1
    int check = 0;  // (괄호) 속에 값이 있는지 없는지 확인하는 변수

    printf("<<중위 표기법을 후위 표기법으로 변환하는 프로그램>>\n\n");
    printf("계산식을 중위 표기법으로 입력하세요.\n=> ");
    scanf("%s", formula);   //사용자에게 식을 받아옴

    for(int i = 0; i < strlen(formula); i++){   //중위 표기법을 왼->오 차례대로 읽음

        //1. 숫자일 때
        if((int)formula[i] < 58 && (int)formula[i] >= 47){  // ASCII로 숫자 1~9는 47~57
            result[++j] = formula[i];   // 숫자는 그대로 출력되므로 바로 저장한다

        //2. 연산자,(,)일 때
        }else{
            //(1) '(' 속에 있는 경우
            if (check > 0){
                //(1)-1. ')'인 경우
                if(formula[i] == ')'){
                    check--;    // '(괄호)'속에서 나오므로 check 감소시킴
                    while(stack->next->data != '('){    // '(' 전까지 스택을 pop함
                        result[++j] = pop(stack);   // pop한 것을 result에 저장
                    }
                    pop(stack); // '('는 버린다.

                //(1)-2. 연산자인 경우
                }else{
                     push(stack, formula[i]);    //')'가 나오기 전까지 모든 연산자는 무조건 push한다
                }


            //(2) (괄호) 바깥에 있는 경우
            }else{
                //(2)-1. '('인 경우
                if(formula[i] == '('){
                    check++;    //check+1하여 '('속에 있음 알림
                    push(stack, formula[i]);    //자신('(')을 push

                //(2)-2. -,+인 경우 : 가장 낮은 연산자이므로 스택의 값들을 모두 pop함
                }else if(formula[i] == '-' || formula[i] == '+'){
                    // stack의 값을 모두 pop
                    while(stack->next != NULL){
                        result[++j] = pop(stack);   //result에 pop한 값을 저장
                    }
                    //자신을 push
                    push(stack, formula[i]);

                //(2)-3. 우선 연산자(*,/,%)인 경우
                }else if(formula[i] == '*' || formula[i] == '/' || formula[i] == '%'){
                    // 낮은 연산자(+,-)가 나오기 전까지 연산자들(*,/,%)을 pop한다
                    while(stack->data == '+' || stack->data == '-'){
                        result[++j] = pop(stack);   //result에 pop한 값을 저장
                    }
                    push(stack, formula[i]);    // 자신을 push

                //(2)-4. 앞에서 나온 연산자가 아닌 문자일 경우
                }else{
                    printf("연산자가 아닌 것이 있습니다. 다시 실행해주세요.\n");
                    exit(1);    // 프로그램을 종료시킨다
                }
            }
        }
    }
    // 마지막으로 스택에 남은 값들을 pop하고 그 값들을 result에 저장
    while(stack->next != NULL){
        result[++j] = pop(stack);
    }

    //후위표기법 결과 출력
    printf("결과: %s\n\n", result);

    //스택에 들어간 모든 노드는 pop하였기 때문에 남은 노드가 없으므로 스택 안의 모든 노드를 돌며 메모리 해제할 필요가 없다.
}
