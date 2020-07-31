#include <stdio.h>  //fopen, fgets, fclose
#include <cs50.h>
#include <stdlib.h> //exit()

int main(void){
    char num[20];
    FILE *fp = fopen("10.txt", "r");

    fgets(num, sizeof(num), fp);

    if (fp == NULL) {
        fprintf(stderr, "Can't open input file in.list!\n");
        exit(1);
    }else{  
        printf("%s\n",num); //읽어온 데이터는 문자열로 저장됨
    }
    
    fclose(fp);

}
