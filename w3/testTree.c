// By Matthew Di Meglio
#include <stdio.h>
#include <assert.h>
#include "Tree.h"

void testCountNodes();
void testHeight();
void testNodeDepth();
void testNthSmallest();

int main() {
    testHeight();
    testNodeDepth();
    testCountNodes();
    testNthSmallest();
    printf("All tests passed!\n");
    return 0;
}

void testCountNodes() {
    // Tree looks like:
    /*
                5
            3        X
         X     4 
             X   X 
    */

    Tree t = nonEmptyTree(5,
                    nonEmptyTree(3,
                                 emptyTree(),
                                 nonEmptyTree(4,
                                              emptyTree(),
                                              emptyTree())),
                    emptyTree());

    assert(countNodes(t) == 3);
    assert(countNodes(NULL) == 0);
    printf("Passed count nodes :)\n");
    freeTree(t);
}

void testHeight() {
    Tree t;
    
    t = nonEmptyTree(5,
               nonEmptyTree(3,
                      emptyTree(),
                      nonEmptyTree(4,
                             emptyTree(),
                             emptyTree()
                            )
                     ),
               emptyTree()
              );

    assert(height(t) == 3);
    freeTree(t);

    t = nonEmptyTree(5,
               nonEmptyTree(3,
                      emptyTree(),
                      emptyTree()
                     ),
               emptyTree()
              );

    assert(height(t) == 2);
    freeTree(t);

    assert(height(emptyTree()) == 0);
    printf("Passed height :)\n");
}

void testNodeDepth() {

    /*
                5
            3       X
              4
    */ 


    Tree t =
        nonEmptyTree(
            5,
            nonEmptyTree(
                3,
                NULL,
                nonEmptyTree(
                    4,
                    NULL,
                    NULL
                )
            ),
            NULL
        );

    int depth;
    depth = nodeDepth(t, 3);
    assert(depth == 2);

    depth = nodeDepth(t, 5);
    assert(depth == 1);

    depth = nodeDepth(t, 29);
    assert(depth == -1);

    depth = nodeDepth(t, -2);
    assert(depth == -1);

    freeTree(t);
    printf("Passed node depth :)\n");
}

void testNthSmallest() {
    Tree t =
        nonEmptyTree(
            5,
            nonEmptyTree(
                3,
                emptyTree(),
                nonEmptyTree(
                    4,
                    emptyTree(),
                    emptyTree()
                )
            ),
            emptyTree()
        );
    int m;
    m = nthSmallest(t, 1);
    assert(m == 3);

    m = nthSmallest(t, 2);
    assert(m == 4);

    m = nthSmallest(t, 3);
    assert(m == 5);

    freeTree(t);
}