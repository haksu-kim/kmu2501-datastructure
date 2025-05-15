#pragma once

#define NULL_ITEM (elementType) {-1,-1,-1}

//배열에 들어갈 항목이 정수리는 것을 정의

typedef struct ElementType {
    int row;
    int col;
    int val;
} elementType;

typedef struct ListType {
    int size;
    int last;
    int move;
    elementType *array;
} listType;



extern listType* createList(int size); //creatList함수가 있는데, 
//size를 주면 리스트를 만들어 돌려주고, (extern)다른데에 있다.
extern elementType readItem(listType *list, int index);
extern int insertItem(listType *list, int index, elementType item);
extern elementType deleteItem(listType *list, int index);
extern int printList(listType *list);
extern int initList(listType *list);
extern int ordered_insertItem(listType *list, elementType item);
extern int sum_List(listType *list1, listType *list2);