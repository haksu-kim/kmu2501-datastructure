/*
    int 첫 번째, 두 번째, 결과값 2차원 배열 선언
    print 첫 번째 행렬
    for 0부터 2까지
        for 0부터 2까지
            scanf 첫 번째 행렬
    print 두 번째 행렬
    for 0부터 2까지
        for 0부터 2까지
            scanf 두 번째 행렬
    print 행렬 덧셈 결과
    for 0부터 2까지
        for 0부터 2까지
            print 결과값 행렬

*/
#include <stdio.h>

int main() {

    int i_arr[2][2], j_arr[2][2], result[2][2];

    printf("첫 번째 2x2 행렬 입력 : \n");
    
    for (int i=0; i<2; i++) {
        for (int j=0; j<2; j++) {
            scanf("%d", &i_arr[i][j]);
            }
        }

    printf("두 번째 2x2 행렬 입력 : \n");
    
    for (int i=0; i<2; i++) {
        for (int j=0; j<2; j++) {
            scanf("%d", &j_arr[i][j]);
            }}

    printf("행렬 덧셈 결과 : \n");
    
    for(int i=0; i<2; i++) {
        for(int j=0; j<2; j++) {
            printf("%d ", i_arr[i][j]+j_arr[i][j]);
        }
            printf("\n");
    }

    return 0;
}