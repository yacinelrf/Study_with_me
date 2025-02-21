#include <stdlib.h>
#include <stdio.h>
#include "bst.h"
#include "stack_link.h"

/** Searches a BST for a label and returns a pointer to a node with this label */
/* Returns NULL if there is no node with this label */
link search_BST(link h, item v) {
  if (h == NULL) return NULL;
  item t = get_binary_tree_root(h);
  if eq(v, t) return h;
  if less(v, t) return search_BST(h->left, v);
    else return search_BST(h->right, v);
  }

/** Inserts RECURSIVELY a node with a given label in a BST (as a leaf) */
/* and returns a link to the updated BST */
link insert_BST(link h, item v) {
  if (h == NULL) return cons_binary_tree(v, NULL, NULL);
  if less(v, get_binary_tree_root(h)) {
    h->left = insert_BST(h->left, v);
  }
  else {
    h->right = insert_BST(h->right, v);
  }
  return h;
}

/** Selects the kth label of a BST */
/* and returns a pointer to the corresponding node */
/* Returns NULL if the BST does not contain k labels */
link select_BST(link h, int k) {
    int t;
    if (h == NULL) return NULL;
    t = size_binary_tree(h->left);
    if (t > k) return select_BST(h->left, k);
    if (t < k) return select_BST(h->right, k-t-1);
    return h;
}

/*************     ROTATIONS        *************/

/** Applies a right rotation the root of a BST */
link rotate_right(link h) {
  link x;
  if (NULL == h) return NULL;
  x = h->left;
  h->left = x->right;
  x->right = h;
  return x;
}

/** Applies a left rotation to the root of a BST */
link rotate_left(link h) {
  link x;
  if (NULL == h) return NULL;
  x = h->right;
  h->right = x->left;
  x->left = h;
  return x;
}
