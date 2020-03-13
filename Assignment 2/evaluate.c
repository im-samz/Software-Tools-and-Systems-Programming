#include <stdio.h>
#include <stdlib.h>

// Declare the functions we will be using.
float s_exp(void);
float m_exp(float sub_exp, char op);
char get_op(void);
float get_num(void);

/*
main() will prompt the user to enter an expression, evaluate it, and print it back. It will continue to do this unter the user tells it to stop.
*/
int main()
{
  // Initialize the while loop. The program will continue to ask for new expressions until the user enters N to stop.
  char cont = 'Y';
  do
  {
    // Ask the user to enter an expression to stdin.
    printf("Please enter an expression: ");

    // s_exp() with the use of the other helper functions can handle the entire expression and return the answer.
    float answer = s_exp();
    printf("The expression evaluates to: %f\n", answer);

    // Ask the user if they want to continue...
    printf("Do you wish to continue? Y for yes, N for no: ");
    scanf(" %c", &cont);
    
  } while(cont != 'N');
}

/*
s_exp() will perform any addition or subtraction operations on any 2 adjacent terms. However, it needs m_exp() to simplify a chain of terms combined by multiplication or division into a single term.
The function will terminate once it reaches the end of the expression (\n). It will return the value of the simplified expression.
*/
float s_exp() 
{
  float first_num = get_num();
  char first_op = get_op();

  // In the case that the user inputs a single-digit integer...
  if (first_op == '\n')
    return first_num;
  
  // Call m_exp() to evaluate the next chain of terms combined with the * or / operation.
  // If the next operator was + or -, m_exp() will just return first_num...
  float sub_exp = m_exp(first_num, first_op);

  // next_op will be the next operator that m_exp() cannot handle, ie. +, -, or \n
  char next_op = get_op();

  // Keep evaluating all additions or subtractions. Every chain of multiplication or division will be simplified by calling the m_exp() function.
  float next_num;
  while (next_op != '\n')
  {
    // This block will add the next 2 terms.
    if (next_op == '+')
    {
      next_num = get_num();
      next_op = get_op();
      sub_exp += m_exp(next_num, next_op);  // m_exp() will give us the next chain of * or / terms.
    }
    
    // This block will subtract the next 2 terms.
    else if (next_op == '-')
    {
      next_num = get_num();
      next_op = get_op();
      sub_exp -= m_exp(next_num, next_op);
    }

    // Once m_exp() reaches a +, -, or \n, we take the next operator and the process is done again.
    next_op = get_op();
  }

  // Before \n is reached, sub_exp() be will evaluated all the way through the expression. \n will terminate the loop, so sub_exp() will be the answer we desire.
  return sub_exp;
}

/*
m_exp() will simplify the following chain of terms joined by * or / into 1 number, so that s_exp() can add or subtract them together.
*/
float m_exp(float sub_exp, char op)
{
  // If the next operator is not * or /, then the end of the chain is reached.
  if (op == '\n' || op == '+' || op == '-')
  {
    ungetc(op, stdin);  // move the reader back so that s_exp() can read the next operator.
    return sub_exp; // return this chain.
  }

  // If the next operator is just invalid input, quit the program.
  else if (op == '%' || op == '^' || op == '$')
  {
    printf("Invalid Operator. Please try again,");
    exit(EXIT_FAILURE);
  }
    
  // get the next number, perform the operation and store it into next_sub_op.
  else
  {
    float next_num = get_num();
    float next_sub_exp;

    // If the passed operator is *, multiply the next two numbers.
    if (op == '*')
    {
      next_sub_exp = (sub_exp * next_num);
    }

    // If the passed operator is /, divide the next two numbers.
    else if (op == '/')
    {
      // Just in case the user attempted to divide by 0...
      if (next_num == 0)
      {
        printf("Error: Cannot divide by zero.");
        exit(EXIT_FAILURE);
      }
      else 
        next_sub_exp = (sub_exp / next_num);
    }

    // get the next operator and call m_exp() again.
    // if next_op can be handled, the chain will continue to be simplified; if not, the expression will be returned in the next call.
    char next_op = get_op();

    return m_exp(next_sub_exp, next_op);
  }
}

// The function call is wisely called so no characters will be expected.
float get_num()
{
  float num = ' ';
  // Skip all the white spaces until a number is reached.
  while (num == ' ')
  {
    scanf("%f", &num);  // store the first number it sees into num.
  }
  return num; // return it for use.
}

// The function call is wisely called so no numbers will be expected.
char get_op()
{
  char op = ' ';
  // Skip all the white spaces until an operator or \n is reached.
  while (op == ' ')
  {
    scanf("%c", &op); // store the first character it sees into op.
  }
  return op;
}