#ifndef LIST_H
#define LIST_H

typedef struct _IntListWrapperRep *IntList;

// Create the initial IntListWrapper :)
IntList IntListCreate();

// Modifying operations by creating new elements in the list
void IntListAppend(IntList, int);
void IntListInsertNth(IntList, int v, int pos);

// Modifying operations by changing existing elements within the list (mutation)
void IntListTransformSquare(IntList);
void IntListTransformGreaterZero(IntList);

// Non-modifying operations
int IntListSumIter(IntList);    // return back sum of the list via iteration
int IntListSumRec(IntList);     // return back sum of the list via recursion


// Extension: for the more curious! 
// Operations via higher order functions (functions that take in functions)
void IntListMap(IntList, void (*f)(int));
int IntListFoldl(IntList, void (*f)(int,int));
IntList IntListFilter(IntList, void (*f)(int));

#endif
