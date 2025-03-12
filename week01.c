#include <stdio.h>

void Bit(unsigned int i) { //Bit함수 생성
    for(int k=31; k>=0; k--) { //k가 31부터 -1씩 감소하며 0까지 printf 반복
        printf("%d", (i>>k) & 1); // 비트를 추출하면서 추출 된 비트값을 오른쪽으로 k만큼 밀어낸다
    }
}

int main() {
    int i;
    printf("정수를 입력하세요 : ");
    scanf("%d", &i); //정수값 받기
    Bit(i); // Bit함수에 값 대입
    return 0;
}
