#include <stdio.h>
#define NUM_OF_PEOPLE 4
int timeOfPeople[NUM_OF_PEOPLE] = {1, 2, 5, 10};
int totalTime = 0;

void returnBridge(int fast)
{
    totalTime += timeOfPeople[fast];
    printf("%d\n", timeOfPeople[fast]);
}

void crossBridge(int slow, int slower)
{
    totalTime += timeOfPeople[slower];
    printf("%d %d\n", timeOfPeople[slow], timeOfPeople[slower]);
}

void bridge(int numOfPeople)
{
    if (numOfPeople == 1)
        returnBridge(0);
    else if(numOfPeople == 2)
       crossBridge(0, 1);
    else if(numOfPeople == 3)
    {
        crossBridge(0, 1);
        returnBridge(0);
        crossBridge(0, 2);
    }
    else
    {
        crossBridge(0, 1);
        returnBridge(0);
        crossBridge(numOfPeople - 2, numOfPeople - 1);
        returnBridge(1);
        bridge(numOfPeople - 2);
    }
}

int main(void)
{
    bridge(NUM_OF_PEOPLE);
    printf("Total Time: %d\n", totalTime);
}