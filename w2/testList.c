#include <stdio.h>
#include "List.h"

int main(void)
{
    IntList L = IntListCreate();
    IntListAppend(L, 1);
    IntListAppend(L, 2);
    IntListAppend(L, 3);

    printf("%d\n", IntListLength(L));
}