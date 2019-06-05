#include<stdio.h>

int main() {
  int ii = 0;
  char c = 13;  /* ASCII 13 = CR (carriage return) */
  for(;;) {
    printf("%cii=%d",c,ii++);
  }
  return 0;
}
