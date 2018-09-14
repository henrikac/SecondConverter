/*
 * Programmer: Henrik A. Christensen     Date Completed: still in progress
 * Instructor: Kurt Nørmark              Class:          Imperative Programming
 *
 * Prompts the user to enter a number of seconds
 * Then convert the entered number of seconds to
 *   weeks, days, hours, minutes and seconds
 * and output the result to the user
 *
 * examples:
 *
 * if 650 seconds:     0 weeks, 0 days, 0 hours, 10 minutes and 50 seconds
 * if 4000 seconds:    0 weeks, 0 days, 1 hours, 6 minutes and 40 seconds
 * if 1000000 seconds: 1 weeks, 4 days, 13 hours, 46 minutes and 40 seconds
*/

#include <stdio.h>

#define EXIT_SUCCESS 0
#define INVALID_INPUT -1

int main(void)
{
  int input;

  printf("Enter a number of seconds: ");

  /* checks if the user enters a char or string */
  if (scanf("%d", &input) == 0)
  {
    printf("\nInvalid input\n");
    return INVALID_INPUT;
  }

  /* checks if entered number of seconds is greater than 0 */
  if (input < 1)
  {
    printf("The entered number of seconds has to be greater than 0\n");
    return INVALID_INPUT;
  }

  printf("\n%d weeks, %d days, %d hours, %d minutes and %d seconds\n",
	 (input / (3600 * 24 * 7)) % 52, /* weeks */
	 (input / (3600 * 24)) % 7, /* days */
	 (input / 3600) % 24, /* hours */
	 (input / 60) % 60, /* minutes */
	 input % 60 /* seconds */
	 );
  
  return EXIT_SUCCESS;
}
