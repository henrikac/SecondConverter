/*
 * Programmer: Henrik A. Christensen     Date Completed: in progress
 * Instructor: Kurt Nørmark              Class:          Imperative Programming
 *
 * Prompts the user for a number of seconds
 * Then convert the entered number of seconds to
 *   weeks, days, hours, minutes and seconds
 * and output the result to the user
 *
 * examples:
 *
 * if 43 seconds:      43 seconds
 * if 650 seconds:     10 minutes and 50 seconds
 * if 4000 seconds:    1 hours, 6 minutes and 40 seconds
 * if 1000000 seconds: 1 weeks, 4 days, 13 hours, 46 minutes and 40 seconds
*/

#include <stdio.h>
#include <stdlib.h>

#define SECONDS_PR_MINUTE 60
#define SECONDS_PR_HOUR 3600
#define HOURS_PR_DAY 24
#define DAYS_PR_WEEK 7
#define WEEKS_PR_YEAR 52
#define INVALID_INPUT -1

int main(int argc, char *argv[])
{
  int input;

  /* checks if user enter seconds in the command line */
  if (argc == 2)
  {
    if (sscanf(argv[1], " %d", &input) != 1)
    {
      printf("\nInvalid input\n");
      return INVALID_INPUT;
    }
  }
  else
  {
    printf("Enter a number of seconds: ");

    /* checks if the user enters a char or string */
    if (scanf("%d", &input) != 1)
    {
      printf("\nInvalid input\n");
      return INVALID_INPUT;
    }
  }

  /* checks if entered number of seconds is greater than 0 */
  if (input < 1)
  {
    printf("The entered number of seconds has to be greater than 0\n");
    return INVALID_INPUT;
  }

  printf("\n%d weeks, %d days, %d hours, %d minutes and %d seconds\n",
	 (input / (SECONDS_PR_HOUR * HOURS_PR_DAY * DAYS_PR_WEEK)) % WEEKS_PR_YEAR, /* weeks */
	 (input / (SECONDS_PR_HOUR * HOURS_PR_DAY)) % DAYS_PR_WEEK,                 /* days */
	 (input / SECONDS_PR_HOUR) % HOURS_PR_DAY,                                  /* hours */
	 (input / SECONDS_PR_MINUTE) % SECONDS_PR_MINUTE,                           /* minutes */
	 input % SECONDS_PR_MINUTE                                                  /* seconds */
	 );
  
  return EXIT_SUCCESS;
}
