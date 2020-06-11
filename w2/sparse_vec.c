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
struct sparse_vec *add_sparse_vecs(struct sparse_vec *a, struct sparse_vec *b) {
    if (a->dimension != b->dimension) return NULL;
    struct sparse_vec *v = create_sparse_vec(a->dimension);
    struct vec_node *curr_a = a->first, *curr_b = b->first;

    ////////////// ////////////// ////////////// ////////////// //////////////
    // Implement me below !
    ////////////// ////////////// ////////////// ////////////// //////////////

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
