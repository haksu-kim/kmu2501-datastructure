#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

listType *add_Con(int size) {
    
    listType* lptr;
    lptr = (listType*)malloc(sizeof(listType));
    lptr->array = (elementType *)malloc(sizeof(elementType)*size);
    lptr->size = size;
    lptr->last = -1;
    lptr->move = 0;

    return lptr;
}

int insert_Con(listType *list, int index, elementType item) {
    if(index<0 || index>(list->last+1)) {
        fprintf(stderr,"Index error %d in readItem\n", index); //stderr 에러메시지가 우선권을 가지는 방법
        // 1. return (elementType)-1;
        return -1;
    }
    if(index>list->size) {
        fprintf(stderr,"Iist is full(%d) in readItem\n", index); //stderr 에러메시지가 우선권을 가지는 방법
        // 1. return (elementType)-1;
        return -1;
    }
    for(int i=list->last+1; i>index; i--) {
        list->array[i] = list->array[i-1];
    }
    list->array[index].order = index;
    strcpy(list->array[index].name, item.name);  // 문자열 복사
    strcpy(list->array[index].number, item.number);  // 문자열 복사
    
    list->array[index] = item;
    list->last++;
    
    return 0;
}

int print_Con(listType *list) {
    for(int i=0; i<=list->last; i++) {
        printf("[%d] 이름 : %s, 전화번호 : %s\n", list->array[i].order, list->array[i].name, list->array[i].number);
    }
    return 0;
}

int search_Con(listType *list, char *name) {
    //name으로 리스트에서 검색해서 그 name의 인덱스 추출
    for(int i=0; i<=list->last; i++){
        if(strcmp(name, list->array[i].name) == 0) {
            printf("[%d] 이름 : %s, 전화번호 : %s", i, list->array[i].name, list->array[i].number);
        }
        if(strcmp(name, list->array[i].name) != 0) {
            printf("존재하지 않는 연락처 입니다.\n");
        }
    }//이름으로 인덱스 찾기
    return 0;
}

elementType delete_Con(listType *list, char *name) {
    int index=0;
    for(int i=0; i<=list->last; i++) {
        if(strcmp(list->array[i].name, name) == 0) {
            index = list->array[i].order;
            //index = i;
            break;
        }
        index++;
    }
    elementType r = list->array[index];
    if(index<0 || index>list->last) {
        fprintf(stderr,"Index error %d in readItem\n", index); //stderr 에러메시지가 우선권을 가지는 방법
        // 1. return (elementType)-1;
        return NULL_ITEM;
    }
    for(int i=index; i<=list->last; i++) {
        if(strcmp(r.name, list->array[i].name) == 0) {
            list->array[i] = list->array[i+1];
            list->move++;
        }
    }
    list->last--;
    return r;
}

void menu_print(void) {
    printf("\n===== 전화번호부 메뉴 ======\n");
    printf("1. 연락처 추가\n");
    printf("2. 연락처 삭제\n");
    printf("3. 연락처 검색\n");
    printf("4. 전체 연락처 출력\n");
    printf("0. 종료\n");
}
