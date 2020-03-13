#include <stdio.h>
#include <stdlib.h>
#include "bst.h"

// Declare the prototypes for the functions we will use
void bst_insert(BStree, int, Key *key, Data);
int new_node(BStree, Key *key, Data);
void in_order(BStree, int);
void free_memory(BStree, int);

// This function will create a binary search tree
BStree bstree_ini(int size) {
  // Allocate enough memory for the BStree structure
  BStree_struct *newTree;
  newTree = (BStree_struct*)malloc(sizeof(BStree_struct));

  // Allocate memory for an array of Nodes of size, size + 1. Assign this to newTree.
  Node *a;
  a = (Node*)malloc(sizeof(Node)*(size+1));
  newTree->tree_nodes = a;

  // Allocate memory for an array of unsigned integers of size+1. Assign this to free_nodes
  unsigned int *b;
  b = (unsigned int*)malloc(sizeof(unsigned int)*(size+1));
  newTree->free_nodes = b;

  // Set the tree size
  newTree->size = size;

  // Set every position of free_nodes to its relative array position.
  for (int i=0; i <= size; i++)
    newTree->free_nodes[i] = i;

  // Initialize the root and first unused position, top.
  newTree->top = 1;
  newTree->root = 0;

  // Return this new tree structure we created.
  return newTree;
}

// This insert function controls when to insert a node with a helper function 
void bstree_insert(BStree bst, Key *key, Data data) {
  // If top = 1, then the tree is empty. Thus, create the root node. 
  if (bst->top == 1)
    bst->root = new_node(bst, key, data);
  
  // If the node is full, do nothing.
  else if (bst->top > bst->size)
    ;
  
  // If the tree can fit another node, call the helper function to actually insert.
  else {
    bst_insert(bst, bst->root, key, data);  // pass the index of the root
  }
}

// This function inserts the node recursively.
// The function compares the key you wish to insert with the BST's keys to determine whose child the new node will be.
void bst_insert(BStree bst, int node_index, Key *key, Data data) {
  // Start from the root node, and always check if the new node would be a left or right child.
  if (key_comp(key, bst->tree_nodes[node_index].key) < 0)
  {
    // Keep traversing to the left until you reach a leaf node (child = 0).
    if (bst->tree_nodes[node_index].left == 0)
      // Call new_node to create a node, which will return the array index. The proper parent will have it's child set to this index.
      bst->tree_nodes[node_index].left = new_node(bst, key, data);
    // If the left child is still an internal node, call the function to determine which direction to go.
    else bst_insert(bst, bst->tree_nodes[node_index].left, key, data);
  }

  // This handles the case where the new node would be a right child of the parent.
  else if (key_comp(key, bst->tree_nodes[node_index].key) > 0)
  {
    // Uses the same logic as the above block of code.
    if (bst->tree_nodes[node_index].right == 0)
      bst->tree_nodes[node_index].right = new_node(bst, key, data);
    else bst_insert(bst, bst->tree_nodes[node_index].right, key, data);
  }
  // If the key already exists in the tree, don't insert it. Furthermore, free the memory that was allocated to create key.
  else
  {
    free(key->name);
    free(key);
  }
}

// This function calls a helper method to print the nodes in-order.
void bstree_traversal(BStree bst) {
  //call print_node recursively inorder
  in_order(bst, bst->root);
}

// This function calls a helper method to free all the nodes of the BST recursively post-order. Don't free the node array first because we wouldn't be able to access the nodes.
void bstree_free(BStree bst) {
  free_memory(bst, bst->root);
  
  // Once the nodes are freed, free the array of nodes, free the free_nodes array, and free the tree itself.
  free(bst->tree_nodes);
  free(bst->free_nodes);
  free(bst);
}

// This function creates a new node in the array and returns the index, so that the node can be placed as the child of the proper parent.
int new_node(BStree bst, Key *key, Data data) {
  // Access the next open position in the free_nodes array. This is tracked by the variable top.
  int index = bst->free_nodes[bst->top];

  // This block of code initializes the node variables of tree_nodes in the particular position.
  bst->tree_nodes[index].key = key;
  bst->tree_nodes[index].data = data;
  bst->tree_nodes[index].left = 0;
  bst->tree_nodes[index].right = 0;

  // Once the node is created, increment the top by 1 so that it refers to the next open position.
  bst->top += 1;

  // Return the index of where we just created the node.
  return index;
}

// Traverse the tree in order and print the nodes respectively by calling the print_node function we created. The base case if when we access a leaf node.
void in_order(BStree bst, int index) {
  // Base case
  if (index == 0)
    return;

  // In-order traversal
  in_order(bst, bst->tree_nodes[index].left);
  print_node(bst->tree_nodes[index]);
  in_order(bst, bst->tree_nodes[index].right);
}

// Free the memory of the nodes in post-order because we want to free the tree from the bottom up.
void free_memory(BStree bst, int index) {
  // Base case when we access a leaf node
  if (index == 0)
    return;
  
  // Post-order traversal
  free_memory(bst, bst->tree_nodes[index].left);
  free_memory(bst, bst->tree_nodes[index].right);
  free(bst->tree_nodes[index].key->name);
  free(bst->tree_nodes[index].key);
}