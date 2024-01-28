#ifndef _H_TREE_
#define _H_TREE_

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// Tree represents a simple binary search tree for a size_t value
typedef struct Tree_t {
  size_t value;
  struct Tree_t *left;
  struct Tree_t *right;
} Tree;


// allocate a leaf node a node with no children
Tree *leaf(size_t value);

// check for the presence of node in the three
// if the given value
bool value_present(Tree *node, size_t value);

// given the value allocate a new node and insert in the tree
Tree *add_node(Tree *root, size_t value);

// assumes that the tree is balanced search and return the min value found
Tree *find_min(Tree *node);

// remove a node if the given value if found
Tree *remove_node(Tree *root, size_t value);

// walk node per node to free all memory
void clear_tree(Tree *root);

#endif // _H_TREE_
