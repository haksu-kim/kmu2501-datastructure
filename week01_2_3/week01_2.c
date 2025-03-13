#include <stdio.h>

void ShowBits(int count, unsigned int num, int start_bit,int end_bit) {
    int show_bit_count = end_bit - start_bit + 1;
     num = (num << start_bit);
    num = num >> (count - show_bit_count);

    int bit_index = show_bit_count - 1;

    for(int k=0; k<show_bit_count; k++) {
        printf("%d", (num & (1 << bit_index)) >> bit_index);
        bit_index--;
    }//for
    printf("\n");
}

int main() {

    float i;
    printf("실수를 입력하시오 : ");
    scanf("%f", &i);
    int *p = (int *)&i;

    printf("부호 (1비트) : ");
    ShowBits(1, *p, 0, 0);
    printf("지수 (8비트) : ");
    ShowBits(8, *p, 1, 8);
    printf("지수 (23비트) : ");
    ShowBits(8, *p, 9, 31);

    return 0;
}

// split or 교수님 집어줒신 것