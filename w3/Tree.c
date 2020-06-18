// By Matthew Di Meglio & Adrian Martinez
#include <stdio.h>
#include <stdlib.h>
#include "Tree.h"

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

int countNodes(Tree t) {
    // The way I like to implement recursion a la 'wishful thinking'
    // Imagine our function already works on the smaller trees to the left and right.
    // I'm on a node above them, i've got a tree to my left and a tree to my right.
    // Using countNodes, what do I return back to the user that called me?
    return 0;
}

int max(int a, int b) {
    if (a > b) {
        return a;
    } else {
        return b;
    }
}

int height(Tree t) {
    // TODO
    return 0;
}

// Returns depth of node with key
int nodeDepth(Tree t, int key) {
    return -1;
}  

// Challenge: Try and use this helper function signature to create an O(N) algo to solve it :)
void nthSmallestHelper(Tree t, int n, int *nvisited, int *res) {

}

int nthSmallest(Tree t, int n) {
    return -1;
}