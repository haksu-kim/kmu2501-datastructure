#include<stdio.h>
#include<stdlib.h>
#include"Linearlist.h"

#define MAX 100

listType *polymul(listType *f, listType *s) {
    listType *t;
    int i=0, j=0, k=0;
    elementType f_item, s_item, t_item;
    t = createList(f->last + s->last);

    while(i<=f->last && j<=s->last) {
        f_item = readItem(f, i);
        s_item = readItem(s, j);
        if(s_item.expo == 0 ) {
            ordered_insertItem(t, (elementType) {f_item.coef*s_item.coef, f_item.expo});
            i++;
            j=0;
        } else if(f_item.expo == 0) {
            ordered_insertItem(t, (elementType) {f_item.coef*s_item.coef, s_item.expo});
            break;
        } else {
            ordered_insertItem(t, (elementType) {f_item.coef*s_item.coef, f_item.expo+s_item.expo});
            j++;
        }

        
    }//f의 첫 번째 항을 기준으로 곱셈
    while(1) {
        t_item = readItem(t, k);
        if(k+1 <= t->last) {
            elementType t_next_item = readItem(t, k+1);
            if(t_item.expo == t_next_item.expo) {
                t_item.coef += t_next_item.coef;
            deleteItem(t, k+1);
        } else {
            k++;
            }
        } else {
            break;
        }
    }//while 차수 합
    return t;
}


int main(void) {
    listType *poly1, *poly2, *poly3;
    int coef=0, expo=0;
    poly1 = createList(MAX);
    
    printf("첫 번째 다항식을 입력하세요 (예: 3x^2+4x+1) :\n");
    char input1[MAX];
    scanf("%s", input1);
    int i=0;
    while(1) {
        int coef_sign = 1;
        coef=0;
        expo=0;
        
        if(input1[i]=='-') {
            coef_sign = -1;
            i++;
        } else if(input1[i] == '+') {
            i++;
        }
        if(input1[i] >= '0' && input1[i] <= '9') {
            coef = coef * 10 + (input1[i] - '0');
            i++;
        }
        
        if(input1[i] == 'x') {
            i++;
            if(input1[i] == '^') {
                i++;
                if(input1[i] >= '0' && input1[i] <= '9') {
                    expo = expo * 10 + (input1[i] - '0');
                    i++;
                }
            } else {
                coef = 1;
                expo = 1;
            }
            coef *= coef_sign;
        } else {
            expo = 0;
        }
        
        ordered_insertItem(poly1, (elementType){coef, expo});
        
        if(input1[i] == '\0') {
            break;
        }
    }
    
    poly2 = createList(MAX);
    
    printf("두 번째 다항식을 입력하세요 (예: 3x^2+4x+1) :\n");
    char input2[MAX];
    scanf("%s", input2);
    i=0;
    while(1) {
        int coef_sign = 1;
        coef=0;
        expo=0;
        
        if(input2[0]=='x') {
            coef = 1;
        }
        if(input2[i]=='-') {
            coef_sign = -1;
            i++;
        } else if(input2[i] == '+') {
            i++;
        }
        if(input2[i] > '0' && input2[i] <= '9') {
            coef = coef * 10 + (input2[i] - '0');
            i++;
        }
        if(coef == 0) {
            coef = 1;
        }

        coef *= coef_sign;
        
        if(input2[i] == 'x') {
            i++;
            
            if(input2[i] == '^') {
                i++;
                if(input2[i] >= '0' && input2[i] <= '9') {
                    expo = expo * 10 + (input2[i] - '0');
                    i++;
                }
            } else {
                expo = 1;
            }
        } else {
            expo = 0;
        }
        
        ordered_insertItem(poly2, (elementType){coef, expo});
        
        if(input2[i] == '\0') {
            break;
        }
    }
    
    printList(poly1);
    printList(poly2);
    poly3 = polymul(poly1, poly2);
    printf("[곱셈 결과]\n");
    printList(poly3);

    destroyList(poly1);
    destroyList(poly2);
    destroyList(poly3);
    
    return 0;
}


//Linear List ADT
