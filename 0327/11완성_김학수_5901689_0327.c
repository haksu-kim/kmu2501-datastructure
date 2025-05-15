#include <stdio.h>
#include <stdlib.h>

struct student{
    char name[10];
    int id;
    int score;
};

int main() {

    int num;
    int student_id;

    printf("몇 명의 학생 정보를 입력하시나요 ? : ");
    scanf("%d", &num);

    struct student *students = (struct student *)malloc(num * sizeof(struct student));

    for(int i=0; i<num; i++) {
        printf("[%d] 학생의 정보를 입력하세요 (이름 학번 점수): ", num);
        scanf("%s %d %d", students[i].name, &students[i].id, &students[i].score);
    }

    while(1) {
        printf("학번을 입력하세요(0이면 종료)? ");
        scanf("%d", &student_id);

        if(student_id == 0) {
            break;
        }

        int found = 0;
        for (int i=0; i<num; i++) {
            if(students[i].id == student_id) {
                printf("%s %d %d\n", students[i].name, students[i].id, students[i].score);
                found = 1;
                break;
            }
        }
        if(!found) {
            printf("해당 학번의 학생이 없습니다.\n");
        }

    }

    return 0;

}