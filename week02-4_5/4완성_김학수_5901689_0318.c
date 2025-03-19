/*
의사코드
1. 사용자로부터 정수 N을 변수 i에 입력받는다.
2. N이하의 소수를 찾기 위해 k가 2부터 1씩 증가하며 N-1까지 반복하는 for반복문을 실행한다.
    2-1. 소수에 대해 참과 거짓을 판별을 위한 변수 prime을 1로 설정한다.
    2-2. 2부터 k-1까지의 k가 1씩 증가하며 그 값에 대해 나누는 값을 생성해주는 for반복문을 실행한다.
        -만약 k가 나누어 떨어져 나머지가 0이면 k는 소수가 아니다.
        -변수 prime을 0으로 설정하며 k가 소수가 아니라는 것을 표현한다.
    2-3. prime값이 1. 즉, 조건에 맞는 값이 존재한다면, 값을 출력한다.

*/

#include <stdio.h>

int main() {

    int i;

    printf("정수 N을 입력하세요 : ");
    scanf("%d", &i);
    printf("%d 이하의 소수 : ",i);

    for(int k=2; k<=i-1; k++) {
        int prime = 1;

        for(int div=2; div<k; div++) {
            if(k%div==0) {
                prime = 0;
                break;
            }
        }
        if(prime) {
            printf("%d ", k);
        }
    }
    return 0;
}