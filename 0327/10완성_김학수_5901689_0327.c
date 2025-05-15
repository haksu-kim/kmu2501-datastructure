#include <stdio.h>
#include <stdlib.h>

int main() {

    int **i_arr, **j_arr, **result;

        i_arr = (int **)malloc(sizeof(int*)*2);
        j_arr = (int **)malloc(sizeof(int*)*2);
        result = (int **)malloc(sizeof(int*)*2);

    for(int i=0; i<2; i++) {
        i_arr[i] = (int *)malloc(sizeof(int)*2);
        j_arr[i] = (int *)malloc(sizeof(int)*2);
        result[i] = (int *)malloc(sizeof(int)*2);
    }

    printf("첫 번째 2x2 행렬 입력 : \n");
    
    for(int i=0; i<2; i++) {
        for(int j=0; j<2; j++) {
            scanf("%d", &i_arr[i][j]);
        }
    }

    printf("두 번째 2x2 행렬 입력 : \n");
    
    for(int i=0; i<2; i++) {
        for(int j=0; j<2; j++) {
            scanf("%d", &j_arr[i][j]);
        }
    }

    for(int i=0; i<2; i++) {
        for(int j=0; j<2; j++) {
            result[i][j] = i_arr[i][j] + j_arr[i][j];
        }
    }
        
    printf("행렬 덧셈 결과 : \n");
    
    for(int i=0; i<2; i++) {
        for(int j=0; j<2; j++) {
            printf("%d ", result[i][j]);
        }
            printf("\n");
    }

    free(i_arr);
    free(j_arr);
    free(result);

    return 0;
}