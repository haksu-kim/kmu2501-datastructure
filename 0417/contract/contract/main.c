#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

int main(void) {
    int index=0;
    listType *conList;
    conList = add_Con(MAX);
    
    while(1) {
        int num = 0;
        char name[MAX];
        char number[MAX];
        menu_print();
        printf("메뉴를 선택하세요 :");
        scanf("%d", &num);
        
        if(num == 1) { // 추가
            printf("이름을 입력하세요 : ");
            scanf("%s", name);
            printf("전화번호를 입력하세요 : ");
            scanf("%s", number);
            printf("연락처가 추가되었습니다.");
            elementType newContact;
            strcpy(newContact.name, name);
            strcpy(newContact.number, number);
            insert_Con(conList, index, newContact);
            index++;
        }
        if(num == 2) { // 삭제
            printf("삭제할 이름을 입력하세요 : ");
            scanf("%s", name);
            printf("삭제되었습니다.");
            delete_Con(conList, name);
            
        }
        if(num == 3) { // 검색
            printf("검색할 이름을 입력하세요 : ");
            scanf("%s", name);
            search_Con(conList, name);
        }
        if(num == 4) { // 전체 출력
            printf("----- 전체 연락처 -----\n");
            print_Con(conList);
        }
        if(num == 0) {
            break;
        }
    }
    
    
    
    return 0;
}
