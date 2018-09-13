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
  int seconds;
  int minutes;
  int hours;
  int days;
  int weeks;

  printf("Enter a number of seconds: ");
  scanf("%d", &input);

  if (input < 1)
  {
    printf("The entered number of seconds has to be greater than 0\n");
    return INVALID_INPUT;
  }

  seconds = input % 60;
  minutes = (input / 60) % 60;
  hours = (input / 3600) % 24;
  days = (input / (3600 * 24)) % 7;
  weeks = (input / (3600 * 24 * 7)) % 52;

  printf("\n%d weeks, %d days, %d hours, %d minutes and %d seconds\n",
	 weeks, days, hours, minutes, seconds);
  
  return EXIT_SUCCESS;
}
