#include <stdio.h>
#include <stdlib.h>

/* Define the methods we will call later. */
int km_mile();
int m_ft();
int cm_inch();
int cel_far();

int main() 
{
  /* Initialize the decision variable, which will store the user decision. */ 
  int decision;

  /* Keep asking the user to choose an option until they quit by inputting 5. */
  while (decision != 5) 
  {
    /* Ask for an option number */
    printf("\nWelcome to the conversion program! \nPlease Select an Option: \n");
    printf("\n 1 for conversion between Kilometer and Mile" 
    "\n 2 for conversion between Meters and Feet" 
    "\n 3 for conversion between Centimeters and Inches"
    "\n 4 for conversion between Celsius and Fahrenheit" 
    "\n 5 to quit \n");

    /* Store the decision option. */
    scanf(" %d", &decision);

    /* For every decision, call its respective method and let it handle the work. The method will handle the printing.*/
    if (decision == 1) 
    {
      km_mile();
    }

    /* Same logic as the above section */
    else if (decision == 2) 
    {
      m_ft();
    }

    else if (decision == 3) 
    {
      cm_inch();
    }

    else if (decision == 4) 
    {
      cel_far();
    }

    else if (decision == 5) 
    {
      printf("Thanks for using this program! Goodbye.");
      exit(0);
    }

    /* If the user inputs an integer that is out of the accepted range, print an error message. The program will loop and the user will be given another chance. */
    else if (!(decision > 0 && decision <6)) 
    printf("*Invalid Option. Please Try Again.\n");
  }
    return 0;
}

/* Method to convert Kilometers to Miles and vice versa.  
It doesn't take in any parameters, but it will construct a custom conversion statement by asking the user for information. It returns the integer 0 to formally mark that it has completed. */
int km_mile() 
{
  /* Unit will store what type of conversion, flag is used for the following loop, and converted is the final converted value. */
  char unit;
  int flag = 0;
  float converted;

  /* While loop is used until the user inputs an accepted character. */
  while (flag != 1) 
  {
    printf("\nPress K for conversion from Kilometers to Miles.\n"
  "Press M for conversion from Miles to Kilometers.\n");
    scanf(" %c", &unit);
    /* If the input was valid, the flag is switched and the loop terminates. If not, error message is printed. */
    if (unit == 'K' || unit == 'M')
      flag = 1;
    else printf("\n*Invalid Option. Please Try Again.");
  }

  /* value stores the number that is to be converted. */
  float value;
  printf("\nPlease enter a value to convert: ");
  scanf(" %f", &value);
  
  /* Depending on 'unit' the appropriate equation is used. Then a custom output is printed.*/
  if (unit == 'K')
  {
    converted = value / 1.609;
    printf("%f Kilometers is equal to %f Miles.\n", value, converted);
  }

  if (unit == 'M')
  {
    converted = value * 1.609;
    printf("%f Miles is equal to %f Kilometers.\n", value, converted);
  }
  return 0;
}

/* This method converts Meters to Feet and vice versa. It uses the same logic as the previous method. */
int m_ft() 
{
  char unit;
  int flag = 0;
  float converted;

  while (flag != 1) 
  {
    printf("\nPress M for conversion from Meters to Feet.\n"
  "Press F for conversion from Feet to Meters.\n");
    scanf(" %c", &unit);

    if (unit == 'M' || unit == 'F')
      flag = 1;
    else printf("\n*Invalid Option. Please Try Again.");
  }

  float value;
  printf("\nPlease enter a value to convert: ");
  scanf(" %f", &value);

  if (unit == 'M')
  {
    converted = value * 3.281;
    printf("%f Meters is equal to %f Feet.\n", value, converted);
  }

  if (unit == 'F')
  {  
    converted = value / 3.281;
    printf("%f Feet is equal to %f Meters.\n", value, converted);
  }
  return 0;
}

/* This method converts Centimeters to Inches and vice versa. It uses the same logic as the previous methods.*/
int cm_inch() 
{
  char unit;
  int flag = 0;
  float converted;

  while (flag != 1) 
  {
    printf("\nPress C for conversion from Centimeters to Inches.\n"
  "Press I for conversion from Inches to Centimeters.\n");
    scanf(" %c", &unit);

    if (unit == 'C' || unit == 'I')
      flag = 1;
    else printf("\n*Invalid Option. Please Try Again.");
  }

  float value;
  printf("\nPlease enter a value to convert: ");
  scanf(" %f", &value);

  if (unit == 'C')
  {
    converted = value / 2.54;
    printf("%f Centimeters is equal to %f Inches.\n", value, converted);
  }

  if (unit == 'I')
  {
    converted = value * 2.54;
    printf("%f Inches is equal to %f Centimeters.\n", value, converted);
  }
  return 0;
}

/* This method converts from Celsius to Fahrenheit and vice versa. Again, it uses the same logic as the previous conversion methods. */
int cel_far() 
{
  char unit;
  int flag = 0;
  float converted;

  while (flag != 1) 
  {
    printf("\nPress C for conversion from Celsius to Fahrenheit.\n"
  "Press F for conversion from Fahrenheit to Celsius.\n");
    scanf(" %c", &unit);

    if (unit == 'C' || unit == 'F')
      flag = 1;
    else printf("\n*Invalid Option. Please Try Again.");
  }

  float value;
  printf("\nPlease enter a value to convert: ");
  scanf(" %f", &value);

  if (unit == 'C')
  {
    converted = ((value * 9/5) + 32);
    printf("%f Celsius is equal to %f Fahrenheit.\n", value, converted);
  }

  if (unit == 'F')
  {
    converted = ((value - 32) * 5/9);
    printf("%f Fahrenheit is equal to %f Celsius.\n", value, converted);
  }
  return 0;
}
