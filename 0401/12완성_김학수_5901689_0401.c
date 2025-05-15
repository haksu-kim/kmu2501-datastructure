#include<stdio.h>
#include<stdlib.h>

int fibo_rec(int r) {
    if(r==0) {
        return 0;
    } else if(r==1) {
        return 1;
    } else {
        return (fibo_rec(r-1)+fibo_rec(r-2));
        }
}

int fibo_itr(int n) {
    int f;
    int f_1 = 1;
    int f_2 = 0;

    for(int i=2; i<=n; i++) {
        f = f_1 + f_2;
        f_2 = f_1;
        f_1 = f;
    }

    if(n==0) {
        return 0;
    } else if(n==1) {
        return 1;
    } else {
        return f; 
    }
}

int main() {
    int s;
    int m;

    while(1) {
    printf("피보나치 수열 방법 선택 (1: 재귀적, 2: 순환적, 0: 종료) : \n");
    scanf("%d", &s);
    //scanf("피보나치 수열 방법 선택 (1: 재귀적, 2: 순환적, 0: 종료) : \n");
    if(s==1){
        printf("정수 N을 입력하세요 (종료하려면 0 입력): ");
        scanf("%d", &m);
        printf("F(%d) = %d (재귀적 방법)\n", s, fibo_rec(m));
    } else if(s==2){
        printf("정수 N을 입력하세요 (종료하려면 0 입력): \n");
        scanf("%d", &m);
        printf("F(%d) = %d (순환적 방법)\n", s, fibo_itr(m));
    } else {
        printf("프로그램이 종료되었습니다.");
        return 1;
        }
    }
    return m;
}