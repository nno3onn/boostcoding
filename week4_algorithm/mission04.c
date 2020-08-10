#include <stdio.h> // 표준입출력 (printf, scanf) 함수 이용
#include <stdlib.h> // calloc, free 함수를 이용하여 배열을 동적으로 할당 및 해제
#include <stdbool.h> // bool 자료형과 true, false 리터럴 사용

void cal_fall_depth(int *, int *, int); // 각 열에서 가장 많이 낙하하는 상자(최상단 상자)의 낙하거리 계산
int max_element(int *, int); // 배열에서 최대의 요소를 구하여 반환하는 함수

int main() {
    int room_length = 1, // 방의 가로 길이 N
        room_height = 1; // 방의 세로 길이 M

    while (room_length < 2 || room_length > 100 || room_height < 2 || room_height > 100) {
                             // 범위(2 ~ 100)내에 있을 때까지 N, M 값을 입력
        printf("Enter room length N and room height M (2 ~ 100), separated by a space: ");
        scanf("%d%d", &room_length, &room_height);
        while ((getchar()) != '\n'); // 입력 버퍼 초기화
    } // (의도한 입력 수보다 많이 입력한 경우 다음 입력으로 저장 방지)

    bool invalid_input = true; // 범위에서 벗어난 상자 높이값이 있는지 여부
    int i, *box_height = calloc(room_length, sizeof(int));
                                // 각 열의 상자 높이를 저장할 배열을 동적으로 할당
    while (invalid_input) { // N개의 모든 높이값이 범위(0 ~ M)에 맞을 때까지 입력
        printf("Enter box height values (0 ~ M) for N columns, with each value spaced: ");
        for (i = 0; i < room_length; i++)
            scanf("%d", &box_height[i]);
        while ((getchar()) != '\n');

        invalid_input = false;
        for (i = 0; i < room_length; i++) {
            if (box_height[i] < 0 || box_height[i] > room_height) {
                invalid_input = true;
                 break;
            }
        }
    } // (여기까지는 숫자들을 입력받는 부분)
    int *fall_depth = calloc(room_length, sizeof(int));
    // 각 열의 최상단 상자가 낙하하는 거리를 저장할 배열 초기화
    // (calloc 함수는 배열의 모든 요소를 0으로 초기화)
    cal_fall_depth(box_height, fall_depth, room_length);
    // 낙하거리 계산
    int max_depth = max_element(fall_depth, room_length);
    // 계산된 낙하거리 중 최댓값을 저장
    printf("The maximum drop distance is %d!\n", max_depth);
    // 최대 낙하거리 출력
    free(box_height); // 동적 할당 메모리 해제
    free(fall_depth);
}

void cal_fall_depth(int *heightV, int *depthV, int length) {
    // 각 열의 (최대) 낙하거리를 계산하는 함수의 정의
    for (int i = 0; i < length; i++)
        if (heightV[i] > max_element(heightV, i))
        // 왼쪽의 모든 열보다 더 높은 열들의 낙하거리만 필요하므로,
        // 나머지 열들은 낙하거리 미계산, 결과적으로 depthV[i] 값(0) 유지
            for (int j = i + 1; j < length; j++)
                if (heightV[j] < heightV[i])
                    depthV[i]++; // i번째 열보다 상자가 더 낮게 쌓인 i번째 이후 열의 개수가
} // 최종적으로 depthV[i]에 저장됨

int max_element(int *numV, int num) {
                        // 배열 요소들의 최댓값을 구하는 함수의 정의
    if (num <= 0)
        return 0;

    int max = numV[0];
    for (int i = 1; i < num; i++)
        if (numV[i] > max)
            max = numV[i];
    return max;
}
