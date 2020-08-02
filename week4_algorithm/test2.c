#include <stdio.h>

int* whatnumber(const int *a,int b[]);
int isthissame(const int *a,int b[]);

int main(void) {
    int number_1[5] = {1,2,3,4,5};
    int number_2[5]={2,3,5,4,8} ;
    int num_1[10]={0,0,0,0,0,0,0,0,0,0};
    int num_2[10]={0,0,0,0,0,0,0,0,0,0};


    if(sizeof(number_1)==sizeof(number_2)){

        int* result_arr1= whatnumber(number_1,num_1);
        int* result_arr2= whatnumber(number_2,num_2);
        int isitsame=isthissame(result_arr1,result_arr2);

        if(isitsame==1){
            printf("true\n");
        }else{
            printf("false\n");
        }
    }
    else{
        printf("false\n");
    }
    return 0;
}

int* whatnumber(const int *a,int b[]){
    for(int i=0;i<5;i++){
        b[a[i]-1]+=1;
    }
    return b;
}

int isthissame(const int *a,int b[]){
    for(int i=0; i<10; i++){
        if(a[i]!=b[i]){
            return 0;
        }
    }
    return 1;
}
