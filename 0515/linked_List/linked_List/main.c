
#include <stdio.h>
#include <stdlib.h>

#include "Linked List.h"

int main(void) {
    
    linkedList_h* mylist;
    mylist = createCLinkedList();
    int n, loc, item;
    
    while(1) {
        printf("===== Linke_List Menu =====\n");
        printf("1) insertFirst  (리스트의 제일 앞에 삽입)\n");
        printf("2) insertLast  (리스트의 제일 뒤에 삽입)\n");
        printf("3) insertMiddle  (특정 값 앞에 삽입)\n");
        printf("4) insertNthNode  (N번째 위치 삽입)\n");
        printf("6) deleteNode  (특정 값 삭제)\n");
        printf("7) print Head/Tail\n");
        printf("0) Program Stop\n");
        printf("Select menu > ");
        scanf("%d", &n);
        
        if(n == 1) {
            printf("Input item : ");
            scanf("%d", &item);
            insertFirstCNode(mylist, item);
            printCList(mylist);
            item = 0;
        }
        if(n == 2) {
            printf("Input item : ");
            scanf("%d", &item);
            insertLastCNode(mylist, item);
            printCList(mylist);
        }
        if(n == 3) {
            printf("어떤 값 뒤에? : ");
            scanf("%d", &loc);
            printf("Input item : ");
            scanf("%d\n", &item);
            int count = searchList(mylist, loc);
            insertMiddleCNode(mylist, count, item);
            printCList(mylist);
        }
        if(n == 4) {
            printCList(mylist);
            printf("위치(index, 0부터) : ");
            scanf("%d", &loc);
            printf("삽입할 값 : ");
            scanf("%d", &item);
            //int count = searchList(mylist, loc);
            insertNthCNode(mylist, loc, item);
            printCList(mylist);
        }
        if(n == 6) {
            printf("삭제할 값 : ");
            scanf("%d", &item);
            deleteCNode(mylist, item);
            printCList(mylist);
        }
        if(n == 7) {
            printHeadTailList(mylist);
        }
        if(n == 0) {
            break;
        }
        printf("\n");
    }//while
    
}
