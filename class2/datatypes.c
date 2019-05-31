/* Examples of C data types */
#include<stdio.h>
#include<limits.h>

int main(void) {
  char c;
  int i = 10;
  unsigned int ui = 10;

  /* char */
  printf("Char\n");
  c = 'a';   /* Character literal */
  printf("  char 1: %d %c\n", c, c);
  c++;       /* Arithmetic */
  printf("  char 2: %d %c\n", c, c);
  c = 67;    /* Integer literal */
  printf("  char 3: %d %c\n", c, c);
  c = 070;   /* Octal literal */
  printf("  char 4: %d %c\n", c, c);
  c = 0x58;  /* Hexidecimal literal */
  printf("  char 5: %d %c\n", c, c);
  c = 65;
  printf("  char 6: %d %o %x %c\n", c, c, c, c);

  /* int */
  printf("\n\nInteger\n");
  printf("   int 1:  i=%d  ui=%u\n", i, ui);
  i = -10;
  ui = -10;
  printf("   int 2:  i=%d  ui=%u\n", i, ui);
  /* Careful! */ 
  printf("   int 3:  i=%u  ui=%d\n", i, ui);

  printf("\nData types & sizes:\n");
  printf("         char:\tsize=%ld\tmin=%d,\t\tmax=%d\n", sizeof(char), CHAR_MIN, CHAR_MAX);
  printf("          int:\tsize=%ld\tmin=%d,\tmax=%d\n", sizeof(int), INT_MIN, INT_MAX);
  printf("        short:\tsize=%ld\tmin=%d,\t\tmax=%d\n", sizeof(short), SHRT_MIN, SHRT_MAX);
  printf("         long:\tsize=%ld\tmin=%ld,\tmax=%ld\n", sizeof(long), LONG_MIN, LONG_MAX);
  printf("unsigned long:\tsize=%ld\tmax=%lu\n", sizeof(unsigned long), ULONG_MAX);
  printf("        float:\tsize=%ld\n", sizeof(float));
  printf("       double:\tsize=%ld\n", sizeof(double));

  return 0;
}
