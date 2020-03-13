#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "data.h"

// This function allocates memory to store the key and its name. It also copies the data from the input to the members of the Key.
Key *key_construct(char *in_name, int in_id) {
  // Create a pointer of type Key
  Key *newKey;

  // Assigning memory for the key
  newKey = (Key*)malloc(sizeof(Key));

  // Copy the passed in ID to the Key's ID
  newKey->id = in_id;

  // Assigning memory for the key name
  newKey->name = (char *) malloc(sizeof(char) * (strlen(in_name)+1));

  // Use string copy to make the Key's name the same as the name that was passed in.
  strcpy(newKey->name, in_name);

  // Return a pointer to the Key we just created
  return newKey;
}

// This function compares two keys to determine which one is lessor and greater according to ASCII.
int key_comp(Key *key1, Key *key2) {
  // Check if the two names are the same. If so, check the ID's.
  if (strcmp(key1->name, key2->name) == 0) 
  {
    // Return 1 if the first key's ID is greater than the second.
    if (key1->id > key2->id)
      return 1;
    
    // Return -1 if the first key's ID is less than the second.
    else if (key1->id < key2->id)
      return -1;
    
    // Return 0 if both keys are the same
    else return 0;
  }
  // Once we are sure the names are not the same, return the integer comparison.
  else return strcmp(key1->name, key2->name);
}

// Void function that prints out the Key's name and ID.
void print_key(Key *key) {
  printf("Key name: %s\n", key->name);
  printf("key ID: %d\n", key->id);
}

// Void functoin that prints out the Node: its key's ID, key's name, and its data.
void print_node(Node node) {
  printf("( %-18s%d )      %d\n", node.key->name, node.key->id, node.data);
}