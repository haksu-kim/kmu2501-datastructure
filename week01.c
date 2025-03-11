#include <stdio.h>

void Bit(unsigned int i) {
    for(int k=31; k>=0; k--) {
        printf("%d", (i>>k) & 1);
    }
}

int main() {
    int i;
    printf("정수를 입력하세요 : ");
    scanf("%d", &i);
    Bit(i);
    return 0;
}