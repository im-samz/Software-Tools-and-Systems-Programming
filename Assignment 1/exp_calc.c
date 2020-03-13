#include <stdio.h>

/* Define the exp_calculator method we will use later. */ 
float exp_calculator(float base, int exp);

int main() 
{
  /* Declare the base and exponent variables.
  Also initialize a flag to use in the coming while loop. */
  float base;
  int exp;
  int flag = 0;

  /* Greet the user. */
  printf("Welcome to the Exponent Calculator!\n");
  
  /* This block will ask for the base. To ensure proper input, a while loop will keep asking for input until a non-negative base is given. */
  while (flag != 1) 
  {  
    printf("\nPlease enter a non-negative base: ");
    scanf(" %f", &base);

    /* The if statement checks the value of the base. If it is acceptable, the flag will switch and the while loop will terminate, allowing the user to progress into the code. */
    if (base < 0)
      printf("\n*Incorrect Input. Please Try Again.");
    else flag = 1;
  }

  /* This block uses the same logic as the above to ensure an acceptable input for the exponent. */
  while (flag != 0) 
  {
    printf("\nPlease enter a non-negative exponent: ");
    scanf(" %d", &exp);
    
    if (exp < 0)
      printf("\n*Incorrect Input. Please Try Again.");
    else flag = 0;
  }
  
  /* Initialize the result variable. Call the calculator and store the power into 'power'. Then it will be printed. */
  float power;
  printf("\nThe power of %f to the exponent of %d is: %f", base, exp, power = exp_calculator(base, exp));
  
  /* Lets main() know that everything is completed. */
  return 0;
}

/* This method contains the code to calculate the power given the passed base and exponent. */
float exp_calculator(float base, int exp) 
{
  /* This is the base case. When this happens, pass up the base. */
  if (exp == 1)
    return base;

  /* This block is here in case the user enters 0 for the exponent. */
  if (exp == 0)
    return 1;

  /* If the exponent is even, keep dividing it in half until they are fully split into bases with the exponent 1-the base case. This must be done twice per call to retain the whole exponent.*/
  else if (exp % 2 == 0) 
  {
    return (exp_calculator(base, exp/2))*(exp_calculator(base, exp/2));
  }

  /* If the exponent is odd, subtract 1 and divide it by two, and call the calculator recursively. This will invoke the even condition. The split is done twice per call and the base is multiplied, since we subtracted 1 from both halves, to retain the whole exponent. */
  else if (exp % 2 == 1) 
  {
    return (base*exp_calculator(base, (exp-1)/2)*exp_calculator(base, (exp-1)/2));
  }
}