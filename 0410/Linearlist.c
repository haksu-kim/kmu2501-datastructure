#include <stdio.h>
#include <stdlib.h>
#include "Linearlist.h"
//CRUD-PI Program

//createList
listType *createList(int size) {
    listType* lptr;

    lptr = (listType*)malloc(sizeof(listType));
    //메모리에 운영체제를 달라고 한다. listType만큼 그리고 그 주어진 메모리만큼 listtype의 주소에 등록한다
    //현재 공간이 비어있는 상태.
    lptr->array = (elementType *)malloc(sizeof(elementType)*size); //4바이트 정수에 size를 곱한 만큼 공간을 받는다
    lptr->size = size;
    lptr->last = -1;
    lptr->move = 0;
    return lptr;
    //create function
}

int destroyList(listType* list) {
    free(list->array);
    free(list);
    
    return 0;
}

//readItem
elementType readItem(listType *list, int index){
    if(index<0 || index>list->last) {
        fprintf(stderr,"Index error %d in readItem\n", index); //stderr 에러메시지가 우선권을 가지는 방법
        // 1. return (elementType)-1;
        return NULL_ITEM;
    }
    // 1. return *(list->array+index)
    return list->array[index];
}

int ordered_insertItem(listType *list, elementType item) {
    int i;

    // 동일한 차수의 항이 있는지 확인
    for (i = 0; i <= list->last; i++) {
        if(list->array[i].expo == item.expo) {
            list->array[i].coef += item.coef;
            if(list->array[i].coef == 0) {
                deleteItem(list, i);
            }
            return 0;
        }
    }

    for(i = list->last; i>=0 && list->array[i].expo < item.expo; i--) {
        list->array[i+1] = list->array[i];
        list->move++;
    }
    list->array[i+1] = item;
    list->last++;
    /*
    printf("Item: ");
    for(int j=0; j<=list->last; j++) {
        printf(" %dx^%d ", list->array[j].coef, list->array[j].expo);
    }
    printf("\n");
*/
    return 0;
}

//insertItem
int insertItem(listType *list, int index, elementType item) {
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
        list->move++;
    }
    list->array[index] = item;
    list->last++;
    
    return 0;
}

int removeItem(listType *list, int index) {
    if(index<=0 || index>list->last) {
        fprintf(stderr, "Index erro %d in removeItem\n", index);
        return -1;
    }
    for(int i=index; i<list->last; i++){
        list->array[i] = list->array[i+1];
    }
    list->last--;
    return 0;
}

//deleteItem
elementType deleteItem(listType *list, int index) {
    elementType r = list->array[index];

    if(index<0 || index>list->last) {
        fprintf(stderr,"Index error %d in readItem\n", index); //stderr 에러메시지가 우선권을 가지는 방법
        // 1. return (elementType)-1;
        return NULL_ITEM;
    }
    for(int i=index; i<=list->last; i++) {
        list->array[i] = list->array[i+1];
        list->move++;
    }//move
    list->last--;
    return r;
}

int printList(listType *list) {
    for (int i = 0; i <= list->last; i++) {
        elementType item = list->array[i];
/*
        if(item.coef > 0 && i > 0) {
            printf("+");
        } else if(item.coef < 0) {
            printf("-");
        }
  */
        // 계수 출력
        /*
        if (item.coef != 1 && item.coef != -1) {
            printf("%d", item.coef);
        } else if(item.coef > 1) {
            printf("+");
        } else if(item.coef < 1) {
            printf("-");
        }*/
        if(item.coef >= 1 && i>0) {
            printf("+%d", item.coef);
        } else if(item.coef >= 1 && i==0) {
            printf("%d", item.coef);
        } else if(item.coef < -1) {
            printf("%d", item.coef);
        } else if(item.coef == -1) {
            printf("-");
        }

        // 지수 출력
        if (item.expo > 1) {
            printf("x^%d", item.expo);
        } else if (item.expo == 1) {
            printf("x");
        } else if (item.expo == 0) {
            if (item.coef == 1 || item.coef == -1) {
                printf("");
            }
        }



    }
    printf("\n");
    return 0;
}

//initList
int initList(listType *list) {
    list->last = -1;
    list->move = 0;
    
    return 0;
}
