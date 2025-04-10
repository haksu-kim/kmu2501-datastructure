#define _CRT_NO_SECURE_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include"Linearlist.h"

#define MAX 10

listType *SmTranspose(listType* org) {
    listType* tr;
    elementType o_item;
    tr = createList(org->size);

    for(int i=0; i<=org->last; i++) {
        o_item = readItem(org, i);
        ordered_insertItem(tr, (elementType) {o_item.col, o_item.row, o_item.val});
    }
    return tr;
} //전치행렬

main() {
    listType *myList1, *myList2, *myList, *trans;

    int row, col, val=0;

    myList1 = createList(MAX);
    myList2 = createList(MAX);

    printf("행렬을 입력하시오? (-1입력 시 행렬의 입력이 종료됨)\n");
    while(1) {
        scanf("%d", &val);
        ordered_insertItem(myList1, (elementType) {row, col, val});
        if(col<3) {
            col++;
        } else if(col==3) {
            row++;
        }
        if(val == -1) {
            break;
        }
    }
    printList(myList1);

    row=0, col=0;
    printf("행렬을 입력하시오? (-1입력 시 행렬의 입력이 종료됨)\n");
    while(1) {
        scanf("%d", &val);
        ordered_insertItem(myList2, (elementType) {row, col, val});
        if(col<3) {
            col++;
        } else if(col==3) {
            row++;
        }
        if(val == -1) {
            break;
        }
    }

    printf("두 행렬의 합\n"); 
    myList = sum_List(myList1, myList);
    printList(myList);
}
