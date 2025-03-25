/*
    첫 번째 2x2 행렬의 int 4개 변수 선언
    두 번째 2x2 행렬의 int 4개 변수 선언
    각 행렬 결과값 출력 int 4개 변수 선언

    int 2차원배열 초기화
    int 2차원배열 초기화

    print 첫 번째 2x2 행렬 입력
    
    scanf 첫 번째 배열의 두 값
    두 값 가로 0번 배열에 저장
    scanf 두 번째 배열의 두 값
    두 값 가로 1번 배열에 저장

    print 두 번째 2x2 행렬 입력
    scanf 두 번째 배열의 두 값
    두 값 가로 0번 배열에 저장
    scanf 두 번째 배열의 두 값
    두 값 가로 1번 배열에 저장

    print 각 행렬의 결과값
*/
#include <stdio.h>

int main() {

    int i_i, i_j, i_k, i_q;
    int j_i, j_j, j_k, j_q;
    int result1, result2, result3, result4;

    int i_arr[1][1] = {{},{}};
    int j_arr[1][1] = {{},{}};

    printf("첫 번째 2x2 행렬 입력 : \n");
    scanf("%d %d", &i_i, &i_j);
    i_arr[0][0] = i_i;
    i_arr[0][1] = i_j;
    scanf("%d %d", &i_k, &i_q);
    i_arr[1][0] = i_k;
    i_arr[1][1] = i_q;
    
    printf("두 번째 2x2 행렬 입력 : \n");
    scanf("%d %d", &j_i, &j_j);
    j_arr[0][0] = j_i;
    j_arr[0][1] = j_j;
    scanf("%d %d", &j_k, &j_q);
    j_arr[1][0] = j_k;
    j_arr[1][1] = j_q;

    //

    result1 = i_i+j_i;
    result2 = i_j+j_j;
    result3 = i_k+j_k;
    result4 = i_q+j_q;

    printf("행렬 덧셈 결과 : \n");
    printf("%d ", result1);
    printf("%d\n", result2);
    printf("%d ", result3);
    printf("%d\n", result4);

    return 0;
}