#include <stdio.h>

// 덧셈 함수
int add();

// 뺄셈 함수
int subtract();

// 곱셈 함수
int multiply();

// 나눗셈 함수
float divide();

int main() {
    int num1, num2;

    // 사용자로부터 양의 정수 입력받기
    printf("첫 번째 양의 정수를 입력하세요: ");
    scanf("%d", &num1);

    printf("두 번째 양의 정수를 입력하세요: ");
    scanf("%d", &num2);

    // 사칙연산 결과 출력
    printf("덧셈: %d\n", add(/*해당 함수에 필요한 변수를 구현한다.*/));
    printf("뺄셈: %d\n", subtract(/*해당 함수에 필요한 변수를 구현한다.*/));
    printf("곱셈: %d\n", multiply(/*해당 함수에 필요한 변수를 구현한다.*/));
    printf("나눗셈: %.2f\n", divide(/*해당 함수에 필요한 변수를 구현한다.*/));

    return 0;
}

int add(/*해당 함수에 필요한 변수를 구현한다.*/) {
    // 해당 함수의 기능을 구현한다.
}

// 뺄셈 함수
int subtract(/*해당 함수에 필요한 변수를 구현한다.*/) {
    // 해당 함수의 기능을 구현한다.
}

// 곱셈 함수
int multiply(/*해당 함수에 필요한 변수를 구현한다.*/) {
    // 해당 함수의 기능을 구현한다.
}

// 나눗셈 함수
float divide(/*해당 함수에 필요한 변수를 구현한다.*/) {
    // 해당 함수의 기능을 구현한다.
}
