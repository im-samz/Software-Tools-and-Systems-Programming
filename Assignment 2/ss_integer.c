#include <stdio.h>
#include <stdlib.h>

// Display is a bank containing all the digit representations; one index for each digit. It is initialized as a global variable.
const char display[10][3][3] = {
    {{' ', '_', ' '}, {'|', ' ', '|'}, {'|', '_', '|'}}, 
    {{' ', ' ', ' '}, {' ', ' ', '|'}, {' ', ' ', '|'}},
    {{' ', '_', ' '}, {' ', '_', '|'}, {'|', '_', ' '}},
    {{' ', '_', ' '}, {' ', '_', '|'}, {' ', '_', '|'}},
    {{' ', ' ', ' '}, {'|', '_', '|'}, {' ', ' ', '|'}},
    {{' ', '_', ' '}, {'|', '_', ' '}, {' ', '_', '|'}},
    {{' ', '_', ' '}, {'|', '_', ' '}, {'|', '_', '|'}},
    {{' ', '_', ' '}, {' ', ' ', '|'}, {' ', ' ', '|'}}, 
    {{' ', '_', ' '}, {'|', '_', '|'}, {'|', '_', '|'}},
    {{' ', '_', ' '}, {'|', '_', '|'}, {' ', '_', '|'}}
  };

/*
main() asks an user for an integer and will create a seven-segment display of it by mapping the character representation of each digit to a position in a secondary array based on the order of the digits.
*/
int main() 
{ 
  // our secondary array where we will map the character representations to. There are 11 1D positions: 0 to store the sign if negative, 1-9 to store up to a 10-digit integer.
  char to_print[11][3][3];

  // We use a flag and while loop to keep prompting the user to use the program.
  char flag = 'Y';
  while (flag != 'N')
  {
    int num;
    int num_digits;
    int count = 0;
    printf("Please present an integer to print: ");
    scanf(" %d", &num);
    
    // num_digits is used to determine the number of digits. Every time it is divided by 10, the count increases.
    num_digits = num;
    while (num_digits != 0)
    {
      num_digits /= 10;
      count++;
    }

    // A special case occurs when the integer is negative. Thus, the first position in the array is set aside for the sign.
    if (num < 0)
    {
      // Place an underscore in the middle row to mimic a negative sign.
      // However, make the first position a space for aestetics.
      to_print[0][1][0] = ' ';
      for (int i = 1; i<3; i++)
      {
        to_print[0][1][i] = '_';
      }
      
      // Fill the top and bottom row with spaces, so that the consecetive numbers are evenly spaced.
      for (int j = 0; j < 3; j++)
      {
        to_print[0][0][j] = ' ';
        to_print[0][2][j] = ' ';
      }
    }
    
    // convert the input into a positive integer, which is easier to handle.
    num = abs(num);

    // Take the last digit out of the input and place it at the end of the second array so that the first digit is in position 1.
    while (num != 0)
    {
      // we initialize i to be at count, the last position, and we work backwards.
      for (int i=count; i > 0; i--) // note that i = count and  i > 0 because the position 0 is reserved for the sign.
      {
        int next_digit = num % 10; // modulus takes the last digit
        num /= 10;  // divide cuts the integer by a digit

        // Find the digit's representation and copy its data over to the position it belongs to in the second array.
        for (int j = 0; j < 3; j++)
        {
          for (int k = 0; k < 3; k++)
          {
            to_print[i][j][k] = display[next_digit][j][k];
          }
        }
        
      }
    }

    // Print the array storing the integer.
    printf("The analog representation is: \n"); 

    // Print all the columns in the first row before moving down. That way the integer is printed horizontally.
    for (int j = 0; j < 3; j++)
    {
      for (int i = 0; i < count+1; i++)
      {
        for (int k = 0; k < 3; k++)
        {
          printf("%c", to_print[i][j][k]);
        }
        printf(" "); // Leave a space between the top rows of each digit.
      }
      printf("\n"); // start a new line after printing each row.
    }
    printf("\n"); // leave a space when done for aestetics.
    

    // Prompt the user if they would like to enter another integer.
    printf("Would you like to continue? ");
    scanf(" %c", &flag);
  }
}