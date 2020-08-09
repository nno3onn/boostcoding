#include <cs50.h>
#include <stdio.h>
int *bubble_sort(int arr[], int length);
int compare(int *A, int *B);
void print(int* arr);

int main()
{
    int NUMBER1[5] = {1,2,3,4,5};
    int NUMBER2[5] = {1,2,3,4,5};

    int* a=bubble_sort(NUMBER1,5);
    int* b=bubble_sort(NUMBER2,5);

    compare(a, b);
    return 0;
}
/////////// 버블 정렬 함수
int* bubble_sort(int arr[], int length)
{
    int temp;
    for(int i=0; i < length-1; i++)
    {
        for(int j=0; j<length-i-1; j++)
        {
            if(arr[j] > arr[j+1])
            {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    return arr;
}


//////////////비교 함수(compare)
int compare(int* A, int* B)
{

    // for (int i = 0; i < 5; i++){
    //     if(*(A+1) != *(B+1)){
    //         printf("false\n");
    //         return 1;
    //     }
    // }

    int i = 0;
    while(i < 5)
    {
        printf("i1:%i \n", i);
        if(*(A+i) != *(B+i))
        {
            printf("i: %i, ",i);
            printf("A: %i, ",*(A+i));
            printf("B: %i ",*(B+i));
            printf("A2: %i, ",*(A+1));
            printf("B2: %i",*(B+1));
            printf("\nfalse\n");
            return 1;
        }
        else
        {
            i++;
        }
    }
     printf("true\n");
     return 0;
}

void print(int* arr){
    for(int i = 0; i < 5; i++){
        printf("%i",arr[i]);
    }
    printf("\n");
}