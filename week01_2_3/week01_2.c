#include <stdio.h>

void ShowBits(int count, unsigned int num, int start_bit,int end_bit) {
    int show_bit_count = end_bit - start_bit;
    num = (num >> start_bit);

    int bit_index = show_bit_count - 1;

    for(int k=show_bit_count; k>=0; k--) {
        printf("%d", (num >> k)&1);
    }//for
    printf("\n");
}

int main() {

    float i;
    printf("실수를 입력하시오 : ");
    scanf("%f", &i);
    int *p = (int *)&i;

    printf("부호 (1비트) : ");
    ShowBits(1, *p, 31, 31);
    printf("지수 (8비트) : ");
    ShowBits(8, *p, 23, 30);
    printf("지수 (23비트) : ");
    ShowBits(23, *p, 0, 22);

    return 0;
}