/*
 * Programmer: Henrik A. Christensen     Date Completed: 27-09-2018
 * Instructor: Kurt N�rmark              Class:          Imperative Programming
 *
 * Prompts the user for a number of seconds
 * Then convert the entered number of seconds to
 *   hours, minutes and seconds
 * and output the result to the user
 *
 * examples:
 *
 * if 75 seconds:      1 minute and 15 seconds
 * if 3700 seconds:    1 hour, 1 minute and 40 seconds
 * if 55 seconds:      55 seconds
 * if 3661 seconds:    1 hour, 1 minute and 1 second
*/

#include <stdio.h>
#include <stdlib.h>

#define SECONDS_PR_MINUTE 60
#define SECONDS_PR_HOUR 3600
#define INVALID_INPUT -1

int main(int argc, char *argv[])
{
  int input;
  int seconds, minutes, hours;

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
    if (scanf(" %d", &input) != 1)
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

  seconds = input % SECONDS_PR_MINUTE;
  minutes = (input / SECONDS_PR_MINUTE) % SECONDS_PR_MINUTE;
  hours = input / SECONDS_PR_HOUR;

  if (hours > 0)
    printf("%d %s ", hours, hours > 1 ? "hours" : "hour");
  if (minutes > 0)
    printf("%d %s ", minutes, minutes > 1 ? "minutes" : "minute");
  if (seconds > 0) 
    printf("%d %s\n", seconds, seconds > 1 ? "seconds" : "second");
  
  return EXIT_SUCCESS;
}
