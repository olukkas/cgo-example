#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Tree represents a simple binary search tree for a size_t value
typedef struct Tree_t {
  size_t value;
  struct Tree_t *left;
  struct Tree_t *right;
} Tree;

// allocate a leaf node a node with no children
Tree *leaf(size_t value) {
  size_t len = sizeof(Tree);
  Tree *t = malloc(len);
  memset(t, 0, len);

  t->value = value;

  return t;
}

// check for the presence of node in the three
// if the given value
bool value_present(Tree *node, size_t value) {
  while (node != NULL) {
    if (node->value == value)
      return true;

    if (value < node->value)
      node = node->left;
    else
      node = node->right;
  }

  return false;
}

// given the value allocate a new node and insert in the tree
Tree *add_node(Tree *root, size_t value) {
  if (root == NULL)
    return leaf(value);

  if (value < root->value) {
    root->left = add_node(root->left, value);
  } else
    root->right = add_node(root->right, value);

  return root;
}

// assumes that the tree is balanced search and return the min value found
Tree *find_min(Tree *node) {
  while (node->left != NULL) {
    node = node->left;
  }
  return node;
}

// remove a node if the given value if found
Tree *remove_node(Tree *root, size_t value) {
  if (root == NULL) {
    return NULL;
  }

  if (value < root->value) {
    root->left = remove_node(root->left, value);
  } else if (value > root->value) {
    root->right = remove_node(root->right, value);
  } else {
    if (root->left == NULL) {
      Tree *temp = root->right;
      free(root);
      return temp;
    } else if (root->right == NULL) {
      Tree *temp = root->left;
      free(root);
      return temp;
    }

    Tree *min_right = find_min(root->right);
    root->value = min_right->value;
    root->right = remove_node(root->right, min_right->value);
  }

  return root;
}

// walk node per node to free all memory
void clear_tree(Tree *root) {
  if (root != NULL) {
    clear_tree(root->left);
    clear_tree(root->right);

    free(root);
  }
}
