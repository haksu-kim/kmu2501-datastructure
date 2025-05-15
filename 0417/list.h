#pragma once

#define MAX 20
#define NULL_ITEM (elementType) {-1,-1,-1}

typedef struct ElementType {
    int order;
    char name[MAX];
    char number[MAX];
} elementType;

typedef struct ListType {
    int size;
    int last;
    int move;
    elementType *array;
} listType;

extern listType* add_Con(int size);
extern int insert_Con(listType *list, int index, elementType item);
extern elementType delete_Con(listType *list, char *name);
extern int print_Con(listType *list);
extern int search_Con(listType *list, char *name);
extern void menu_print(void);
