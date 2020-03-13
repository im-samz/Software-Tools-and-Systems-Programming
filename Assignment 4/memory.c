#include <stdio.h>
#include <stdlib.h>
#include "memory.h"

static unsigned char *memory;
static BStree bst;

// Input: the amount of memory to be allocated
// Ouput: nothing
// Effect: a memory tracker will be created with an unsigned array and a binary search tree. 
void mem_ini(unsigned int size) {
	memory = (unsigned char *) malloc(size);
	bst = bstree_ini(size/5); // size/5 is large enough
	bstree_insert(bst, 0, size);
}

// Input: unsigned integer specifying how much requested memory
// Output: nothing
// Effect: Notes how much memory is used in the unsigned array and replaces node containing free memory with an updated node.
void *simu_malloc(unsigned int size) {
  // Retrieve the first open slot of memory
  Key *key1 = bstree_data_search(bst, size+4);
  
  // Return NULL if no memory of that size remains
  if (key1 == NULL)
    return NULL;

  else { 
    // The size of the free memory block
    Data *data1 = bstree_search(bst, *key1);
    //int data2 = memory[*key1-4];

    // Calculate how much free memory remains after assigning memory and which location that free block begins
    int remaining = *data1 - size - 4;
    int pos = *key1 + 4 + size;

    // Replace the integer storing the size of memory block
    //int* address = (int*) &memory[*key1];
    //*address = size;
    *(int*)(memory + *key) = size;

    // Delete the old node
    bstree_delete(bst, *key1);

    // If there is still memory remaining add a node
    if (remaining > 0)
      bstree_insert(bst, pos, remaining);

    // Return the first memory position for the user to access
    return &memory[*key1+4];
  }
}

// Input: a pointer pointing to an integer related to a memory location.
// Output: nothing
// Effect: Clear a block of used memory from the unsigned array and restores a node in the BST containing the now free memory block.
void simu_free(void *ptr) {
  // ptr is the size of the memory block they want back
  int block_size = memory[(int)ptr - 4];
  memory[(int)ptr-4] = 0;

  // Turn the old block into a free memory block and add it to the tree.
  int pos = (int)ptr - 4;
  int remaining = block_size + 4;
  bstree_insert(bst, pos, remaining);
}

// Input: nothing
// Output: prints all the nodes of the binary search tree in-order
// Effect: Since all the free memory blocks are stored in a BST, an in-order BST traversal is called to print its nodes. 
void mem_print(void) {
  bstree_traversal(bst);
}

// Input: nothing
// Output: nothing
// Effect: frees the memory used for the array and binary search tree
void mem_free(void) {
  free(memory);
  bstree_free(bst);
}

