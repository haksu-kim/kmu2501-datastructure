#include <stdio.h>

int main() {

    int i, k;
    
    printf("정수의 개수를 입력하세요 : ");
    scanf("%d", &i);
    int arr[i];

    printf("%d개의 정수를 입력하세요 :\n", i);
    for(int j=0; j<i; j++) {
        scanf("%d", &k);
        arr[j] = k;
    }//for

    for(int q=0; q<i; q++) {
        for(int p=q+1; p<i; p++) {
            if( arr[q] > arr[p] ) {
                int temp = arr[q];
                arr[q] = arr[p];
                arr[p] = temp;
            }//후에 더 큰 수가 있다면...
        }
    }

    printf("오름차순으로 정렬된 정수들 : \n");
    for(int a=0; a<i; a++) {
        printf("%d ", arr[a]);
    }

    return 0;
}