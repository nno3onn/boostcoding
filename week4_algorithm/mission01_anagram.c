#include <stdio.h>
#include <string.h> //strneln(), strcpy_s(char *dest, int dest_size(dest가 가리키는 메모리의 크기), const char *src);
#define MAX 256

void test_anagram(const char* s1, const char* s2);
int is_anagram(const char* s1, const char* s2);

int main(void){
    test_anagram("silent","listen");
    test_anagram("garden","ranged");
    test_anagram("split","lisp");
    test_anagram("ssss","sssw");
    test_anagram("aaff","afff");
    test_anagram("afff","aaff");

    return 0;
}

void test_anagram(const char* s1, const char* s2){
    if(is_anagram(s1,s2)){  //return 1;
        printf("%s %s : anagram\n", s1, s2);
    }else{  //return 0;
        printf("%s %s : not anagram\n",s1, s2);
    }
}

int is_anagram(const char* s1, const char* s2){
    int i, j;
    int check;

    if(strlen(s1) != strlen(s2)){
        return 0;   //anagram (X)
    }

    char buf[MAX] = ""; //s1을 복사하는 문자열
    strcpy(buf, s1);

    for(i = 0; s2[i]; i++){ //s2[i]가 종료문자. 즉, 거짓이면 종료
        check = 0;  //check=0(거짓)으로 초기화 (s2[i]에 종료문자 없음)
        for(j = 0; buf[j]; j++){    //buf[j]가 종료문자. 즉, 거짓이면 종료
            if(s2[i] == buf[j]){
                printf("buf+j: %c\n",buf+j);
                printf("buf+j+1: %c\n",buf+j+1);
                strcpy(buf+j, buf+j+1); //buf+j를 buf+j+1로 변경 (문자열 buf에서 buf+j이후 부분이 buf+j+1로 변경되므로 j번째 문자가 제거됨)
                printf("%s\n", buf);
                check = 1;  // 같으면 check=1
                break;
            }
            printf("%s\n", buf);
        }
        if(check == 0){
            return 0;   //anagram (X)
        }
    }
    return 1;   //anagram (O)
}