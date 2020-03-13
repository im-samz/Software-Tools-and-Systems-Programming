#include <stdio.h>

// Declare the prototypes
double approx_e(double small, long long n);
long long factorial(long long num);

// The main function asks the user for input, calls the approximation function, and prints out the result.
int main(void) {
  // Get the input required for the calculation.
  printf("Please enter a small number: ");
  double small; // How precise to calculate
  scanf("%lf", &small);

  // Call the approximation function.
  double e;
  long long n = 1;  // The first time through is when n = 1, so we pass that first.
  e = 1 + approx_e(small, n);
  
  // Print the approximation of e.
  printf("The approximation for e is: %0.15lf\n", e);
}

// This function approximates e to the precision of small. 
// We return a double for the sake of having a 15 decimal precision. We use a long long n because it will take on the form of an extremely large number.
double approx_e(double small, long long n) {
  // Once we approximate to the point that 1/!n < desired precision, we are done.
  if ((1/(double)factorial(n)) < small)
    return 0;
  
  // Until then, apply the recursive formula, which will call a helper function that computes the factorial.
  else {
    return (((double)1/factorial(n)) + approx_e(small, n+1));
  }
}

// This function will compute the factorial expression.
long long factorial(long long num) {
  if (num == 1)
    return 1;
  
  else return num * factorial(num-1);
}
