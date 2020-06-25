// By Matthew Di Meglio & Adrian Martinez
#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

struct branch {
	int key;
	Tree left;
	Tree right;
};

Tree nonEmptyTree(int key, Tree left, Tree right) {
    Tree t = malloc(sizeof(struct branch));
    t->key = key;
    t->left = left;
    t->right = right;
    return t;
}

Tree emptyTree() {
    return NULL;
}

void freeTree(Tree t) {
    if (t != NULL) {
        freeTree(t->left);
        freeTree(t->right);
        free(t);
    }
}

    // The way I like to implement recursion a la 'wishful thinking'
    // Imagine our function already works on the smaller trees to the left and right.
    // I'm on a node above them, i've got a tree to my left and a tree to my right.
    // Using countNodes, what do I return back to the user that called me?
    /*
                [v]
               /   \ . numNodesRight
        subtreel . subtreer
    */

int countNodes(Tree t) {

    if (t == NULL) return 0;

    int numNodesLeft = countNodes(t->left);
    int numNodesRight = countNodes(t->right); 
    return 1 + numNodesLeft + numNodesRight;
}

int max(int a, int b) {
    if (a > b) {
        return a;
    } else {
        return b;
    }
}

    /*
                [v]
               /   \ . height(r)
        subtreel . subtreer
    */
int height(Tree t) {
    /*
    if (t == NULL) return 0;
    if (t leaf) return 1
    return 1 + max(height(l), height(r));
    */
   return 0;
}

// Returns depth of node with key
    /*
                [v] .   v < key, v > key, v == key
               /   \ . 
        subtreel . subtreer
    */
int nodeDepth(Tree t, int key) {
    if (t == NULL) return -1;
    int found = 0;
    if (t->key == key) return 1;
    else if (t->key < key) found = nodeDepth(t->right, key);
    else found = nodeDepth(t->left, key);
    /* if (found == -1) then (return -1) otherwise (return 1 + found) */
    // Ternary condition
    return found == -1 ? found : 1 + found;
}  

int printPostfixHeightDiff(Tree t)
{
    return 0;
}

#define NOT_BALANCED (-99)

int isHeightBalanced(Tree t)
{
    return NOT_BALANCED;
}







// Challenge: Try and use this helper function signature to create an O(N) algo to solve it :)
void nthSmallestHelper(Tree t, int n, int *nvisited, int *res) {

}

int nthSmallest(Tree t, int n) {
    return -1;
}