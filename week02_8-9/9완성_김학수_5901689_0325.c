/*
    두 개 변수 선언
    print 정수 개수 입력
    scanf 정수 개수
    정수 배열 선언

    print 정수 입력
    for 0부터 정수까지 배열에 저장

    for 0부터 정수까지 오름차순으로 배열 정렬
    
    print 정렬된 정수들
        for 0부터 정수까지
*/
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
            }
        }
    }

    printf("오름차순으로 정렬된 정수들 : \n");
    for(int a=0; a<i; a++) {
        printf("%d ", arr[a]);
    }

    return 0;
}