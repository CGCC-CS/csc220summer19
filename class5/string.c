/* Examples of string functions
 * Keep in mind: in C strings are null-terminated character arrays,
 * so my_string[10] can hold a string of 9 characters + 1 null
 */

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define LEN 10

void str_fun(char str[]);

int main(void) {
  char str1[LEN] = "Hello";
  char str2[LEN] = "World";
  char * ptr1 = (char *) malloc(LEN);
  char * ptr2 = (char *) malloc(LEN);

  /* use strncpy to copy strings - string gets truncated if too long */
  /* do NOT use strcpy */
  /* WARNING  strcpy(ptr1, "CSC220 Summer 2019 CHO104 TTh 7:00-9:40");  WARNING */
  /* WARNING */ strcpy(ptr1, "CSC220"); /* WARNING */
  strncpy(ptr2, "Summer '19 THIS GETS TRUNCATED", LEN);

  printf("Initial strings: \n");
  printf("  str1: sizeof=%lu  strlen=%lu  str1=%s\n", sizeof(str1), strlen(str1), str1);
  printf("  str2: sizeof=%lu  strlen=%lu  str2=%s\n", sizeof(str2), strlen(str2), str2);
  printf("  ptr1: sizeof=%lu  strlen=%lu  ptr1=%s\n", sizeof(ptr1), strlen(ptr1), ptr1);
  printf("  ptr2: sizeof=%lu  strlen=%lu  ptr2=%s\n", sizeof(ptr2), strlen(ptr2), ptr2);

  printf("Passing a string to a function: \n");
  printf("  str1:\n");
  str_fun(str1);
  printf("  ptr1:\n");
  str_fun(ptr1);

  /* Try Each of these and see which works.  (Print the output for any that
   * allow assignment to be done.  Note that changing ptr1 will mean we
   * no longer have a pointer to the memory we originally allocated, so
   * we would need to free it so we can reuse it.
   */
  /*
  ptr1 = "Chandler";
  ptr1 = str2;
  str1 = "HELLO";
  str1 = ptr1;
  printf("Strings after direct assignment: \n");
  printf("  str1 : %s\n", str1);
  printf("  str2 : %s\n", str2);
  printf("  ptr1 : %s\n", ptr1);
  printf("  ptr2 : %s\n", ptr2);
  */

  /* COMPARING STRINGS - strcmp, strncmp */
  /* NOTE: strcmp should not be used because it does no bounds checking! */
  printf("\nComparing strings: \n");
  if (strcmp(str1, "Hello") == 0) 
      printf ("  %s and \"Hello\" are the same\n", str1);
  else 
      printf ("  %s and \"Hello\" are different\n", str1);

  /* Compare end of one string or first N characters */
  if (strncmp(str1, "Hello", LEN) == 0) 
      printf ("  %s and \"Hello\" are the same through 5 characters\n", str1);
  else 
      printf ("  %s and \"Hello\" are different through 5 characters\n", str1);

  if (strncmp(str1, "Hello, World!", 5) == 0) 
      printf ("  %s and \"Hello World!\" are the same through 5 characters\n", str1);
  else 
      printf ("  %s and \"Hello World!\" are different through 5 characters\n", str1);

  if (strncmp(str1, "Hello, World!", 100) == 0) 
      printf ("  %s and \"Hello World!\" are the same through 100 characters\n", str1);
  else 
      printf ("  %s and \"Hello World!\" are different through 100 characters\n", str1);
  if (strncmp(str1, str2, LEN) < 0) 
      printf ("  %s is before %s\n", str1, str2);
  else if (strncmp(str1, str2, LEN) > 0) 
      printf ("  %s is before %s\n", str2, str1);
  else
      printf ("  %s and %s are the same\n", str1, str2);
  if (strncmp(str2, str1, LEN) < 0) 
      printf ("  %s is before %s\n", str2, str1);
  else if (strncmp(str2, str1, LEN) > 0) 
      printf ("  %s is before %s\n", str1, str2);
  else
      printf ("  %s and %s are the same\n", str1, str2);
  
  printf("\nCocatenating strings: \n");
  printf("  Before: str2 : %s\n", str2);
  printf("  Before: ptr1 : %s\n", ptr1);
  strncat(str2, "!!!", 3); /* append 3 characters to end */
  strncat(ptr1, " 2017", 3); /* append 3 characters - will cut off any extras */
  printf("  After: str2 : %s\n", str2);
  printf("  AFter: ptr1 : %s\n", ptr1);

  free(ptr1);
  free(ptr2);
  return 0; 
}

void str_fun(char str[]) {
  char str2[] = "1234568901234567890";
  printf("  myfun: sizeof(%s) = %lu\n", str, sizeof(str)); 
  printf("  myfun: strlen(%s) = %lu\n", str, strlen(str)); 
  printf("  myfun: sizeof(%s) = %lu\n", str2, sizeof(str2)); 
  printf("  myfun: strlen(%s) = %lu\n", str2, strlen(str2)); 
}
