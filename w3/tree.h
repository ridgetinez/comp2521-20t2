#pragma once

typedef struct branch *Tree;

Tree nonEmptyTree(int key, Tree left, Tree right);
Tree emptyTree();
void freeTree(Tree t);

// Count the number of nodes in our tree.
int countNodes(Tree t);

// Also known as the depth function, The height is defined as the length of the longest path from root to a leaf. 
// The path length is a count of the number of links (edges) on the path.
// This would mean that the NULL and single node tree would have height zero.
int height(Tree t);

// Returns the depth of the node containing a given key if such a node exists, 
// otherwise the function returns -1 (when a given key is not in the binary search tree). The depth of a root node is zero.
int nodeDepth(Tree t, int key);

// Fetch the nth smallest value from the tree.
// Assume that n >= 0 && n < countNodes(t)
// Exercise: How would you change the signature 
//   of nthSmallest if you can't assume bounds on n?
int nthSmallest(Tree t, int n);