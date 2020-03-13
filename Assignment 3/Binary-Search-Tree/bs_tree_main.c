#include <stdio.h>
#include <stdlib.h>
#include "bst.h"

// Main will ask the user the necessary information to create a tree and the necessary information to create a node to insert into the tree.

// This main will be able to receive information from stdin as the form of a text file.
int main(void) {
  
  // Declare variables we will use
  int size;
  BStree bst;
  char* key_name;
  int key_id;
  int node_data;
  int check;

  // Ask the user for a tree size
  printf("Please input a tree size: ");
  scanf(" %d", &size);

  // Create a tree of that size
  bst = bstree_ini(size);

  // Because key_name is a string pointer, we need to allocate memory to it
  key_name = (char*)malloc(30*sizeof(char));

  // Keep asking the user for information, so we can create a node and insert it into the tree.
  // The loop will continue until the user stops inputting 3 valid inputs; ie. ctr D
  // If the user enters the key in the wrong order, an improper node will be created and the function will terminate. User must try again.
  do {
    printf("Enter a valid input to the tree: \n");
    check = scanf(" %s %d %d", key_name, &key_id, &node_data); // Check is the number of inputs

    bstree_insert(bst, key_construct(key_name, key_id), node_data);

  } while (check == 3 && bst->top <= size);

  printf("\nThis is the tree you contructed...\n");
  
  // After the tree has been created, print the nodes and free the allocated memory.
  bstree_traversal(bst);
  free(key_name);
  bstree_free(bst); // Free the memory we used to store the key_name
  
  
  // Test Cases with the sample code
  /*
  printf("\nNow Testing Sample Code...\n");

  bst = bstree_ini(256);

  bstree_insert(bst, key_construct("Once", 1),      11);
  bstree_insert(bst, key_construct("Upon", 22),      2);
  bstree_insert(bst, key_construct("a", 3),         33);
  bstree_insert(bst, key_construct("Time", 4),      44);
  bstree_insert(bst, key_construct("is", 5),        55);
  bstree_insert(bst, key_construct("filmed", 6),    66);
  bstree_insert(bst, key_construct("in", 7),        77);
  bstree_insert(bst, key_construct("Vancouver", 8), 88);
  bstree_insert(bst, key_construct("!", 99),         9);
  bstree_insert(bst, key_construct("Once", 5),      50);
  bstree_insert(bst, key_construct("Once", 1),      10);

  bstree_traversal(bst);
  bstree_free(bst);

  */
  
  return 0;
}
