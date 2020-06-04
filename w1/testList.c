#include <stdio.h>
#include "List.h"

int main(void)
{
    IntList L = IntListCreate();
    IntListAppend(L, 1);
    IntListAppend(L, 2);
    IntListAppend(L, 3);

    printf("IntListSumIter([1]->[2]->[3]) = %d\n", IntListSumIter(L));
    printf("IntListSumRec([1]->[2]->[3]) = %d\n", IntListSumRec(L));
}