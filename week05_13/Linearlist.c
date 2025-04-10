#include <stdio.h>
#include <stdlib.h>
#include "Linearlist.h"
//CRUD-PI Program

//createList
listType *createList(int size) {
    listType* lptr;

    lptr = (listType**)malloc(sizeof(listType*));
    //메모리에 운영체제를 달라고 한다. listType만큼 그리고 그 주어진 메모리만큼 listtype의 주소에 등록한다
    //현재 공간이 비어있는 상태.
    lptr->array = (elementType **)malloc(sizeof(elementType*)*size); //4바이트 정수에 size를 곱한 만큼 공간을 받는다
    lptr->size = size;
    lptr->last = -1;
    lptr->move = 0;
    return lptr;
    //create function
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

int compare_item(elementType item1, elementType item2) {
    if (item1.row != item2.row) return (item1.row-item2.row);
    else return (item1.col - item2.col);
}

int ordered_insertItem(listType* list, elementType item) {
    int i, j;
    for(i=0; i<=list->last; i++) {
        if (compare_item(list->array[i], item) > 0) break;
    }
    for(int j=list->last+1; j>i; j--) {
        list->array[j] = list->array[j-1];
        list->move++;
    }
    list->array[i] = item;
    list->last++;

    return 1;

}

int sum_List(listType *list1, listType *list2) {
    int i, j=0;
    listType* a;
    elementType item1, item2;
    listType* result = createList(list1->size+list2->size);

    while(i<=list1->last && j<=list2->last) {
        item1 = readItem(list1, i);
        item2 = readItem(list2, j);

        if(item1.row == item2.row && item1.col == item2.col) {
            if(item1.val + item2.val != 0) {
                ordered_insertItem(result, (elementType){item1.val+item2.val});
            }
            i++;
            j++;
        } else if(item1.row < item2.row || (item1.row == item2.row && item1.col < item2.col)) {
            ordered_insertItem(result, item1);
            i++;
        } else {
            ordered_insertItem(result, item2);
            j++;
        }
}
    while(i<=list1->last) {
        ordered_insertItem(result, readItem(list1, i));
        i++;
    }
    while(j<=list2->last) {
        ordered_insertItem(result, readItem(list2, j));
        j++;
    }
    return result;
}//sum_List

//insertItem
int insertItem(listType *list, int index, elementType item) {
    if(index<0 || index>(list->last+1)) {
        fprintf(stderr,"Index error %d in readItem\n", index); //stderr 에러메시지가 우선권을 가지는 방법
        // 1. return (elementType)-1;
        return -1;
    }
    if(index>list->size) {
        fprintf(stderr,"Iist is full(%d) in readItem\n", index); //stderr 에러메시지가 우선권을 가지는 방법
        // 1. r-1;
    }
    for(int i=list->last+1; i>index; i--) {
        list->array[i] = list->array[i-1];
        list->move++;
    }
    list->array[index] = item;
    list->last++;
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

//printList
int printList(listType *list) {
    printf("List: size = %d, last = %d, move = %d\n Items:", list->size, list->last, list->move);
    for(int i=0; i<=list->last; i++) {
        printf(" [%d]{%d, %d, %d} ", i, list->array[i].row, list->array[i].col, list->array[i].val);
    }
    printf("\n");
}

//initList
int initList(listType *list) {
    list->last = -1;
    list->move = 0;
}