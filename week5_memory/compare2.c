#include <stdio.h>
#include <string.h>

int main(){
	char *a = "EMMA";
    char *b = "EMMA";

    for(int i = 0; i < strlen(a); i++){
    	if(*(a+i) != *(b+i)){
        	printf("not same\n");
            return 0;
        }
    }
    printf("same\n");
	return 0;
}