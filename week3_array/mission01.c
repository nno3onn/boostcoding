/*팀원들의 요구로 인해 주석 설명 추가하였음*/

#include <stdio.h>
#include <cs50.h>
#include <stdlib.h> //atoi()
#include <string.h> //strlen()

void printTable(const char* name, const char* score[], int length);
//점수, 학점 테이블을 띄우는 함수
void loop_ft(void);
//사용자의 성적을 입력 받고 학점을 알려주는 함수. '999'를 입력받기 전까지 계속 반복함
int* charToint(const char *array[], const int length);
/*char형으로 된 score[]를 int형으로 바꾼 배열을 출력하는 함수.
사실 처음부터 score[]를 int형 배열로 만들고 printTable없이 띄워줘도 되지만, 
샘플미션에서의 charArrayToIntArray함수를 보고 이렇게 하면 더 편할 것 같아서 그냥 응용해보았음*/
char* calculate( int student_score, int size);
//사용자에게 입력 받은 성적을 학점으로 계산해주는 함수

//아래 3개는 모두 전역변수(사용자 지정 함수에서도 사용하기 위함)
const int length = 9;
const char* score[] = {"95", "90", "85", "80", "75", "70", "65", "60", "0"};
const char* rank[] = {"A+","A","B+","B","C+","C","D+","D","F"};
const int* score_int = NULL;

int main(void){
    printf("학점 프로그램\n");
    printf("종료를 원하면 '999'를 입력\n");

    printf("[학점 테이블]\n");
    printTable("점수", score, length);
    printTable("학점", rank, length);

    loop_ft();
    return 0;
}

void printTable(const char* name, const char* table[], int size){
    printf("%s : ",name);

    for(int i=0; i<size; i++){
        printf("%s\t",table[i]);
    }
    printf("\n");
}

void loop_ft(void){
    int student_score = get_int("성적을 입력하세요 (0 ~ 100) : ");
    
    if(student_score == 999){
        printf("학점 프로그램을 종료합니다.\n");
        exit(1);
    }else if(student_score > 100 || student_score < 0){
        printf("** %i 성적을 올바르게 입력하세요. 범위는 0 ~ 100 입니다.\n", student_score);
        loop_ft();
    }else{
        score_int = charToint(score, length);
        char* grade = calculate(student_score, length);

        printf("학점은 %s 입니다.\n", grade);
        loop_ft();
    }
}

int* charToint(const char* array[], const int size){
    int *result = malloc(sizeof(int)*size);

    for(int i = 0; i < size; i++){
        result[i] = atoi(array[i]);
    }
    return result;
}

char* calculate(int student_score, int size){
    char* grade = malloc(sizeof(char)*strlen(rank[0]));

    for(int i=0; i<size; i++){
        if(student_score >= score_int[i]){
            strcpy(grade,rank[i]);
            break;
        }
    }
    return grade;

/*혹은, 샘플미션에서 작성된 아래 코드로도 작성이 가능하다.
위의 코드도 가능한 이유는, rank[]함수는 포인터이므로 배열 속 각 data는 "주소"를 담고 있기 때문.
따라서 rank[0], rank[1], rank[2], ... 모두 "크기"가 동일하다. */
    // char* grade;

    // for(int i=0; i<size; i++){
    //     if(student_score >= score_int[i]){
    //         grade = malloc(sizeof(char)*strlen(rank[i]));
    //         strcpy(grade,rank[i]);
    //         break;
    //     }
    // }
    // return grade;
}
