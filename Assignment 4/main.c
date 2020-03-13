// Import libraries and header files
#include <stdio.h>
#include "memory.h"
#include <string.h>
#include "list.h"
#include <stdlib.h>

// Main created a list and prompts the user to enter integers into the list. The occurances of each integer is also accounted for. All the memory is freed at the end.
int main() {
  
  int memory;
  int check = 1;

  // Ask user for how much memory to use
  printf("Please enter the size of memory\n");
  scanf("%d", &memory);

  // Keep track of the memory used using our memory files.
  mem_ini(memory);
  List_node *list;
  list = list_ini();

  printf("Please input integers: \n");
  
  // do-while loop that continues as long as the user enters only one integer.
  do {
    
    // store the integer while also checking if it was valid.
    int integer;
    check = scanf(" %d", &integer);

    if (check != 1)
      break;

    else {
      // If user entered a new number, add it to the list with an occurance of one.
      if (list_search(list, integer) == NULL) {
        list_add(list, integer, 1);
      }

      // If the number is already in the list, find how many occurances it already has, delete the old node, and add a new one, but with an occurance of one more.
      else {
      Data occurance;
      occurance = *list_search(list, integer);
      list_delete(list, integer);
      list_add(list, integer, occurance+1);
      }
    } 
  } while (check ==1);

  //Print out how much memory remains after using simu_alloc()
  printf("memory remaining\n");
  mem_print();

  // Print the results  
  printf("\ninteger    occurance\n");
  list_print(list);

  // Free the memory used
  mem_free();

  return 0;
}
