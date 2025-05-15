#include <stdio.h>
#include <stdlib.h>

#include "Linked List.h"

linkedList_h* createLinkedList(void) {
    linkedList_h* lptr;

    lptr = (linkedList_h*)malloc(sizeof(linkedList_h));
    lptr->head = (listNode*)NULL;
    lptr->follow = 0;
    return lptr;
}

linkedList_h* createCLinkedList(void) {
    return createLinkedList();
}

void destroyLinkedList(linkedList_h* L) {
    listNode* p;

    while (L->head != NULL) {
        p = L->head;
        L->head = L->head->link;  // L->head = p->link;
        free(p);
    }
    free(L);
}

void destroyCLinkedList(linkedList_h* L) {
    listNode* p;

    while (L->head != L->head->link) {
        p = L->head;
        L->head = L->head->link;  // L->head = p->link;
        //free(p);
    }
    free(L->head);
    free(L);
}

void insertFirstNode(linkedList_h* L, elementType item) {
    listNode* newNode;

    newNode = (listNode*)malloc(sizeof(listNode));
    newNode->data = item;
    newNode->link = L->head; //(1)
    L->head = newNode;  //(2)

    return;
}

void insertFirstCNode(linkedList_h* L, elementType item) {
    listNode* newNode;

    newNode = (listNode*)malloc(sizeof(listNode));
    newNode->data = item;
    newNode->link = L->head; //(1)
    
    if( L->head != (listNode*)NULL) {
        listNode* temp = L->head;
        while(temp->link != L->head) {
            temp = temp->link;
            L->follow++;
        }
        temp->link = newNode; // (4)
        L->head = newNode; // (5)
    }
    else {
        L->head = newNode;
        newNode->link = newNode;
    }
    L->head = newNode;  //(2)

    return;
}

void insertLastNode(linkedList_h* L, elementType item) {
    listNode* temp, * newNode;

    newNode = (listNode*)malloc(sizeof(listNode));
    newNode->data = item;
    newNode->link = (listNode*)NULL;

    temp = L->head;
    if (temp == (listNode*)NULL) {
        L->head = newNode;
        return;
    }

    while (temp->link != (listNode*)NULL) {
        temp = temp->link;
        L->follow++;
    }

    temp->link = newNode;

    return;
}

void insertLastCNode(linkedList_h* L, elementType item) {
    listNode* temp, * newNode;

    newNode = (listNode*)malloc(sizeof(listNode));
    newNode->data = item;
    newNode->link = (listNode*)NULL;

    temp = L->head;
    if (temp == (listNode*)NULL) {
        L->head = newNode;
        return;
    }

    while (temp->link != L->head) {
        temp = temp->link;
        L->follow++;
    }
    temp->link = newNode;
    
    newNode->link = L->head; //Circle return First

    return;
}

void insertMiddleNode(linkedList_h* L, listNode* pre, elementType item) {

    listNode* newNode;

    newNode = (listNode*)malloc(sizeof(listNode));
    newNode->data = item;

    if (L->head == (listNode*)NULL) {
        newNode->link = (listNode*)NULL;
        L->head = newNode;
    }
    else if (pre == (listNode*)NULL) {
        newNode->link = L->head;
        L->head = newNode;
    }
    else {
        newNode->link = pre->link;
        pre->link = newNode;
    }
}

void insertMiddleCNode(linkedList_h* L, int count, elementType item) {

    listNode* lptr = L->head, * newNode;

    newNode = (listNode*)malloc(sizeof(listNode));
    newNode->data = item;

    if (L->head == (listNode*)NULL) {
        newNode->link = (listNode*)NULL;
        L->head = newNode;
    }
    else {
        for(int i=0; i<count; i++) {
            lptr = lptr->link;
        }
        newNode->link = lptr->link;
        lptr->link = newNode;
    }
}



void insertNthNode(linkedList_h* L, int loc, elementType item) {
    if(L->head == (listNode *)NULL) {
        if(loc == 0) insertFirstNode(L, item);
        else fprintf(stderr, "[insertNthNode: list empty and loc not zero 0\n");
        return;
    } else {
        if(loc == 0) insertFirstNode(L, item);
        else {
             int i=loc; listNode* pre = L->head;
             
            while(i>1 && pre->link != (listNode*)NULL) {
                i--;
                pre = pre->link;
             }
             
            if(i == 1) insertMiddleNode(L, pre, item);
            else fprintf(stderr, "[insertNthNode: location error");
             
        }
        return;
    }
}

void insertNthCNode(linkedList_h* L, int loc, elementType item) {
    listNode* pre = L->head;
    if(L->head == (listNode *)NULL) {
        if(loc == 0) insertFirstCNode(L, item);
        else fprintf(stderr, "[insertNthNode: list empty and loc not zero 0\n");
        return;
    } else {
        if(loc == 0) insertFirstCNode(L, item);
        else {
            int i=loc;
             
            while(i>1 && pre->link != (listNode*)NULL) {
                i--;
                pre = pre->link;
             }
             
            if(i == 1) insertMiddleCNode(L, loc-1, item);
            else fprintf(stderr, "[insertNthNode: location error");
             
        }
        
        /*while(pre->link != L->head) {
            pre = pre->link;
        }*/
        
        
        return;
    }
}

int compare_item (elementType first, elementType second) {
    return (first - second);
}

void ordered_insertNode(linkedList_h* L, elementType item) {
    listNode* pre;
    
    if(L->head == (listNode*)NULL) insertFirstNode(L, item);
    else {
        if(compare_item(L->head->data, item) > 0) insertFirstNode(L, item);
        else {
            pre = L->head;
            while(pre->link != (listNode*)NULL) {
                if(compare_item(pre->data, item) < 0 && compare_item(pre->link->data, item) > 0) break;
                pre = pre->link;
                L->follow++;
            }
            insertMiddleNode(L, pre, item);
        }
    }
}

void deleteNode(linkedList_h* L, listNode* p) {
    listNode* pre;
    
    if(L->head == (listNode*)NULL) return;
    /* if(L->head->link == (listNOde*)NULL) {
        free(L->head);
        L->head = (listNode*)NULL;
        return; */
    else if(p == (listNode*)NULL) return;
    else {
        pre = L->head;
        while(pre->link != p && p->link != (listNode*)NULL) {
            pre = pre->link;
            L->follow++;
        }
            if(pre->link == p) {
                pre->link = p->link; // link changed
                free(p);
            }
            else {
                fprintf(stderr, "delete item not in the list\n");
            }
        }
    }

void deleteCNode(linkedList_h* L, int item) {
    listNode* pre, *delete = NULL;
    
    pre = L->head;
    
    int loc = searchList(L, item);
    int count = countCList(L);
    
    if(count == 0 && item == pre->data) free(pre);
    else if(L->head == (listNode*)NULL) return;
    else {
        for(int i=0; i<loc-1; i++) {
            pre = pre->link;
        }
        if(loc == 0) {
            free(pre);
        } else if(loc>0) {
                delete = pre->link;
                pre->link = pre->link->link;
                free(delete);
            }
            else {
                fprintf(stderr, "delete item not in the list\n");
            }
        }
    }

int printList(linkedList_h* L) {
    listNode* lptr = L->head; //첫 번째 가리킴

    printf("Linked List(%d): ",L->follow);
    while (lptr->link != (listNode*)NULL) {
        printf("[%d]", lptr->data);
        lptr = lptr->link;
    }
    printf("[%d] \n", lptr->data);
    
    return 0;
}

int printCList(linkedList_h* L) {
    listNode* lptr = L->head; //첫 번째 가리킴

    printf("Circlular Linked List(%d): ",L->follow);
    
    if(lptr->link == NULL) {
        printf("\n");
        return 0;
    } else {
        
        while (lptr->link != L->head) {
            printf("[%d]", lptr->data);
            lptr = lptr->link;
        }
        printf("[%d] \n", lptr->data);
    }
    
    return 0;
}

int printHeadTailList(linkedList_h* L) {
    listNode* lptr = L->head, *tail=L->head;
    
    printf("\n");
    
    if(lptr == NULL) {
        printf("Empty List\n");
    } else {
        
        printf("[head] : %d\n", lptr->data); // head
        
        while(lptr->link != L->head) {
            lptr = lptr->link;
            tail = lptr;
        }
        
        printf("[Tail] : %d\n", tail->data); // tail
    }
    
    return 0;
}

int searchList(linkedList_h* L, elementType loc) {
    listNode* lptr = L->head;
    int count=0;
    
    while(lptr != (listNode*)NULL) {
        lptr = lptr->link;
        count++;
        if(lptr->data == loc) {
            break;
        }
        if(lptr->data != loc && lptr == (listNode*)NULL) {
            printf("No data");
        }
    }
    return count;
}

int countCList(linkedList_h* L) {
    listNode* p = L->head;
    int count=0;
    while(p->link != L->head) {
        p = p->link;
        count++;
    }
    return count;
}
