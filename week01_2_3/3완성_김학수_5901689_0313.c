#include <stdio.h>
#include <string.h>

int main() {
    char l[256]; //문자열 저장 배열
    int len = 0; //문자열 길이 변수 초기화

    printf("문자열을 입력하세요 : ");

    fgets(l, sizeof(l), stdin); //공백을 포함해 입력받기 위해 scanf대신 fgets 함수 사용
    len =strlen(l)-1; //문자열 길이 계산

    printf("문자열의 길이 : %d\n", len);

    for(int i=0; i<len; i++) {
        if(l[i] >='a' && l[i] <='z') {
            l[i] -= 32;
        }//소문자를 대문자로 변환
        else if(l[i] >= 'A' && l[i] <= 'Z') {
            l[i] += 32;
        }//대문자를 소문자로 변환
    }
    printf("변환된 문자열 : %s\n", l);

    return 0;
}