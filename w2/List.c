#include <stdio.h>
#include <stdlib.h>
#include "List.h"

typedef struct _IntListNodeRep {
    int data;
    struct _IntListNodeRep *next;
} *IntListNode;

struct _IntListWrapperRep {
    int size;
    IntListNode first, last;
};

static IntListNode newIntListNode(int data)
{
    IntListNode newNode = malloc(sizeof(struct _IntListNodeRep));
    if (newNode == NULL) return newNode;
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

IntList IntListCreate()
{
    IntList L = malloc(sizeof(struct _IntListWrapperRep));
    if (L == NULL) return L;
    // BAD STYLE!!!!
    L->size = (int)(L->first = L->last = NULL);
    return L;
}

void IntListAppend(IntList L, int v)
{
    IntListNode newNode = newIntListNode(v);

    if (L->first == NULL) {
        L->first = L->last = newNode;
        L->size++;
    } else {
        L->last->next = newNode;
        L->last = newNode;
    }
}

int IntListSumIter(IntList L)
{
    /* Todo in tutorial :) */
    return 0;
}


static int IntListLengthRecHelper(IntListNode l)
{
    /* WEEK 2 IMPLEMENT ME! */
}

int IntListLength(IntList L)
{
    return IntListLengthRecHelper(L->first);
}


int IntListSumRecHelper(IntListNode l) 
{
    // Base case "given a list, can I give back an answer immediately?"
    if (l == NULL) return 0;
    // General/Recursive case:
    return l->data + IntListSumRecHelper(l->next);
}

int IntListSumRec(IntList L)
{ 
    return IntListSumRecHelper(L->first);
}

void IntListInsertNth(IntList L, int v, int pos)
{
    /* Todo in tutorial :) */
}