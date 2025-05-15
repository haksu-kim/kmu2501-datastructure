#include <stdio.h>

void ShowBits(int count, unsigned int num, int start_bit,int end_bit) { //비트 출력 함수 정의
    int show_bit_count = end_bit - start_bit+1; // 출력할 비트 개수 계산
    num = (num >> start_bit); //num을 start_bit만큼 오른쪽으로 이동

    int bit_index = show_bit_count - 1; //최상위 비트부터 출력할 수 있도록 변수 설정

    for(int k=bit_index; k>=0; k--) {
        printf("%d", (num >> k)&1);
    }//num을 k만큼 오른쪽으로 밀고, 맨 오른쪽 비트 값만 출력
    printf("\n");
}

int main() {

    float i;
    printf("실수를 입력하시오 : ");
    scanf("%f", &i);

    int *p = (int *)&i; //부동소수점 내부 비트 구조를 확인하기 위한. i값을 정수형 비트로 접근 

    printf("부호 (1비트) : ");
    ShowBits(1, *p, 31, 31);
    printf("지수 (8비트) : ");
    ShowBits(8, *p, 23, 30);
    printf("가수 (23비트) : ");
    ShowBits(23, *p, 0, 22);

    return 0;
}