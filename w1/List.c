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
    /* Todo :) */
    return NULL;
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

    // This line should check if the list is empty, what does it actually do?
    if (L == NULL) {
        // What's wrong with line 28?
        L = newNode;
        L->size++;
    } else {
        // What's wrong/missing with line 32?
        L->last = newNode;
    }
}

int IntListSumIter(IntList L)
{
    /* Todo in tutorial :) */
    return 0;
}

int IntListSumRec(IntList L)
{
    /* Todo in tutorial :) */
    return 0;
}

void IntListInsertNth(IntList L, int v, int pos)
{
    /* Todo in tutorial :) */
}