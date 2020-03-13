#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "memory.h"

// Input: nothing
// Output: the head node of the created list
// Effect: creates a list node using simu_malloc() that points to null.
List list_ini(void) {
	List_node *head= (List_node *) simu_malloc( sizeof(List_node) ); 
	head->next = NULL;
	return head;
}

// Input: the list
//        the key
// Output: the data if the node is found; NULL otherwise
// Effect: Algorithm loops through the list until a matching key is found.
//        if it goes through the list, no node exists; NULL is returned.
Data *list_search(List list, Key key) {
  List_node *current = list->next;
  while (current != NULL) {
    if (key_comp(current->key, key) == 0)
      return &current->data;

    else current = current->next;
  }
  // If the loop goes through the list, but no matching key is found.
  if (current == NULL)
    return NULL;
}

// Input: the list, the key to be added, the data to be added.
// Output: nothing
// Effect: Searches the list if key already exists; if it does, do nothing.
//         If not, a new node is created and placed at the front of the list.
void list_add(List list, Key key, Data data) {
  // If the node is already in the list, do nothing.
  if (list_search(list, key) != NULL)
    return;

  List_node *toAdd;
  toAdd = simu_malloc(sizeof(List_node));
  toAdd->key = key;
  toAdd->data = data;
  toAdd->next = list->next;
  list->next = toAdd;
}

// Input: the list, the key of the node to be deleted
// Output: nothing
// Effect: Algorithm first searches if the associated node is in the list. Then it will traverse to the node before. Then the current node will set its next pointer to the node next of the one to be deleted, skipping the node.
void list_delete(List list, Key key) {
  List_node *current = list;
  // Check if the associated node is in the list; if not, do nothing.
  if (list_search(list, key) != NULL) {
    while (current->next->key != key)
      current = current->next; 
    
    if (current->next == NULL)
      return;
    // skip the node to be deleted.
    else {
      List_node* deleted = current->next;
      current->next = current->next->next;
    }
  }
  else
  ;
}

// Input: the list to be printed
// Output: Function prints the contents of the list
void list_print(List list) {
  List_node *current = list->next;
  // Loop through each node and call print_list_node() on it.
  while (current != NULL) {
    print_list_node(current);
    current = current->next;
  }
}

// Input: the list to be freed
// Output: nothing
// Effect: all the memory used by the list will be freed
void list_free(List list) {
  List_node *current = list->next;
  // Loop through the list freeing the nodes
  while (current != NULL) {
    free(&current->key);
    free(&current->data);
    current = current->next;
  }
  // Finally free the header
  simu_free(list);
}