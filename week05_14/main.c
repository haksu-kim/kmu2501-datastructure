#include<stdio.h>
#include<stdlib.h>
#include"Linearlist.h"

listType *polyadd(listType *f, listType *s) {
    listType* a;
    int i, j=0;
    elementType f_item, s_item;
    a = createList(f->last + s->last+2);

    while(i<=f->last && i<=s->last) {
        f_item = readItem(f, i);
        s_item = readItem(s, j);
        if(f_item.expo<s_item.expo) {
            ordered_insertItem(a, f_item);
            i++;
        } else if(f_item.expo==s_item.expo) {
            ordered_insertItem(a, (elementType) {f_item.coef+s_item.coef, f_item.expo});
            i++; j++;
        } else {
            ordered_insertItem(a, s_item);
            j++;
        }
    }
    while(i<=f->last) {
        ordered_insertItem(a, readItem(f,i));
        i++;
    }
    while(i<=s->last) {
        ordered_insertItem(a, readItem(s,j));
        j++;
    }
    return a;
}

void removeItem(listType *list, int index) {
    for(int i=index; i<list->last; i++) {
        list->array[i] = list->array[i+1];
    }
    list->last--;
}// Function to remove an item from the list

listType *polymul(listType *f, listType *s) {
    listType *t;
    int i=0, j=0, k=0;
    elementType f_item, s_item, t_item;
    t = createList(f->last + s->last);

    while(i<=f->last && j<=s->last) {
        f_item = readItem(f, i);
        s_item = readItem(s, j);
        ordered_insertItem(t, (elementType) {f_item.coef*s_item.coef, f_item.expo});
        j++;
        if(j==s->last) {
            i++;
            j=0;
        }
    }//f의 첫 번째 항을 기준으로 곱셈

    while(1) {
        t_item = readItem(t, k);
        if(k+1 <= t->last) {
            elementType t_next_item = readItem(t, k+1);
            if(t_item.expo == t_next_item.expo) {
                t_item.coef += t_next_item.coef;
            removeItem(t, k+1);
        } else {
            k++;
            }
        } else {
            break;
        }
    }//while 차수 합
    return t;
}

main() {
    listType *poly1, *poly2, *poly3;
    int coef, expo;

    poly1 = createList(10);
    while(1) {
        scanf("%d %d", &coef, &expo);
        ordered_insertItem(poly1, (elementType){coef, expo});
        if(expo == 0) {
            return 1;
        }
    }

    poly2 = createList(10);
    while(1) {
        scanf("%d %d", &coef, &expo);
        ordered_insertItem(poly2, (elementType){coef, expo});
        if(expo == 0) {
            return 1;
        }
    }

    poly3 = polymul(poly1, poly2);
    printList(poly3);

    destroyList(poly1);
    destroyList(poly2);
    destroyList(poly3);
}
//Linear List ADT