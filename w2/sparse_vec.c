#include <stdio.h>
#include <stdlib.h>

struct sparse_vec {
    struct vec_node *first, *last;
    int dimension;
};

struct vec_node {
    double data;
    int pos;
    struct vec_node *next;
};

struct vec_node *create_node(double data, int pos) {
    struct vec_node *n = calloc(1, sizeof(struct vec_node));
    if (n == NULL) return n;
    n->data = data; n->pos = pos;
    return n;
}

struct sparse_vec *create_sparse_vec(int dim) {
    struct sparse_vec *v = calloc(1, sizeof(struct vec_node));
    if (v == NULL) return v;
    v->dimension = dim;
    return v;
}

void append(struct sparse_vec *v, double data, int pos) {
    struct vec_node *to_insert = create_node(data, pos);
    if (v->first == NULL) { v->first = v->last = to_insert; return; }
    v->last->next = to_insert;
    v->last = to_insert;
}

// Denote N to be the length of A, and M be the length of B. What's the time complexity of this function?
// A: O(M+N) (followup: why can't we just say it's O(n)?)
struct sparse_vec *add_sparse_vecs(struct sparse_vec *a, struct sparse_vec *b) {
    // We only define vector addition on vectors that have same dimension i.e. two vectors from R^3,
    // but not one from R^3 and another from R^4.
    if (a->dimension != b->dimension) return NULL;
    struct sparse_vec *v = create_sparse_vec(a->dimension);
    struct vec_node *curr_a = a->first, *curr_b = b->first;

    // A and B are sorted by the position in which their non-zero elements appear.
    // We can walk pointers and check if their positions are equal.
    // What do we do when they're equal?
    //      Well this means that they should be added together! Being careful to not append if their sum is 0,
    //      Since we don't add zeroes into our sparse vector representation.
    // Okay, they're not equal, the position of one is smaller than the other?
    //      The smaller one is being added with zero, so we can append the smaller one to the new vector as it is.
    // Why can we just add to the end?
    //      If the position of one is smaller, then in the other list we've past any hope of finding a non-zero
    //      element at the same position. This is because our vectors are sorted by position.
    while (curr_a != NULL && curr_b != NULL) {
        if (curr_a->pos < curr_b->pos) {
            append(v, curr_a->data, curr_a->pos);
            curr_a = curr_a->next;
        } else if (curr_a->pos > curr_b->pos) {
            append(v, curr_b->data, curr_b->pos);
            curr_b = curr_b->next;
        } else {
            if (curr_b->data + curr_a->data != 0) {
                append(v, curr_b->data + curr_a->data, curr_b->pos);
            }
            curr_a = curr_a->next;
            curr_b = curr_b->next;
        }
    }

    // The loop above us is (curr_a != NULL && curr_b != NULL). We exit the loop when the condition is false:
    // !(curr_a != NULL && curr_b != NULL) ====> curr_a == NULL || curr_b == NULL
    // Ahh! So we might still have elements remaining in one. Since the other list doesn't have any elements
    // we'll just append to the end of the new vector.
    while (curr_a != NULL) { append(v, curr_a->data, curr_a->pos); curr_a = curr_a->next; }
    while (curr_b != NULL) { append(v, curr_b->data, curr_b->pos); curr_b = curr_b->next; }
    return v;
}

void print_sparse_vec(struct sparse_vec *v) {
    struct vec_node *curr = v->first;
    while (curr != NULL) {
        printf("[%lf,%d]->", curr->data, curr->pos);
        curr = curr->next;
    }
    printf("[X]\n");
}

int main(void) {
    struct sparse_vec *a_vec = create_sparse_vec(8);
    struct sparse_vec *b_vec = create_sparse_vec(8);

    append(a_vec, 2.3, 0);
    append(a_vec, -0.1, 1);
    append(a_vec, 1.7, 4);

    append(b_vec, 3.14, 1);
    append(b_vec, -1.7, 4);
    append(b_vec, -1.8, 7);

    struct sparse_vec *v = add_sparse_vecs(a_vec, b_vec);
    print_sparse_vec(v);
}
